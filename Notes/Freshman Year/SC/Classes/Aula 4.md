# Aula 4

subject: Number representation
topics: Addition overflow, Conversions, Excess representation, Hexadecimal numbers, Octal numbers, Positional systems, Signed numbers
created: March 9, 2023 1:29 PM

## Positional Numeral Systems

A numeral system is a writing system for expressing numbers that uses digits and other symbols to do so.

These systems are usually positional numeral systems, which represent a number by a sequence of juxtaposed digits.

### Digit and radix

A digit is a symbol used alone or in combination with other digits to represent a larger number.

The position of a digit matters, has it has it’s corresponding weight.

**Example**

The value of a decimal integer number $D$ in the form $d_3d_2d_1d_0$ is

$$
d_3*10^3+d_2*10^2+d_1*10^1+d_0*10^0
$$

Here, the radix (or **base**) of this numeral system is **10**.

### Least & Most significant digits

In positional numeral systems:

- the rightmost digit is the least significant digit (LSD)
- the leftmost digit is the most significant digit (MSD)

In binary numbers, the naming is a bit different:

- LSD is the least significant bit (LSB)
- MSD is the most significant bit (MSB)

---

## Octal and Hexadecimal Numbers

Because the binary notation is **too verbose**, bases 8 (octal) and 16 (hexadecimal) are used instead, as they offer a shorthand representation for binary numbers.

![Untitled](Aula%204%20162a977086fc4674a578abea0cfa2940/Untitled.png)

---

## Conversions

### From base 2 to bases 8-16

Starting at the binary point and moving to the left, the bits are separated into groups of three or four, and each group is replaced by the corresponding octal or hexadecimal digit.

Zeros (0s) can be added to the left, since they do not change the value.

$$
\begin{aligned}& 100010101001_2=100 \quad 010 \quad 101 \quad 001_2 \quad=4251_8 \\& 100010101011_2=1000\quad1010\quad1011_2 \quad=8 \mathrm{AB}_{16} \\& 11111100011101110_2=011 \quad 111 \quad 100\quad011 \quad 101 \quad 110_2=374356_8 \\& 11111100011101110_2=0001\quad1111\quad1000\quad1110 \quad 1110_2=1 \text { F8EE }_{16}\end{aligned}
$$

$$
\begin{aligned}& .11001_2=.110 \quad 010_2=.62_8 \\& \quad\quad\enspace\enspace\space=.1100\quad1000_2=. \mathrm{C8}_{16} \\& 1234_8=001\quad010 \quad 011 \quad 100_2 \\& 234.05_8=010 \quad 011 \quad 100.000 \quad 101_2 \\& 1234_{16}=0001\quad0010\quad0011 \quad 0100_2 \\& \mathrm{AB3.05} 5_{16}=1010 \quad 1011 \quad 0011.0000 \quad 0101_2\end{aligned}
$$

### General conversion

Any other conversion that can’t be done by the previous step (since it can only be used when both bases are powers of the same number) we follow the following steps:

1. First we convert the given number to base 10:

$$
\begin{aligned}& \mathrm{AB3}_{16}=10 \cdot 16^2+11 \cdot 16^1+3 \cdot 16^0 \quad=2739_{10} \\& 2345_8=2 \cdot 8^3+3 \cdot 8^2+4 \cdot 8^1+5 \cdot 8^0 \quad=1253_{10} \\& 124.7_8=1 \cdot 8^2+2 \cdot 8^1+4 \cdot 8^0+7 \cdot 8^{-1} \quad=84.875_{10} \\& 120.01_3=1 \cdot 3^2+2 \cdot 3^1+0 \cdot 3^0+0 \cdot 3^{-1}+1 \cdot 3^{-2}=15 .(1)_{10}\end{aligned}
$$

1. Then, we divide that number using the radix we want to convert to, and the remainder indicates the digit of the number in a reversed order:

$$
\begin{array}{rlr}177 \div 2=88 & & \text { remainder } 1 \\88 \div 2=44 & & \text { remainder } 0 \\44 \div 2=22 & & \text { remainder } 0 \\22 \div 2=11 & & \text { remainder } 0 \\11 \div 2=5 & & \text { remainder } 1 \\5 \div 2=2 & & \text { remainder } 1 \\2 \div 2=1 & & \text { remainder } 0 \\1 \div 2=0 & & \text { remainder } 1 \\177_{10}=10110001_2 &\end{array}
$$

