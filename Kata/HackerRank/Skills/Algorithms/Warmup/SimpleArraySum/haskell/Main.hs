import qualified Data.List          as DL
import           System.Environment
import           System.IO

simpleArraySum :: [Int] -> Int
simpleArraySum = sum

main :: IO()
main = do
  stdout     <- getEnv "OUTPUT_PATH"
  fptr       <- openFile stdout WriteMode
  arCount    <- readLn :: IO Int
  arTemp     <- getLine
  let ar     =  DL.map (read :: String -> Int) . words $ arTemp
  let result =  simpleArraySum ar
  hPutStrLn fptr $ show result
  hFlush fptr
  hClose fptr
