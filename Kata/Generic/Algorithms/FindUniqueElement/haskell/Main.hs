import qualified Data.List as DL -- Is this cheating if it's in Base?

findUniqueElem :: [Int] -> [Int]
findUniqueElem = concat . filter (\x -> length x == 1) . DL.group . DL.sort

main :: IO()
main = do
  let test00 = [0,0,1,1,2,3,3,3]
  putStrLn $ show $ findUniqueElem test00
