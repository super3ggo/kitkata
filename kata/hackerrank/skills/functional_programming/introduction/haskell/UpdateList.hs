f :: [Int] -> [Int]
f arr = let update n = if n < 0
                          then n * (-1)
                          else n
         in map update arr

main :: IO()
main = do
  inputdata <- getContents
  mapM_ putStrLn $ map show $ f $ map (read :: String -> Int) $ lines inputdata
