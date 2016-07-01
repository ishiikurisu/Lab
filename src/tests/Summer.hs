import System.IO

summer :: [Integer] -> Integer
summer []    = 0
summer stuff = head stuff + summer(tail stuff)

splitString :: String -> Char -> [[String]]
splitString inlet param = splitStringLoop inlet param [ ]

splitStringLoop :: String -> Char -> [String] -> [[String]] -> [[String]]
splitStringLoop str delim box outlet = 
	if null str
		then box:outlet
		else if (head str) == delim
			then splitStringLoop (tail str) delim [ ] (box:outlet)
			else splitStringLoop (tail str) delim (box ++ [head str]) outlet

--readData :: [String]
--readData = do
--	contents <- getContents
--	 () contents

--main = putStrLn(summer(readData))
