Dados $\blue n\in\N$ e $\blue{a,b}\in\Z$ com $\blue a\neq 0$, queremos encontrar todos os inteiros $x\in\Z$:

$$
ax\equiv_{\blue n} \blue b
$$

Esta expressão diz-se uma congruência linear na incógnita $x$.

## Existência de Solução

Sabemos que

$$
\blue{ax}\equiv_{\blue n} \blue b \Longleftrightarrow \blue n|\blue a x-\blue b
$$

ou seja existe $y\in\Z$ tal que

$$
\blue a x-\blue b=\blue n y \quad \Longleftrightarrow \quad \blue a  x-\blue n y=\blue b
$$

Logo

$$
\blue a x \equiv_{\blue n} \blue b \text { tem solução } \Longleftrightarrow \blue a x-\blue n y=\blue b \quad \text { tem solução }
$$

## Teorema

Dados $\blue n\in\N$ e $\blue{a,b}\in\Z$ com $a\neq 0$,

$$
\blue a x \equiv_{\blue n} \blue b \text { tem solução } \Longleftrightarrow \quad \text { m.d.c. }(\blue a, \blue n) \mid \blue b
$$

## Unicidade de Solução

Se a congruência linear

$$
\blue a x\equiv_{\blue n} \blue b
$$

tem solução então $\text{m.d.c}(\blue{a,n})|\blue b$ e portanto

$$
\text { m.d.c. }(\blue a, \blue n) \mid \blue b \quad \wedge \quad \text { m.d.c. }(\blue a, \blue n) \mid \blue a \quad \wedge \quad \text { m.d.c. }(\blue a, \blue n) \mid \blue n
$$

Logo podemos (e devemos) dividir $\blue{a,b}$ e $\blue n$ por $\text{m.d.c}(\blue{a,n})$ de forma a obter uma congruência linear equivalente, que se diz na forma irredutível, onde o módulo e o coeficiente da incógnita **são primos entre si**.

Se $\text{m.d.c}(\blue{a,n})=1$ a congruência linear

$$
\blue ax\equiv_{\blue n}\blue b
$$

tem solução e pela equação diofantina

$$
\blue ax-\blue ny=\blue b
$$

sabemos que, dada uma solução $\red x_{\red 0}$, a solução geral para a incógnita $x$, é dada por:

$$
x=\red{x_0}+\blue n k \quad \text { com } k \in \mathbb{Z} \quad \text { ou seja } \quad x=\left[\red{x_0}\right]_{\blue n}
$$

## Teorema

Seja $\blue ax\equiv_{\blue n}\blue b$ uma congruência linear. Se $\text{m.d.c}(\blue{a,n})=1$ então a congruência linear tem **exatamente** uma classe de congruência módulo $\blue n$ como solução.

---

## Resolução de Congruências Lineares

Sabemos que se $\blue ax\equiv_{\blue n}\blue b$ é uma congruência linear irredutível então tem **exatamente** uma classe de congruência módulo $\blue n$ como solução.

Para encontrarmos essa solução temos os seguintes métodos:

1. Por tentativas - procurando a solução num sistema completo de resíduos módulo $\blue n$.
2. Equação diofantina - usando o algoritmo de Euclides para encontrar as soluções da equação diofantina:

$$
\blue a x - \blue n y = \blue b
$$

1. Redução do coeficiente - tentando reduzir o coeficiente $\blue a$ da incógnita $x$, a $\red 1$ (ou $\red{-1}$):

### Proposição

Seja $\blue ax\equiv_{\blue n}\blue b$ uma congruência linear e $\red k\in\Z$ tal que:

$$
\text{m.d.c}(\blue n,\red k) = 1
$$

Então:

$$
\blue{\text { (Regra 1) }} \quad \blue a x \equiv_{\blue n} \blue b \Longleftrightarrow \red k \blue a x \equiv_{\blue n} \red k \blue b
$$

e se $\red k|\blue a$ e $\red k|\blue b$

$$
\blue{\text { (Regra 2) }} \quad \blue a x \equiv_{\blue n} \blue b \Longleftrightarrow \frac{\blue a}{\red k} x \equiv_{\blue n} \frac{\blue b}{\red k}
$$

---

## Sistemas de Congruências Lineares

Um sistema de congruências lineares terá solução se existir um valor $x\in\Z$ que satisfaça todas as congruências lineares do sistema.

Obviamente, se uma das congruências lineares do sistema não tiver solução, o sistema também não tem solução.

No entanto, é possível que todas as congruências lineares do sistema tenham solução, mas o sistema seja impossível.

### Teorema

Seja $\blue ax\equiv_n\blue b$ uma congruência linear e sejam $\blue{n_1,n_2}\in\Z$ tais que $\blue{n=n_1*n_2}$ e $\blue{\text{m.d.c}(n_1,n_2)=1}$. Então:

$$
a x \equiv_n b \quad\left\{\begin{array}{l}a x \equiv_{n_1} b \\a x \equiv_{n_2} b\end{array}\right.
$$

### Corolário

Se $\blue{n=p_1^{\alpha_1}p_2^{\alpha_2}\cdots p_k^{\alpha_k}}$ é a decomposição de $\blue n$ em números primos:

$$
a x \equiv_n b \Longleftrightarrow\left\{\begin{array}{l}a x \equiv_{p_1^{\alpha_1}} b \\a x \equiv_{p_2^{\alpha_2}} b \\\cdots \\a x \equiv_{p_k^{\alpha_k}} b\end{array}\right.
$$

### Existência de Solução

Dados $\blue{n_1,n_2,\cdots,n_k}\in\N$ e $\blue{b_1,b_2,\cdots,b_k}\in\Z$, o sistema

$$
\begin{cases}x \equiv_{n_1} & b_1 \\ x \equiv_{n_2} & b_2 \\ \cdots & \\ x \equiv_{n_k} & b_k\end{cases}
$$

tem solução **se e só se**, $\forall{i,j}\quad\text{m.d.c}(\blue{n_i,n_j})|\blue{b_i-b_j}$.

Além disso, se o sistema tiver solução, ela é única módulo o inteiro $\blue n$, onde $\blue n$ é o mínimo múltiplo comum entre $\blue{n_1,n_2,\cdots,n_k}$.
