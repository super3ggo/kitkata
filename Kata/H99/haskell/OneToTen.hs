-- Filename: OneToTen.hs
-- Note:     Solutions to H99 problems 1 through 10.

module H99.OneToTen where

-- 1. Find the last element of a list.
getLast :: [a] -> a
getLast [x]    = x
getLast (x:xs) = getLast xs

-- 2. Find the last but one element of a list.
getPenultimate :: [a] -> a
getPenultimate [x,xs] = x
getPenultimate (x:xs) = getPenultimate xs

-- 3. Find the kth element of a list. The first element in the list is number 1.
getKth :: [a] -> Int -> a
getKth (x:_) 1  = x
getKth (_:xs) i = getKth xs (i - 1)

-- 4. Find the number of elements in a list.
mySize :: [a] -> Int
mySize []     = 0
mySize (x:xs) = 1 + mySize xs

-- 5. Reverse a list.
--    Incidentally, this is how Base defines reverse.
myReverse :: [a] -> [a]
myReverse []     = []
myReverse (x:xs) = myReverse xs ++ [x]

-- 6. Find out whether a list is a palindrome.
isPalindrome :: (Eq a) => [a] -> Bool
isPalindrome list = list == (myReverse list)

-- 7. Flatten a nested list structure. Transform a list, possibly holding lists
--    as elements into a `flat' list by replacing each list with its elements
--    (recursively).

-- They give you this type.
data NestedList a = Elem a | List [NestedList a]

myFlatten :: NestedList a -> [a]
myFlatten (Elem a)      = [a]
myFlatten (List (x:xs)) = myFlatten x ++ myFlatten (List xs)

-- 8. Eliminate consecutive duplicates of list elements. If a list contains
--    repeated elements they should be replaced with a single copy of the
--    element.  The order of the elements should not be changed.

compress :: Eq a => [a] -> [a]
compress []     = []
compress (x:xs) = x : (compress $ dropWhile (== x) xs)

-- The following is a solution they give, but I don't understand the pattern
-- matching going on here!
compress' :: Eq a => [a] -> [a]
compress' (x:xs@(y:_))
  | x == y    = compress xs
  | otherwise = x : compress xs
compress' xs = xs

-- 9. Pack consecutive duplicates of list elements into sublists. If a list
--    contains repeated elements they should be placed in separate sublists.
myPack :: (Eq a) => [a] -> [[a]]
myPack []     = []
myPack [x]    = [[x]]
myPack (x:xs) = let first = head $ myPack xs
                    rest  = tail $ myPack xs
                in if elem x first
                   then (x:first):rest
                   else [x]:(myPack xs)

-- 10. Run-length encoding of a list. Use the result of problem P09 to implement
--     the so-called run-length encoding data compression method. Consecutive
--     duplicates of elements are encoded as lists (N E) where N is the number
--     of duplicates of the element E.
myEncode :: Eq a => [a] -> [(Int,a)]
myEncode xs = [(length x, head x) | x <- myPack xs]
