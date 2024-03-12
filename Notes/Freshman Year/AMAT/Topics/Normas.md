## Norma

Uma norma em $\mathbb{R}^n$ é uma aplicação de $\mathbb{R}^n$ em $\mathbb{R}$ que a cada ${x}\in\mathbb{R}^n$ faz corresponder um número real $\|{x}\|$, verificando as seguintes propriedades:

- $\|{x}\| \geq 0, \forall{x}\in\mathbb{R}^n \text{ e } \|{x}\|=0\text{ sse } {x} = 0$
- $\|\alpha{x}\|= |\alpha|\|{x}\|, \forall{x},{y}\in\mathbb{R}^n,\forall\alpha\in\mathbb{R}$
- $\|{x+y}\|\leq \|{x}\|+\|{y}\|, \forall{x},{y}\in\mathbb{R}^n$

O espaço vetorial $\mathbb{R}^n$ munido com uma norma $\|\cdot\|$ diz-se um **espaço normado** e representa-se por $(\mathbb{R}^n,\|\cdot\|)$.

## Produto Interno Euclidiano

Dados ${x}=(x_1,…x_n)$ e ${y}=(y_1,…y_n)$ em $\mathbb{R}^n$, definimos o produto interno euclidiano de **x** e **y** por

$$
<x,y>= x_1y_1 +...+x_ny_n	
$$

- **x** e **y** são ortogonais quando $<x,y> = 0$

## Norma Euclidiana

Dados ${x}=(x_1,…x_n)$ em $\mathbb{R}^n$, definimos a norma euclidiana de x por

$$
\| x \| = \sqrt{<x,x>} = \sqrt{(x_1)^2+...+(x_n)^2}
$$

Se $x, y \in \mathbb{R}^n \setminus \{0\}$, definimos o ângulo $Θ$ entre x e y, e tem-se

$$
<x,y> = \|x\|\|y\|\cos\theta
$$

### Calcular $\cos\theta$:

$$
\begin{align*}
<x,y>&= \|x\|*\|y\|*\cos\theta\\
\frac{<x,y>}{\|x\|*\|y\|}&=\cos\theta
\end{align*}
$$

## Distância Euclidiana

Dados ${x}=(x_1,…x_n)$ e ${y}=(y_1,…y_n)$ em $\mathbb{R}^n$, definimos a distância euclidiana de **x** e **y** por

$$
d(x,y) = \|x-y\|\\
d(x,y) = \sqrt{<x-y,x-y>}\\
d(x,y) = \sqrt{(x_1 - y_1)^2+...+(x_n-y_n)^2}
$$

- Se $d(x,y)= 0$ se e só se $x = y$

## Bola Aberta e Bola Fechada

Sejam ${a}\in\mathbb{R}^n$ e $r\in\mathbb{R}^+$. Chama-se _bola aberta_ de centro ${a}$ e raio $r$ ao conjunto

$$
B({a},r) = \{{x}\in\mathbb{R}^n:\|{x-a}\|<r\}
$$

e _bola fechada_ de centro ${a}$ e raio $r$ ao conjunto

$$
\overline{B}({a},r) = \{{x}\in\mathbb{R}^n:\|{x-a}\|\leq r\}
$$

Bola fechada segundo as normas euclidiana, infinito e um, respetivamente.
![[Untitled.png]]

## Conjunto Limitado

Um conjunto $X\subset\mathbb{R}^n$ diz-se **limitado** quando existirem ${a}\in\mathbb{R}^n$ e $r\in\mathbb{R}^+$ tais que a bola aberta $B({a},r)$ contém $X$, isto é:

$$
\exists a \in \mathbb{R}^n, \exists r > 0: X\subset B({a},r)
$$

Nota que seria equivalente definir conjunto limitado usando a noção de bola fechada em vez de bola aberta.

## Conjunto Aberto

Sejam $A\subset\mathbb{R}^n$ um conjunto e ${x}\in\mathbb{R}^n$ um ponto. Dizemos que ${x}$ é _ponto interior_ de $A$ quando

$$
\exists r > 0: B({x},r)\subset A
$$

Em termos intuitivos, significa que ${x}$ é ponto interior de $A$ quando nas _proximidades_ de ${x}$, apenas existem pontos de $A$.

Designamos por _interior de_ $A$ o conjunto $int\space A$ constituído pela totalidade dos pontos que são interiores a $A$. É imediato que $int\space A\subset A$.

Assim, um conjunto diz-se **aberto** quando $int\space A = A$

## Pontos de Acumulação

Sejam $A\subset\mathbb{R}^n$ e ${x}\in\mathbb{R}^n$. Dizemos que ${x}$ é **ponto de acumulação** do conjunto $A$ quando

$$
\forall r > 0, \Big( B({x},r)\setminus\{{x}\}\Big)\space\cap\space A \neq\varnothing
$$

Em termos intuitivos, significa que ${x}$ é ponto de acumulação quando _na sua proximidade_ existem pontos de $A$ distintos do próprio ${x}$.

## Ponto Isolado

Um ponto ${y}\in A$ diz-se um **ponto isolado** de $A$ quando ${y}$ não é ponto de acumulação do mesmo, ou seja, quando

$$
\exists r > 0: B({y},r)\space\cap\space A\neq\varnothing
$$
