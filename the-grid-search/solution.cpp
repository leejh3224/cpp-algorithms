/*
 * The idea is simple.
 * 1. loop through the given area (R-r, C-c)
 * 2. compare substring of the grid with pattern line by line
 * 3. if there was match, check the size of matched area
 * 4. if it is same as that of the pattern, then we can say it matches
 * 
 * my mistake
 * 1. always use while if you don't know when to end the loop
 * 2. range is always important (R-r, C-c)
 */
string gridSearch(vector<string> G, vector<string> P)
{
  size_t R{G.size()};
  size_t C{G[0].size()};
  size_t r{P.size()};
  size_t c{P[0].size()};

  for (int i = 0; i <= R - r; i++)
    for (int j = 0; j <= C - c; j++)
    {
      int p = 0, k = i;

      while (G[k].substr(j, c) == P[p])
      {
        if (k - i + 1 == r)
          return "YES";

        k++, p++;
      }
    }

  return "NO";
}