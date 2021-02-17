import qualified Data.List          as DL
import qualified Data.Text          as DT
import           System.Environment
import           System.IO

-- Write your code here
birthdayCakeCandles :: [Int] -> Int
birthdayCakeCandles []   = 0
birthdayCakeCandles list = let max = head $ reverse $ DL.sort list
                            in length $ filter (== max) list

lstrip = DT.unpack . DT.stripStart . DT.pack
rstrip = DT.unpack . DT.stripEnd   . DT.pack

main :: IO()
main = do
  putStrLn "hello"
  stdout           <- getEnv "OUTPUT_PATH"
  fptr             <- openFile stdout WriteMode
  candlesCountTemp <- getLine
  let candlesCount = read $ lstrip $ rstrip candlesCountTemp :: Int
  candlesTemp      <- getLine
  let candles      = DL.map (read :: String -> Int) . DL.words $ rstrip candlesTemp
  let result       = birthdayCakeCandles candles
  hPutStrLn fptr $ show result
  hFlush fptr
  hClose fptr
