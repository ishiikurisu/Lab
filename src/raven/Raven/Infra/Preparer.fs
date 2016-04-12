#light
module Infra.Preparer

open System.IO
open System.Collections.Generic
open System.Linq

let file2strings(input: string): string[] =
    let inlet = new StreamReader(input)
    let rec loop(line: string, box: 'string) =
        if line.Equals(null) then 
            box 
        else 
            loop(inlet.ReadLine(), Seq.append(box, {line}))
    loop(inlet.ReadLine(), new string[])

// GetPaths(@".\assets\config\assets\versions.txt")
let GetPaths(input: string) =
    input
    |> file2strings
    |> Seq.map(fun line -> line.Split(' ').GetValue(0))

let GetTests(input: string) =
    input
    |> file2strings
    |> Seq.map(fun line -> 
        line.Split(' ')
        |> Aggregate(fun (acc, it) -> acc + it))

