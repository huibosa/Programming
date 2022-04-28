def list2strs(arr):
    for ch in arr:
        print(ch, end="")
    print()


def grid2graph(grid):
    rowCount = len(grid[0])
    for i in range(rowCount):
        line = [row[i] for row in grid]
        list2strs(line)


grid = [
    [".", ".", ".", ".", ".", "."],
    [".", "O", "O", ".", ".", "."],
    ["O", "O", "O", "O", ".", "."],
    ["O", "O", "O", "O", "O", "."],
    [".", "O", "O", "O", "O", "O"],
    ["O", "O", "O", "O", "O", "."],
    ["O", "O", "O", "O", ".", "."],
    [".", "O", "O", ".", ".", "."],
    [".", ".", ".", ".", ".", "."],
]

grid2graph(grid)
