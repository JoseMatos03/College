## Teorema de Fermat

Seja $\blue a\in\Z$ e $\blue p$ um primo tal que $\blue{p\nmid a}$. Então:

$$
\blue{a^{p-1}}\equiv_{\blue p}1
$$

### Corolário

$\blue p\text{ primo}\quad\Rightarrow\quad\blue{a^p}\equiv_{\blue p}\blue a\quad\forall\blue{a}\in\Z$

**Demonstração**

![IMG_C969C0B6536F-1.jpeg](Aula%206%205f6f56adeb31498696865411c250f5de/IMG_C969C0B6536F-1.jpeg)

## Função de Euler

Para cada $\blue n\in\N$, representa-se por $\phi(\blue n)$ o número de inteiros positivos, menores ou iguais a $\blue n$, que são primos com $\blue n$. A função $\phi:\N\rightarrow\N$, assim definida, diz-se a função de Euler.

**Exemplos**

- $n=6 \quad \red1,2,3,4,\red5,6 \quad \text{logo} \quad \phi(6)=2$
- $n=9 \quad \red1,\red2,3,\red4,\red5,6,\red7,\red8,9 \quad \text { logo } \quad \phi(9)=6$
- $n=7 \quad \red1,\red2,\red3,\red4,\red5,\red6,7 \quad \text { logo } \quad \phi(7)=6$

### Propriedades

A função de Euler tem as seguintes propriedades:

1. $\blue p \text { primo } \Rightarrow \phi(\blue p)=\blue{p-1}$
2. $\blue p \text { primo e } \alpha \in \mathbb{N} \Rightarrow \phi\left(\blue p^\alpha\right)=\blue p^\alpha-\blue p^{\alpha-1}$
3. $\blue{n, m} \in \mathbb{N} \text { e } \quad \text { m.d.c. }(\blue{n, m})=1 \quad \Rightarrow \quad \phi(\blue{n m})=\phi(\blue n) \phi(\blue m)$
4. Se $\blue{n=p_1^{\alpha_1} p_2^{\alpha_2} \cdots p_k^{\alpha_k}}$ é a decomposição em primos de $\blue n$:

$$
\phi(\blue n)=\left(\blue{p_1^{\alpha_1}-p_1^{\alpha_1-1}}\right)\left(\blue{p_2^{\alpha_2}-p_2^{\alpha_2-1}}\right) \cdots\left(\blue{p_k^{\alpha_k}-p_k^{\alpha_k-1}}\right)
$$

## Teorema de Euler

Seja $\blue a\in\Z$ e $\blue n\in\N$ tais que $\text{m.d.c}(\blue{n,a})=1$. Então:

$$
\blue{a^{\phi(n)}}\equiv_{\blue n} 1
$$

**Nota:** Se $\blue n$ for primo $\blue{\phi(n)=n-1}$ e obtemos $\blue{a^{n-1}}\equiv_{\blue n}1$. Ou seja, nesse caso obtemos o Teorema de Fermat.

## Teorema de Wilson

$\blue p \enspace\text { primo }\enspace \Rightarrow \quad(\blue p-1)! \equiv_{\blue p}-1$
