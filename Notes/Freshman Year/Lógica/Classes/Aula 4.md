# Aula 4

subject: Dedução Natural
topics: DNP, Deduções, Regras de Inferência
created: March 15, 2023 1:10 PM

## Sistema Formal da Dedução Natural

Uma regra de inferência representa-se na forma

$$
\frac{\varphi_1 \cdots \varphi_n}{\varphi} \text { nome }
$$

- As fórmulas acima do traço de inferência são chamadas de premissas.
- A fórmula abaixo do traço de inferência é chamada de conclusão.

As notações do tipo

$$
\begin{array}{ccc}\rho & & \cancel\rho \\\vdots & & \vdots \\\theta & \text { ou } & \dot{\theta}\end{array}
$$

representam árvores finitas de fórmulas construídas a partir das regras de inferência, de **raiz** $\theta$, nas quais $\rho$ ocorre como folha, zero ou mais vezes, sem ou com corte.

---

## Regras de inferência

As regras de inferência do sistema formal de Dedução Natural para o Cálculo Proposicional (DNP) são as seguintes:

![Untitled](Aula%204%20b2ed37b09f0245438911187fcb2ffe5e/Untitled.png)

![Untitled](Aula%204%20b2ed37b09f0245438911187fcb2ffe5e/Untitled%201.png)

---

### Definição

O conjunto $\purple{D^{DNP}}$ das derivações de DNP (também chamadas deduções ou demonstrações) é o conjunto de árvores finitas de fórmulas gerado pelo conjunto de regras indutivas.

![Untitled](Aula%204%20b2ed37b09f0245438911187fcb2ffe5e/Untitled%202.png)

![Untitled](Aula%204%20b2ed37b09f0245438911187fcb2ffe5e/Untitled%203.png)

---

### Definição

Numa derivação $D$:

- a raiz de $D$ é chamada a conclusão de $D$;
- as folhas de $D$ são chamadas as hipóteses de $D$;
- as folhas de $D$ anotadas com um corte são chamadas as hipóteses canceladas (ou cortadas) e as folhas de $D$ sem qualquer anotação chamadas as hipóteses não canceladas (or não cortadas) de $D$.