Classificação de problemas de otimização
![[Screenshot 2024-04-15 at 16.12.02.png]]
![[Screenshot 2024-04-15 at 16.12.45.png]]

## Formulação de Um Problema Sem Restrições

$$
min_{x\in R^n}f(x)
$$

$n$ representa o número de variáveis no problema.
- Se $n=1$ $\Rightarrow$ problema diz-se **unidimensional**, $x$ é escalar
- se $n>1$ $\Rightarrow$ problema **multidimensional**,

$$
x=\begin{pmatrix}
	x_1 \\
	x_2 \\
	\vdots \\
	x_n
\end{pmatrix}\text{ é vetor de dimensão } n
$$

## Mínimos vs Máximos

$$
max f(x) = -min(-f(x))
$$

$$
x^*=arg\space max(f(x)) = arg\space min(-f(x))
$$

### Classificação de Mínimos (e máximos)
Seja $V(x,\delta)$ uma vizinhança (bola aberta) de $x^*$ de raio $\delta$ ($\delta > 0$)
$x^*$ é _minimizante_ **local** forte (fraco) se $\exists\delta > 0$:
- $f(x)$ é definida em $V(x^*,\delta)$
- $f(x^*) < (\leq)\space f(x)$, $\forall x\in V(x^*,\delta)$; $x\neq x^*$
![[Screenshot 2024-04-15 at 16.29.10.png]]

$$
\begin{cases}
\text{min(max)imizante global } \Rightarrow\text{ min(max)imizante local} \\
\\
\text{min(max)imizante global } + \text{ f convexa (côncava) }\Rightarrow\text{ min(max)imizante local}
\end{cases}
$$

![[Screenshot 2024-04-15 at 16.31.53.png]]
$x^*$ é maximizante **local** forte (fraco) se $\exists\delta > 0$:
- $f(x)$ é definida em $V(x^*,\delta)$
- $f(x^*)> (\geq)\space f(x)\space \forall x\in V(x^*,\delta)$; $x\neq x^*$
![[Screenshot 2024-04-15 at 16.36.07.png]]
---
$x^*$ é minimizante **global** forte (fraco) se $f(x^*) < (\leq)\space f(x)$, para todo o $x$ que pertence ao domínio de $f(x)$ (onde a função é definida);
![[Screenshot 2024-04-15 at 16.37.37.png]]
$x^*$ é maximizante **global** forte (fraco) se $f(x^*) > (\geq)\space f(x)$, para todo o $x$ que pertence ao domínio de $f(x)$ (onde a função é definida);
![[Screenshot 2024-04-15 at 16.38.25.png]]

## Condições de Otimalidade
Assume-se que $f(x)$ é continuamente diferenciável até à 2ª ordem.

**Condição necessária (e suficiente) de 1ª ordem**
Se $x^*$ é uma solução do problema $(2)\space(n=1)$ então
- $f'(x) = 0$

**Condição necessária de 2ª ordem (para ser minimizante)**
Se $x^*$ é uma solução do problema $(2)\space(n=1)$ que satisfaz a condição de 1ª ordem, então
- $f''(x) \geq 0$

## Métodos de Resolução para Problemas Unidimensionais

$$
min_{x\in R} f(x)
$$

- Métodos de procura (ou pesquisa) direta (que não usam derivadas)
- Métodos de aproximação
- Métodos mistos

### Método DSC
- É iterativo que só usa informação da função objetivo $f$
- É do tipo misto (tem uma fase de procura e uma fase de aproximação)
- A fase de aproximação usa interpolação quadrática
- É para problemas de otimização unidimensionais

1. **Fase de procura**
	- procura no sentido positivo e/ou sentido negativo
	- constrói, em cada iteração, _3 pontos igualmente distanciados_ que definem um _intervalo_ que contém o minimizante da função
	- compara apenas os valores da função objetivo em diversos pontos
2. **Fase de aproximação**
	- seleciona 3 pontos igualmente distanciados que definem um intervalo que contém o minimizante da função objetivo
	- aproxima a função nesse _intervalo_ por uma **quadrática** e usa o seu minimizante como aproximação ao minimizante da função
3. **Critério de paragem**
	- é baseado na distância entre os pontos que foram usados na aproximação quadrática
	- se o CP for verificado então o minimizante da quadrática é a melhor aproximação à solução
---
**Em qualquer iteração**:
a procura começa com uma aproximação inicial à solução, designada $x_1$, e uma perturbação $\delta > 0$.

A partir do $x_1$ e no _sentido positivo_, calcula-se uma sequência de pontos $x_2$,$x_3$,$x_4$,… distanciados, respetivamente, de $\delta$,$2\delta$,$4\delta$,$8\delta$,…

$$
\begin{cases}
x_1\\
x_2 = x_1+\delta \\
x_3 = x_2+2\delta \\
\cdots \\
x_k = x_{k-1}+2^{k-2}\delta \\
\end{cases}
$$

até que no ponto $x_k$ se tenha $f(x_k) > f(x_{k-1})$.
![[Screenshot 2024-04-15 at 17.01.01.png]]

Calcula-se o ponto médio do último intervalo:

$$
x_m = \frac{x_k+x_{k-1}}{2}
$$

e fica-se com 4 pontos igualmente espaçados

$$
x_{k-1}<x_{k-1}<x_m<x_k
$$

Para a aproximação quadrática, é necessário seleccionar três dos quatro pontos. Comparam-se os valores de $f(x)$ nos dois pontos interiores do intervalo:
- Se $f(x_{k−1}) \leq f(x_m)$ então escolhem-se os pontos $x_{k−2}$, $x_{k−1}$ e $x_m$
- Se $f(x_{k−1}) > f(x_m)$ escolhem-se os pontos $x_{k−1}$, $x_m$ e $x_k$
![[Screenshot 2024-04-15 at 17.06.02.png]]

### Fase de Aproximação do Método DSC
O minimizante da quadrática, $x^* (q)$, que passa por estes três pontos determina-se por:

$$
x^*(q)=x_2+\Delta\frac{f(x_1)-f(x_3)}{2(f(x_3)-2f(x_2)+f(x_1))}
$$

com $\Delta = (x_2 - x_1) = (x_3 - x_2)$.

**Critério de paragem:**
verificar se a distância entre os pontos que foram usados para construir a quadrática não excede $\epsilon > 0$ $(\eqsim 0)$:

$$
(x_2 - x_1) = (x_3 - x_2) = \Delta\leq\epsilon
$$

### Paragem do Método DSC
1. Se o critério de paragem _for verificado_, o processo iterativo termina, sendo $x^*(q)$ a melhor aproximação calculada à solução;
2. Se o critério de paragem _não se verificar_, o processo repete-se e o minimizante da quadrática, $x^*(q)$, passa a ser o $x_1$ da nova iteração. A perturbação $\delta$ também deve ser reduzida através de: $\delta = M\delta$, com $M<1$.

## Formulação de um Problema sem Restrições
