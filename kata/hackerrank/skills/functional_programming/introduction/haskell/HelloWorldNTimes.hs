helloWorldNTimes :: Int -> [String]
helloWorldNTimes n = replicate n "Hello World"

main :: IO()
main = do
  n <- readLn :: IO Int
  putStrLn $ unlines $ helloWorldNTimes n
