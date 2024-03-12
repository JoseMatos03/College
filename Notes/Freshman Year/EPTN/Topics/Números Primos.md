Um inteiro $\blue{p} > 1$ diz-se um **número primo** se $\blue 1$ e $\blue p$ são os seus únicos divisores positivos.

Número que não é primo é número composto.

## Teorema

Sejam $\blue a,\blue b\in\N$ e $\blue p$ um número primo. Então:

$$
\blue p|\blue{ab} \Longrightarrow \blue p | \blue a \space\lor\space \blue p|\blue b
$$

## Corolário

Sejam $\blue{a_1,a_2,…,a_n}\in\N$ e $\blue p$ e um número primo. Então:

$$
\blue p|\blue{a_1a_2...a_n}\Longrightarrow \blue p|\blue{a_i}\text{ para algum \blue{i}}
$$

---

## Decomposição em Números Primos

Se um número $\blue n$ não for primo, então ele pode escrever-se como produto de dois fatores inteiros:

$$
\blue{n = ab}
$$

Se $\blue a$ ou $\blue b$ não forem primos, repete-se este processo até chegar à decomposição esperada.

### Teorema Fundamental da Aritmética

Todo o inteiro $\blue n > 1$ pode ser decomposto num produto de números primos, de forma **única**:

$$
\blue n = p_1^{\alpha_1}p_2^{\alpha_2}...p_k^{\alpha_k}
$$

### Propriedade

Para decompor um inteiro $\blue n>1$ em fatores primos, basta procurar divisores de $n$ que sejam primos até ao valor $\blue{\sqrt{n}}$

---

## Crivo de Erastótenes

É um processo para encontrar todos os inteiros primos até um valor previamente fixado.

Vamos usar o processo para encontrar todos os primos até $\blue{100}$:

1. Começamos por listar todos os inteiros até $\blue{100}$ e riscamos o número $\blue 1$;
2. O numero seguinte da lista é o $\red 2$ (que é _primo_) e riscamos da lista todos os múltiplos de $\red 2$;
3. O numero seguinte da lista é o $\red 3$ (que é _primo_) e riscamos da lista todos os múltiplos de $\red 3$;
4. O numero seguinte da lista é o $\red 5$ (que é _primo_) e riscamos da lista todos os múltiplos de $\red 5$;
5. O numero seguinte da lista é o $\red 7$ (que é _primo_) e riscamos da lista todos os múltiplos de $\red 7$.

Como só precisámos de verificar os números até $\blue{\sqrt{n}}$, só verificamos até $\sqrt{100}=\red{10}$.

A lista dos números não riscados é a lista de todos os primos até $\blue{100}$.

![Untitled](Aula%203%208e64cef8c6d646e188f570ea380c0d7d/Untitled.png)

---

## Divisores Positivos

Se um inteiro $\blue n>1$ tem decomposição em primos:

$$
n=p_1^{\alpha_1} p_2^{\alpha_2} \cdots p_k^{\alpha_k}
$$

os seus divisores positivos são da forma:

$$
p_1^{\beta_1}p_2^{\beta_2}...p_k^{\beta_k}\space\text{ com }\space 0\leq\beta_i\leq\alpha_i
$$

e o número de divisores positivos de $\blue n$ é dado por:

$$
(\alpha_1+1)(\alpha_2+1)...(\alpha_k+1)
$$

**Exemplo:**

Dado:

$$
\blue{792}=2^{\red3} \times 3^{\red2} \times 11^{\red1}
$$

Logo o número de divisores positivos de $\blue{792}$ e dado por:

$$
(\red3+1) \times(\red2+1) \times(\red1+1)=4 \times 3 \times 2=24
$$

e a lista dos mesmos é dado por:

$$
\begin{array}{llll}1 & 2 & 2^2 & 2^3 \\3 & 2 \times 3 & 2^2 \times 3 & 2^3 \times 3 \\3^2 & 2 \times 3^2 & 2^2 \times 3^2 & 2^3 \times 3^2 \\11 & 2 \times 11 & 2^2 \times 11 & 2^3 \times 11 \\3 \times 11 & 2 \times 3 \times 11 & 2^2 \times 3 \times 11 & 2^3 \times 3 \times 11 \\3^2 \times 11 & 2 \times 3^2 \times 11 & 2^2 \times 3^2 \times 11 & 2^3 \times 3^2 \times 11\end{array}
$$

---

## MDC e MMC

Sejam $\blue n$ e $\blue m$ inteiros maiores do que $1$, com a seguinte decomposição em primos:

$$
\blue n = p_1^{\alpha_1}p_2^{\alpha_2}...p_k^{\alpha_k}\qquad\qquad\blue m=q_1^{\beta_1}q_2^{\beta_2}...q_r^{\beta_r}
$$

Então

- O $m.d.c\blue{(n,m)}$ é o produto dos primos comuns, elevados ao menor dos expoentes de ambos.
- O $m.m.c\blue{(n,m)}$ é o produto de todos os primos, elevados ao maior dos expoentes de ambos.
