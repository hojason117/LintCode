package temp

func dotProduct(A []int, B []int) int {
	if len(A) != len(B) || len(A) == 0 {
		return -1
	}

	result := 0
	for i := 0; i < len(A); i++ {
		result += A[i] * B[i]
	}

	return result
}
