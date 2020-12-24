import qualified Control.Monad as CM

factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n-1)

eToTheXSeries :: Int -> Double -> Double
eToTheXSeries 0 _ = 1.0
eToTheXSeries n x = (x^n / (fromIntegral $ factorial n)) + eToTheXSeries (n-1) x

main :: IO()
main = do
  n <- readLn :: IO Int
  CM.forM_ [1..n] $ \n_itr -> do
    x <- readLn :: IO Double
    putStrLn $ show $ eToTheXSeries 9 x
