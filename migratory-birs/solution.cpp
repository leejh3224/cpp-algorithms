using namespace std;

int migratoryBirds(int n, vector<int> ar)
{
  // used enum to represent the type of birdss
  enum BirdTypes
  {
    A,
    B,
    C,
    D,
    E,
    MAX_BIRDS,
  };

  // can use std::array
  int birdsFrequency[5]{0};

  for (int i = 0; i < n; i++)
  {
    if (ar[i] == A + 1)
      birdsFrequency[A] += 1;
    else if (ar[i] == B + 1)
      birdsFrequency[B] += 1;
    else if (ar[i] == C + 1)
      birdsFrequency[C] += 1;
    else if (ar[i] == D + 1)
      birdsFrequency[D] += 1;
    else if (ar[i] == E + 1)
      birdsFrequency[E] += 1;
  }

  // must return value of pointer(max_element returns int*)
  return *max_element(birdsFrequency, birdsFrequency + 5);
}