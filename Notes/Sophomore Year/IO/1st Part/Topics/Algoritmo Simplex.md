## Matriz Identidade do Quadro Simplex
Quadro simplex deve ter sempre uma matriz identidade. Só assim é que:
- cada equação mostra como variam:
	- cada variável básica e
	- a função objectivo em função apenas das variáveis não-básicas;
- se podem identificar as decisões correctas no algoritmo simplex.
![[Screenshot 2024-04-30 at 13.53.35.png]]

## Método Simplex
Um simplex é um poliedro formado por um dado vértice e n vértices adjacentes. É o poliedro mais simples no espaço a n dimensões.
O método simplex dá origem a um algoritmo que percorre uma sequência de vértices admissíveis até atingir a solução óptima.

Assim, o algoritmo simplex consiste em:
- seleccionar um vértice admissível inicial
- enquanto (existir um vértice admissível adjacente melhor) mudar para vértice admissível adjacente melhor

Operações fundamentais do algoritmo simplex:
1. **teste de otimalidade**: existe algum vértice admissível adjacente ao vértice actual com melhor valor de função objectivo?
2. **pivô**: mudança de uma base (vértice) para uma base adjacente.

### Seleção do Elemento Pivô
Efectuar um pivô traduz-se em reescrever o sistema de equações, resolvendo-o em ordem a um novo conjunto de variáveis básicas, o que se faz usando eliminação de Gauss.
Na inversão de matrizes ou na resolução de sistemas de equações, há regras para seleccionar o elemento pivô (cruzamento da coluna pivô com a linha pivô).

No algoritmo simplex, a regra de seleção da:
1. _coluna pivô_ (variável não-básica que entra na base) visa mudar para um vértice melhor;
2. _linha pivô_ (variável básica que sai da base) assegura que o próximo vértice é admissível.

#### Coluna Pivô: Regra de Seleção
- A coluna com o coeficiente mais negativo da linha da função objectivo, em problemas de maximização.
- A coluna com o coeficiente mais positivo da linha da função objectivo, em problemas de minimização.
Em caso de empate, a escolha é arbitrária (ou desempata-se seleccionando a aresta que conduz ao vértice adjacente com melhor valor da função objectivo).

#### Linha Pivô: Regra de Seleção
Dada uma coluna pivô, a linha pivô (da variável básica que sai da base): é a linha com **menor razão positiva**.
Clarificação:
- positiva significa que o coeficiente da coluna pivô deve ser > 0.
- A menor razão pode ser 0, se o lado direito for 0.
Se não existir um coeficiente da coluna pivô > 0, a solução óptima é ilimitada.
Em caso de empate, o próximo vértice é degenerado.

## Algoritmo
1. Selecção de um vértice admissível inicial
	- Se não existir, problema é impossível
2. Repetir
	- Selecção da coluna pivô:
		- Coeficiente mais negativo da linha da função objectivo
		- (em caso de empate, escolha arbitrária)
		- Se não existir coeficiente $<0$, solução óptima.
	- Selecção da linha pivô:
		- Menor razão (lado direito/coluna pivô) positiva (coeficiente coluna $>0$)
		- (em caso de empate, o próximo vértice é degenerado)
		- Se não existir coeficiente coluna $>0$, solução óptima é ilimitada
	- Fazer eliminação de Gauss
3. Enquanto (solução não for óptima)

## Conclusão
O resultado que estabelece que existe um vértice que é uma solução óptima do problema permite que o algoritmo simplex restrinja a procura apenas aos vértices admissíveis.
As decisões (selecção da coluna e da linha pivô) garantem que se muda de um vértice admissível (do problema primal) para outro vértice admissível mais próximo da solução óptima.
A mudança de base faz-se usando eliminação de Gauss.
