-- Function defition
fib :: Integer -> Integer
fib x = if x < 2 then 1 else fib(x-1) + fib(x-2)

-- Turning stuff into readable data
beautify [] = ""
beautify (x:xs) = show(x) ++ " " ++ beautify(xs)

-- Main function
main = putStrLn(beautify(map fib [0..10]))