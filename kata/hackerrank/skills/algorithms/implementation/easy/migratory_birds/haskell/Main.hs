module Main where

import qualified Data.List          as DL
import qualified Data.Map           as DM
import qualified Data.Text          as DT
import           System.Environment
import           System.IO

-- Complete the migratoryBirds function below.
migratoryBirds :: [Int] -> Int
migratoryBirds arr = let common =
                             reverse
                           $ DL.sortBy (\(_,a) (_,b) -> compare a b)
                           $ frequency arr
                         first  = common !! 0
                         second = common !! 1
                     in if snd first == snd second
                           then fst second
                           else fst first

-- Helper method you stole from the Internet!
frequency :: (Ord a) => [a] -> [(a, Int)]
frequency xs = DM.toList (DM.fromListWith (+) [(x, 1) | x <- xs])

lstrip :: String -> String
lstrip = DT.unpack . DT.stripStart . DT.pack
rstrip :: String -> String
rstrip = DT.unpack . DT.stripEnd . DT.pack

main :: IO()
main = do
  stdout <- getEnv "OUTPUT_PATH"
  fptr <- openFile stdout WriteMode
  arrCountTemp <- getLine
  let arrCount = read $ lstrip $ rstrip arrCountTemp :: Int
  arrTemp <- getLine
  let arr = DL.map (read :: String -> Int) . DL.words $ rstrip arrTemp
  let result = migratoryBirds arr
  hPutStrLn fptr $ show result
  hFlush fptr
  hClose fptr
