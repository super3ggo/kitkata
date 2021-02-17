isOdd :: Int -> Int -> Bool
isOdd i e = i `mod` 2 /= 0

f :: [Int] -> [Int]
f lst = [x | (i,x) <- zip [0..] lst, isOdd i x]

main :: IO()
main = do
  inputdata <- getContents
  mapM_ (putStrLn. show). f. map read. lines $ inputdata
