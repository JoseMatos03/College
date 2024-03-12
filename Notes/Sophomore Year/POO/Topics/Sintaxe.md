## Comentários

- Comentar uma linha

```java
// Este comentário termina no fim da linha
```

- Comentar várias linhas

```java
/* Este comentário pode ter várias linhas
pois só termina quando aparecer
o delimitador final */
```

- Gerar documentação

```java
/** Este comentário vai gerar documentação via o programa javadoc */
```

## Declaração de variáveis

- `*tipo* nome_da_variável;`
- `*tipo* nome_da_variável [= valor];`

**Exemplos:**

```java
String nome;
int i = 5, j = 4;
long k = i + j;
```

## Declaração de constantes

- `**final** *tipo* nome_da_constante = valor;`

**Exemplo:**

```java
final double PI = 3.1416;
```

## Estruturas de controlo

- Condicionais:

```java
if (condição) intrução
if (condição) instrução else instrução
switch (expressão) {
	case valor_1: instruções; [break;]
	...
	case valor_n: instruções; [break;]
	default: instruções; [break;]
}
```

- Ciclos:

```java
while (condição) instrução
do instrução while (condição)
for (inicialização; condição; incremento) instrução
for (variável: colecção_de_valores) instrução
```

## Input / Output

### Escrever

- Instruções de escrita no ecrã são enviadas ao objeto `System.out`

```java
System.out.println("A idade é " + id); // Escreve e muda de linha
System.out.print("A idade é "); System.out.println(id); // Escreve o valor passado um parâmetro
System.out.printf("A idade é %d\n", id); // Escreve de acordo com o formato
```

### Leitura de valores

- A leitura de valores é feita através de um objeto da classe `java.util.Scanner`
- Declarar e criar o objeto:

```java
Scanner input = new Scanner(System.in);
```

- Alguns métodos para leitura:

```java
input.next() // Lê uma string
input.nextLine() // Lê uma linha de texto
input.nexIntt() // Lê um int
input.nextDouble() // Lê um double
input.nextFloat() // Lê um float
```