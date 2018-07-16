/*
 * Learned:
 * 1. Segmentation fault happens when:
 *  - type of some elements in vector is wrong
 *  - accessing invalid index
 * 
 * 2. Initializing multiple variables with same type
 *  - you should initialize all variables, you can't omit some of them like in js
 *  - ex) int x {3};
 *        int y {x}, z{x};
 * 
 * O(n^2) solution
 * 
 * There are four different state of the grid.
 * 
 * A: Initial state where n = 0 or 1
 * B: Full of bombs where n = 2, 4, 6, 8 ...
 * C: Pattern A where n = 3, 7, 11 ...
 * D: Pattern B where n = 5, 9, 13 ...
 * 
 * It is much harder to find pattern in small grids.
 * It is recommended to think about big grids like 10 x 10 grid.
 * 
 * And one more lesson I learned:
 * if the problem is related to find patterns, 
 * you should always think about the big one first.
 * patterns are more easily found when the input size is big.
 */
void fillGridWithBombs(vector<string> &grid)
{
  size_t r{grid.size()};
  size_t c{grid[0].size()};

  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      grid[i][j] = 'O';
}

void detonate(vector<string> &grid, vector<string> &previous_grid)
{
  size_t r{grid.size()};
  size_t c{grid[0].size()};

  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
    {
      if (previous_grid[i][j] == 'O')
      {
        grid[i][j] = '.';

        if (i + 1 < r)
          grid[i + 1][j] = '.';

        if (i - 1 >= 0)
          grid[i - 1][j] = '.';

        if (j + 1 < c)
          grid[i][j + 1] = '.';

        if (j - 1 >= 0)
          grid[i][j - 1] = '.';
      }
    }
}

vector<string> bomberMan(int n, vector<string> grid)
{
  vector<string> initial_grid{grid}, full_of_bombs{grid}, pattern_a;

  fillGridWithBombs(grid);
  fillGridWithBombs(full_of_bombs);

  detonate(grid, initial_grid);

  pattern_a = grid;

  fillGridWithBombs(grid);
  detonate(grid, pattern_a);

  int k{n % 4};

  if (n == 1)
    return initial_grid;

  if (k == 0 || k == 2)
    return full_of_bombs;
  else if (k == 3)
    return pattern_a;

  return grid;
}