$$
\begin{array}{rr}177 \div 8=22 & \text { remainder } 1 \\22 \div 8=2 & \text { remainder } 6 \\2 \div 8=0 & \text { remainder } 2 \\177_{10}=261_8 &\end{array}
$$

$$
\begin{aligned}177 \div 16=11 & \text { remainder } 1 \\11 \div 16=0 & \text { remainder } 11 \\177_{10}=\mathrm{B1}_{16} &\end{aligned}
$$

---

## Negative numbers

Representing signed numbers requires extra information, such as a sign bit.

We will now discuss four different ways to represent signed numbers:

### Sign-magnitude

This is the most intuitive method of signing numbers. It uses a single bit to store the sign and the remaining bits are reserved for the actual value (absolute value) of the number.

By convention, a ‘1’ is used for negative numbers and a ‘0’ for positive numbers.

**Examples:**

- $+120_{10}=\orange01111000_2$
- $-120_{10}=\orange11111000_2$

It is necessary to know how many bits are used to represent numbers.

The range of representable integer numbers with $n$ bits is $-(2^{n-1})$ through $+(2^{n-1})$

### One’s-complement

Using the MSB weight, the one's complement of binary numbers is calculated as $-2^{n-1}+1$.

- $\orange011001_2=1*16+1*8+1*1\qquad\qquad\enspace\enspace\space= 25$
- $\orange111001_2=1*(-31)+1*16+1*8+1*1 = -6$

For a binary number, its one’s complement is obtained by subtracting all ones. Which ends up *switching* all the bits.

- The one’s complement of $0101_2$ is $1111-0101=1010_2$.

Additionally, this method simplifies subtraction by turning it into addition:

1. To subtract $10$ from $24$, we express the subtrahend $(10)$ in one’s-complement and then **add** it to the minuend $(24)$.
2. This effectively adds $-10$ to $24$.
3. The MSB will have a ‘0’ or a ‘1’ carry, which will be added to the LSB of the sum.

![Untitled](Aula%204%20162a977086fc4674a578abea0cfa2940/Untitled%201.png)

The range of representable integer numbers with $n$ bits is $-(2^{n-1})$ through $+(2^{n-1})$

### Two’s-complement

Most computers use the complementary two-digit numerical system. It is the same as the complement of one **increased by 1**.

The two’s-complement of binary numbers is computed by the weight of the MSB is $-2^{n-1}$.

- $\orange011001_2=1*16+1*8+1*1 \qquad\qquad\quad\space=25_{10}$
- $\orange111001_2=1*(-32)+1*16+1*8+1*1=-7_{10}$

To find the two’s-complement of a binary number, we just need to *flip* the bits and **add 1**. Any carries involving the MSB are discarded.

- $+24_{10}=+00011000_2=00011000_2$
- $-24_{10}=-00011000_2=11100111_2+1=11101000_2$
- $-10_{10}=-00001010_2=11110101_2+1=11110110_2$

![Untitled](Aula%204%20162a977086fc4674a578abea0cfa2940/Untitled%202.png)

The range of representable integer numbers with $n$ bits is $-(2^{n-1})$ through $+(2^{n-1}-1)$

---

## Excess Representations

In an excess-b representation, an *n*-bit pattern, whose unsigned integer value is $V\space(0\leq V\leq2^n)$ represents the signed integer $V\it{-b}$, where $\it b$ is the **bias** (or offset) of the numeral system.

The representable numeric values range from $\it{-b}$ to $2^n-1\it{-b}$*.*

**Example:**

With 8 bits and $b=100$, this range represents $256$ different integer numbers from $-100$ to $+155$.

---

## Different Numeral Systems

![Untitled](Aula%204%20162a977086fc4674a578abea0cfa2940/Untitled%203.png)

---

## Addition overflow

An addition overflows whenever the signs of the addends are the same and the sign of the sum is different from the addends’ sign.

![Untitled](Aula%204%20162a977086fc4674a578abea0cfa2940/Untitled%204.png)