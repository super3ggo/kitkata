staircase :: Int -> IO()
staircase n
  | n <= 0 || n > 100 = putStrLn "Input OOB!"
  | otherwise         = let stair x = replicate x '#'
                            space x = replicate x ' '
                            draw  x = space (n-x) ++ stair x
                         in mapM_ putStrLn $ id $ map draw [1..n]

main :: IO()
main = do
  n <- readLn :: IO Int
  staircase n
