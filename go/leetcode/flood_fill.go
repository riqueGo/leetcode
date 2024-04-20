package leetcode

func dfsFill(image [][]int, sr, sc, newColor, initialColor int) {
	if sr < 0 || sc < 0 || sr >= len(image) || sc >= len(image[0]) || image[sr][sc] != initialColor {
		return
	}
	image[sr][sc] = newColor
	dfsFill(image, sr-1, sc, newColor, initialColor)
	dfsFill(image, sr+1, sc, newColor, initialColor)
	dfsFill(image, sr, sc-1, newColor, initialColor)
	dfsFill(image, sr, sc+1, newColor, initialColor)
}

func floodFill(image [][]int, sr, sc int, newColor int) [][]int {
	if newColor != image[sr][sc] {
		dfsFill(image, sr, sc, newColor, image[sr][sc])
	}
	return image
}
