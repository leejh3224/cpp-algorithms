/*
 * simplest approach
 * but given max input size 10^12, it times out.
 */
long strangeCounter(long t)
{
  long v{3};
  long prev_v{v};

  for (size_t i = 1; i < t; i++)
  {
    if (--v <= 0)
    {
      v = 2 * prev_v;
      prev_v = v;
    }
  }

  return v;
}