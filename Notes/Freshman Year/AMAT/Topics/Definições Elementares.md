

Uma função real de $n$ variáveis reais é uma aplicação

$$
\begin{split}
f :\space\space\space\space &U\longrightarrow\R\\
&\bold{x}\longmapsto f(\bold{x})
\end{split}
$$

- $U \sub \R^n$ é o domínio.
- $\R$ é o conjunto de chegada.

## Contradomínio

O **contradomínio** de $f$ é o conjunto $CD_f\sub\R$ constituído por todas as imagens de $f$:

$$
CD_f = \{f(\bold{x})\in\R:\bold{x}\in U\}
$$

---

Dada $f:D\longrightarrow\R$, dizemos que

## Injetividade

- $f$ é **injetiva** quando a objetos distintos em $D$, correspondem imagens distintas em $\R$

$$
\forall\bold{x,y}\in D,\space\space\bold{x}\neq\bold{y}\Longrightarrow f(\bold{x})\neq f(\bold y)
$$

## Sobrejetividade

- $f$ é **sobrejetiva** quando o seu contradomínio coincide com o conjunto de chegada

$$
\forall a\in \R,\space\space\exists\bold{x}\in D:f(\bold{x}) = a
$$

## Bijetividade

- $f$ é **bijetiva** quando é simultaneamente injetiva e sobrejetiva.

---

## Limitações

- $f$ é **minorada** quando

$$
\exists m\in \R:f(\bold{x})\geq m, \forall\bold{x}\in D
$$

- $f$ é **majorada** quando

$$
\exists M\in \R:f(\bold{x})\leq M, \forall\bold{x}\in D
$$

A função é **limitada** quando é simultaneamente minorada e majorada, ou seja, quando

$$
\exists L \in \R^+:|f(\bold{x})|\leq L, \forall\bold{x}\in D
$$

---

Sejam $f:D\longrightarrow\R$ e $A,S\sub\R^n$ dois subconjuntos tais que $A\sub D\sub S$:

## Restrição

- chama-se **restrição** de $f$ a $A$ à função

$$
f|_A:A\longrightarrow\R\text{ tal que } (f|_A)(\bold{x}) = f(\bold{x}), \forall\bold{x}\in A
$$

## Extensão

- chama-se **extensão** ou **prolongamento** de $f$ a $S$ à função

$$
f^*:S\longrightarrow\R\text{ tal que } f^*(\bold{x}) = f(\bold{x}), \forall\bold{x}\in D
$$

---

Sejam $f:D\longrightarrow\R$ e dois subconjuntos de $A$ e $B$, não vazios, com $A\sub D$ e $B\sub R$:

## Imagem

- chama-se **imagem** de $A$ por $f$ ao conjunto

$$
f(A)=\{w\in\R:w=f(\bold{x})\space\text{ e }\space\bold{x}\in A\}\sub f(D)
$$

## Imagem Recíproca

- chama-se **imagem recíproca** de $B$ por $f$ ao conjunto

$$
f^{-1}(B)=\{\bold{x}\in D:f(\bold{x})\in B\}
$$

## Gráfico

Seja $f:U\sub\R^n\longrightarrow\R$ e $\bold{x} = (x_1,…,x_n)\in\R^n$:

- O **gráfico** **de** $f$ é o conjunto $G_f\sub\R^{n+1}$ com $\bold{x}\in U$

$$
G_f=\{\big(\bold{x},f(\bold{x})\big):\bold{x}\in U\}
$$

![Untitled](Aula%202%20a97b49656ad14193a5e42f2e60aaec79/Untitled.png)

Só é possível fazer o esboço do gráfico de um função até $\R^3$

---

### Plano

Um **plano** é uma função linear de duas variáveis:

$$
f(x,y)=ax+by+c,\space\space a,b,c\in\R
$$

![Untitled](Aula%202%20a97b49656ad14193a5e42f2e60aaec79/Untitled%201.png)

---

### Parabolóide

![Untitled](Aula%202%20a97b49656ad14193a5e42f2e60aaec79/Untitled%202.png)

---

### Outras Superfícies

[SuperficiesQuadricas.pdf](Aula%202%20a97b49656ad14193a5e42f2e60aaec79/SuperficiesQuadricas.pdf)

---

## Conjuntos de Nível

O **conjunto de nível $k$** de $f$ é o conjunto formado por todos os pontos $\bold{x}\in U$ cuja imagem por $f$ é igual a $k$,

$$
N_k=f^{-1}\big(\{k\}\big) = \{\bold{x}\in U: f(\bold{x}) = k\}\sub\R^n
$$

### Curvas de Nível

Para obter um **esboço do gráfico** de uma função de duas variáveis, recorremos ao método de desenhar um mapa de curvas no plano.

![Untitled](Aula%202%20a97b49656ad14193a5e42f2e60aaec79/Untitled%203.png)

![Untitled](Aula%202%20a97b49656ad14193a5e42f2e60aaec79/Untitled%204.png)
