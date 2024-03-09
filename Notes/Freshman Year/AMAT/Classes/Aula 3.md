## Limite

**Intuitivamente**, dizemos que

$$
\lim_{(x,y)\rightarrow(a,b)} f(x,y) = l
$$

para traduzir a ideia de que

$f(x,y)$ aproxima-se dum número real $l$, desde que $(x,y)$ se aproxime de $(a,b)$, **sem nunca o atingir**.

---

**Simbolicamente**, escrevemos

$$
\lim_{(x,y)\rightarrow(a,b)} f(x,y) = l
$$

se e só se (por Cauchy)

$$
\forall\delta>0,\exists\epsilon>0:(0<\|(x,y)-(a,b)\|<\epsilon)\Longrightarrow|f(x,y)-l)<\delta
$$

em que

$|f(x,y)-l|$ indica a distância entre $f(x,y)$ e $l$, em $\R$

$\|(x,y)-(a,b)\|$ indica a distância entre $(x,y)$ e $(a,b)$, em $\R^2$

![Untitled](Aula%203%2013549739642240f4b229528435d7c08c/Untitled.png)

## Limites Trajetoriais

Recordar que, em $\R$, uma função $f: D\sub\R\longrightarrow\R$,

ter $x\rightarrow a$ significa ter $x\rightarrow a^+$ ou $x\rightarrow a^-$

---

Em $\R^2$, ter $(x,y)\rightarrow(a,b)$ significa ter (infinitas) trajetórias que conduzem ao ponto $(a,b)$.

$$
\lim_{\substack{(x,y)\rightarrow(a,b)\\(x,y)\in\mathscr{C}}}f(x,y)
$$

Desta forma, não usamos este conceito para mostrar que existe limite, pois há infinitas trajetórias. Usamos, então, para provar que não existe limite.

### Exemplo

Considere a função definida por

$$
f(x,y)=\frac {xy} {x^2+y^2},\space\space(x,y)\in\R^2\setminus\{(0,0)\}
$$

e analise a existência de limite na origem, estudando os limites trajetoriais ao longo das retas.

**Comecemos por observar que**

- Indeterminação do tipo $\frac00$.
- Limites trajetoriais sobre os eixos coordenados $\green{OX}$ e $\red{OY}$.

$$
\substack{\lim\\(x,y)\rightarrow(0,0)\\\green{(x,y)\in OX}} \frac{xy}{x^2+y^2} = \substack{\lim\\(x,y)\rightarrow(0,0)\\\green{y=0}}\frac{xy}{x^2+y^2} = \lim_{x\rightarrow0}\frac{0}{x^2}=\green{0}
$$

$$
\substack{\lim\\(x,y)\rightarrow(0,0)\\\red{(x,y)\in OY}} \frac{xy}{x^2+y^2} = \substack{\lim\\(x,y)\rightarrow(0,0)\\\red{x=0}}\frac{xy}{x^2+y^2} = \lim_{y\rightarrow0}\frac{0}{y^2}=\red{0}
$$

### O Que Podemos Concluir?

Calculámos apenas dois limites trajetoriais, apesar de haver uma infinidade de outros que ficaram de fora.

Então, apesar de estes limites trajetoriais serem iguais, **não podemos concluir que o limite proposto vale 0**.

Apenas podemos concluir que se o limite existir, então vale 0.

### Temos de continuar…

- Limites trajetoriais sobre as retas $\blue{y=mx}\space\space(m\in\R)$.

$$
\substack{\lim\\(x,y)\rightarrow(0,0)\\\blue{y=mx}}\frac{xy}{x^2+y^2} = \lim_{x\rightarrow0}\frac{x\blue{mx}}{x^2+\blue{(mx)^2}} = \lim_{x\rightarrow0}\frac{\blue mx^2}{x^2+\blue{m^2}x^2}
$$

donde

$$
\substack{\lim\\(x,y)\rightarrow(0,0)\\\blue{y=mx}}\frac{xy}{x^2+y^2}=\blue{\frac{m}{1+m^2}}
$$

### O Que Significa?

Significa que o limite existe ao longo de cada reta, **mas depende do seu declive.**

**Logo, o limite proposto não existe.**

---

## Continuidade

Dados uma função $f:D\sub\R^n\longrightarrow\R$ e um ponto $\bold{a}\in D$, dizemos que $\green{f}$ é contínua no ponto $\green{\bold{a}}$ se e só se

- $\bold{a}$ é um ponto isolado de $D$;
- $\bold{a}\in D'\cap D$ e $lim_{x\rightarrow\bold{a}} f(x) = f(\bold{a})$

![Untitled](Aula%203%2013549739642240f4b229528435d7c08c/Untitled%201.png)
