module Main where

-- Ran into issues getting main to compile from the HR template. Just test this
-- with GHCI 8.10.1 or higher for now. Meh.
plusMinus :: (Eq a, Fractional a, Ord a) => [a] -> [a]
plusMinus []   = []
plusMinus list = let calc  = fromIntegral . length
                     total = calc list
                     pos   = calc $ filter (> 0)  list
                     neg   = calc $ filter (< 0)  list
                     zero  = calc $ filter (== 0) list
                  in map (/ total) (pos:neg:[zero])

main :: IO()
main = do
  putStrLn "testing"
