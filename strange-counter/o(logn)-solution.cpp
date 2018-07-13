/*
 * O(logn) solution.
 * 
 * we can think of this counter as two sequences.
 * 
 * Seq1 -> time
 * Seq2 -> value
 * each Seq has k sub sequences.
 * 
 * first, we store the head of the Seq1.
 * Then, compare time_elapsed with head.
 * if time_elapsed is bigger than head,
 * it means index of the seq k is differnt,
 * so subtract head from time_elapsed and doubles the head value
 * if time_elapsed is no longer bigger than head,
 * we can get value by head - time_elapsed + 1.
 */
long strangeCounter(long t)
{
  long head{3};
  int time_elapsed = t;

  while (time_elapsed > head)
  {
    time_elapsed -= head;
    head *= 2;
  }

  return head - time_elapsed + 1;
}