module Main where

-- Prompt: Implement a method that takes an integer and returns the string
--         "Fizz," "Buzz," or "FizzBuzz" depending on whether the number is
--         divisible by 3, 5, or both sans remainder.

fizzBuzz :: Int -> String
fizzBuzz n
  | mod n 15 == 0 = "FizzBuzz"
  | mod n 5  == 0 = "Buzz"
  | mod n 3  == 0 = "Fizz"
  | otherwise     = show n

main :: IO()
main = do
  putStrLn "Running tests.."
  let control00 = ["FizzBuzz","1","2","Fizz","4","Buzz","Fizz","7","8","Fizz"]
  let test00    = map fizzBuzz [0..9]
  putStrLn ("test 00 -> " ++ (show $ (control00 == test00)))
