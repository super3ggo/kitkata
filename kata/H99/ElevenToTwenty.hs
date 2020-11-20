-- Filename: ElevenToTwenty.hs
-- Note:     Solutions to H99 problems 11 through 20.

module H99.ElevenToTwenty
  ( myEncode'
  ) where

-- Note, some of these problems require loading the solutions from 1-10.hs.
import qualified H99.OneToTen as OTT

-- 11. Modified run-length encoding.
--     Modify the result of problem 10 in such a way that if an element has no
--     duplicates it is simply copied into the result list. Only elements with
--     duplicates are transferred as (N E) lists.
data MyEncoding a = Single a
                  | Multiple Int a
                  deriving (Eq, Show)

-- My hideous version.
myEncode' :: Eq a => [a] -> [MyEncoding a]
myEncode' xs = [if fst x == 1 then Single (snd x) else Multiple (fst x) (snd x) | x <- OTT.myEncode xs]

-- And their beautiful one.
myEncode'' :: Eq a => [a] -> [MyEncoding a]
myEncode'' = map helper . OTT.myEncode
  where
    helper (1,x) = Single x
    helper (n,x) = Multiple n x

-- 12. Decode a run-length encoded list. Given a run-length code list generated
--     as specified in problem 11. Construct its uncompressed version.
myDecode :: Eq a => [MyEncoding a] -> [a]
myDecode = concatMap helper
  where
    helper (Single x)     = [x]
    helper (Multiple n x) = take n $ repeat x

-- 13. Run-length encoding of a list (direct solution).
--     Implement the so-called run-length encoding data compression method
--     directly. I.e. don't explicitly create the sublists containing the
--     duplicates, as in problem 9, but only count them. As in problem P11,
--     simplify the result list by replacing the singleton lists (1 X) by X.

-- Unfortunately, you didn't manage to get this one.
encodeDirect :: (Eq a)=> [a] -> [MyEncoding a]
encodeDirect [] = []
encodeDirect (x:xs)
    | count==1  = (Single x):(encodeDirect xs)
    | otherwise = (Multiple count x):(encodeDirect rest)
    where
      (matched,rest) = span (==x) xs
      count          = 1 + (length matched)

-- 14. Duplicate the elements of a list.
myDup :: [a] -> [a]
myDup []     = []
myDup (x:xs) = x:x:(myDup xs)

-- Using the List Monad.
myDup' :: [a] -> [a]
myDup' xs = xs >>= (\x -> [x,x])

-- 15. Replicate the elements of a list a given number of times.
myReplicate :: [a] -> Int -> [a]
myReplicate [] _     = []
myReplicate (x:xs) n = (replicate n x) ++ (myReplicate xs n)

-- Again, using the List Monad.
myReplicate' :: [a] -> Int -> [a]
myReplicate' xs n = xs >>= replicate n

-- 16. Drop every N'th element from a list.
myDropEvery :: [a] -> Int -> [a]
myDropEvery xs 0 = xs
myDropEvery xs n = if length xs < n
                      then xs
                      else take (n-1) xs ++ myDropEvery (drop n xs) n

-- 17. Split a list into two parts; the length of the first part is given. Do
--     not use any predefined predicates.
mySplit :: [a] -> Int -> ([a],[a])
mySplit xs n = (take n xs, drop n xs)

-- 18. Extract a slice from a list. Given two indices, i and k, the slice is the
--     list containing the elements between the i'th and k'th element of the
--     original list (both limits included). Start counting the elements with 1.
mySlice :: [a] -> Int -> Int -> [a]
mySlice [] _ _ = []
mySlice xs 0 _ = xs
mySlice xs i k = if i >= k
                    then xs
                    else drop (i-1) $ take k xs

-- 19. Rotate a list N places to the left. Hint: Use the predefined functions
--     length and (++).
myRotate :: [a] -> Int -> [a]
myRotate xs n = drop (calc n) xs ++ take (calc n) xs
  where calc n = if n > 0
                   then n
                   else length xs + n

-- 20. Remove the K'th element from a list.
myRemoveK :: [a] -> Int -> (a,[a])
myRemoveK xs k = if k <= 0 || k > length xs
                    then error "OOB k!" -- Disgusting!
                    else (xs !! (k-1), take (k-1) xs ++ drop k xs)
