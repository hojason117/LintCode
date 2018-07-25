package temp

func isToeplitzMatrix(matrix [][]int) bool {
	width := len(matrix[0])
	height := len(matrix)

	for i := width - 1; i >= 0; i-- {
		value := matrix[0][i]
		x, y := 0, i
		for x <= height-1 && y <= width-1 {
			if matrix[x][y] != value {
				return false
			}
			x++
			y++
		}
	}
	if height > 1 {
		for i := 1; i < height; i++ {
			value := matrix[i][0]
			x, y := i, 0
			for x <= height-1 && y <= width-1 {
				if matrix[x][y] != value {
					return false
				}
				x++
				y++
			}
		}
	}

	return true
}
