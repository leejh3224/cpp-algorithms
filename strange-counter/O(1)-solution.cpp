/*
 * O(1) solution
 * 
 * we can see that between each Seq2 (value),
 * value of first element is 3 * 2^(k-1).
 * and head of the Seq1 (time) is 2 less than the head of the Seq2.
 * 
 * so we can say that t + 2 = 3 * 2^(k-1)
 * such that, given t, k = floor(log2(t + 2) / 3))
 * 
 * value would be head_value - (t - head_time)
 */
long strangeCounter(long t)
{
  int k = floor(log2((t + 2) / 3));
  long head_value = 3 * pow(2, k);
  long head_time = head_value - 2;
  long time_elapsed = t - head_time;

  return head_value - time_elapsed;
}