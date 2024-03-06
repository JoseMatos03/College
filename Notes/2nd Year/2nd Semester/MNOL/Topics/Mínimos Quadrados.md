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

## Dedução do Sistema de Equações Normais

### Matriz dos Coeficientes do Sistema das Equações Normais

### Sistema das equações normais

#### Passos para calcular o modelo linear não polinomial
