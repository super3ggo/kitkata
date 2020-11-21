{-# LANGUAGE DuplicateRecordFields, FlexibleInstances, UndecidableInstances #-}

module Main where

import           Control.Monad
import           Data.Array
import           Data.Bits
import qualified Data.List          as DL
import           Data.List.Split
import           Data.Set
import           Data.Text
import           Debug.Trace
import           System.Environment
import           System.IO
import           System.IO.Unsafe

-- Complete the compareTriplets function below.
data Score = Alice
           | Bob
           | Tie
           deriving (Eq, Show)

compareTriplets :: (Ord a, Num a) => [a] -> [a] -> [Int]
compareTriplets [] _  = []
compareTriplets _  [] = []
compareTriplets xs ys = let scores = DL.map calcScores $ DL.zipWith (\x y -> (x,y)) xs ys
                            alice  = Prelude.length $ Prelude.filter (==Alice) scores
                            bob    = Prelude.length $ Prelude.filter (==Bob) scores
                         in alice:[bob]
                        where
                          calcScores (a,b)
                            | a > b     = Alice
                            | a < b     = Bob
                            | otherwise = Tie

lstrip = Data.Text.unpack . Data.Text.stripStart . Data.Text.pack
rstrip = Data.Text.unpack . Data.Text.stripEnd . Data.Text.pack

main :: IO()
main = do
    stdout <- getEnv "OUTPUT_PATH"
    fptr <- openFile stdout WriteMode

    aTemp <- getLine

    let a = DL.map (read :: String -> Int) . DL.words $ rstrip aTemp

    bTemp <- getLine

    let b = DL.map (read :: String -> Int) . DL.words $ rstrip bTemp

    let result = compareTriplets a b

    hPutStrLn fptr $ DL.intercalate " " $ DL.map (\x -> show x) $ result

    hFlush fptr
    hClose fptr
