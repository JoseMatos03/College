Imaginemos que queremos dividir 171 por 14, em que podemos utilizar o algoritmo da divisão, **ou poderemos resolver usando a reta real**:

1. A partir do inteiro 171, avançamos 14 unidades na direção da origem;
2. Eventualmente, poderemos atingir um **inteiro positivo** inferior a 14;
3. Esse **inteiro** será o resto, e o número de vezes que nos deslocamos 14 unidades indica-nos o quociente.

$$
\begin{CD}
   0 @<<\textcolor{red}{3}< \textcolor{red}{3} @<<\textcolor{blue}{14}< 17 @<<\textcolor{blue}{14}< ... @<<\textcolor{blue}{14}< 143 @<<\textcolor{blue}{14}< 157 @<<\textcolor{blue}{14}< \textcolor{green}{171}
\end{CD}
$$

Assim, para calcular o resto da divisão de 171 por 14, podemos subtrair a 171 múltiplos de 14 até obter um inteiro entre 0 e 13.

## Algoritmo da Divisão

### Para Inteiros Positivos

Dados $a,b\in\N$ existem **inteiros únicos**, $q,r\in\N_0$, tais que:

$$
a=q*b+r \space\space\text{com}\space\space 0\leq r < b
$$

### Para Inteiros

Dados $a,b\in\Z\setminus \{0\}$ existem **inteiros únicos**, $q,r\in\N_0$, tais que:

$$
a=q*b+r \space\space\text{com}\space\space 0\leq r < |b|
$$

## Relação de Divisibilidade

Dados $a,b\in\Z\setminus\{0\}$, quando o resto da divisão de _a_ por _b_ é zero, temos que $a = q*b$ e nesse caso escrevemos:

$$
b|a \Longleftrightarrow \exists q \in\Z:a=q*b
$$

- Lê-se como:
    - b **divide** a
    - b é um **divisor** de a
    - a é **divisível** por b
    - a é um **múltiplo** de b
- **Propriedades**

    Sejam $a,b,c,d\in\Z\setminus\{0\}$. Então:

    - $a|a$
    - $a|b \land b|a\Rightarrow a=\pm b$
    - $a|b \land b|c\Rightarrow a|c$

    ---

    - $a|b\Rightarrow a|-b\land -a|b\land -a|-b$
    - $a|b\land c|d\Rightarrow ac|bd$

    ---

    - $a|b \land a|c\Rightarrow a|b+c$
    - $a|b \land a|c\Rightarrow a|b-c$
    - $a|b+c \land a|b\Rightarrow a|c$
    - $a|b \land a|c\Rightarrow a|bx+cy\space\space\space\space\forall x,y\in\Z$

## Máximo Divisor Comum
