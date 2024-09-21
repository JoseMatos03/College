# Code Optimisations

subject: Optimisations
created: May 16, 2023 6:34 PM

## Compilers

The **compilers** can exploit opportunities:

1. to simplify expressions
2. to use a single computation in several different places,
3. to reduce the number of times a given computation must be performed.

A **compiler** is expected to be conservative in applying optimisations: whenever in doubt, it does not apply them.

### Optimisation blockers

Compilers usually have problems in dealing with optimisation blockers.
Optimisation blockers can greatly limit the opportunities for a compiler to generate optimised code.

Often, the optimisation blockers are dependent on the execution environment.

---

![Untitled](Code%20Optimisations%20c72bf920e9be462db1233ec3f7211179/Untitled.png)

![Untitled](Code%20Optimisations%20c72bf920e9be462db1233ec3f7211179/Untitled%201.png)

---

Another optimisation blocker may occur when a function has side effects.
A function (or expression) has a side effect, if it alters the values of some variables outside its local context.

![Untitled](Code%20Optimisations%20c72bf920e9be462db1233ec3f7211179/Untitled%202.png)

Compilers tend to treat procedures as black boxes that cannot be analysed.
Compilers assume the worst case and the function call remains intact.

## Types of optimisations

### Code motion

Loops are good candidates for improvements.

The most typical cases of code motion consist of statements in a loop that can be moved outside its body, without affecting its semantics.
Moving statements from the inside to the outside of the loop obviously reduces the execution time of the program.

![Untitled](Code%20Optimisations%20c72bf920e9be462db1233ec3f7211179/Untitled%203.png)

Compilers try to transform WHILE-DO and FOR loops in equivalent DO-WHILE loops, to avoid the IF-THEN statement.

![Untitled](Code%20Optimisations%20c72bf920e9be462db1233ec3f7211179/Untitled%204.png)

The assembly code for DO-WHILE loops, in general, can be made faster than equivalent FOR and WHILE-DO loops.

### Elimination of accesses to memory