## Pressupostos De Um Modelo De Programação Linear
Um modelo é uma representação da realidade.
A validade de um modelo de PL (que usa funções lineares na função objetivo e nas restrições) resulta da assunção de que são válidos os seguintes pressupostos:
- Proporcionalidade: os contributos para a função objectivo e para as funções usadas nas restrições são proporcionais aos valores das variáveis de decisão.
- Aditividade: em cada função, o contributo total é dado pela soma dos contributos das diferentes variáveis.
- Divisibilidade: as variáveis de decisão podem tomar qualquer valor, incluindo valores fraccionários.
- Determinismo: os dados são valores conhecidos e constantes.

## Elementos Dos Modelos (exemplos)
Variáveis de decisão:
- quantidades a produzir de um artigo;
- rotas a percorrer por veículos;
- fluxos a enviar pelos arcos duma rede;
- actividades (ou projectos) a seleccionar;
- instantes para iniciar as actividades.

Parâmetros (dados):
- recursos disponíveis;
- número de unidades pedidas por um cliente;
- tempo de processamento de uma actividade.

Restrições:
- relação entre a função que exprime a quantidade de um recurso que as actividades consomem e o recurso disponível;
- relação entre a função que exprime a quantidade de um bem que as actividade produzem e a procura a satisfazer;
- relação que traduz as regras de funcionamento do sistema (e.g., conservação de fluxo, precedência entre operações).

## Transformações Básicas
### Do Tipo $\leq$
Qualquer inequação do tipo de menor ou igual pode ser transformada numa equação, introduzindo uma variável adicional de folga com valor não-negativo:

$$
\sum^n_{j=1}a_{ij}x_j\leq b_i\iff\sum^n_{j=1}a_{ij}x_j+s_i=b_i,\space si\geq 0
$$

**Exemplo:**

$$
\begin{array}{ll} \text{Antes:} & \text{Depois:} \\ 2x_1 − 3x_2 + 4x_4 ≤ 8 & 2x_1 − 3x_2 + 4x_4 + s_1 = 8 \\ & s_1\geq 0 \end{array}
$$

### Do Tipo $\geq$
Qualquer inequação do tipo de menor ou igual pode ser transformada numa equação, introduzindo uma variável adicional de folga com valor não-negativo:

$$
\sum^n_{j=1}a_{ij}x_j\geq b_i\iff\sum^n_{j=1}a_{ij}x_j-s_i=b_i,\space si\geq 0
$$

**Exemplo:**

$$
\begin{array}{ll} \text{Antes:} & \text{Depois:} \\ 1x_1 − 2x_2 + 3x_4 \geq 4 & 1x_1 − 2x_2 + 3x_4 - s_1 = 4 \\ & s_1\geq 0 \end{array}
$$

### De Uma Equação Em Duas Inequações
Qualquer restrição de igualdade pode ser expressa como uma par de inequações do tipo de menor ou igual:

$$
\sum^n_{j=1}a_{ij}x_{j}=b_{i}\iff
\begin{cases}
  \sum^n_{j=1} a_{ij}x_j \leq b_i \\
  \sum^n_{j=1} a_{ij}x_j \geq b_i \\
\end{cases}
\iff
\begin{cases}
  \space\space\space\sum^n_{j=1} a_{ij}x_j \leq b_i \\
  -\sum^n_{j=1} a_{ij}x_j \leq -b_i \\
\end{cases}
$$

**Exemplo:**

$$
\begin{array}{ll} \text{Antes:} & \text{Depois:} \\ 1x_1 − 2x_2 + 3x_4 = 4 & 1x_1 − 2x_2 + 3x_4 \leq 4 \\ & 1x_1 − 2x_2 + 3x_4 \geq 4 \end{array}
$$

### De Minimização Em Maximização
Qualquer problema de minimização pode ser reduzido a um problema de maximização, em que se optimiza a função objectivo simétrica da original:

$$
\text{min}\space z=cx\iff\text{max}\space z'=-cx
$$
