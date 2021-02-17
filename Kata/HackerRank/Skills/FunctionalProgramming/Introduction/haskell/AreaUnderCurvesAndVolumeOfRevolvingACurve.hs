import Text.Printf (printf)

solve :: Double -> Double -> [Double] -> [Double] -> [Double]
solve l r a b = let coords = zip a b
                    step   = 0.001
                    xs     = [l, l+step..r]
                 in [ sum [(poly coords x) * step | x <- xs],          -- area
                      sum [pi * (poly coords x) ** 2 * step | x <- xs] -- volume
                    ]

poly :: [(Double,Double)] -> Double -> Double
poly coords x = sum [fst pair * x ** snd pair | pair <- coords]

main :: IO()
main = getContents >>= mapM_ (printf "%.1f\n")
  . (\[a, b, [l, r]] -> solve l r a b)
  . map (map read. words)
  . lines
