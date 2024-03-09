## Objetivo
Definir um **modelo** $M(x;c_i)$ - expressão matemática - que melhor se ajuste à função dada, $f(x)$, no intervalo $[a,b]$.
Usando a técnica dos [[Mínimos Quadrados|mínimos quadrados]], pretende-se _minimizar a soma dos quadrados dos erros_.

- **Problema discreto:**
	Dados os $m$ pontos $x_1<x_2<…<x_m$ no intervalo $[a,b]$:
	minimizar $\sum^{m}_{j=1}(f(x_j)-M(x_j;c_i))^2$
	![[Screenshot 2024-03-05 at 23.22.18.png]]
- **Problema contínuo:**
	Dada $f(x)$:
	minimizar $\intop_{a}^{b}(f(x)-M(x;c_i))^2dx$
	![[Screenshot 2024-03-05 at 23.24.06.png]]

### Tipos de Modelos
- Modelo **linear e polinomial**: define um problema de mínimos quadrados linear
	Exemplo: $M(x;a_0,a_1,a_2)\equiv p_2(x) = a_0+a_1 x+a_2 x^2$
- Modelo **linear e não polinomial**: define um problema de mínimos quadrados linear
	Exemplo: $M(x;c_1,c_2)=c_1 e^{x^2}+c_2\sin (x)$
- Modelo **não linear**: define um problema de mínimos quadrados não linear
	Exemplo: $M(x;c_1,c_2)=\ln(c_1 x^2)+ e^{c_2 x}$

## Modelo Linear e Polinomial
**Objetivo:**
	definir polinómio de grau $n$ (_completo_) $p_n(x)$;
**Condição única para que o problema seja bem definido:**
	$m\geq n+1$, sendo $m$ o número de pontos onde a função é definida e $n$ o grau do polinómio;

Para que o problema seja bem condicionado, isto é, não seja sensível a erros nos dados ou erros de arredondamento nos cálculos, o polinómio $p_n(x)$ deve ser construído, usando _sequência de polinómios ortogonais_

$$
P_0(x),P_1(x),P_2(x),...,P_n(x),
$$

na forma

$$
p_n(x)=c_0P_0(x)+c_1P_1(x)+c_2P_2(x)+\cdots+c_nP_n(x)
$$

**Propriedade dos polinómios ortogonais:**

$$
\sum_{i=1}^{m}P_j(x_i)P_k(x_i)
\begin{cases}
= 0,\text{ se } j \neq k \\
\neq 0,\text{ se } j = k
\end{cases}
$$

Como se constrói o polinómio $p_n(x)$ (_completo_)?
	a partir dos pontos dados $(x_j,f_j),j=1,2,…,m$
	determinam-se $P_0(x),…,P_n(x)$ e $c_0,…,c_n$ para formar

$$
p_n(x)=c_0P_0(x)+c_1P_1(x)+c_2P_2(x)+\cdots+c_nP_n(x)
$$

### Construção do Polinómio $p_n(x)$
1. Construir os polinómios ortogonais da sequência de polinómios ortogonais $P_0(x), P_1(x), P_2(x),…,P_n(x)$ usando a **relação de recorrência**

$$
P_{i+1}(x)=(x-B_i)P_i(x)-\mathbb C_iP_{i-1}(x),\space\text{ para } i=0,1,...,n-1
$$

em que $P_{-1}(x)= 0$ e $P_0(x)=1$,

$$
B_i=\frac{\sum_{j=1}^{m}x_jP_i^2(x_j)}{\sum_{j=1}^{m}P_i^2(x_j)},\text{ para todo o }i
$$

$$
\mathbb C_0=0\text{ e }
\mathbb C_i=\frac{\sum_{j=1}^{m}P_i^2(x_j)}{\sum_{j=1}^{m}P_{i-1}^2(x_j)},\text{ para }i>0
$$

2. Calcular os coeficientes do polinómio

$$
c_0, c_1,c_2,...,c_n
$$

sendo

$$
c_i=\frac{\sum_{j=1}^{m}f_jP_i(x_j)}{\sum_{j=1}^{m}P_i^2(x_j)},\space i =0,1,...,n
$$

3. Formar o polinómio pretendido:

$$
p_n(x)=c_0P_0(x)+c_1P_1(x)+c_2P_2(x)+\cdots+c_nP_n(x)
$$

## Modelo Linear mas não Polinomial
**Forma do modelo:**

$$
M(x;c_1,...,c_n)=c_1\phi_1(x)+c_2\phi_2(x)+\cdots+c_n\phi_n(x)
$$

(_linear nos coeficientes_) em que

$$
c_1,c_2,...,c_n
$$

são os **coeficientes** do modelo e

$$
\phi_1(x),\phi_2(x),...,\phi_n(x)
$$

