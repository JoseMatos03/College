# Aula 3

subject: Semântica do Cálculo Proposicional
topics: Conjuntos completos, Consequência semântica, Consistência semântica, Formas normais, Satisfação de fórmulas, Teorema da substituição
created: March 1, 2023 2:15 PM

## Substituição de variáveis por fórmulas

### Teorema

Sejam $\varphi,\psi\in F^{CP}$ e $p_i\in V^{CP}$. Se $\varphi$ é uma tautologia, então $\varphi[\psi/p_i]$ também é uma tautologia.

### Teorema da substituição

Sejam $\psi_1,\psi_2\in F^{CP}$ e seja $p_i\in V^{CP}$. Então

$$
\psi_1 \Leftrightarrow \psi_2 \enspace\text{sse}\enspace\varphi[\psi_1/p_i]\Leftrightarrow\varphi[\psi_2/p_i],\space\text{para todo}\space\varphi\in F^{CP}
$$

## Conjunto completo de conetivos

Um conjunto $A$ de conetivos diz-se completo se

$$
\text{para cada}\enspace\varphi\in F^{CP}\enspace\text{existe}\enspace\psi\in F^{CP}\enspace\text{tal que}\enspace\varphi\Leftrightarrow\psi
$$

e todos os conetivos que ocorrem em $\psi$ pertencem a $A$.

### Teorema

Os conjuntos completos minimos são:

$$
\{\neg,\lor\},\enspace\{\neg,\land\},\enspace\{\neg,\rightarrow\},\enspace\{\perp,\rightarrow\}
$$

## Formas normais

As variáveis proposicionais $p_i$ e as negações de variáveis proposicionais $\neg p_i$ são chamadas literais.

Fórmulas do tipo

- $(l_{11}\lor...\lor l_{1m_1})\land...\land(l_{n1}\lor...\lor l_{nm_n})$ → Forma Normal Conjuntiva;
- $(l_{11}\land...\land l_{1m_1})\lor...\lor(l_{n1}\land...\land l_{nm_n})$ → Forma Normal Disjuntiva.

### Teorema

Para cada fórmula $\varphi\in F^{CP}$, existem FNC e FND tal que

$$
\varphi\Leftrightarrow\varphi^c\enspace\text{e}\enspace\varphi\Leftrightarrow\varphi^d
$$

### Como obter uma FNC/FND?

Usamos o teorema dos **conetivos completos minímos** para transformar uma fórmula numa FNC/FND.

Em alternativa, podemos obter uma fórmula normal aplicando os seguintes passos:

1. Se $\varphi$ é uma contradição, escolhe-se $\varphi^d=p_0\land\neg p_0$.
2. Senão, suponhamos que $var(\varphi)=\{p_1,p_2,...,p_n\}$ e que a tabela de verdade de $\varphi$ é:

![Screenshot 2023-03-01 at 15.05.22.jpg](Aula%203%20c06b0cf06ec84e84856870c9b2ac2bb4/Screenshot_2023-03-01_at_15.05.22.jpg)

### Exemplo

![Screenshot 2023-03-01 at 15.06.00.jpg](Aula%203%20c06b0cf06ec84e84856870c9b2ac2bb4/Screenshot_2023-03-01_at_15.06.00.jpg)

---

## Satisfação de fórmulas

Se $v$ é uma valoração e $\Gamma\sube F^{CP}$, diz-se que:

- $v$ satisfaz $\Gamma$ se $v(\varphi) = 1$ para toda a fórmula $\varphi\in\Gamma$. Em tal caso escreve-se $v \vDash\Gamma$.
- $v$ não satisfaz $\Gamma$ se existe $\varphi\in\Gamma$ tal que $v(\varphi)=0$. Em tal caso escreve-se $v \nvDash\Gamma$.

## Consistência semântica

Um conjunto $\Gamma$ de fórmulas diz-se:

- consistente se existe pelo menos uma valoração $v$ tal que $v\vDash\Gamma$.
- inconsistente se não é consistente e $v\nvDash\Gamma$ para toda a valoração $v$.

### Lema

Sejam $\Gamma, \Delta\sube F^{CP}$ tais que $\Gamma\sube\Delta$:

- Se $\Delta$ é consistente, então $\Gamma$ é consistente.
- Se $\Gamma$ é inconsistente, então $\Delta$ é inconsistente.

## Consequência semântica

Sejam $\varphi\in F^{CP}$ e $\Gamma\sube F^{CP}$. Diz-se que $\varphi$ é uma consequência semântica de $\Gamma$, se $v\vDash\Gamma$ implica $v\vDash\varphi$ para toda a valoração $v$.

Em tal caso, escreve-se $\Gamma\vDash\varphi$, e diz-se que $\Gamma$ é um modelo de $\varphi$.

### Teorema

Seja $\varphi\in F^{CP}$. Então, $\vDash\varphi$ se e só se $\empty\vDash\varphi$.

### Teorema da Redução ao Absurdo

Sejam $\varphi\in F^{CP}$ e $\Gamma\sube F^{CP}$. Então,

$$
\Gamma\vDash\varphi\enspace\text{se e só se}\enspace\Gamma\cup\{\neg\varphi\}\enspace\text{é semanticamente inconsistente.}
$$