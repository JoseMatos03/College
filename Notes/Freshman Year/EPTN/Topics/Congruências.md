Sejam $\blue{n}\in\N$ e $\blue{a,b}\in\Z$. Diz-se que $\blue a$ e $\blue b$ são congruentes módulo $\blue n$ se $\blue a$ e $\blue b$ têm o mesmo resto quando divididos por $\blue n$

$$
\blue a \equiv_n \blue b
$$

Nota importante:

$$
\blue a\equiv_{\blue{n}} \blue b \Longleftrightarrow \blue n|\blue{a-b}
$$

## Proposição

A relação $\equiv_n$ é uma relação de equivalência em $\Z$, isto é, dados $a,b,c\in\Z$:

- $a\equiv_na$
- $a\equiv_nb\Rightarrow b\equiv_na$
- $a\equiv_nb\land b\equiv_nc\Rightarrow a\equiv_nc$

## Propriedades

![Screenshot 2023-03-07 at 12.09.27.jpg](Aula%204%208af9013905e94c90a2d4ed910ee99a59/Screenshot_2023-03-07_at_12.09.27.jpg)

---

## Classes de Congruência

Dados $\blue n\in\N$ e $\blue a\in\Z$, chama-se classe de congruência de $a$ módulo $n$ ao conjunto de todos os inteiros que têm o mesmo resto que $\blue a$ quando divididos por $\blue n$, e representa-se por

$$
[\blue a]_{\blue n}
$$

A classe de congruência de 3 módulo 14 é constituida por todos os inteiros que divididos por 14 dão resto 3.

$$
[\red 3]_{\blue{14}} = \{...,-25,-11,\red3,17,31,...\}
$$

$$
[\red3]_{\blue{14}}=[-25]_{\blue{14}} = [-11]_{\blue{14}} = [17]_{\blue{14}} = [31]_{\blue{14}}
$$

---

## O Conjunto $\Z_n$

Dado $\blue n\in\N$ o conjunto de todas as classes de congruência módulo $\blue n$ representa-se por $\blue{\Z_n}$ e diz-se o conjunto quociente de $\blue\Z$ pela relação $\blue{\equiv_n}$.

$$
\blue{\Z_n} = \{[0]_{\blue n},[1]_{\blue n},[2]_{\blue n},...,[\blue n-1]_{\blue n}\}
$$

Neste conjunto definem-se as operações $\blue+$ e $\blue\times$ da seguinte forma:

$$
[a]_{\blue n} + [b]_{\blue n} = [a+b]_{\blue n}\qquad\quad [a]_{\blue n}\times[b]_{\blue n} = [a\times b]_{\blue n}
$$

---

## Sistema Completo de Resíduos

Dado $\blue n\in\N$, chama-se sistema completo de resíduos módulo $n$ a qualquer conjunto de $n$ inteiros que tenha **exatamente** um representante de cada classe de congruência módulo $\blue n$.

**Exemplo:**

$$
\{0,1,2,3,4,5,6,7,8,9,10,11,12,13\}
$$

é um sistema completo de resíduos módulo $\blue{14}$ e,

$$
\{14,29,-12,17,32,5,-8,-7,22,37,-4,-3,-2,-1\}
$$

também é.

---

## Critérios de Divisibilidade

![Untitled](Aula%204%208af9013905e94c90a2d4ed910ee99a59/Untitled.png)

![Untitled](Aula%204%208af9013905e94c90a2d4ed910ee99a59/Untitled%201.png)

![Untitled](Aula%204%208af9013905e94c90a2d4ed910ee99a59/Untitled%202.png)

![Untitled](Aula%204%208af9013905e94c90a2d4ed910ee99a59/Untitled%203.png)
