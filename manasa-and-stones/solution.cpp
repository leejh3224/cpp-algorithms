/*
 * What you should know is that although number of permutations for possible difference is 2^(n-1), 
 * your goal is to get only different values among them.
 * 
 * So if possible diffs are [2,3,3,4], all you have to return is [2,3,4].
 * 
 * Here is an example of getting an answer when n = 4, a = 4, b = 5.
 * 
 * 4 4 4 = 12 // a + a + a
 * 4 4 5 = 13 // a + a + b
 * 4 5 5 = 14 // a + b + b
 * 5 5 5 = 15 // b + b + b
 * 
 * You can find out that number of answers would be n and 
 * you can get those values by increasing the number of b in sum.
 * 
 * And you should be aware that answers must be sorted in ascending order and there are some edge cases like when n = 1 or a = b.
 * Here is solution for c++ users.
 */
vector<int> stones(int n, int a, int b)
{
  vector<int> answer;

  if (n == 1)
  {
    answer.push_back(0);
    return answer;
  }

  if (a == b)
  {
    answer.push_back((n - 1) * a);
    return answer;
  }

  for (int i = 0; i < n; i++)
  {
    int num_a = i;
    int num_b = n - i - 1;

    if (a < b)
    {
      num_a = n - i - 1;
      num_b = i;
    }

    answer.push_back(num_a * a + num_b * b);
  }

  return answer;
}