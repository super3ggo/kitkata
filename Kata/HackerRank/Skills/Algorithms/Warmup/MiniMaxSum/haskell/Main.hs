import qualified Data.List as DL

miniMaxSum :: [Int] -> (Int,Int)
miniMaxSum [] = (0,0)
miniMaxSum xs = let sorted = DL.sort xs
                    max    = sum $ tail sorted
                    min    = sum $ reverse $ tail $ reverse sorted
                 in (min,max)

showTuple :: Show a => (a,a) -> String
showTuple tuple = (show $ fst tuple) ++ " " ++ (show $ snd tuple)

main :: IO()
main = do
  arrTemp <- getLine
  let arr    = DL.map (read :: String -> Int) . words $ arrTemp
  let result = miniMaxSum arr
  putStrLn $ id $ showTuple result
