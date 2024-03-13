## Porquê Criar Vários Processos?
**Conveniência**:
- Estruturação dos programas
- Para não estar à espera (spooling, background…)
- Multiplas atividades/janelas
**Eficiência**:
- Múltiplos CPUs
- Aumenta a utilização de recursos (multiprogramação)

### Benefícios da Multiprogramação
![[Screenshot 2024-03-09 at 19.27.58.png]]

## Processos
Um **programa** em execução e que tem atividade própria:
- Programa é uma entidade _estática_.
- Processo é uma entidade _dinâmica_.
Duas invocações do mesmo programa resultam em dois processos diferentes.

O contexto de execução dum processo (o seu _estado_) compreende:
- código
- dados (variáveis globais, heap, stack)
- estado do processador (registos)
- ficheiros abertos
- tempo de CPU consumido
- …

**Informação de processo**
![[Screenshot 2024-03-11 at 15.38.57.png]]

### Gestão de Processos
Os programas em execução requerem tempo de CPU, memória, utilização de dispositivos, entradas livres em estruturas de dados do SO, canais de comunicação com outros processos, etc. (**competem por recursos**)
A competição é no entanto mediada pelo SO. Como os processos **não** podem aceder diretamente ao código e dados do SO, necessitam de uma API para solicitar serviços através das _system calls_.

**Exemplo**
Para criar um novo processo:
- _fork_: cria um novo processo (a chamada ao sistema retorna **duas vezes**, uma para o pai e outra para o filho);
- A partir daí, ambos executam o mesmo programa.
Para executar outro programa dentro do mesmo processo:
- _exec_: substitui o programa por um novo programa
Para terminar a execução:
- _exit_

```C
pid = fork()
if (pid == 0) { // Código do filho
	exec(novo_programa);
} else {
	// Código do pai
}
```

Cabe ao sistema operativo de fazer o _escalonamento_ dos processos, garantindo que a ordem de acesso ao CPU corresponde às políticas de escalonamento previamente definidas. É necessário definir **objetivos**.

#### Objetivos
Conveniência:
- Justiça
- Redução dos tempos de resposta
- Previsibilidade
Eficiência:
- Débito (_throughput_), transações por segundo
- Maximização da utilização de CPU e outros recursos
- Favorecer processos "bem comportados", etc.

