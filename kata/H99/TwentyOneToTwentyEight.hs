-- Filename: TwentyOneToTwentyEight.hs
-- Note:     Solutions to H99 problems 21 through 28.

module H99.TwentyOneToTwentyEight where

-- Note, some of these problems reuse previous solutions.
import qualified H99.ElevenToTwenty as ETT

-- 21. Insert an element at a given position into a list.
myInsert :: a -> [a] -> Int -> [a]
myInsert x xs i = if i < 0 || i > length xs
                     then xs
                     else take (i+1) xs ++ [x] ++ drop (i+1) xs

-- Using mySplit from ElevenToTwenty module
myInsert' :: a -> [a] -> Int -> [a]
myInsert' x xs i = if i < 0 || i > length xs
                      then xs
                      else let split = ETT.mySplit xs i
                           in fst split ++ [x] ++ snd split

-- 22. Create a list containing all integers within a given range.
-- This seems like cheating..
myRange :: (Enum a, Num a, Ord a) => a -> a -> [a]
myRange i j
  | i > j     = [j..i]
  | i == i    = [i]
  | otherwise = [i..j]

-- Better?
myRange' :: (Enum a, Num a, Ord a) => a -> a -> [a]
myRange' i j
  | i > j      = reverse $ myRange' j i
  | i == j     = [j]                    -- need j to exit recursion in otherwise
  | otherwise  = i:(myRange' (i+1) j)

-- 23. Extract a given number of randomly selected elements from a list.
--     Skipped. System.Random not part of Base.

-- 24. Lotto: Draw N different random numbers from the set 1..M.
--     Skipped. System.Random not part of Base.

-- 25. Generate a random permutation of the elements of a list.
--     Skipped. System.Random not part of Base.

-- 26. Generate the combinations of K distinct objects chosen from the N
--     elements of a list In how many ways can a committee of 3 be chosen from a
--     group of 12 people? We all know that there are C(12,3) = 220
--     possibilities (C(N,K) denotes the well-known binomial coefficients). For
--     pure mathematicians, this result may be great. But we want to really
--     generate all the possibilities in a list.
myCombo :: Int -> [a] -> [[a]]
myCombo 0 _      = [[]]
myCombo _ []     = []
myCombo n (x:xs) = (map (x:) (myCombo (n-1) xs)) ++ (myCombo n xs)

-- 27. Group the elements of a set into disjoint subsets.
--
--     a) In how many ways can a group of 9 people work in 3 disjoint subgroups
--     of 2, 3 and 4 persons? Write a function that generates all the
--     possibilities and returns them in a list.
--
--     b) Generalize the above predicate in a way that we can specify a list of
--     group sizes and the predicate will return a list of groups.

-- 28. Sorting a list of lists according to length of sublists
--
--     a) We suppose that a list contains elements that are lists themselves.
--     The objective is to sort the elements of this list according to their
--     length.  E.g. short lists first, longer lists later, or vice versa.
--
--     b) Again, we suppose that a list contains elements that are lists
--     themselves. But this time the objective is to sort the elements of this
--     list according to their length frequency; i.e., in the default, where
--     sorting is done ascendingly, lists with rare lengths are placed first,
--     others with a more frequent length come later.
