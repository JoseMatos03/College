## Derivadas Parciais

Suponhamos que fixamos $y=b$, com $b$ uma constante real, e que apenas $x$ é variável. Significa que estamos a considerar uma função dependente apenas da variável $x$

$$
g(x)=f(x,b)
$$

A função $g(x)$ é a restrição de $f(x,y)$ à reta horizontal $y=b$.

Se a função $g(x)$ for derivável num ponto a, então à derivada $g'(a)$ chamamos **derivada parcial** de $f$ em ordem a $x$ no ponto $(a,b)$.

$$
g'(a)=\frac{\partial f}{\partial x}(a,b)=\lim_{h\rightarrow0}\frac{f(a+h,b)-f(a,b)}{h}
$$

Esta é a expressão que define a **derivada parcial** de $f(x,y)$ em ordem a $x$ no ponto $(a,b)$.

De forma análoga, definimos a **derivada parcial** de $f(x,y)$ em ordem a $y$ no ponto $(a,b)$. Para isso, fixamos $x=a$ e deixamos apenas $y$ como variável.

$$
\frac{\partial f}{\partial y}(a, b)=\lim _{h \rightarrow 0} \frac{f(a, b+h)-f(a, b)}{h}
$$

Fazendo o ponto $(a,b)$ percorrer o domínio $D$, definimos **derivadas parciais de** $f$

$$
\frac{\partial f}{\partial x}(x, y)=f_x(x, y) \quad \text { e } \quad \frac{\partial f}{\partial y}(x, y)=f_y(x, y)
$$

### Observação

Ainda que existam as derivadas parciais de uma função num ponto, a função pode não ser contínua nesse ponto.

**Isto acontece porque** a continuidade de $f$ em $(a,b)$ depende do comportamento da função uma bola aberta centrada em $(a,b)$

**Enquanto que** uma derivada parcial depende do comportamento da função apenas ao longo de uma trajetória.

---

## Derivadas Parciais de Ordem Superior

Partindo de uma função $f(x,y)$, por exemplo

$$
f(x,y)=x^2y^3
$$

e derivando parcialmente, obtemos

$$
f_x(x, y)=2 x y^3 \quad f_y(x, y)=3 x^2 y^2
$$

que definem novas funções de duas variáveis.

Cada uma destas funções pode ser derivada parcialmente, as vezes que quisermos. Obtemos **derivadas parciais de segunda ordem**, dadas por

$$
\text { e } \quad \begin{array}{ll}f_{x x}(x, y)=2 y^3 & f_{x y}(x, y)=6 x y^2 \\f_{y x}(x, y)=6 x y^2 & f_{y y}(x, y)=6 x^2 y\end{array}
$$

e assim sucessivamente.

### Notações

$$
\begin{aligned}f_{x x} & =\frac{\partial^2 f}{\partial x^2}=\frac{\partial}{\partial x}\left(\frac{\partial f}{\partial x}\right) & f_{x y} & =\frac{\partial^2 f}{\partial y \partial x}=\frac{\partial}{\partial y}\left(\frac{\partial f}{\partial x}\right) \\f_{y x} & =\frac{\partial^2 f}{\partial x \partial y}=\frac{\partial}{\partial x}\left(\frac{\partial f}{\partial y}\right) & f_{y y} & =\frac{\partial^2 f}{\partial y^2}=\frac{\partial}{\partial y}\left(\frac{\partial f}{\partial y}\right)\end{aligned}
$$

e

$$
\begin{aligned}& f_{x x x}=\frac{\partial^3 f}{\partial x^3}=\frac{\partial}{\partial x}\left(\frac{\partial}{\partial x}\left(\frac{\partial f}{\partial x}\right)\right) \\& f_{x x y}=\frac{\partial^3 f}{\partial y \partial x \partial x}=\frac{\partial}{\partial y}\left(\frac{\partial}{\partial x}\left(\frac{\partial f}{\partial x}\right)\right)\end{aligned}
$$

etc…

### Teorema de Clairaut-Schwarz

