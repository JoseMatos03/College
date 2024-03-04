Usando um número limitado e finito de dígitos na representação de $x$, então o número usado nos cálculos x obtém-se
- por **arredondamento** e é o que está mais **próximo** de $x$:
	 exemplo: se $x = sqrt(2) = 1.414213562…$
		se usarmos **7** casas decimais nos cálculos $=> x = 1.4142136$
		se usarmos **5** casas decimais nos cálculos $=> x = 1.41421$
- O **erro de arredondamento** é a diferença $x -$ x.
- Conseguimos definir um **limite superior** do erro (absoluto) cometido

## Medir Os Erros
### Erro Absoluto
Seja $x$ o valor aproximado que é usado nos cálculos e $\overline{x}$ o valor exato,

$$
\text{erro absoluto}=\overline{x}-x
$$

que pode ser $> 0, < 0\text{ ou }=0$.
O **limite superior do erro absoluto** é a quantidade $\left(\ge0\right)\delta_{x}$ tal que

### Erro Relativo
Um certo erro absoluto pode ser considerado pequeno numas situações e grande noutras. **Esta classificação depende do valor de $\overline x$**. Uma medida que relaciona o erro absoluto com o valor de $\overline x$ é

$$
\text{erro relativo}=r_x=\frac{|\overline x - x|}{|\overline x|}
$$

Se $\delta_{x}$ for pequeno quando comparado com $\overline x$ então

$$
r_x\approx\frac{|\overline x - x|}{|x|}\le\frac{\delta_x}{|x|}\text{ limite superior do erro relativo}
$$

À quantidade $100r_x$% dá-se o nome de **percentagem do erro**.

## Erros De Truncatura
Cometemos erros de truncatura quando usamos
- métodos iterativos
- métodos de discretização
Um **método iterativo** é definido por uma equação iterativa

$$
x_{k+1}=F(x_k)
$$

a partir da qual geramos uma sucessão de _aproximações_ à solução exata do problema, $x^*$
- $k$ indica o índice da iteração;
- $x_k$ representa a _aproximação_ à solução na iteração $k$.

Dada uma _aproximação inicial_ $x_1$, a equação iterativa gera as aproximações

$$
x_1\curvearrowright x_2\curvearrowright x_3\curvearrowright ...\curvearrowright x_n\curvearrowright x_{n+1}
$$

e se o processo iterativo convergir, esta sucessão converge para $x^*$.

O **erro de truncatura** é a diferença $x^*-x_{n+1}$.
