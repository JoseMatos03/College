module Ficha3 (
    my_assocr,
    α
) where


import Cp

-- Ex 2.
my_assocr :: ((a, b), c) -> (a, (b, c))
my_assocr = split ( p1 . p1 ) (p2 >< id)

-- Ex 5.
α :: Either a a -> (Bool, a)
α = either (\a -> (False, a)) (\a -> (True, a))
