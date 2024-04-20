package leetcode

func maxProfit(prices []int) int {
	if len(prices) < 2 {
		return 0
	}

	buy := 0
	sell := 1
	result := 0
	tempSellResult := 0

	for sell < len(prices) {
		tempSellResult = prices[sell] - prices[buy]

		if tempSellResult < 0 {
			buy = sell
		} else if tempSellResult > result {
			result = tempSellResult
		}

		sell++
	}

	return result
}
