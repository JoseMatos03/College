Um sistema de equações lineares de ordem $n$ é

$$
\begin{pmatrix}
\begin{aligned}
	a_{11}x_1 + a_{12}x_2 + \dotsb + a_{1n}x_n = b_1 \\
	a_{21}x_1 + a_{22}x_2 + \dotsb + a_{2n}x_n = b_2 \\
	a_{31}x_1 + a_{32}x_2 + \dotsb + a_{3n}x_n = b_3 \\
	\dotsb                                           \\
	a_{n1}x_1 + a_{n2}x_2 + \dotsb + a_{nn}x_n = b_n
\end{aligned}
\end{pmatrix}
$$

ou na forma simplificada

$$
Ax=b
$$

## Métodos de Resolução

$$
Ax=b
$$

### Métodos Diretos
- sistema de pequena ou média dimensão;
- a solução exata é obtida ao fim de um número finito de operações.

### Métodos Iterativos
- para sistemas de grandes dimensões;
- a solução exata é obtida ao fim de um número infinito de operações.

## Método Direto de Eliminação de Gauss com Pivotagem Parcial (EGPP)
1. transformar $Ax=b$ em $Ux=c$ usando as _operações elementares_ - a partir da matriz ampliada $(A|b)$:
	- troca de duas linhas paralelas;
	- multiplicação de uma linha por um escalar $\neq 0$;
	- substituição de uma linha pela que dela se obtém adicionando o produto de outra linha paralela por um escalar.
2. resolver $Ux = c$ por substituição inversa.
