package temp

import (
	"math"
)

func secondMax(nums []int) int {
	max := nums[0]
	maxIndex := 0

	for i, value := range nums {
		if value > max {
			maxIndex, max = i, value
		}
	}

	second := math.MinInt64
	for i, value := range nums {
		if value > second && i != maxIndex {
			second = value
		}
	}

	return second
}
