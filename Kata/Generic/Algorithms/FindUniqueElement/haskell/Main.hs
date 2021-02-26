import qualified Data.List as DL -- Is this cheating if it's in Base?

--
-- Prompt: Given an array of integers, find the unique, i.e. non-duplicate,
--         elements.

--
-- Solution
--

findUniqueElem :: [Int] -> [Int]
findUniqueElem = concat . filter (\x -> length x == 1) . DL.group . DL.sort

--
-- Util
--

testResult :: Bool -> String -> String
testResult result testCase = if result == True
                             then testCase ++ " -> success"
                             else testCase ++ " -> failure"

--
-- Test(s)
--

main :: IO()
main = do
  putStrLn "Running tests.."
  let control00 = [2]
  let wild00    = findUniqueElem [0,0,1,1,2,3,3,3]
  putStrLn $ testResult (control00 == wild00) "test00"
