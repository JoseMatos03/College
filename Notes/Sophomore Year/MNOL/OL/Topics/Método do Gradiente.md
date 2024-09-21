Dado um **problema sem restrições**:

$$
\underset{x\in R^n}{min}\space\space f(x) \space (n>1)
$$

- Métodos de procura direta (que _não_ usam derivadas)
- [[Método do Gradiente|Métodos do gradiente]]

## Método
Estes métodos:
- usam informação da função e das derivadas (gradiente e/ou Hessiana);
- só podem ser usados na resolução de **problemas diferenciáveis**;
- convergem mais rapidamente do que os métodos de procura direta.
---
- geram um sucessão de aproximação $\lbrace x^{(k)}\rbrace$ à solução:

$$
x^{(k+1)}=x^{(k)}+\alpha^kd^{(k)}
$$

- em que $d^{(k)}$ (vetor) é a _direção de procura_ (ou passo) e $\alpha^k$ (escalar) é o _comprimento do passo_;
- A equação iterativa para o cálculo da direção de procura é diferente para cada método.

### Algoritmo Geral dos Métodos
Dados: aproximação inicial $x^{(1)}$, $\epsilon > 0 (\eqsim 0)$, $k\leftarrow 1$
**Enquanto $||\nabla f(x^{(k)})||_2 > \epsilon$ fazer**:
- calcular $d^{(k)}$ (direção de procura ou passo)
- calcular $\alpha^{(k)}$ (comprimento do passo)
- definir $x^{(k+1)} \leftarrow x^{(k)}+\alpha^{(k)}d^{(k)}$
- $k=k+1$
**Fim de enquanto**
$$
\text{Solução}
\begin{cases}
x^* \eqsim x^{(k+1)} \\
f^* \eqsim f(x^{(k+1)})
\end{cases}
$$
#### Métodos mais usados
Em cada iteração $k$, para calcular a direção de procura ou passo $d^{(k)}$:
- métodos de Segurança de Newton
$$
\text{direção é } d_{SN}^{(k)}
$$
- método quasi-Newton
$$
\text{direção é } d_{QN}^{(k)}
$$
para calcular o comprimento do passo $\alpha^{(k)}$ - se a direção for _descendente_ para $f(x)$ em $x^{(k)}$:
- critério de Armijo
