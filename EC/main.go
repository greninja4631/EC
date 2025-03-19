package main

import (
	"fmt"

	"github.com/greninja4631/EC/api/auth"
	"github.com/greninja4631/EC/api/cart"
	"github.com/greninja4631/EC/api/order"
	"github.com/greninja4631/EC/api/product"
)

func main() {
	fmt.Println("Starting the application...")

	// 認証処理
	auth.Login()

	// カートの処理
	cart.CartFunction()

	order.OrderFunction()

	product.ProductFunction()

	fmt.Println("Application finished successfully.")
}
