/*
 * What I learned:
 * 
 * 1. stoi vs atoi
 * 
 * There are 2 differences between these two functions.
 *   - stoi accepts "string" but atoi accpets "c style string (const char*)".
 *   - atoi returns "0" if there was error while stoi returns "invalid argument error".
 * so, it's better to use stoi over atoi.
 * 
 * 2. char vs string
 * 
 * In c/c++, char notations are '' (sigle quote) and string notations are "" (double quote).
 * And if you're accessing a part of a string using int index, then you're accessing char, not string.
 * ex) string s = "hello world!"; char h = s[0];
 * 
 * And if you try to access "out of bound" characters in string, it would print � which means invalid utf8 character.
 * Char type is a number, so you don't have to convert them into int before you compare them.
 * ('6' < '7' is true)
 *    
 * 3. check input type of the problem
 * 
 * I thought "grid" was vector of vector<int> but actually it was vector of string.
 * Of course, it took a while to find out what really was a problem and it made debugging much harder.
 * So before you start coding, you should always check format of input and output that is required.
 */
vector<string> cavityMap(vector<string> grid)
{
  vector<string> answer = grid;

  int n = grid.size();

  // except elements at border of grid
  for (int i = 1; i < n - 1; i++)
    for (int j = 1; j < n - 1; j++)
    {
      char cell = grid[i][j];
      char east = grid[i][j + 1];
      char west = grid[i][j - 1];
      char north = grid[i - 1][j];
      char south = grid[i + 1][j];

      // strictly deeper than all the adjacent edges
      bool isCavity = cell > east && cell > west && cell > north && cell > south;

      if (isCavity)
        answer[i][j] = 'X';
    }

  return answer;
}
