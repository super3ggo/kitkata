import qualified Control.Monad      as CM
import           System.Environment
import           System.IO

-- Complete the saveThePrisoner function below.
-- Attempt 1
-- Pretty sure this works, and it's way easier to understand. But it's too slow
-- because you abuse replicate. Heh.
saveThePrisonerSlow :: Int -> Int -> Int -> Int
saveThePrisonerSlow n m s = let replications   = (m `quot` n) + 1
                                prisonerCircle = concat $ replicate replications [1..n]
                             in (drop (s-1) prisonerCircle) !! (m-1)

-- Attempt 2
-- Port of the same algorithm you did in C++.
saveThePrisoner :: Int -> Int -> Int -> Int
saveThePrisoner n m s = let count    = if m `mod` n == 0 then (n-1) else ((m `mod` n) - 1) -- clever bit here
                            prisoner = s + count
                         in if prisoner >= n
                               then if (prisoner-n) == 0
                                       then n
                                       else prisoner-n
                               else prisoner

main :: IO()
main = do
  stdout <- getEnv "OUTPUT_PATH"
  fptr <- openFile stdout WriteMode
  t <- readLn :: IO Int
  CM.forM_ [1..t] $ \t_itr -> do
    nmsTemp <- getLine
    let nms = words nmsTemp
    let n = read (nms !! 0) :: Int
    let m = read (nms !! 1) :: Int
    let s = read (nms !! 2) :: Int
    let result = saveThePrisoner n m s
    -- let result = "foo"
    hPutStrLn fptr $ show result
  hFlush fptr
  hClose fptr
