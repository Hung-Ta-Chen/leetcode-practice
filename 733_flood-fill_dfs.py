class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if color == image[sr][sc]: return image
        m = len(image); n= len(image[0])
        color_o = image[sr][sc]
        stack = [(sr, sc)]
        while stack:
            i, j = stack.pop()
            image[i][j] = color
            if i != 0 and image[i-1][j] == color_o:
                stack.append((i-1, j))
            if i != m-1 and image[i+1][j] == color_o:
                stack.append((i+1, j))
            if j != 0 and image[i][j-1] == color_o:
                stack.append((i, j-1))
            if j != n-1 and image[i][j+1] == color_o:
                stack.append((i, j+1))
        return image
