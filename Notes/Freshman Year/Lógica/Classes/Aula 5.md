# Aula 5

subject: Dedução Natural
topics: DNP, Deduções, Teorema da Adequação, Teorema da Completude, Teorema da Correção
created: March 15, 2023 1:11 PM

### Definição

Uma fórmula $\varphi$ diz-se derivável a partir de um conjunto $\Gamma$ de fórmulas, ou uma consequência sintática de $\Gamma$, se existir uma derivação $D$ do DNP cuja conclusão é $\varphi$ e cujo conjunto de hipóteses não canceladas é um subconjunto de $\Gamma$.

Em tal caso, escreve-se $\Gamma\vdash\varphi$ e diz-se que $D$ é uma derivação de $\varphi$ a partir de $\Gamma$.

### Definição

Uma fórmula $\varphi$ diz-se um teorema de DNP se existir uma derivação $D$ de $\varphi$ a partir do conjunto vazio de hipóteses não canceladas. Em tal caso, escreve-se $\purple{\vdash\varphi}$ e diz-se que $D$ é uma derivação de $\varphi$.

### Proposição

Sejam $\varphi,\psi\in F^{CP}$ e $\Gamma$ e $\Delta$ subconjuntos de $F^{CP}$. Então:

- se $\varphi\in\Gamma$, então $\Gamma\vdash\varphi$;
- se $\Gamma\vdash\varphi$ e $\Gamma\subseteq\Delta$, então $\Delta\vdash\varphi$;
- se $\Gamma\vdash\varphi$ e $\Delta,\varphi\vdash\psi$, então $\Delta,\Gamma\vdash\psi$;
- $\Gamma\vdash\varphi\rightarrow\psi$ se e só se $\Gamma,\varphi\vdash\psi$;
- se $\Gamma\vdash\varphi\rightarrow\psi$ e $\Gamma\vdash\varphi$, então $\Gamma\vdash\psi$.

### Definição

Seja $\Gamma\subseteq F^{CP}$. Diz-se que:

- $\Gamma$ é sintaticamente inconsistente se $\Gamma\vdash\perp$;
- $\Gamma$ é sintaticamente consistente se $\Gamma\nvdash\perp.$

### Proposição

Seja $\Gamma\sube F^{CP}$. As seguintes afirmações são equivalentes:

- $\Gamma$ é sintaticamente inconsistente;
- para alguma fórmula $\varphi,\Gamma\vdash\varphi$ e $\Gamma\vdash\neg\varphi$;
- para qualquer fórmula $\psi,\Gamma\vdash\psi$.

### Lema

Para toda a derivação $D$, se $D$ é uma derivação de $\varphi$ a partir de $\Gamma$, então $\Gamma\vDash\varphi$.

### Teorema da Correção

Para toda a formula $\varphi$ e para todo o conjunto de fórmulas $\Gamma$,

$$
\text { se }\Gamma\vdash \varphi \text {, então } \Gamma \models \varphi \text {. }
$$

### Proposição

Seja $\Gamma\sube F^{CP}$. Se $\Gamma$ é semanticamente consistente, então $\Gamma$ é sintaticamente consistente.

### Teorema da Completude

Para toda a fórmula $\varphi$ e para todo o conjunto de fórmulas $\Gamma$,

$$
\text { se } \Gamma \models \varphi \text {, então } \Gamma \vdash \varphi.
$$

### Teorema da Adequação

Para toda a fórmula $\varphi$ e para todo o conjunto de fórmulas $\Gamma$,

$$
\Gamma \vdash \varphi \text { se e só se } \Gamma \models \varphi.
$$