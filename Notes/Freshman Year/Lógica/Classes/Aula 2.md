# Aula 2

subject: Semântica do Cálculo Proposicional
topics: Equivalência lógica, Valorações, Valores lógicos
created: February 22, 2023 2:23 PM

## Árvore de Parsing

A cada fórmula $\psi\in\cal{F}^{CP}$ pode associar-se uma árvore $T(\psi)$ do seguinte modo:

- 

 Permite ler o *flow* duma proposição.

---

## Valores lógicos

Os **valores lógicos** do Cálculo Proposicional são símbolos

- 1 (ou V) → Verdadeiro;
- 0 (ou F) → Falso.
- Podemos somar estes valores da seguinte forma:
    1. $0 + 0\rightarrow0$
    2. $0 + 1 \rightarrow 1$
    3. $1 + 0 \rightarrow 1$
    4. $1+1\rightarrow 1$

## Valorações

Uma **valoração** é uma função $v:\cal{F}^{CP}\rightarrow\{0,1\}$ tal que, para quaisquer $\varphi,\psi\in\cal{F}^{CP}$:

- $v(\perp)=0$;
- $v(\neg\varphi)=1-v(\varphi)$;
- $v(\varphi\lor\psi)=\max\{v(\varphi),v(\psi)\}$;
- $v(\varphi\land\psi)=\min\{v(\varphi),v(\psi)\}$;
- $v(\varphi\rightarrow\phi)=0$ se e só se $v(\varphi)=1$ e $v(\psi)=0$;
- $v(\varphi\leftrightarrow\phi)=0$ se e só se $v(\varphi)=v(\psi)$;

Sendo $\varphi$ uma fórmula, $v(\varphi)$ é chamado de **valor lógico** de $\varphi$ para a valoração $v$.

## Tautologias

Uma fórmula $\varphi$ diz-se uma

- **tautologia** se $v(\varphi)=1$ para toda a valoração $v$ (escreve-se $\vDash\varphi$);
- **contradição** se $v(\varphi)=0$ para toda a valoração $v$ (escreve-se $\nvDash\varphi$);

Se $\varphi$ é uma tautologia, então $\varphi[\psi/p_i]$ também é uma tautologia.

## Equivalência lógica

Duas fórmulas $\varphi$ e $\psi$ dizem-se **logicamente equivalentes** (escreve-se $\varphi\Leftrightarrow\psi$) se $\varphi\leftrightarrow\psi$ for uma tautologia.

Em $\cal{F}^{CP}$, a relação de equivalência lógica é uma relação de equivalência.