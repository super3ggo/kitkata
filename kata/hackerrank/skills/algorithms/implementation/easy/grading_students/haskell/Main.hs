import qualified Data.List          as DL
import qualified Data.Text          as DT
import           System.Environment
import           System.IO

-- Complete the 'gradingStudents' function below. Write your code here
gradingStudents :: [Int] -> [Int]
gradingStudents grades = map calc grades
  where calc n = if diffTo5 < 3 && n >= 38
                    then n + diffTo5
                    else n
                      where diffTo5 = 5 - (n `mod` 5)

lstrip = DT.unpack . DT.stripStart . DT.pack
rstrip = DT.unpack . DT.stripEnd   . DT.pack

readMultipleLinesAsStringArray :: Int -> IO [String]
readMultipleLinesAsStringArray 0 = return []
readMultipleLinesAsStringArray n = do
  line <- getLine
  rest <- readMultipleLinesAsStringArray(n - 1)
  return (line : rest)

main :: IO()
main = do
  stdout          <- getEnv "OUTPUT_PATH"
  fptr            <- openFile stdout WriteMode
  gradesCountTemp <- getLine

  let gradesCount = read $ lstrip $ rstrip gradesCountTemp :: Int

  gradesTemp <- readMultipleLinesAsStringArray gradesCount

  let grades = DL.map (read :: String -> Int) gradesTemp
  let result = gradingStudents grades

  hPutStrLn fptr $ DL.intercalate "\n" $ DL.map (\x -> show x) $ result
  hFlush fptr
  hClose fptr
