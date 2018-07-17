/*
 * Math concept here:
 * ** parity of permutation **
 * 
 *  - parity: being even or odd
 *  - it is related to the number of inversions
 *  - if sum of inversions in sequence is even, it is called "even" permutation
 *  - else, it is called "odd" permutation
 * 
 * ex)
 *  sequence: [3, 1, 2]
 *  - 3 is smaller in index but bigger in value for 1 and 2.
 *  - the number of inversions is 2 -> even permutation
 * 
 *  sequence: [1, 3, 2]
 *  - 3 is smaller in index but bigger in value for 2.
 *  - the number of inversions is 1 -> odd permutation
 */
string larrysArray(vector<int> A)
{
  size_t k{A.size()};
  int inversions{0};

  for (int i = 0; i < k - 1; i++)
    for (int j = i + 1; j < k; j++)
      if (A[i] > A[j])
        inversions++;

  return inversions % 2 == 0 ? "YES" : "NO";
}