#### Critérios de Escalonamento
- [[Gestão de Processos#Benefícios da Multiprogramação|IO-bound ou CPU-bound]]
- Interativo ou não (batch, background)
- Urgência de resposta (ex.: tempo real)
- Comportamento recente (utilização de memória, CPU)
- Necessidade de periféricos especiais
- **Pediu** para ir à frente dos outros…

### Estados de Um Processo
![[Screenshot 2024-03-11 at 15.49.54.png]]

Podemos admitir que durante a sua **vida**, os processos passam por 2 estados:
![[Screenshot 2024-03-11 at 15.50.19.png]]

Na prática, há mais processos não bloqueados do que CPUs. Surge, assim, uma fila de espera com processos **prontos a executar**.
Processos em execução podem ser desafetados.
![[Screenshot 2024-03-11 at 15.52.03.png]]

**Em execução**:
- Foi-lhe atribuído o/um CPU, executa o programa correspondente.
**Bloqueado**:
- O processo está logicamente impedido de prosseguir porque lhe falta um recurso ou espera por evento;
- Do ponto de vista do SO, é uma transição _voluntária_.
**Pronto a executar**:
- Aguarda escalonamento.

#### Primitivas de Despacho
![[Screenshot 2024-03-11 at 15.54.20.png]]

**`bloqueia(evento)`**:
- Coloca _processo corrente_ na fila de processos _parados_ à espera deste `evento`;
- Invoca `próximo_processo()`.
**`liberta(evento)` ou `liberta(processo, evento)`**:
- Se o _outro_ processo não está à espera de mais nenhum evento, então coloca-o na lista de processos _prontos a executar_;
- Nesta altura pode invocar **ou não** `próximo_processo()`.
**`próximo_processo()`**:
- Seleciona um dos processos existentes na lista de processos prontos a executar, de acordo com a [[Gestão de Processos#Políticas de Escalonamento|política de escalonamento]];
- Executa a comutação de contexto:
	- Salvaguarda contexto volátil do processo corrente
	- Carrega contexto do processo escolhido e regressa (executa o `return`)

### Escalonamento de Processos
Quando, uma vez atribuído a um processo, o CPU nunca lhe é retirado então diz-se que o escalonamento é **cooperativo**. (_non-preemptive_)
- Exemplos: Windows 3.1 / co-rotinas / `thread_yield()`.
Quando o CPU pode ser retirado a um processo ao fim do _quantum_ ou porque surgiu outro de maior prioridade diz-se que o escalonamento é com **desafetação forçada**. (_preemptive_)

Escalonamento **cooperativo**:
- "poor man's approach to multitasking"
- sensível às variações de carga
Escalonamento com **desafetação forçada**:
- sistema "responde" melhor
- comutação de contexto tem _overhead_

#### Modelo de Sistema Interativo
![[Screenshot 2024-03-13 at 02.19.39.png]]

##### Tempo de Resposta (carga homogénea)
![[Screenshot 2024-03-13 at 02.20.24.png]]

##### Tempo de Resposta (carga heterogénia)
![[Screenshot 2024-03-13 at 02.20.54.png]]
Para evitar que as interações longas monopolizem o CPU e aumentem o tempo de resposta das restantes deve usar-se desafetação forçada.
Neste caso deve atribuir-se um _quantum_ (ou _time slice_) para permitir a troca rápida de processos:
- Interações curtas terminam dentro dessa fatia de tempo, logo não são afetadas pela política de desafetação.
- Interações longas executam durante um quantum e a seguir o processo correspondente regressa ao estado de **pronto a executar**, dando a vez a outros processos. Mais tarde ser-lhe-á atribuído uma nova fatia de tempo, e sucessivamente até a interação terminar.

###### Duração da Fatia de Tempo
Maioria das interações deve "caber" num _quantum_.

$$
R = W + C
$$

Se precisar de 2 passagens pelo CPU, $T_{\text{resposta}}$ é quase o dobro.

$$
R = W + q + W + c'
$$

![[Screenshot 2024-03-13 at 02.26.15.png]]
___

#### Definições
- Escalonadores de longo-prazo (segundos, minutos) e de curto-prazo (milisegundos);
- _Processo CPU-bound_: processo que faz pouco I/O mas requer muito processamento;
- _Processo I/O-bound_: processo que está frequentemente à espera de I/O.

- Os processos prontos são seriados numa fila (_ready list_);
- A lista é uma lista ligada de apontadores para PCB's;
- A lista poderá estar ordenada por vários critérios de forma a dar tratamento preferencial a alguns processos.

Quando um processo é escalonado, é retirado da _ready list_ e posto a executar.
Pode "perder" o CPU por 2 razões:
- Faz um pedido de I/O que não pode ser servido imediatamente (teclado, etc.) ou pede ao SO pare esperar $\rightarrow$ passa ao estado de **bloqueado**;
- É _desafetado_ porque aparece um processo com maior "prioridade" ou o seu _quantum_ expira $\rightarrow$ passa ao estado de **pronto**.

Pretende-se maximizar a utilização do CPU tendo em atenção outros aspetos:
- Tempo de resposta para aplicações interativas;
- Utilização de dispositivos I/O;
- Justiça na distribuição do tempo de CPU.

A decisão de escalonar um processo pode ser tomada em diversas alturas:
- Quando o processo é **bloqueado**;
- Quando o processo passa a **pronto a executar**;
- Quando se completa um operação de I/O;
- Quando um processo termina.

Por fim, diferentes algoritmos de escalonamento ([[Gestão de Processos#Políticas de Escalonamento|políticas de escalonamento]]) visam objetivos diferentes:
- Diminuir o tempo de resposta (reduzindo o tempo de espera para determinados processos);
- Maximizar a utilização do CPU.

#### Políticas de Escalonamento
Alguns algoritmos de escalonamento:
- [[Gestão de Processos#First Come, First Served (FCFS)|FCFS (First Come, First Served)]]
- [[#Shortest Job First (SJF)|SJF (Shortest Job First)]]
- SRTF (Shortest Remaining Time First)
- [[#Preemptive Priority|Preemptive Priority Scheduling]]
- [[#Round Robin (RR)|RR (Round Robin)]]

##### First Come, First Served (FCFS)
**Características**:
- A _ready list_ é uma fila First In, First Out (FIFO);
- Os processos são colocados no fim da fila e selecionado o da frente;
- Método cooperativo;
- Nada apropriado para ambientes interativos.

Uma vantagem óbvia do FCFS é a sua simplicidade de implementação: lista de processos por ordem de criação do processo (_batch_).
Sujeito a tempos de espera com grandes flutuações, dependendo da ordem de chegada e das características dos processos (_efeito comboio_).

Parece haver vantagens em escalonar os processos mais curtos à frente…

##### Shortest Job First (SJF)
A ideia é escalonar o processo mais curto primeiro.
**Possibilidades**:
- Desafetação forçada (SRTF) - interrompe-se o processo em execução se aparecer um mais curto;
- Cooperativo - mesmo na presença de um processo mais curto, pode aguardar-se pela terminação ou bloqueio voluntário do processo em execução. E nessa altura escolhe-se o mais curto.

##### Preemptive Priority
**Características**:
- Associa uma _prioridade_ (geralmente um inteiro) a cada processo;
- A _ready queue_ é uma fila seriada por prioridades;
- Escalona sempre o processo na frente da fila;
- Se aparece um processo com maior prioridade do que o que está a executar, faz a troca dos processos.

**Problema**: _starvation_.
**Solução**: _envelhecimento_ - aumenta a prioridade dos processos pouco a pouco de forma a que inevitavelmente executem e terminem.
É necessário justificar quando e quanto aumenta.

##### Round Robin (RR)
**Características**:
- Dá a cada processo um intervalo de tempo fixo de CPU de cada vez;
- Quando um processo esgota o seu _quantum_, retira-o do CPU e volta a colocá-lo no fim da fila;
- Ignorando os _overheads_ do escalonamento, cada um dos $n$ processos CPU-bound terá ($1/n$) do tempo disponível de CPU.

**Problemas**:
- Se o _quantum_ for (muito) grande, o RR tende a comportar-se como o FCFS;
- Se o _quantum_ for (muito) pequeno, então o _overhead_ de mudanças de contexto tende a dominar degradando os níveis de utilização útil de CPU;
- Favorece processos que libertem o CPU ao fim de pouco tempo (aproxima-se do **shortest**) mas sem exigir conhecimento rigoroso do tempo de cada _CPU burst_.

#### Níveis de Escalonamento
Uma vez que há inúmeros critérios de escalonamento e muitas variáveis a considerar para saber qual o **melhor** processo a escolher, é habitual dividir a questão em 2 ou 3 níveis:
- **Nível 0** $\rightarrow$ só despacha o que está em RAM (RR ou MLQ)
- **Nível 1** $\rightarrow$ decide que processos são multiprogramados, por indicação do gestor de memória
- **Nível 2** $\rightarrow$ não deixa criar processos nas horas de ponta, por decisão de quem administra e conhece a carga diária
