import qualified Data.List          as DL
import           System.Environment
import           System.IO

-- Complete the howManyGames function below.
howManyGames :: Int -> Int -> Int -> Int -> Int
howManyGames p d m s = let prices = [p,(p-d)..m] ++ [m,m..]
                        in length $ last $ takeWhile (\x -> sum x <= s) $ DL.inits prices -- inits is key, hoogle it

main :: IO()
main = do
  stdout <- getEnv "OUTPUT_PATH"
  fptr <- openFile stdout WriteMode
  pdmsTemp <- getLine
  let pdms = words pdmsTemp
  let p = read (pdms !! 0) :: Int
  let d = read (pdms !! 1) :: Int
  let m = read (pdms !! 2) :: Int
  let s = read (pdms !! 3) :: Int
  putStrLn "hello"
  let answer = howManyGames p d m s
  hPutStrLn fptr $ show answer
  hFlush fptr
  hClose fptr
