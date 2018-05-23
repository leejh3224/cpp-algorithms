/*
 * At first glance, forming magic square looks like an easy problem,
 * however, in order to solve this problem you should know some basic properties of magic squares
 * First, center of 3 x 3 magic square is always 5.
 * Second, each row, column, diagonal sums up to 15 in 3 x 3 magic square.
 * To get an answer, we should find all possible magic squares (there are 9 of them)
 * And then, compare the difference of each cell between our given vecotor s and each of the hard coded magic square
 * find the minimum value of difference!
 */

int formingMagicSquare(vector<vector<int>> s)
{
  // hard coded magic squares
  int magicSquares[8][3][3]{
      {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
      {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
      {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
      {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
      {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
      {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
      {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
      {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}};

  // set it to large number
  int answer{5000};

  for (int i = 0; i < 8; i++)
  {
    // temporary value to store sum of differences
    int sumDiff{0};
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 3; k++)
        sumDiff += abs(magicSquares[i][j][k] - s[j][k]);
    }

    // compare the sumDiff and answer to get smaller value
    answer = min(answer, sumDiff);
  }

  return answer;
}