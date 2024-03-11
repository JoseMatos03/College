## Sistema Operativo
Programa que atua como _intermediário_ entre os utilizadores e o hardware.
Assim, o sistema operativo deve gerir o hardware e colocá-lo à disposição dos programas e utilizadores, de uma forma:
- conveniente;
- protegida;
- eficiente;
- justa…

### Conveniência
- SO esconde os detalhes do hardware (dimensão e organização da memória)
- Simula uma máquina virtual com valor acrescentado (cada _processo_ executa numa "máquina")
- Fornece API mais fácil de usar do que o hardware (ficheiros vs blocos em disco)

### Eficiência
- SO controla a alocação de recursos
	- Se 3 programas usarem a impressora ao mesmo tempo $\rightarrow$ _sai lixo?_
	- Programa em ciclo infinito $\rightarrow$ _computador bloqueia?_
	- Processo corrompe a memória dos outros $\rightarrow$ _programas morrem?_
- Multiplexação:
	- Tempo: cada processo usa o recurso à vez (impressora, CPU)
	- Espaço: recurso é partilhado simultaneamente por vários processos (memória central, disco)

## No Início
Acesso livre ao computador, ou seja, o utilizador podia fazer de tudo, mas para isso teria de fazer tudo.
A eficiência era baixa devido ao elevado tempo de preparação e o tempo _desperdiçado_ com debugging.

![[Screenshot 2024-03-09 at 03.21.01.png]]
Comprava-se _hardware sem software_.

### Acesso Livre
Utilizador fazia tudo:
1. Percebe o problema e idealiza a solução (algoritmo + dados);
2. Descreve o algoritmo em "alguma notação de alto nível";
3. Estuda o manual do CPU e memória, faz então a tradução para a linguagem máquina (e decide que endereços vais usar);
![[Screenshot 2024-03-09 at 03.23.29.png]]
4. Chegada a hora, carrega manualmente o programa e dados;
5. Executa o programa;
6. Se não está correto, tem de descobrir sozinho os erros;
7. Eficiência é muito baixa devido ao desperdício de tempo de CPU

### Para Aumentar a Eficiência - I
Surgiu a ideia de reduzir a intervenção humana, fazendo a preparação de programas e dados _off-line_ e acelerando o seu carregamento posterior.
Inventaram-se periféricos de _input_ e _output_, como a **Teletype**, embora a velocidade ainda era muito baixa (10 chars/s) para ler da fita ou escrever na fita/papel

### Para Aumentar a Eficiência - II
Automatizou-se uma parte do _procedimento_:
- Utilizador deixa de interagir com o seu programa, usa fita perfurada ou coloca os cartões num cesto e espera…
- Operadores recolhem o cesto periodicamente e colocam programas e dados no leitor. O sistema executa os _jobs_ e imprime os resultados, que são devolvidos a determinadas horas.

Ganhou-se em **eficiência**, perdeu-se em **conveniência**:
- Um _job_ que antes demorava uma hora é agora executado em segundos;
- Turnaround tempo de horas: entrega às 9h, recebe às 19h.

### Para Aumentar a Eficiência - III
Apesar de cada _job_ "curto" demorar (dezenas de) segundos, o CPU está ocupado todo esse tempo, ora a executar código ora em espera ativa de IO.
E se… input, execução e output pudessem ser **realizados em paralelo**? $\rightarrow$ Pipelining

#### Riscos
Havia riscos de perder eficiência a erros de programação:
- Ciclos infinitos
- Espera ativa por periféricos lentos
- Erros na leitura ou escrita de periféricos
- Programa do utilizador destruir o _programa de controle_.

##### Soluções (hardware)
- Interrupções
- Relógio de **tempo virtual**
- Instruções privilegiadas, 2 ou mais _modos de execução_, proteção de memória
Aparecem, assim, as **system calls**.

##### Soluções (software)
- Chamadas ao sistema
- Virtualização de periféricos (leitor de cartões):
	- Programa pede para ler o periférico
	- SO devolve o conteúdo de um cartão que foi copiado para banda magnética ou lido anteriormente para memória (SPOOL)
Mais tarde aparece a **multiprogramação**.

### Primeiros Sistemas de Batch
Processador auxiliar faz IO de periféricos lentos (virtuais)
- Carregar cartões no 1401, que os copia para banda magnética
- Colocar banda no 7094 e executar os programas
- Recolher banda com resultados do batch e colocá-la na 1401, que os envia para a impressora
![[Screenshot 2024-03-09 at 19.14.21.png]]

## Multiprogramação
- Memória central dividida em várias zonas (partições);
- Vários jobs simultaneamente em memória mas não "vêem" os outros;
- Isto permite executar concorrentemente vários processos, repartindo o tempo de CPU entre eles.
![[Screenshot 2024-03-09 at 19.17.20.png]]
**Proteção de memória**
![[Screenshot 2024-03-09 at 19.16.50.png]]
Note que estes teste têm de ser feitos sempre que há um acesso à memória até 4 vezes por instrução.

## Multiprocessamento
A ideia é executar mais carga no mesmo intervalo de tempo (aumentar o _throughput_). **Não é** executar um programa mais depressa (baixar o seu _tempo de resposta_). Para isso é preciso dividir uma aplicação em vários processos e executar cada um no seu CPU/core.
No entanto, consegue reduzir o tempo de espera até ter acesso a um CPU.

Arquitetura:
- Simétrica:
	- qualquer CPU pode executar código do SO
	- cuidado com _race conditions_ (acesso à tabela de blocos de memória livres)
	- hardware mais sofisticado (disco interrompe todos os CPUs)
- Assimétrico
	- Periféricos associados a um só CPU, o que executa o SO
	- CPUs podem estar parados porque o SO não "despacha"
