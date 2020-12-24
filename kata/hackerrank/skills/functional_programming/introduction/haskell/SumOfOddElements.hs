f :: [Int] -> Int
f arr = sum $ filter (\x -> x `mod` 2 /= 0) arr

main :: IO()
main = do
  inputdata <- getContents
  putStrLn $ show $ f $ map (read :: String -> Int) $ lines inputdata
