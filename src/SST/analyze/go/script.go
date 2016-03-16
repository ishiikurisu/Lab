package main

import "fmt"
import "os"

func main() {
	inlet, _ := os.Open(os.Args[1])
	stuff := ""
	_, shit := fmt.Fscanln(inlet, &stuff);
	
	defer inlet.Close()
	for shit != nil {
		fmt.Printf("- %#v\n", stuff)
		_, shit = fmt.Fscanln(inlet, &stuff)
	}
	fmt.Printf("FUCK: %#v\n", shit)
}