são funções.

Neste modelo só é preciso determinar os coeficientes, pois as funções $\phi_i(x),i=1,…,n$ são dadas.
O número de termos na definição do modelo caracteriza a dimensão do problema - $n$ - este é também o número de coeficientes a determinar:

**Condição única para que o problema seja bem definido:**

$$
m\geq n
$$

sendo $m$ o _número de pontos_ onde a função é definida e $n$ o número de coeficientes a determinar;
O cálculo dos coeficientes

$$
c_1,c_2,...,c_n
$$

é feito a partir do **sistema de equações normais**.

### Dedução do Sistema de Equações Normais

$$
M(x;c_1,...,c_n)=c_1\phi_1(x)+c_2\phi_2(x)+\cdots+c_n\phi_n(x)
$$

No sentido dos mínimos quadrados, o **objetivo** é encontrar o modelo $M(x;c_1,…,c_n)$ tal que

$$
\underset{c_1,...,c_n}{\text{minimizar}}\space\space S(c_1,c_2,...,c_n)\equiv\sum_{j=1}^{m}(f_j-M(x_j;c_1,...,c_n))^2
$$

$$
\underset{c_1,...,c_n}{\text{minimizar}}\space\space \sum_{j=1}^{m}(f_j-(c_1\phi_1(x_j)+x_2\phi_2(x_j)+\cdots+c_n\phi_n(x_j)))^2
$$

## Matriz dos Coeficientes do Sistema das Equações Normais

$$
A=
\begin{pmatrix}
\begin{aligned}
	\sum_{j=1}^{m}\phi_1^2(x_j) && \sum_{j=1}^{m}\phi_2(x_j)\phi_1(x_j) && \cdots && \sum_{j=1}^{m}\phi_n(x_j)\phi_1(x_j) \\
	\sum_{j=1}^{m}\phi_1(x_j)\phi_2(x_j) && \sum_{j=1}^{m}\phi_2^2(x_j) && \cdots && \sum_{j=1}^{m}\phi_n(x_j)\phi_2(x_j) \\
	\cdots && \cdots && \ddots && \cdots \\
	\sum_{j=1}^{m}\phi_1(x_j)\phi_n(x_j) && \sum_{j=1}^{m}\phi_2(x_j)\phi_n(x_j) && \cdots && \sum_{j=1}^{m}\phi_n^2(x_j)
\end{aligned}
\end{pmatrix}
$$

### Sistema das Equações Normais

$$
A=\begin{pmatrix}
	c_1\\c_2\\\cdots\\c_n
\end{pmatrix}
=
\begin{pmatrix}
	\sum_{j=1}^{m}f_j\phi_1(x_j)\\
	\sum_{j=1}^{m}f_j\phi_2(x_j)\\
	\cdots\\
	\sum_{j=1}^{m}f_j\phi_n(x_j)\\
\end{pmatrix}
$$

A resolução do sistema linear das equações normais fornece os coeficientes pretendidos $c_1,c_2,…,c_n$ e deve ser feita por um método direto e estável - [[Sistemas de equações lineares#Método Direto de Eliminação de Gauss com Pivotagem Parcial (EGPP)|EGPP]]

#### Passos para Calcular o Modelo Linear não Polinomial
Para calcular o modelo na forma:

$$
M(x;c_1,...,c_n)=c_1\phi_1(x)+c_2\phi_2(x)+\cdots+c_n\phi_n(x)
$$

1. Identificar:
	- $n$ (número de termos/número de coeficientes a determinar/dimensão do problema)
	- $\phi_1=\cdots,\phi_2=\cdots,\cdots,\phi_n=\cdots$
2. Formar o [[Mínimos Quadrados#Sistema das Equações Normais|sistema de equações normais]] - de $n$ equações nas $n$ incógnitas $c_1,c_2,…,c_n$ - na forma matricial;

$$
\begin{pmatrix}
\begin{aligned}
	\cdots && \cdots && \cdots && \cdots \\
	\cdots && \cdots && \cdots && \cdots \\
	\cdots && \cdots && \cdots && \cdots \\
	\cdots && \cdots && \cdots && \cdots
\end{aligned}
\end{pmatrix}
\begin{pmatrix}
\begin{aligned}
	c_1 \\
	c_2 \\
	\cdots \\
	c_n
\end{aligned}
\end{pmatrix}
=
\begin{pmatrix}
\begin{aligned}
	\cdots \\
	\cdots \\
	\cdots \\
	\cdots
\end{aligned}
\end{pmatrix}
$$

4. Resolver este sistema por EGPP;
5. Formar o modelo pretendido.

$$
M(x;c_1,...,c_n)=c_1\phi_1(x)+c_2\phi_2(x)+\cdots+c_n\phi_n(x)
$$
