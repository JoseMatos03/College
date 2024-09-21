## Restrições Ativas
![[Screenshot 2024-04-30 at 13.41.54.png]]

## Determinação de Coordenadas
![[Screenshot 2024-04-30 at 13.42.28.png]]

## Caso Geral: Vértices do Poliedro e Solução Básicas
A cada vértice de um poliedro corresponde uma solução do sistema de equações designada por **solução básica (admissível)**.
Numa solução básica. há:
- **variáveis não-básicas**: as que têm valor 0, e identificam as faces (fronteiras das restrições) cuja intersecção determina o vértice;
- **variáveis básicas**: as restantes.

## Ideia Chave
Representar o sistema de equações numa dada base permite saber:
- as coordenadas do vértice correspondente à solução básica;
- como varia, ao longo de cada _aresta_ incidente no vértice:
	- o valor de cada variável;
	- o valor da função objectivo.

Essa informação permite:
- implementar o [[Algoritmo Simplex|algoritmo simplex]], que _percorre_ vértices admissíveis, sucessivamente melhores, até se atingir a solução óptima.

## Arestas do Poliedro
Uma aresta é definida pelas faces que são comuns aos 2 vértices.
![[Screenshot 2024-04-30 at 13.47.58.png]]

### Movimento Ao Longo de uma Aresta
Quando nos movemos ao longo de uma aresta partindo de um vértice, os valores das variáveis alteram-se do seguinte modo:
- Variáveis não-básicas:
	- há 1 única variável não-básica cujo valor aumenta;
	- as restantes variáveis não-básicas permanecem nulas.
- Variáveis básicas:
	- alteram-se de acordo com o sistema de equações.
A equação da função objectivo mostra a alteração do seu valor.
![[Screenshot 2024-04-30 at 13.50.44.png]]

## Simplexes e Método Simplex
Um d-simplex é a figura geométrica mais simples do espaço de dimensão d, definida por d + 1 vértices.
É o poliedro mais simples no espaço de dimensão d:
- um 0−simplex é um ponto
- um 1−simplex é um segmento de recta
- um 2−simplex é um triângulo
- um 3−simplex é um tetraedro (pirâmide triangular)
