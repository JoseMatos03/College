## Curried Functions

Every function in Haskell officially only takes one parameter. So how is it possible that we defined and used several functions that take more than one parameter so far? Well, it's a clever trick! All the functions that accepted _several parameters_ so far have been __curried functions_._**

```haskell
ghci> max 4 5
5
ghci> (max 4) 5
5
```

Why does this happen? Putting a space between two things is simply **function application.** The space is sort of like an operator and it has the highest precedence. Let's examine the type of `max`**:**

- It's `max:: (Ord a) => a -> a -> a`;
- That can also be written as `max:: (Ord a) => a -> (a -> a)`;
- That could be read as: `max` ****takes an `a` and returns (that's the `->`) a function that takes an `a` and returns an `a`**.**

That's why the return type and the parameters of functions are all simply separated with arrows.

---

So how is that beneficial to us? Simply speaking, if we call a function with too few parameters, we get back a **partially applied ****function, meaning a function that takes as many parameters as we left out. Using partial application (calling functions with too few parameters, if you will) is a neat way to create functions on the fly so we can pass them to another function or to seed them with some data.

```haskell
multThree :: (Num a) => a -> a -> a -> a  
multThree x y z = x * y * z
```

- What really happens when we do `multThree 3 5 9` ****or `((multThree 3) 5) 9`?
    1. **3** is applied to **multThree**, because they're separated by a space. That creates a function that takes one parameter and returns a function.
    2. **5** is applied to that, which creates a function that will take a parameter and multiply it by 15.
    3. **9** is applied to that function and the result is 135.

Remember that this function's type could also be written as:

1. `multThree:: (Num a) => a -> (a -> (a -> a))` (the thing before the `->` ****is the parameter that a function takes and the thing after it is what it returns);
2. So our function takes an `a` ****and returns a function of type `(Num a) => a -> (a -> a)`;
3. This function takes an `a` and returns a function of type `(Num a) => a -> a`;
4. This function, finally, just takes an `a` ****and returns an `a`.

Take a look at this:

```haskell
ghci> let multTwoWithNice = multThree 9
ghci> multTwoWithNine 2 3
54
ghci> let mulWithEighteen = multTwoWithNine 2
ghci> multWithEighteen 10
180
```

---

By calling functions with too few parameters, we're creating new functions on the fly:

```haskell
compareWithHundred :: (Num a, Ord a) => a -> Ordering
compareWithHundred x = compare 100 x
```

Notice that:

- the `x` in on the right hand side on both sides of the equation;
- `compare 100` returns a function that takes a number and compares it with 100.

That's what we wanted, meaning we can rewrite the function as:

```haskell
compareWithHundred :: (Num a, Ord a) => a -> Ordering
compareWithHundred = compare 100
```

The type declaration stays the same, because `compare 100` returns a **function**. `compare` has a type of `(Ord a) => a -> (a -> Ordering)` and calling it with `100` returns a `(Num a, Ord a) => a -> Ordering`.

## Maps and Filters

`map` takes a function and a list and applies that function to every element in the list, producing a new list.

```haskell
map :: (a -> b) -> [a] -> [b]
map _ [] = []
map f (x:xs) = f x : map f xs
```

The type signature says that it takes a function that takes an `a` and returns a `b`, a list of `a`'s and a returns a list of `b`'s.

---

`filter` is a function that takes a predicate and a list and then returns the list of elements that satisfy that predicate.

```haskell
filter :: (a -> Bool) -> [a] -> [a]
filter _ [] = []
filter p (x:xs)
		| p x       = x : filter p xs
		| otherwise = filter p xs
```

If `p x` evaluates to `True`, the element gets included in the new list. If it doesn't, it stays out.

## Lambdas

Lambdas are basically anonymous functions that are used because we need some functions only once. Normally, we make a lambda with the sole purpose of passing it to a **higher-order function**.

```haskell
numLongChains :: Int
numLongChains = length (filter (\xs -> length xs > 15) (map chain [1..100]))
```

```haskell
ghci> map (\(a,b) -> a + b) [(1,2),(3,5),(6,3),(2,6),(2,5)]
[3,8,9,8,7]
```

## Only Folds and Horses

A fold takes a binary function, a starting value (an accumulator) and a list to fold up.

1. The binary is called with the accumulator and the first (or last) element and produces a new accumulator.
2. The binary function is called again with he new accumulator and the now new first (or last) element, and so on.
3. Once we've walked over the whole list, only the accumulator remains, which is what we've reduced the list to.

### `foldl`

Also called the **left fold** function. It folds the list up from the left side. The binary function is applied between the starting value and the head of the list.

```haskell
sum :: (Num a) => [a] -> a
sum xs = foldl (\acc x -> acc + x) 0 xs
```

```haskell
sum [3,5,2,1] =
foldl 0 [3,5,2,1] =
foldl (0 + 3) [5,2,1] =
foldl (3 + 5) [2,1] =
foldl (8 + 2) [1] =
foldl (10 + 1) [] = 11
```

### `foldr`

The **right fold** works similarly to the left fold, only the accumulator eats up the values from the right. The right fold's binary function has the current value as the first parameter and the accumulator as the second one, since it folds from the right side.

```haskell
map :: (a -> b) -> [a] -> [b]
map f xs = foldr (\x acc -> f x : acc) [] xs
```

```haskell
map (*2) [3,5,2,1] =
foldr [] [3,5,2,1] =
foldr [1*2] [3,5,2] = 
foldr [2*2,2] [3,5] =
foldr [5*2,4,2] [3] =
foldr [3*2,10,4,2] =
[6,10,4,2]
```

## Function Application with `$`

```haskell
($) :: (a -> b) -> a -> b
f $ x = f x
```

From the definition, it looks pointless, but it can simplify the readability of the code. It's a convenience function so that we don't have to write so many parentheses.

Consider the expression `sum (filter (> 10) (map (*2) [2..10]))`. Because `$` is right-associative, `f (g (z x))` is equal to `f $ g $ z x`. And so, we can rewrite it as:

```haskell
sum $ filter (> 10) $ map (*2) [2..10]
```

---

But apart from getting rid of parentheses, `$` means that function application can be treated just like another function. That way, we can map function application over a list of functions:

```haskell
ghci> map ($ 3) [(4+), (10*), (^2), sqrt]
[7.0,30.0,9.0,1.7320508075688772]
```

## Function Composition

In Haskell, function composition is pretty much the same as in mathematics. We do function composition with the `.` functions:

```haskell
(.) :: (b -> c) -> (a -> b) -> a -> c
f . g = \x -> f (g x)
```

Mind the type declaration. `f` must take as its parameter a value that has the same type as `g`'s return value.

---

One of the uses for function composition is making functions on the fly to pass to other functions. Sure, we can use lambdas for that, but many times, function composition is clearer and more concise:

> Say we have a list of numbers and we want to turn them all into negative numbers. One way to do that would be to get each number's absolute value and then negate it:

```haskell
ghci> map (\x -> negate (abs x)) [5,-3,-6,7,-3,2,-19,24]
[-5,-3,-6,-7,-3,-2,-19,-24]
```

Notice the lambda and how it looks like the result function composition. Using function composition, we can rewrite that as:

```haskell
ghci> map (negate . abs) [5,-3,-6,7,-3,2,-19,24]
[-5,-3,-6,-7,-3,-2,-19,-24]
```
