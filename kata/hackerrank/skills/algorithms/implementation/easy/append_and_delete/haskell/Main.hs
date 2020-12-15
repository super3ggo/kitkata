import System.Environment
import System.IO

-- Complete the appendAndDelete function below
data CanAppendAndDelete = Yes | No deriving Show

-- You need a k number of actions to cover at least the sum of deletions and
-- appendages required, and if you have a nonzero difference, two must evenly
-- divide it, i.e. you balance the appendages with deletions and vice versa. A
-- negative difference indicates that k actions will not sufficiently perform
-- the required number of operations.
appendAndDelete :: String -> String -> Int -> CanAppendAndDelete
appendAndDelete s t k = let totalLength = length s + length t
                            commonElems = length $ map fst $ takeWhile (uncurry (==)) $ zip s t
                            deletions   = length $ drop commonElems s
                            appendages  = length $ drop commonElems t
                            actions     = k - (deletions + appendages) -- cf note on top
                         in if k >= totalLength -- more than enough steps
                               then Yes
                               else calc actions
                         where calc actions
                                 | actions < 0          = No
                                 | actions `mod` 2 == 0 = Yes
                                 | otherwise            = No

main :: IO()
main = do
  stdout <- getEnv "OUTPUT_PATH"
  fptr <- openFile stdout WriteMode
  s <- getLine
  t <- getLine
  k <- readLn :: IO Int
  putStrLn "hello"
  let result = show $ appendAndDelete s t k
  hPutStrLn fptr result
  hFlush fptr
  hClose fptr
