$$
S_k = \langle X_1, X_2, ...,X_n,X_n+1\rangle
$$

representa o simplex, da iteração $k$, em que os _vértices já estão ordenados_, por **ordem crescente dos valores da função objetivo** do problema, isto é,

$$
f(X_1)\leq f(X_2)\leq \cdots\leq f(X_n)\leq f(X_{n+1})
$$

sendo
- $X_1$ - o melhor vértice
- $X_n$ - o segundo pior vértice
- $X_{n+1}$ - o _pior vértice_

## Método de Nelder-Mead
Em $R^2$, o simplex é um triângulo
![[Screenshot 2024-04-17 at 16.18.33.png]]

Em cada iteração, definem-se _pontos auxiliares_ candidatos a vértices de um novo simplex - que serão aceites ou rejeitados comparando apenas os seus valores de $f$ com
- $f(X_1)\space\space\space f(X_n)\space\space\space f(X_{n+1})$
Lista dos _pontos auxiliares_:
- vértice refletido;
- vértice expandido;
- vértices contraídos;
- vértices de um simplex escolhido.
---

Seja $S_1$ o simplex inicial já ordenado $(k=1)$

$$
S_1 = \langle X_1, X_2,...,X_{n+1} \rangle
$$

_Em cada iteração_, começa-se por calcular o **centróide** do simplex, que é o ponto médio do hiperplano definido por $X_1,X_2,…,X_n$ ($n$ melhores vértices do simplex)
![[Screenshot 2024-04-17 at 16.24.04.png]]

$$
\overline x = \frac{1}{n}\sum_{i=1}^n X_i
$$

De seguida, calcula-se o vértice refletido (com $\delta = 2$)

$$
x_r = X_{n+1} + \delta(\overline x - X_{n+1})
$$

**Caso 1:**
![[Screenshot 2024-04-17 at 16.25.38.png]]
Se $x_r$ for bom ($f(X_1)\leq f(x_r)< f(X_n)$) aceita-se _$x_r$_ e $S_{k+1} = \langle X_1,X_2,…,X_n,X_r\rangle$ é o simplex para a iteração seguinte.

**Caso 2:**
![[Screenshot 2024-04-17 at 17.42.24.png]]
Se $x_r$ for muito bom ($f(x_r)< f(X_1)$) faz-se uma expansão do simplex:
- cálculo do _vertice expandido_ (com $\delta = 3$)

$$
x_e = X_{n+1} + \delta (\overline x - X_{n+1})
$$

- Se $x_e$ for muito bom ($f(x_e)<f(X_1)$) aceita-se $x_e$ e $S_{k+1} = \langle X_1,X_2,x_e\rangle$
- Senão aceita-se $x_r$ e $S_{k+1} = \langle X_1,X_2,x_r\rangle$

**Caso 3:**
![[Screenshot 2024-04-17 at 17.46.45.png]]
Se $x_r$ for fraco ($f(X_n)\leq f(x_r)< f(X_{n+1})$) faz-se uma contração para o exterior:
- cálculo do _vértice contraído_ para o exterior (com $\delta = 1.5$)

$$
\hat x_c = X_{n+1} + \delta (\overline x - X_{n+1})
$$

- Se $\hat x_c$ for bom ($f(\hat x_c)<f(X_n)$) aceita-se $\hat x_c$ e $S_{k+1}=\langle X_1,X_2,…,X_n,\hat x_c \rangle$
- Senão encolhe-se o simplex

**Caso 4:**
![[Screenshot 2024-04-17 at 17.51.49.png]]
Se $x_r$ for muito fraco ($f(x_r) > f(X_{n+1})$) faz-se uma contração para o interior:
- cálculo do _vertice contraído_ para o interior (com $\delta = 0.5$)

$$
x_c = X_{n+1} + \delta (\overline x - X_{n+1})
$$

- Se $x_c$ for bom ($f(x_c)<f(X_n)$) aceita-se $x_c$ e $S_{k+1} = \langle X_1,X_2,…,X_n,x_c\rangle$
- Senão encolhe-se o simplex

### Escolher o Simplex
Consiste em substituir cada um dos vértices $X_i, \space i=2,…,n+1$ pelo ponto médio do segmento que une esse $X_i$ a $X_1$

$$
x_i = \frac{X_i + X_1}{2}
$$

e $S_{k+1}=\langle X_1,x_2,…,x_n,x_{n+1}\rangle$.
![[Screenshot 2024-04-25 at 14.54.09.png]]

### Critério de Paragem
**Nota:** Calculado o simplex para a iteração seguinte, é necessário _ordenar_ o simplex para verificar o critério de paragem.

Consiste em verificar se o tamanho relativo do simplex já é inferior ou igual a uma quantidade pequena, $\epsilon > 0(\eqsim 0)$:
- _se_

$$
\frac{\underset{2\leq i\leq n+1}{max} || X_i - X_1 ||_2}{max \lbrace 1, ||X_1||_2\rbrace} \leq \epsilon
$$

- _então_ o processo iterativo termina (o vértice do simplex com menor valor da função objetivo, $X_1$, é considerado como **a melhor aproximação** calculada à solução)
- _senão_, o processo iterativo continua.
