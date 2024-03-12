## Thinking Recursively

Usually we define an edge case and then we define a function that does something between some element and the function applied to the rest.

Of course, these also may have edge cases. Usually the edge case is some scenario where a recursive application doesn't make sense.

## Examples of Recursion

### Quick, Sort!

We have a list of items that can be sorted. Their type is an instance of the `Ord` typeclass. And now, we want to sort them!

So, the type signature is going to be `quicksort:: (Ord a) ⇒ [a] → [a]`. No surprises there. The edge condition? Empty list, as is expected. Now, the main algorithm:

> A sorted list is a list that has all the values smaller than (or equal to) the head of the list in front (and those values are sorted), then comes the head of the list in the middle and then come all the values that are bigger than the head (they're also sorted).

```haskell
quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) =
		let smallerSorted = quicksort [a | a <- xs, a <= x]
				biggerSorted = quicksort [a | a <- xs, a > x]
		in  smallerSorted ++ [x] ++ biggerSorted
```

---

## Active Recall

- What are the most common edge cases?
    - When dealing with lists, the edge case is most often an empty list.
    - If we're dealing with trees, the edge case is usually a node without any children.

- How to solve a problem recursively?
    1. Try to think of when a recursive solution doesn't apply and apply an edge case;
    2. Think about identities (often the edge case value turns out to be an identity);
    3. Think about whether you'll break apart the parameters of the function (for instance, lists are usually broken into a head and a tail via pattern matching);
    4. Finally, think about on which part you'll use the recursive call.
