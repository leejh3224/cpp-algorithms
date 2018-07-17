/*
 * Based on Rys23's answer
 * 
 * 1. findPlus for every grid cells that is not 'B'
 * 2. and compare each pluses that if they overlaps each other (use bitwise and operation)
 * 3. get the product of area
 * 
 * Lessons learned:
 *  1. Bitset container
 *    - you can't use bitset container unless you have constexpr that can be set befor runtime.
 *    - if you want to do it on runtime use vector<bool> instead
 *    - or initialize huge bitset that is capable of accepting biggest input
 *  2. nested vectors
 *    - you'll get segmetation fault when you're using nested vectors without specifying the size of outermost vector.
 *    - do this: vector<vector<bool> v(size);
 *  3. need to calculate overlapped area?
 *    - use bitwise operation!
 *  
 */
class Plus
{
private:
  int m_x;
  int m_y;
  int m_stretch{0};
  int m_area{1};

public:
  Plus(int x, int y) : m_x{x}, m_y{y}
  {
  }

  Plus(int x, int y, int stretch, int area) : m_x{x}, m_y{y}, m_stretch{stretch}, m_area{area}
  {
  }

  // getters
  int get_x()
  {
    return m_x;
  }

  int get_y()
  {
    return m_y;
  }

  int get_stretch()
  {
    return m_stretch;
  }

  int get_area()
  {
    return m_area;
  }

  void grow();

  bool overlaps(Plus *p2, int n, int m);
};

void Plus::grow()
{
  m_stretch++;
  m_area += 4;
}

void setPlusBits(vector<vector<bool>> &bits, int x, int y, int stretch, int n, int m)
{
  int k{-1};

  while (++k <= stretch)
  {
    if (y + k < n)
      bits[y + k][x] = true;

    if (y - k >= 0)
      bits[y - k][x] = true;

    if (x + k < m)
      bits[y][x + k] = true;

    if (x - k >= 0)
      bits[y][x - k] = true;
  }
}

bool Plus::overlaps(Plus *p2, const int n, const int m)
{
  int p2_x{p2->get_x()};
  int p2_y{p2->get_y()};
  int p2_stretch{p2->get_stretch()};

  // 비트 & -> 0 겹치 x, 1 -> 겹치 yes
  vector<vector<bool>> p1_bits(n);
  vector<vector<bool>> p2_bits(n);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      p1_bits[i].push_back(false);
      p2_bits[i].push_back(false);
    }

  setPlusBits(p1_bits, m_x, m_y, m_stretch, n, m);
  setPlusBits(p2_bits, p2_x, p2_y, p2_stretch, n, m);

  int overlapped_area{0};

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      overlapped_area += static_cast<int>(p1_bits[i][j]) & static_cast<int>(p2_bits[i][j]);

  return overlapped_area > 0;
}

void findPlus(int x, int y, int n, int m, vector<string> grid, vector<Plus *> &pluses)
{
  Plus *plus = new Plus{x, y};

  int k{1};

  while (x - k >= 0 && grid[y][x - k] != 'B' &&
         x + k < m && grid[y][x + k] != 'B' &&
         y - k >= 0 && grid[y - k][x] != 'B' &&
         y + k < n && grid[y + k][x] != 'B')
  {
    pluses.push_back(new Plus{plus->get_x(), plus->get_y(), plus->get_stretch(), plus->get_area()});
    plus->grow();
    k++;
  }
  pluses.push_back(plus);
}

int twoPluses(vector<string> grid)
{
  size_t n{grid.size()};
  size_t m{grid[0].size()};

  vector<Plus *> pluses;

  for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++)
      if (grid[y][x] == 'G')
        findPlus(x, y, n, m, grid, pluses);

  int max{0};

  for (int i = 0; i < pluses.size() - 1; i++)
    for (int j = i + 1; j < pluses.size(); j++)
    {
      Plus *p1 = pluses[i];
      Plus *p2 = pluses[j];

      int product{p1->get_area() * p2->get_area()};

      if (product > max && !p1->overlaps(p2, n, m))
        max = product;
    }

  return max;
}