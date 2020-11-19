-- Filename: ElevenToTwenty.hs
-- Note:     Solutions to H99 problems 11 through 20.
--

module H99.ElevenToTwenty
  ( myEncode'
  ) where

-- Note, some of these problems require loading the solutions from 1-10.hs.
import qualified H99.OneToTen as OTT

-- 11. Modified run-length encoding.
--     Modify the result of problem 10 in such a way that if an element has no
--     duplicates it is simply copied into the result list. Only elements with
--     duplicates are transferred as (N E) lists.
data MyEncoding' a = Single a
                   | Multiple Int a
                   deriving (Eq, Show)

-- My hideous version.
myEncode' :: Eq a => [a] -> [MyEncoding' a]
myEncode' xs = [if fst x == 1 then Single (snd x) else Multiple (fst x) (snd x) | x <- OTT.myEncode xs]

-- And their beautiful one.
myEncode'' :: Eq a => [a] -> [MyEncoding' a]
myEncode'' = map helper . OTT.myEncode
           where
             helper (1,x) = Single x
             helper (n,x) = Multiple n x
