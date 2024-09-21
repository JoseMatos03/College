**Antes**:
- O [[Algoritmo Simplex|algoritmo simplex]] foi implementado usando quadros.

## Representação Matricial
![[Screenshot 2024-03-12 at 11.16.10.png]]

### Determinação de Coordenadas
Sistema de equações do vértice D, e a sua representação matricial após ordenação de colunas:

$$
\begin{array}{ll}
3x_1 + 2x_2 + 1s_1 = 120 \\
1x_1 + 2x_2 + 1s_2 = 80 \\
1x_1 + 1s_3 = 30 \\
1s_1 = 0 \\
1s_2 = 0
\end{array}
\qquad\qquad
\left[
\begin{array}{ccc|cc}
    3 & 2 & 0 & 1 & 0 \\
    1 & 2 & 0 & 0 & 1 \\
    1 & 0 & 1 & 0 & 0 \\
    \hline
    0 & 0 & 0 & 1 & 0 \\
    0 & 0 & 0 & 0 & 1 \\
\end{array}
\right]
*
\begin{bmatrix}
x_1 \\
x_2 \\
s_3 \\
s_1 \\
s_2 \\
\end{bmatrix}
=
\begin{bmatrix}
120 \\
80 \\
30 \\
0 \\
0 \\
\end{bmatrix}
$$

Solução do sistema de equações é única:
$x_D = (x_1,x_2,s_1,s_2,s_3)_D^T = (20,30,0,0,10)^T$

### Caso Geral
Solução do sistema de equações $Bx_B + Nx_N = b$ e $x_N = 0$?

$$
\left[
\begin{array}{c|c}
B & N \\
\hline
0 & I_{n-m}
\end{array}
\right]
*
\left[
\begin{array}{c}
x_B \\
\hline
x_N
\end{array}
\right]
=
\left[
\begin{array}{c}
b \\
\hline
0
\end{array}
\right]
$$

- A solução é $x_B = B^{-1}b$ e $x_N = 0$
- A matrix $B$ deve ter inversa (ser não-singular)
- Vetores de $B$ são linearmente independentes, e formam uma _base_
- Por isso é que a solução se diz uma _solução básica_ (vértice)

### Sistema de Equações e Soluções Básicas
Dada uma qualquer escolha de variáveis básicas, o problema $max z = cx$, suj. a $Ax=b,x\geq 0$ é equivalente a:

$$
\begin{array}{ll}
\text{max }z = c_Bx_B + c_Nx_N \\
\text{suj. a} \qquad Bx_B + Nx_N = b \\
\qquad \qquad x_B,x_N\geq 0
\end{array}
$$

em que o vetor de variáveis $x$ é partido em dois subvetores:
- $x_B\in\mathbb{R}_+^{m * 1}$: subvetor de $x$ com variáveis básicas;
- $x_N\in\mathbb{R}_+^{(n - m) * 1}$: subvetor de $x$ com as variáveis não-básicas.
o vetor de custos $c$ é partido em dois subvetores:
- $c_B\in\mathbb{R}_+^{1 * m}$: subvetor de $c$ com os custos das variáveis não-básicas;
- $c_N\in\mathbb{R}_+^{1 * (n - m)}$: subvetor de $c$ com os custos das variáveis não-básicas.
a matrix $A$ é partida em duas submatrizes:
- $B\in\mathbb{R}^{m * m}$: submatriz de $A$ das variáveis básicas (não-singular);
- $N\in\mathbb{R}^{m * (n - m)}$: submatriz de $A$ das variáveis não-básicas.

Pré-multiplicando o sistema de equações por $B^{-1}$, obtendo-se o seguinte sistema de equações equivalentes:

$$
\begin{array}{rr}
B^{-1}(Bx_B + Nx_N) = B^{-1}b\\
x_B+B^{-1}Nx_N = B^{-1}b \\
x_B = B^{-1}b-B^{-1}Nx_N
\end{array}
$$

