# Aula 5

subject: Number representation
topics: Binary codes, Floating-point numbers
created: March 16, 2023 10:44 AM

## Floating-point numbers

### Fixed-point numbers

In many numeral systems, the radix point is assumed to have a **fixed position**, resulting in each number being represented as a fixed-point number. 

For integers, the radix point typically appears on the right side. As a result, with a five-digit decimal system, values between 0 and 99,999 can be accurately represented. This system can represent a total of 100,000 different numbers, with each pair of consecutive numbers differing by exactly 1. 

However, the **position of the radix point can be adjusted** to represent different ranges of values. For instance, placing the radix point after the third decimal digit results in values ranging from 0 to 999.99. In this system, each pair of consecutive numbers only differ by 0.01. 

The value of a fixed-point number can be **determined by an integer scaled by a factor** that is determined by the **position of the radix point**.

---

### Generic format

An alternative is a floating-point numeral system, whose numbers have the generic format:

$$
\text{mantissa }*\text{ radix}^{\text{exponent}}
$$

This format is useful for performing computations involving very large numbers $(V>>0)$, numbers very close to 0 $(V<<1)$.

A **floating-point number** is a fixed-point number, indicated bythe mantissa, whose radix point position is regulated by the exponent.

Generally, **floating-point representations** offer greater range but less precision compared to **fixed-point representations**.

**Example:**

Decimal scientific notation is a format that expresses numbers in two parts: 

- a mantissa;
- an exponential part that indicates an integer power of ten.

The value of the number is obtained by multiplying these parts together.

$$
2.2538 × 10^4\Longrightarrow22,538
$$

 This notation **simplifies arithmetic** **calculations** involving very large or very small numbers and serves as the foundation for floating-point computation in digital computers. 

---

## In digital format

**Example:**

![Untitled](Aula%205%203cfbd25cbd2e4693b3ea7e8bb61e37de/Untitled.png)

### IEEE 754 floating-point standard

---

## BCD