## Regra da Cadeia em $\R$

Se $\green g$ é derivável em $\green{a\in I}$ e $\green f$ é derivável em $\green{b=g(a)\in J}$, então a função composta $\green{f \circ g}$ é derivável em $\green{a\in I}$ e a sua derivada é o produto das derivadas das funções $\green g$ e $\green f$, cada uma delas no ponto respetivo:

$$
(f \circ g)^{\prime}(a)=f^{\prime}(g(a)) g^{\prime}(a)=f^{\prime}(b) g^{\prime}(a), a \in I
$$

## Regra da Cadeia em $\R^2$

**Caso 1**

$$
\green h \longmapsto f<\begin{aligned}& x=\phi \longrightarrow t \\& y=\psi \longrightarrow t\end{aligned}
$$

Sejam $\green{\alpha\in I}$ e $\green{a=\phi(\alpha)}$, $\green{b=\psi(\alpha)}$, com $\green{(a,b)\in D}$. Se $f$ é derivável em $\green{(a,b)\in D}$ e $\green \phi$ e $\green \psi$ são deriváveis em $\green{\alpha\in I}$, então a função composta $h$ é derivável em $\green{\alpha\in I}$, e a sua derivada (total) é dada por

$$
\begin{aligned}h^{\prime}(\alpha) & =\frac{\partial f}{\partial x}(a, b) \phi^{\prime}(\alpha)+\frac{\partial f}{\partial y}(a, b) \psi^{\prime}(\alpha) \\& =\frac{\partial f}{\partial x}(a, b) \frac{d x}{d t}(\alpha)+\frac{\partial f}{\partial y}(a, b) \frac{d y}{d t}(\alpha), \alpha \in I\end{aligned}
$$

**Caso 2**

Consideremos

$$
\green h \longmapsto f<\begin{aligned}& x=\phi< \begin{aligned}& s\\&t\end{aligned} \\& y=\psi< \begin{aligned}& s\\&t\end{aligned} \end{aligned}
$$

Sejam $(\alpha, \beta) \in \mathcal{V}, a=\phi(\alpha, \beta), b=\psi(\alpha, \beta),(a, b) \in D$. Se $\green f$ é derivável em $\green{(a,b)}$ e $\green \phi$, $\green \psi$ são deriváveis em $\green{(\alpha,\beta)}$, então a função composta $\green h$ é derivável em $\green{(\alpha,\beta)}$, e as suas derivadas parciais são dadas por

$$
\begin{aligned}& \frac{\partial h}{\partial s}(\alpha, \beta)=\frac{\partial f}{\partial x}(a, b) \underbrace{\frac{\partial \phi}{\partial s}(\alpha, \beta)}_{\frac{\partial x}{\partial s}(\alpha, \beta)}+\frac{\partial f}{\partial y}(a, b) \underbrace{\frac{\partial \psi}{\partial s}(\alpha, \beta)}_{\frac{\partial y}{\partial s}(\alpha, \beta)} \\& \frac{\partial h}{\partial t}(\alpha, \beta)=\frac{\partial f}{\partial x}(a, b) \underbrace{\frac{\partial \phi}{\partial t}(\alpha, \beta)}_{\frac{\partial x}{\partial t}(\alpha, \beta)}+\frac{\partial f}{\partial y}(a, b) \underbrace{\frac{\partial \psi}{\partial t}(\alpha, \beta)}_{\frac{\partial y}{\partial t}(\alpha, \beta)}\end{aligned}
$$

## Regra da Cadeia Geral

![Untitled](Aula%206%20b28e3cb89d9247a8976379c4366a0910/Untitled.png)

Sejam $\green{f: U \subset \mathbb{R}^n \longrightarrow \mathbb{R} }\text { e  } \green{\phi_i: \mathcal{V} \subset \mathbb{R}^m \longrightarrow \mathbb{R}}$, com $i=1,2,…,n$, funções definidas nos abertos $U$ e $V$. Se cada $\phi_i$ é derivável em $\bold a=(a_1,…,a_m)\in V$ e $f$ é derivável em $\bold b=(\phi_1(a),…,\phi_n(a))\in U$, então a função composta $\green{h:V\sub\R^m\longrightarrow\R}$ é derivável em $\green {\bold a}$ e as suas derivadas parciais são dadas por

$$
\begin{gathered}\frac{\partial h}{\partial t_1}(a)=\frac{\partial f}{\partial x_1}(b) \frac{\partial \phi_1}{\partial t_1}(a)+\cdots+\frac{\partial f}{\partial x_n}(b) \frac{\partial \phi_n}{\partial t_1}(a) \\\quad \cdots \quad \cdots \\\frac{\partial h}{\partial t_m}(a)=\frac{\partial f}{\partial x_1}(b) \frac{\partial \phi_1}{\partial t_m}(a)+\cdots+\frac{\partial f}{\partial x_n}(b) \frac{\partial \phi_n}{\partial t_m}(a)\end{gathered}
$$

---
