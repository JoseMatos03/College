Idealmente a memória seria grande, rápida e não volátil. Na realidade, há uma hierarquia:
- Pouca memória é muito rápida - _cache_
- Velocidade média, custo aceitável - _RAM_
- Giga/terabytes de memória auxilia - _discos / SSDs_

## Monoprogramação
![[Screenshot 2024-04-14 at 17.29.22.png]]

## Multiprogramação
![[Screenshot 2024-04-14 at 17.30.02.png]]

### Recolocação e Proteção
Para carregar um processo em qualquer partição livre:
- O endereço de carregamento do programa não pode ser definido pelo compilador. Isto é, o endereço de variáveis funções não pode ser _absoluto_.
- Tem de ser _recolocável_, para ser alterável no momento do carregamento.
- Para o compilador, tudo começa no endereço 0.
CPUs passam a dispor de registos base e limite:
- Endereços saídos do CPU são adicionados à base para obter endereços físicos
- Valores superiores ao registo limite são erros (processo é **terminado**).

### Swapping
A alocação de memória muda sempre que um processo é criado ou terminado, e também sempre que um processo é _swapped out_ ou _swapped in_ de disco.
![[Screenshot 2024-04-14 at 17.44.35.png]]
![[Screenshot 2024-04-14 at 17.45.15.png]]

### Gestão de Memória com Bitmaps
![[Screenshot 2024-04-14 at 17.46.05.png]]

### Gestão de Memória com Listas Ligadas
![[Screenshot 2024-04-14 at 17.47.56.png]]

Em resumo, a gestão de memória baseada em partições aumenta a eficiência à custa de multiprogramação, mas:
 - É inconveniente:
	 - Restringe a dimensão máxima dos processos
	 - Alocação contígua dificulta a atribuição de endereços
	 - Não permite proteção _fina_ (ex. `read`,`write`,`exec`)
- É ineficiente:
	- Causa fragmentação e não permite partilha
	- Nem tira partido da dispersão de referências

## Memória Virtual
![[Screenshot 2024-04-14 at 17.50.41.png]]
A relação entre endereços virtuais e físicos é dado por uma tabela
![[Screenshot 2024-04-15 at 15.25.12.png]]
![[Screenshot 2024-04-15 at 15.37.04.png]]
Operação da MMU com 16 páginas de 4KB. Offset de 12 bits.

### TLBs
![[Screenshot 2024-04-15 at 15.41.57.png]]

### Aspetos de Implementação
Tratamento da _Page Fault_:
1. MMU interrompe o processador.
2. Kernel salvaguarda os registos e invoca a função de tratamento
3. GMV determina a página necessária e a razão para interrupção
4. SO valida endereço e procura/cria page frame
	- Page in, zero fill, in transit
	- Pode implicar rejeição de outra página

O SO intervém na paginação em 4 situações:
1. Criação do processo
	- Determina o tamanho do programa
	- Cria a tabela de página
2. Execução do processo
	- Reinicializa a MMU para o novo processo
	- Limpa a TLB
3. Page Fault
	- Determina o endereço virtual causador da page fault
	- Coloca a página em memória, se endereço for legal
4. Fim da execução do processo
	- Liberta a tabela de páginas e as páginas/frames

## Segmentação
