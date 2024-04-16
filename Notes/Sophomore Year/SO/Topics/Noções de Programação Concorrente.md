## Paralelismo Vs Concorrência

- Execução paralela $\rightarrow$ hardware
	- Vários computadores (ex. cluster)
	- Multiprocessamento (ex. um processo em cada CPU)
	- Hyper-threading / Dual core
	- CPU a executar instruções em paralelo com a operação de disco (que se manifesta através duma _interrupção_, com prioridade superior à atividade no CPU)

**Em geral:**
Seja num ambiente de paralelismo real ou simulado pelo SO, existem várias _atividades_ em execução _paralela_. Normalmente essas atividades **não são independentes**, há _interação_ entre elas.

O sistema operativo tem, então, responsabilidade de:
- Fornecer _mecanismos_ que permitam a criação e interação de processos
- Gerir a execução concorrente (ou em paralelo), de acordo com as políticas definidas pelo administrador de sistemas

### Cooperação e Competição
Há normalmente 2 padrões de interação entre processos:
- Cooperam entre si para atingir um resultado comum
	- Processo inicia transferência do disco e aguarda _passivamente_ que esta termine
	- O disco interrompe e a rotina de tratamento avisa que o processo já pode prosseguir
- Competem por recursos (CPU, memória, impressora, etc.)
	- Há necessidade de forçar 1 ou mais processos a esperar até que o recurso pretendido fique disponível e lhes seja atribuído (seja a sua vez).

### Sincronização
Nos dois casos anteriores, perante uma questão de sincronização:
- Cooperação (espera até que o evento seja assinalado)
- Competição (espera até que o recurso esteja disponível)
**Sincronizar** é fazer esperar, atrasar deliberadamente um processo até que determinado evento surja (convém que a espera seja _passiva_)

### Comunicação
Para haver interação tem de haver **comunicação**:
- Processos podem requisitar ao SO memória partilhada, podem escrever/ler ficheiros comuns, enviar/receber _mensagens_ através de "canais" (_pipelines_, _sockets_, etc.)
- Threads do mesmo processo podem comunicar através de variáveis globais
A comunicação pode ser tão simples como o assinalar a ocorrência de um evento (de sincronização), ou pode transportar dados.

#### Exemplos de Concorrência
Inspirados na vida real
- Diálogo cliente/bar(wo)men
- Atualização do saldo de uma conta bancária
- Entrada num parque de estacionamento ou sala de cinema sem marcação de lugar
São exemplos, respetivamente, de:
- Sincronização
- Exclusão mútua
- Controlo de capacidade

Na realidade, os três exemplos anteriores são de **sincronização**, pois em todos poderá ser necessário esperar até que se verifique determinada condição.

Assim,
- **Comunicação**: escrita/leitura de dados passados através de vários mecanismos (ficheiros, memória partilhada…)
- **Sincronização**: coordenação de eventos entre processos (usando semáforos, variáveis de condição, locks…), designadamente para garantir uma ordem na ocorrência desses eventos.
Há mecanismos que tratam dos dois aspetos (ex. pipelines, mensagens, sockets…)

### Mecanismos de Sincronização
Existem muitas propostas, sendo o seu estudo diferido para unidades curriculares como programação concorrente, sistemas distribuídos e computação paralela.
Umas são genéricas (semáforos, mensagens), outras vocacionadas para casos particulares nomeadamente:
- exclusão mútua (e.g. mutexes, fcntl, Linux leases, métodos synchronised, etc.)
- para serem usadas dentro do kernel do SO (sleep/wakeup, spin locks)
- em ambientes multithreaded (wait/signal/notify)…

#### Semáforos
Servem para resolver problemas de _sincronização_, _exclusão mútua_ e _controlo de capacidade_
Com apenas 3 operações:
- Inicialização:
	`s = cria_semáforo(valor_inicial)`
- `P(s)` ou `Down(s)`
- `V(s)` ou `Up(s)`
Imagine uma caixa com bolas e as operações:
- P: Se há bola(s) na caixa, retiro uma e continuo, senão aguardo (passivamente) que alguém deposite uma
- V: Devolvo a bola à caixa; se há alguém bloqueado à espera, acordo-o

```c
P(s) {
	s = s - 1;
	if (s < 0)
		bloqueia("S");
}
```

```c
V(s) {
	s = s + 1;
	if (s <= 0)
		liberta("S");
}
```
 - Bloquear significa retirar o processo corrente do estado RUN e inseri-lo na fila “S”
 - "S” contém os processos BLOQUEADOS no semáforo S
 - Libertar significa escolher um processo da fila “S” e inseri-lo na fila READY
 - Normalmente essa escolha é FIFO
 - Mas pode não ser...
##### Receitas com Semáforos
Sabendo que `valor inicial + #V() >= #P() concluídos`:
- _Sincronização_:
	`valor inicial = 0`
- _Exclusão mútua_:
	`valor inicial = 1`
- _Capacidade_:
	`valor inicial = N = capacidade do recuros`