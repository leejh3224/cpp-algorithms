/* 
  * think of finding smallest absolutePermutation as grouping numbers by k and then rotate the position between groups.
  * This means if n is not equally divisible by k or n divided by k is odd, it will fail meet the condition.
  * ex) n = 10, k = 1  
  *    (1 2) (3 4) (5 6) (7 8) (9 10)
  *    (2 1) (4 3) (6 5) (8 7) (10 9)
  * 
  * And usage of rotate function
  * 
  * rotate(first, middle, last)
  * 
  * first = begining iterator of range
  * middle = iterator of element that will become "new first"
  * last = iterator of last element - 1
  * 
  * 1 2 3 4 5 6 7 8 9 10
  *     |     |     |
  *   first  middle last
  * 
  * 1 2 6 7 8 3 4 5 9 10
  */
vector<int> absolutePermutation(int n, int k)
{
  vector<int> pos;
  vector<int> permutationNotExists{-1};

  for (int i = 1; i <= n; i++)
    pos.push_back(i);

  if (!k)
    return pos;

  if (n % k == 0 && (n / k) % 2 == 0)
  {
    for (int i = 1; i <= n / (2 * k); i++)
    {
      auto group_head = pos.begin() + 2 * k * (i - 1);
      rotate(group_head, group_head + k, group_head + 2 * k);
    }

    return pos;
  }

  return permutationNotExists;
}