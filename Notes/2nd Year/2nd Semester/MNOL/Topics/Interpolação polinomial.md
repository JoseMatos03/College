## Objetivo da Aproximação de Funções
**Objetivo:** dada a função $f(x)$, encontrar uma aproximação (por exemplo, um polinómio) com o menor erro possível.
1. Dado um conjunto discreto de valores

$$
(x_i,f_i), \space i=0,1,...,n \space (n+1\text{ pontos})
$$

pretende-se encontrar uma _relação funcional_ (expressão) entre as variáveis $x$ e $f$ para prever o comportamento entre as variáveis e poder estimar valores,
- $x$ é variável independente,
- $f$ é variável dependente.
2. Dada uma função complicada (expressão) $f(x)$, pretende-se conhecer uma expressão mais simples que descreva o melhor possível comportamento de $f$ como função de $x$.

## Erro da Aproximação $e(x)=f(x)-p_n(x)$
**Teorema de Weirstrass:** Dadas a função $f(x)$, contínua num intervalo $[a,b]$, e uma quantidade $\varepsilon > 0$, existe sempre um polinómio $p_n(x)$, de grau $\leq n$, tal que o **erro** da aproximação $||f(x)-p_n(x)||<\varepsilon$.
1. Podemos assegurar que o erro seja igual a zero para um conjunto de $n+1$ pontos selecionados do intervalo $[a,b]$, isto é, o polinómio passa por esses $n+1$ pontos da função,

$$
f_i \equiv f(x_i) = p_n(x_i), \text{ para } i=0,1,...,n
$$

- _interpolação polinomial_ (polinómio de colocação) - é único e é de grau $\leq n$.
- _interpolação segmentada (ou spline)_
2. Podemos assegurar que a soma dos quadrados dos erros seja mínima no intervalo $[a,b]$.
![[Screenshot 2024-03-05 at 20.43.45.png]]![[Screenshot 2024-03-05 at 20.44.15.png]]
[[Mínimos Quadrados|Mínimos quadrados:]]
![[Screenshot 2024-03-05 at 20.45.07.png]]

### Qual o Método Mais Adequado?
Se os dados são precisos, isto é, não contêm [[Erros|erros de observação]], é mais vantajoso usar uma função que passe pelos pontos dados:
- interpolação polinomial - _polinómio de colocação_;
- _spline_.
Se os dados possuem erros de observação, é mais conveniente encontrar uma função que descreva o comportamento dos dados, sem ter a preocupação de passar a curva pelos pontos:
- aproximação dos _mínimos quadrados_.

### Polinómio de Colocação Baseado nas Diferenças Divididas
**Tabela das diferenças divididas** da função dada $f$:

$$
\begin{array}{ll}
x_0 && f_0 \\
    &&     && [x_0,x_1] \\
x_1 && f_1 &&           && [x_0,x_1,x_2] \\
    &&     && [x_1,x_2] &&               && [x_0,x_1,x_2,x_3] \\
x_2 && f_2 &&           && [x_1,x_2,x_3] &&                   && \cdots \\
    &&     && [x_2,x_3] &&               && [x_1,x_2,x_3,x_4] \\
x_3 && f_3 &&           &&    \cdots     &&                   && \cdots \\
\vdots && \vdots && \cdots && && \cdots \\
x_{n-1} && f_{n-1} &&           && [x_{n-2},x_{n-1},x_n] \\
    &&     && [x_{n-1},x_n] \\
x_n && f_n \\
\end{array}
$$

### Diferenças Divididas (dd)
- dd de 1ª ordem (dd1)

$$
\begin{array}{ll}
[x_0,x_1]=\frac{f_0-f_1}{x_0-x_1}=\frac{f_1-f_0}{x_1-x_0} \\
\\
[x_1,x_2]=\frac{f_1-f_2}{x_1-x_2}=\frac{f_2-f_1}{x_2-x_1} \\
\\
\cdots
\end{array}
$$

- dd de 2ª ordem (dd2)

$$
[x_0,x_1,x_2] = \frac{[x_0,x_1]-[x_1,x_2]}{x_0-x_2} = \frac{[x_1-x_2]-[x_0-x_1]}{x_2-x_0}
$$

…
### Propriedades das Diferenças Divididas
1. Podem ser calculadas para **qualquer** espaçamento (não constante) entre os pontos $x_0,x_1,…,x_{n-1},x_n$.
2. As diferenças divididas são funções simétricas dos seus argumentos:

$$
\begin{array}{cc}
[x_0,x_1]=[x_1,x_0] \\
[x_0,x_1,x_2]=[x_2,x_1,x_0] \\
\cdots
\end{array}
$$

3. As diferenças divididas de ordem $n$, de uma função que é um polinómio de grau $n$, são iguais entre si e diferentes de zero $\Rightarrow$ as de ordem $n+1$ são nulas.

## Polinómio Interpolador de Newton Baseado em Diferenças Divididas
Sejam os $(n+1)$ pontos:

$$
\begin{array}{ll}
x_0 && x_1 && x_2 && x_3 && x_4 && \cdots && x_{n-2} && x_{n-1} && x_n \\
f_0 \equiv f(x_0) && f_1 && f_2 && f_3 && f_4 && \cdots && f_{n-2} && f_{n-1} && f_n
\end{array}
$$

o polinómio de grau $\leq n$:

$$
\begin{array}{rr}
p_n(x) = & f_0 + (x-x_0)[x_0,x_1] + (x-x_0)(x-x_1)[x_0,x_1,x_2] \\
       + & (x-x_0)(x-x_1)[x_0,x_1,x_2] \\
\end{array}
$$

## Interpolação Direta
Para estimar o valor de $f(\overline x)$, para um dado ponto $\overline x$ que não está na tabela:
1. e se selecionar interpolação polinomial - polinómio de colocação - escolher o grau do polinómio $n$
2. $\Rightarrow$ selecionar $n+1$ pontos da tabela.
o polinómio de colocação $p_n(x)$, construído com base nos $n+1$ pontos, é único
3. os pontos devem ser escolhidos de modo a:
	 - garantir, pelo menos um ponto à direita e um à esquerda de $\overline x$,
	 - escolher os restantes pontos da tabela que estejam mais próximos de $\overline x$.

## Erro de Truncatura

$$
R_n(x) = (x-x_0)(x-x_1)\cdots(x-x_{n-1})(x-x_n)\frac{f^{(n+1)}(\varepsilon)}{(n+1)!}
$$

com $\varepsilon \in [a,b]$.
O [[Erros#Erros De Truncatura|erro de truncatura]] cometido com a aproximação, para um certo $x$ do intervalo $[a,b]$, que contém $x_0,x_1,x_2,…,x_{n-1},x_n$ - pontos usados para construir o polinómio de grau $n$ - é estimado:
- **CASO 1:** se $f(x)$ for dada por uma expressão, então

$$
|R_n(x)|\leq|(x-x_0)(x-x_1)\cdots(x-x_{n-1})(x-x_n)|\frac{1}{(n+1)!}M_{n+1}
$$

em que

$$
\Bigg |\Big[f^{(n+1)}(x)\Big]_{[a,b]}\Bigg|\leq M_{n+1}
$$

- **CASO 2:** senão - $f(x)$ é dada por uma tabela de valores $|R_n(x)|\leq |(x-x_0)\cdots (x-x_{n-1})(x-x_n)||(\text{dd de ordem }n+1)||$
em que

$$
\text{(dd de ordem }n+1\text{)}=[x_0,x_1,...,x_{n-1},x_n,x_z]
$$

se só existir uma, ou a maior delas em valor absoluto se existirem mais que uma.
