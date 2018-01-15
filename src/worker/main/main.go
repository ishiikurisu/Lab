package main

import (
	"net/http"
	"fmt"
)

func main() {
	http.HandleFunc("/", hello)
	http.HandleFunc("/e2c", e2c)

	http.ListenAndServe(":3000", nil)
}

func hello(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Say hello to server!")
}

func e2c(w http.ResponseWriter, r *http.Request) {
	// TODO Think about how to load a HTML form with a file input
	// TODO Deal with the file input and write the output in the form of a separate file
}
