O uso de sistemas de equações equivalentes permite tomar as decisões algorítmicas corretas.
**A análise de um sistema de equações permite:**
- Associar uma solução (básica) admissível diferente a cada sistema de equações equivalente;
- Avaliar se essa solução admissível é a solução ótima do modelo;
- Determinar qual deve ser o próximo sistema de equações equivalente, se a solução não for ótima.
Assim, o método simplex é um método iterativo que gera uma sequência de soluções admissíveis até atingir uma solução ótima.

## Forma Standard Dum Modelo
O método simplex baseia-se numa definição do domínio que usa equações, em vez de inequações ([[Modelos#Transformações básicas|Transformações]]).

$$
\begin{aligned} & \max z=\boldsymbol{c x} \quad \max z=\boldsymbol{c} \boldsymbol{z} \\ & A x \leq b \quad \Rightarrow \quad A x+s=b \\ & x \geq 0 \quad x, s \geq 0 \\ & \end{aligned}
$$

_s_ é a "folga" para chegar até _b_.

### Soluções Básicas
A solução básica associada a um dado sistema de equações é uma das soluções de um sistema de equações em que as variáveis:
- independentes têm o valor 0, e as
- dependentes têm os valores determinados pela resolução de equações, de uma forma trivial.
Vamos usar:
![[Screenshot 2024-04-30 at 13.32.04.png]]
