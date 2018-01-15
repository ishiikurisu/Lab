package main

import (
	"net/http"
	"fmt"
)

func main() {
	http.HandleFunc("/", hello)

	http.ListenAndServe(":3000", nil)
}

func hello(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Say hello to server!")
}
