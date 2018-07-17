/*
 * Based on amansbhandari's answer.
 * 
 *  1   2   3   4   5
 * 100 100 
 *     100 100 100 100
 *     100 100
 * 
 * turns into this
 * 
 *  1   2   3   4   5
 * 100     -100
 *     100
 *          100    -100
 * 
 * How come this be possible?
 * 
 * Instead of add sum by column or in other words index,
 * we can just express them as maximum sum of unique k.
 * 
 * Detailed explanation:
 * At index 1, k1 is added. So our unique sum of k or what I'll call them, S is k1.
 * And at index 2, we're adding k2. It makes our S 200.
 * 
 * And what happens when we reach index 3?
 * Yeah, k1 is no longer there.
 * It is same as subtracting k1 from the sum.
 * However as newly added k3 becomes effective, we simply put 0 into our sum.
 * At this moment, S is 200.
 * 
 * What happens when we reach index 4?
 * Nothing happens because there is no newly added k. So we move onto the next and the last index 5.
 * 
 * At index 5, k3 is no longer avilable so our S becomes 100 (200 - 100).
 * 
 * And what is the maximum value for all that? Yeah, it's 200.
 * 
 * What is most useful thing is to think this problem as finding the maxium sum of unique k.
 * 
 */
long arrayManipulation(int n, vector<vector<int>> queries)
{
  vector<long> v(n + 1);

  for (const auto &query : queries)
  {
    long a{query[0]}, b{query[1]}, k{query[2]};
    v[a] += k;
    if (b + 1 <= n)
      v[b + 1] -= k;
  }

  long unique_k_sum{0};
  long max{0};

  for (int i = 1; i <= n; i++)
  {
    unique_k_sum += v[i];
    if (unique_k_sum > max)
      max = unique_k_sum;
  }

  return max;
}