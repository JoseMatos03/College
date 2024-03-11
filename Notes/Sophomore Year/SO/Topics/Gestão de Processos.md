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
#### Políticas de Escalonamento
