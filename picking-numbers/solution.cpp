int pickingNumbers(vector<int> a)
{
  map<int, int> m;

  // initialize map with 100 keys
  for (int i = 1; i < 100; i++)
    m[i] = 0;

  // get occurence from vector
  for (auto &el : a)
    m[el]++;

  int sumSequence{0};
  for (auto it = m.begin(); it != m.end(); it++)
    // we can compare current sum of sequence to next sum of sequence
    // as we set 1-100 as a key of our map m,
    // we don't have to care about whether absolute difference of two keys is 1
    sumSequence = max(sumSequence, it->second + next(it, 1)->second);

  return sumSequence;
}