Seja $f:D\subset\R^2\longrightarrow\R$ uma função definida no aberto $D$ contendo o ponto $(a,b)$.

Se as funções $f_{xy}$ e $f_{yx}$ são contínuas em $D$, então

$$
f_{xy}(a,b)=f_{yx}(a,b)
$$

---

## Gradiente

Dada uma função $f: D \subset \mathbb{R}^2 \longrightarrow \mathbb{R}$, definimos o **gradiente** de $f$ por

$$
\nabla f(x, y)=\left(\frac{\partial f}{\partial x}(x, y), \frac{\partial f}{\partial y}(x, y)\right)
$$

em cada ponto $(x,y)\in D$ onde existam as derivadas parciais.

---

## Plano Tangente

Seja $\mathscr{S}$ a superfície de equação $z=f(x,y)$, com $f$ uma função possuindo derivadas parciais contínuas.

Seja $P=(a,b,c)$ um ponto de $\mathscr{S}$.

O significado geométrico das derivadas parciais

$$
f_x(a, b) \quad \text { e } \quad f_y(a, b)
$$

são o declive de retas tangentes nos planos verticais $y=b$ e $x=a$.

Assim, os vetores

$$
(1,0,f_x(a,b))\enspace\enspace\text{e}\enspace\enspace(0,1,f_y(a,b))
$$

são tangentes à superficie $\mathscr S$ no ponto $P=(a,b,c)$, com $c=f(a,b)$.

Logo, o plano tangente a $\mathscr S$ no ponto $(a,b,c)$ é o plano que passa por $(a,b,c)$ e é paralelo aos vetores $(1,0,f_x(a,b))$ e $(0,1,f_y(a,b))$.

![Untitled](Aula%204%20effd462b649c44cd8ecaf250295842f0/Untitled.png)

/col

---

## Derivada Direcional

Dados uma função $f:D\sub\R^2\longrightarrow\R$, um ponto $(a,b)\in\R^2$, e um vetor $v=(v_1,v_2)\neq(0,0)$, vamos definir a **derivada direcional** de $f$ no ponto $(a,b)$, segundo o vetor $v$.

Para tal, vamos considerar a restrição de $f$ à reta $r$ que passa por $(a,b)$ e tem a direção do vetor $v$.

![Untitled](Aula%204%20effd462b649c44cd8ecaf250295842f0/Untitled%201.png)

Os pontos $(x,y)$ da reta $r$ são da forma

$$
(x, y)=(a, b)+\alpha\left(v_1, v_2\right)=\left(a+\alpha v_1, b+\alpha v_2\right), \quad \alpha \in \mathbb{R}
$$

Logo, a restrição da função $f$ à reta $r$ é dada por

$$
f\left(a+\alpha v_1, b+\alpha v_2\right)=g(\alpha), \quad \alpha \in \mathbb{R}
$$

Trata-se de uma função da variável $\alpha\in\R$, tal que $g(0)=f(a,b)$.

Definimos a **derivada direcional** de $f$ no ponto $(a,b)$ segundo o vetor $(v_1,v_2)$, em $\R^2$, como sendo a **derivada** de $g$ no ponto $0$, em $\R$, ou seja

$$
\frac{\partial f}{\partial v}(a, b)=g^{\prime}(0)
$$

Mas

$$
g^{\prime}(0)=\lim _{h \rightarrow 0} \frac{g(h)-g(0)}{h}
$$

e, por outro lado,

$$
g(\alpha)=f\left(a+\alpha \boldsymbol{v}_1, b+\alpha \boldsymbol{v}_2\right)
$$

Juntando tudo, vem

$$
\frac{\partial f}{\partial v}(a, b)=\lim _{h \rightarrow 0} \frac{f\left(a+h v_1, b+h v_2\right)-f(a, b)}{h}
$$

que define a **derivada direcional** de $f$ em $(a,b)$ segundo $(v_1,v_2)$.

Fazendo variar o ponto $(a,b)$, definimos a função $\frac{\partial f}{\partial v}(x, y)$ nos pontos $(x,y)$ de $D$ onde existir o limite acima.
