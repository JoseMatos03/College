## Interpolação Segmentada (_piecewise_)
O **_spline_** é uma função segmentada e é formada por vários polinómios ligados uns aos outros de uma maneira **contínua e suave**, isto é, existe continuidade na _spline_ nos pontos que unem as partes.
![[Screenshot 2024-03-13 at 13.44.49.png]]

Os pontos $x_1,x_2,x_3,…,x_{n-1}$ chamam-se **nós interiores** e $x_0$ e $x_n$ são os **nós exteriores** ou **fronteiras**.

Uma função $s_I(x)$ (com $I$ inteiro não negativo) chama-se _spline_ de grau $I$ se possuir as seguintes propriedades:
- $s_I$ é uma função continuamente diferenciável até à ordem $I-1$;
- $s_I$ é um polinómio de grau $I$ para

$$
x \in [x_i, x_{i+1}], \space 0 \leq i \leq n-1
$$

**Porquê usar splines?**

```functionplot
---
title: 
xLabel: x
yLabel: y
bounds: [-2,2,-2,2]
disableZoom: true
grid: false
---
y=sin(x)
y=x^5-x^4+x^3+2x^2-2x
```

Linha azul representa a função que queremos aproximar.
Linha vermelha representa um [[Interpolação Polinomial|polinómio interpolador]].

```functionplot
---
title: 
xLabel: x
yLabel: y
bounds: [-2,2,-2,2]
disableZoom: true
grid: false
---
y=sin(x)
y=sin(x)-0.02
```

Linha azul representa a função que queremos aproximar.
Linha vermelha representa uma [[#Spline Linear|spline linear]].

### Spline Linear
- Junção de polinómios de grau 1.
- Para cada segmento $i$, a forma do polinómio de grau 1 obtém-se:

$$
s_1^i(x) = f_{i-1} + \frac{f_i - f_{i-1}}{x_i - x_{i-1}} (x - x_{i-1})
$$

$i=1,2,…,n$

- O segmento $i$ é definido por $[x_{i-1}, x_i]$

#### Limite Superior do Erro de Truncatura com a Aproximação _spline_ Linear $s_1$

### Spline Cúbica $s_3(x)$
$s_3^i(x)$ depende de $M_{i-1}$ e $M_i$
	- quando $i = 1$ (1º segmento), precisamos de $M_0$ e $M_1$
	- $i=2$, precisamos de $M_1$ e $M_2$
	- $i=3$, precisamos de $M_2$ e $M_3$
	- $\cdots$
	- $i=n$, precisamos de $M_{n-1}$ e $M_n$
é preciso conhecer _a priori_ as $n + 1$ incógnitas:

$$
M_0, M_1, M_2,...,M_{n-1},M_n
$$

### Spline Cúbica Natural
Os polinómios do 1º segmento e do $n^{\text{esimo}}$ (último) segmento devem ter curvatura nula nos nós da fronteira $(x_0,x_n)$, ou seja,

$$
\begin{cases}
\begin{aligned}
s_3^{1''}(x_0)=0\\
s_3^{n''}(x_n)=0
\end{aligned}
\end{cases}
\Leftrightarrow
\begin{cases}
\begin{aligned}
M_0=0 \\
M_n=0
\end{aligned}
\end{cases}
$$

Falta calcular $M_1,M_2,…,M_{n-1}$ ($n-1$ incógnitas) através de $n-1$ equações, **para cada nó interior $i$**, $i = 1,2,…,n-1$:

$$
\begin{array}
(x_i-x_{i-1})M_{i-1}+2(x_{i+1}-x_{i-1})M_i+(x_{i+1}-x_i)M_{i+1}=\\ \\
\frac{6}{x_{i+1}-x_i}(f_{i+1}-f_i)-\frac{6}{x_i-x_{i-1}}(f_i-f_{i-1})
\end{array}
$$

Estas $n-1$ equações nas $n-1$ incógnitas $M_1,M_2,…,M_{n-1}$ definem um sistema linear tridiagonal a resolver por [[Sistemas de Equações Lineares#Método Direto de Eliminação de Gauss com Pivotagem Parcial (EGPP)|EGPP]].

### Spline Cúbica Completa
Tem $n+1$ incógnitas para determinar: $M_0,M_1,M_2,…,M_n$, por isso precisa de $n+1$ equações.
As equações (1) para os **nós interiores** são $n-1$
As duas equações restantes $(n-1+2=n+1)$ dizem respeito aos **nós de fronteira ($x_0$ e $x_n$)**:

$$
2(x_1-x_0)M_0+(x_1-x_0)M_1=\frac{6}{x_1-x_0}(f_1-f_0)-6f_0'
$$

$$
2(x_n-x_{n-1})M_n+(x_n-x_{n-1})M_{n-1}=6f_n'-\frac{6}{x_n-x_{n-1}}(f_n-f_{n-1})
$$

Se não se conhecer a expressão de $f(x)$, para calcular $f'(x)\begin{cases}f_0'\\f_n'\end{cases}$ usam-se [[Interpolação Polinomial#Diferenças Divididas (dd)|diferenças divididas]] de 1ª ordem para aproximar as primeiras derivadas:

$$
f_0'=\frac{f_A-f_0}{A-x_0}\text{ e }f_n'=\frac{f_n-f_B}{x_n-B}
$$

com $x_0<A$ e $B<x_n$.
- Quanto mais próximo $A$ estiver de $x_0$, melhor é a aproximação à derivada.
- Quanto mais próximo $B$ estiver de $x_n$, melhor é a aproximação à derivada.

Neste caso, os pontos para construir a _spline_:
![[Screenshot 2024-03-13 at 18.35.50.png]]

#### Limite Superior do Erro de Truncatura com a Aproximação _spline_ Cúbica $s_3$
Seja $f(x)$ contínua, com derivadas contínuas até à quarta ordem, em $[a,b]$, sejam os pontos do intervalo $[a,b]$:

$$
a=x_0<x_1<x_2<\cdots<x_{n-1}<x_n=b
$$

Seja $s_3(x)$ a _spline_ cúbica completa composta pelos polinómios de grau 3, $s_3^i(x), i=1,2,…,n$ ($n$segmentos) para aproximar $f(x)$ em $[a,b]$.
Seja

$$
\underset{\varepsilon\in[a,b]}{\text{max}}|f^{iv}(\varepsilon)|\leq M_4
$$

Seja

$$
h=\underset{0\leq i\leq n-1}{\text{max}}(x_{i+1}-x_i)
$$

então

$$
|f(x)-s_3(x)|\leq\frac{5}{384}h^4M_4
$$

e

$$
|f(x)-s_3'(x)|\leq\frac{1}{24}h^3M_4
$$
