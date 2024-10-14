module Ficha2 (
    f,
    acronym,
    short
) where

import qualified Data.List as L
import Cp

-- Definitions
-- data X = B Bool | P (Bool, Int)

-- Ex 2.
f :: ((Bool, Bool), Bool) -> Bool
f = my_xor . (my_and >< id)
    where my_and = uncurry (&&)
          my_xor = uncurry (/=)

-- Ex 10.
acronym :: String -> String
acronym = map head                -- Manter o primeiro caracter de cada palavra
        . L.words                   -- Separar em palavras

short :: String -> String
short = uncurry ((++) . (++ " ")) -- Concatenar com espaço no meio
      . split head last           -- Manter a primeira e a última palavra
      . L.words                     -- Separar em palavras