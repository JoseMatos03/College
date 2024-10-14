{-# OPTIONS_GHC -Wno-type-defaults -Wno-unused-imports #-}

module Main (main) where

import Cp
import Ficha2
import Ficha3

-- Execute exercices from Ficha2
main :: IO ()
main = do
  putStrLn ""
  putStrLn "--------- Ficha 2 --------"
  putStrLn "Ex 2."
  print $ f ((True, True), True)
  print $ f ((True, False), True)
  putStrLn ""
  putStrLn "Ex 10."
  print $ acronym "Jose Rodrigo Ferreira Matos"
  print $ short "Jose Rodrigo Ferreira Matos"
  putStrLn "----- End of Ficha 2 -----"
  putStrLn ""
-- Execute exercices from Ficha3
  putStrLn ""
  putStrLn "--------- Ficha 3 --------"
  putStrLn "Ex 2."
  print $ my_assocr (("Hello World", 10), False)
  putStrLn ""
  putStrLn "Ex 4."
  print $ undistr (Left ("CP", True) :: Either (String, Bool) (String, Bool))
  print $ undistr (Right ("LEI", 1) :: Either (String, Integer) (String, Integer))
  print $ distr (undistr (Left ("CP", True) :: Either (String, Bool) (String, ())))
  putStrLn ""
  putStrLn "Ex 5."
  print $ α (i1 True)
  print $ α (i2 False)
  putStrLn "----- End of Ficha 3 -----"
  putStrLn ""
