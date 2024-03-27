## Objetivo
Calcular uma _aproximação numérica_ a

$$
I=\intop_a^bf(x)dx
$$

(integral **definido**)
- função integranda $f$ definida em $[a,b]$
- limites $a$ e $b$ finitos.

Aplicação a casos em que:
- a primitiva de $f$ não pode vir expressa em termos de funções elementares;
- a expressão da função integranda $f$ é demasiada complicada;
- a função integranda é conhecida apenas para um conjunto discreto de pontos.
---
Se $p_n(x)$ for uma _aproxima polinomial_ a $f(x)$, então

$$
I=\intop_a^bf(x)dx
$$

é aproximado por

$$
\intop_a^bp_n(x)dx
$$

Se $e_n(x)$ é o [[Erros|erro de aproximação]] polinomial $e_n(x)=f(x)-p_n(x)$, então

$$
\Rightarrow I=\intop_a^bp_n(x)dx + \intop_a^be_n(x)dx
$$

$$
I=\intop_a^bp_n(x)dx + \boldsymbol{erro\space de\space integração}
$$

### Como Escolher a Melhor Fórmula?
As diferentes fórmulas de Newton-Cotes podem ser usadas no intervalo de integração $[a,b]$, desde que cada uma (simples ou composta) seja usada em regiões com pontos igualmente espaçados.
Em cada subintervalo de pontos igualmente espaçados, a fórmula mais adequada deve ser escolhida tendo em conta o número de pontos $(n+1)$ ou subintervalos $(n)$ e a precisão desejada.

**Condição mais adequada de aplicabilidade:**
Se o número de subintervalos $n$
- é múltiplo de 2 - usa-se _Simpson_
- é múltiplo de 3 - usa-se _3 oitavos_
- não é múltiplo de 2, nem é múltiplo de 3 - usa-se _trapézio_
