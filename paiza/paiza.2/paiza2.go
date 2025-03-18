package main

import (
	"fmt"
	"strings"
)

func main(){
s := "paiza proggraming"
result := strings.ReplaceAll(s, " " , "_" )
fmt.Println(result)
}


