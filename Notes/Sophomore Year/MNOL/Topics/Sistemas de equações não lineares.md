## Reformulação do Método de Newton para uma Equação não Linear
Para resolver $f(x) = 0, f:\mathbb R \rightarrow \mathbb R$, a equação iterativa do [[Equações não lineares#Método De Newton|método de Newton]] pode ser colocada na forma:

$$
x_{k+1} = x_k + \Delta x_k,\space k=1,2,...
$$

com

$$
\begin{array}{ll}
	\Delta x_k & = - \frac{1}{f'(x_k)}f(x_k) \\
			   & = -(f'(x_k))^{-1}f(x_k) 
\end{array}
$$

**Generalização:** problema com mais que uma equação não linear e mais que uma variável $\longrightarrow$ sistema de equações não lineares.

## Sistemas de Equações não Lineares
**Forma geral** do problema:

$$
f(x)=0,\space f:\mathbb R^n\rightarrow\mathbb R^n\Leftrightarrow
\begin{cases}
\begin{aligned}
  f_1(x_1,x_2,\dots,x_n) = 0 \\
  f_2(x_1,x_2,\dots,x_n) = 0 \\
  \dotsb \\
  f_n(x_1,x_2,\dots,x_n) = 0 \\
\end{aligned}
\end{cases}
$$

$$
f=\begin{pmatrix}
	f_1\\
	f_2\\
	\vdots\\
	f_n
\end{pmatrix}
\text{ e }
x=\begin{pmatrix}
	x_1\\
	x_2\\
	\vdots\\
	x_n
\end{pmatrix}
$$

### Método Iterativo de Newton
Um dos métodos para resolver este sistema de $n$ equações não lineares nas $n$ variáveis é o **método iterativo de Newton** - extensão do método de Newton para 1 equação.

$$
x^{(k+1)}=x^{(k)}+\Delta x^{(k)},\space k=1,2,\dots
$$

com

$$
\Delta x^{(k)} = -\Big(J(x^{(k)})\Big)^{-1}f(x^{(k)})
$$

tal que $\Big(J(x^{(k)})\Big)^{-1}$ - inversa da matriz do **Jacobiano** das funções

$$
\text{em que }
\begin{cases} 
x\in\mathbb R^n\\
\Delta x\in\mathbb R^n \\
f\in\mathbb R^n\\
J(x)\in\mathbb R^{n*n}
\end{cases}
$$

### Matriz do Jacobiano
A matriz do Jacobiano contém as _primeiras derivadas parciais_ das funções $f_1,f_2,…,f_n$ em ordem às variáveis $x_1,x_2,…,x_n$.

$$
J(x)=
\begin{pmatrix}
	\frac{∂f_1}{∂x_1} & \frac{∂f_1}{∂x_2} & \cdots & \frac{∂f_1}{∂x_n} \\
	\frac{∂f_2}{∂x_1} & \frac{∂f_2}{∂x_2} & \cdots & \frac{∂f_2}{∂x_n} \\
	\vdots & \vdots & \ddots & \vdots \\
	\frac{∂f_n}{∂x_1} & \frac{∂f_n}{∂x_2} & \cdots & \frac{∂f_n}{∂x_n} \\
\end{pmatrix}
$$

### Implementação da Equação Iterativa
A equação (1):

$$
\begin{array}{cc}
\Delta x^{(k)}=-\Big(J(x^{(k)})\Big)^{-1}f(x^{(k)})\space\space\space\text{ (1)} \\
\Updownarrow \\
J(x^{(k)})\Delta x^{(k)}=-f(x^{(k)})\space\space\space\space\space\space\space\space\space\space\space\space\text{ (2)}
\end{array}
$$

isto é,
- o vetor $\Delta x^{(k)}$ (em cada iteração) é a **solução do sistema linear** (2) e
- é obtido pelo método [[Sistemas de equações lineares#Método Direto de Eliminação de Gauss com Pivotagem Parcial (EGPP)|eliminação de Gauss com Pivotagem Parcial (EGPP)]].

### Critério de Paragem
- estimativa do [[Erros#Erro Relativo|erro relativo]] da aproximação

$$
\frac{||\Delta x^{(k)}||_2}{||x^{(k+1)}||_2}\leq\varepsilon_1
$$

- aproximação ao zero de $f(x)$

$$
||f(x^{(k+1)})||_2\leq\varepsilon_2
$$

$\varepsilon_1\text{ e }\varepsilon_2$ quantidades positivas e próximas de zero; $||\cdot||_2$ é a norma 2.

## Algoritmo do Método de Newton para Sistemas de Equações não Lineares
1. Fornecer $x^{(1)}$;
2. Fazer $k=1$;
3. Resolver o sistema linear abaixo por [[Sistemas de equações lineares#Método Direto de Eliminação de Gauss com Pivotagem Parcial (EGPP)|EGPP]] para calcular o vetor $\Delta x^{(k)}$;

$$
J(x^{(k)})\Delta x^{(k)}=-f(x^{(k)})
$$

1. Calcular $x^{(k+1)}=x^{(k)}+\Delta x^{(k)}$;
2. Se o critério de paragem é verificado

$$
\begin{array}{ll}
\text{então}
\begin{cases}
\text{terminar com} \\
x^*\leftarrow x^{(k+1)} \\
f(x^*)\leftarrow f(x^{(k+1)})
\end{cases}
\\
\text{senão}
\begin{cases}
\text{fazer } k=k+1 \\
\text{voltar para o passo 3.}
\end{cases}
\end{array}
$$

### Condições de [[Equações não lineares#Método De Newton#Condições De Convergência|Convergência do Método de Newton]]
Para resolver o sistema:

$$
\begin{cases}
\begin{aligned}
f_1(x_1,x_2,\dots,x_n)=0\\
f_2(x_1,x_2,\dots,x_n)=0\\
\cdots\\
f_n(x_1,x_2,\dots,x_n)=0\\
\end{aligned}
\end{cases}
$$

em que $f=(f_1,f_2,…,f_n)^T$ e $x=(x_1,x_2,…,x_n)^T$,
- $x^*$ é tal que $f(x^*)=0$;
- $f$ é um vetor de funções continuamente diferenciáveis;
- matriz $J(x^*)$ é não singular $(\exists(J(x^*))^{-1})$ e $(J(x^*))^{-1}$ é limitada ($||(J(x^*))^{-1}||\leq\beta,\space\beta>0$);
- $J(x)$ matriz _Lipschitz_ contínua na vizinhança de $x^*$;
- $x^{(1)}$ (aproximação inicial) na vizinhança de $x^*$ - convergência local, $\Rightarrow$ o método iterativo de Newton converge e

$$
\lim_{k \rightarrow \infty} \frac{||x^*-x^{(k+1)}||}{||x^*-x^{(k)}||} = L\space\space\space\space(L> 0, p=2)
$$

(convergência quadrática)
