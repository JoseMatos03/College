## Métodos Iterativos
 - permitem resolver uma equação não linear;
 - exigem que seja fornecida **uma** (ou mais do que uma) aproximação inicial.

 Esta aproximação pode ser identificada através da **localização das raízes**, como:
  - $f(x)$ no plano $XOY$, se $f$ for fácil de representar
  - $g(x)$ e $h(x)$ no plano $XOY$, em que

$$
f\left(x\right)=0\lrArr g\left(x\right)=h\left(x\right)
$$

se $f$ for difícil de representar (e $g(x)$ e $h(x)$ forem fáceis de representar).

**Para calcular raízes reais**
- Método da secante
- Método de Newton
- Outros…
Para **raízes complexas**, estes métodos podem ser utilizados desde que se introduza a aritmética complexa nos cálculos e as aproximações iniciais sejam números complexos.

### Método Da Secante
1. Em cada iteração, e com base em dois pontos - **duas aproximações** - o método aproxima a função $f(x)$ por uma reta definida por esses dois pontos;
2. O ponto de interseção da reta com o eixo do $X$ fornece outra aproximação.

#### Exemplo
![[secante-it_1.png]]
A primeira iteração:
- a reta passa pelos 2 últimos pontos $(x_1, f(x_1))$ e $(x_2,f(x_2))$ e a nova aproximação é $x_3$

![[secante-it_2.png]]
A segunda iteração:
- a reta passa agora pelos 2 últimos pontos $(x_2, f(x_2))$ e $(x_3,f(x_3))$
- a nova aproximação é $x_4$

#### Assim
Sejam os dois pontos

$$
\left(x_{k-1},f\left(x_{k-1}\right)\right)\space e \left(x_{k},f\left(x_{k}\right)\right)
$$

então o ponto de interseção da reta, que passa por estes dois pontos, com o eixo do $X$ é

$$
x_{k+1}=x_{k}-\frac{\left(x_{k}-x_{k-1}\right)f\left(x\right)}{f\left(x_{k}\right)-f\left(x_{k-1}\right)}
$$

Esta é a equação iterativa do **método da secante**
Deve ser implementada para $k=2,3,…$

#### Condições De Convergência
O método iterativo da secante nem sempre converge.
Só é possível garantir convergência para a solução se:
- $x^*$ é tal que $f(x^*)=0$
- $f(x)$ é continuamente diferenciável
- $f'(x^*)\ne0$
- $x_1\text{ e }x_2$ (aproximações iniciais) na vizinhança $x^*-\text{convergência local}\implies\text{método iterativo da secante converge e}$

$$
\lim_{k\to\infty}\left(\frac{\left|x^{*}-x_{k+1^{}}\left|\right.\right|}{\left|x^{*}-x_{k}\right|^{p}}\right)=L,\space L>0,p=1.618<=>\text{convergência superlinear}
$$

#### Situação De Divergência
Ao longo do processo iterativo pode acontecer que as duas aproximações, usadas para gerar uma nova aproximação, tenham valores de $f$ muito próximos $\implies$ divergência. (Declive da reta perto de 0).
![[Screenshot 2024-03-04 at 12.23.55.png]]

$$
x_{k+1}=x_k-\frac{(x_k-x_{k-1})f(x_k)}{f(x_k)-f(x_{k-1})}
$$

### Método De Newton
Em cada iteração, e com base na informação de $f$ e de $f'$ relativa a um ponto, o método aproxima a função $f(x)$ por uma reta que é tangente a $f$ nesse ponto.
O ponto de interseção da reta com o eixo $X$ fornece outra aproximação-
![[Screenshot 2024-03-04 at 12.28.23.png]]

Sejam o ponto

$$
(x_k, f(x_k)\text{ e } f'(x_k)
$$

então o ponto de interseção da reta, que passa por este ponto, com declive definido por $f'(x_k)$, com o eixo do $X$ é

$$
x_{k+1}=x_k-\frac{f(x_k)}{f'(x_k)}
$$

Esta é a **equação iterativa** do método de Newton.
Deve ser implementada para $k=1,2,…$

#### Condições De Convergência
O método iterativo da secante nem sempre converge.
Só é possível garantir convergência para a solução se:
- $x^*$ é tal que $f(x^*)=0$
- $f(x)$ é continuamente diferenciável
- $f'(x^*)\ne0$
- $x_1$(aproximação inicial) na vizinhança $x^*-\text{convergência local}\implies\text{método iterativo de Newton converge e}$

$$
\lim_{k\to\infty}\left(\frac{\left|x^{*}-x_{k+1^{}}\left|\right.\right|}{\left|x^{*}-x_{k}\right|^{p}}\right)=L,\space L>0,p=2<=>\text{convergência quadrática}
$$

#### Situação De Divergência
Ao longo do processo iterativo pode acontecer que o declive da reta que é tangente a $f$ na aproximação corrente seja um valor $\eqsim 0\implies\text{divergência}$
![[Screenshot 2024-03-04 at 12.37.35.png]]

$$
x_{k+1}=x_k-\frac{f(x_k)}{f'(x_k)}
$$

## Critério De Paragem
- **estimativa do [[Erros#Erro relativo|erro relativo]] da aproximação** próxima de zero

$$
\frac{\left|x_{k+1}-x_{k}\left|\right.\right.}{\left|x_{k+1}\right|}\leq\epsilon_1
$$

e o valor absoluto de $f(x_k+1)$ próximo de zero (zero de $f(x)$)

$$
|f(x_k+1)|\leq\epsilon_2
$$

$\epsilon_1\text{ e }\epsilon_2$ quantidades positivas e próximas de zero - **tolerâncias** - quanto mais pequenas forem mais próximo $x_k+1$ fica da solução $x^*$.
