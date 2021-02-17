import qualified Data.List as DL

-- Complete the countApplesAndOranges function below.
data FruitHit = FruitHit { applesHit :: Int
                         , orangesHit :: Int
                         } deriving Show

countApplesAndOranges :: Int -> Int -> Int -> Int -> [Int] -> [Int] -> FruitHit
countApplesAndOranges s t a b apples oranges =
  let applesHit  = calc a apples s t
      orangesHit = calc b oranges s t
   in FruitHit applesHit orangesHit
  where calc tree fruit s t = length $ filter (\x -> x >= s && x <= t) $ map (+tree) fruit

printFruitHit :: FruitHit -> IO()
printFruitHit fruit = do
  putStrLn $ id $ show $ applesHit fruit
  putStrLn $ id $ show $ orangesHit fruit

main :: IO()
main = do
  stTemp <- getLine
  let st = words stTemp
  let s = read (st !! 0) :: Int
  let t = read (st !! 1) :: Int

  abTemp <- getLine
  let ab = words abTemp
  let a = read (ab !! 0) :: Int
  let b = read (ab !! 1) :: Int

  mnTemp <- getLine
  let mn = words mnTemp
  let m = read (mn !! 0) :: Int
  let n = read (mn !! 1) :: Int

  applesTemp <- getLine
  let apples = DL.map (read :: String -> Int) . words $ applesTemp

  orangesTemp <- getLine
  let oranges = DL.map (read :: String -> Int) . words $ orangesTemp

  printFruitHit $ countApplesAndOranges s t a b apples oranges