Substituindo $x_B$ na função objetivo, obtém-se:

$$
\begin{array}{ll}
z = c_Bx_B + c_Nx_N = \\
\space\space = c_B(B^{-1}b-B^{-1}Nx_N)+c_Nx_N = \\
\space\space = c_BB^{-1}b+(c_N-c_BB^{-1}N)x_N \\
\end{array}
$$

Quando $\overline{x_N}=0$, a solução do sistema de equações é a solução básica $\overline x$:

$$
\overline x = 
\begin{pmatrix}
\overline{x_B}\\
\overline{x_N}
\end{pmatrix}
=
\begin{pmatrix}
B^{-1}b \\
0
\end{pmatrix}
$$

que tem um valor de função objetivo $\overline z = c_BB^{-1}b = c_B\overline{x}_B$
Se $\overline{x_B}\geq 0$ então $\overline x$ é uma _solução básica admissível_.

## Operação Matricial de Mudança de Base
De seguida, vamos realizar as mesmas operações, mas mantendo as colunas na mesma ordem em que aparecem no quadro simplex.
- Vamos identificar a matriz $M$ que opera a mudança de base, do quadro inicial para o quadro final.
- A matriz do quadro final $Q_F$ é o produto da multiplicação da matriz $M$ pela matriz do quadro inicial $Q_I$:

$$
Q_F=M*Q_I
$$

Para obter o quadro simplex final em que as variáveis básicas são as variáveis de $x_B$, temos de identificar:
- a matriz $B$, que é a submatriz de $[A|I]$ com as colunas das variáveis básicas de $x_B$, e
- o vetor $c_B$, com os coeficientes do vetor $c$ das mesmas variáveis.

$$
M=
\left[\begin{array}{c|c}
B^{-1} & 0 \\
\hline
c_BB^{-1} & 1
\end{array}\right]
\in \mathbb{R}^{(m+1)*(m+1)}
$$

O produto da multiplicação da matriz $M$ pela matriz do quadro inicial $Q_I$ é a matriz do quadro final $Q_F$:

$$
\left[
\begin{array}{c|c}
B^{-1} & 0 \\
\hline
c_BB^{-1} & 1
\end{array}
\right]
*
\left[
\begin{array}{c|c|c}
A & I & b \\
\hline
-c & 0 & 0
\end{array}
\right]
=
\left[
\begin{array}{c|c|c}
B^{-1}A & B^{-1} & B^{-1}b \\
\hline
c_BB^{-1}A-c & c_BB^{-1} & c_BB^{-1}b
\end{array}
\right]
$$

### Linha da Função Objetivo do Quadro Ótimo
Usam-se designações especiais para os coeficientes da linha da função objetivo do quadro ótimo.

$$
\left[
\begin{array}{c|c|c}
B^{-1}A & B^{-1} & B^{-1}b \\
\hline
c_BB^{-1}A-c & c_BB^{-1} & c_BB^{-1}b
\end{array}
\right]
$$

_Custo reduzido_ da variável de decisão $x_j$:
- é o valor do elemento $c_j-c_BB^{-1}a_j$ do vetor $-(c-c_BB^{-1}A)$.
- os valores do vetor custo $c$ são **reduzidos** de $c_BB^{-1}A$.
_Preço-sombra_ da restrição $i$ (recurso $i$):
- é o valor do elemento $(c_BB^{-1})i$ do vetor $c_BB^{-1}$.
Mais informação em [[Análise de Sensibilidade|análise de sensibilidade]].

#### O Vetor $c_BB^{-1}$, e o Vetor $c$ Reduzido de $c_BB^{-1}A$
O vetor $c_BB^{-1}$ guarda informação sobre as transformações efetuadas na linha da função objetivo quando a ela se subtraem múltiplos das linhas pivôs.
Ao calcular $(c-c_BB^{-1}A)$, o resultado é $-(c_BB^{-1}A-c)$.
