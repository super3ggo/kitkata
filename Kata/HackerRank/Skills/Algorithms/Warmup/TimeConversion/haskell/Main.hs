import           System.Environment
import           System.IO

-- Write your code here.
timeConversion :: String -> String
timeConversion time
  | hour == 12 && meridiem == "AM" = "00:" ++ minSec
  | hour <  12 && meridiem == "PM" = show (hour + 12) ++ ":" ++ minSec
  | otherwise                      = id
  where
    hour     = read (take 2 time) :: Int
    meridiem = drop 8 time
    minSec   = take 5 $ drop 3 time
    id       = take 8 time

main :: IO()
main = do
  outputPath <- getEnv "OUTPUT_PATH"
  fptr       <- openFile outputPath WriteMode
  s          <- getLine
  let result =  timeConversion s
  hPutStrLn fptr result
  hFlush fptr
  hClose fptr
