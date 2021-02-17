solve :: [Int] -> [Int] -> Int
solve as bs = length
                $ filter (\x -> bsGcd `mod` x == 0)
                $ takeWhile (<= bsGcd)
                $ map (* asLcm) [1..]
              where asLcm = foldl1 lcm as
                    bsGcd = foldl1 gcd bs

readListInt :: IO [Int]
readListInt = do
  line <- getLine
  return $ map read $ words line

main :: IO()
main = do
  [n,m] <- readListInt          -- don't actually need these
  as    <- readListInt
  bs    <- readListInt
  putStrLn $ show $ solve as bs
