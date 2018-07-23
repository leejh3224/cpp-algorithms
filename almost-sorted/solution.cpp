#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void findPeaksAndValleys(vector<int> &v, vector<int> &peaks, vector<int> &valleys)
{
  size_t n{v.size()};
  for (int i = 1; i < n - 1; i++)
  {
    if (v[i - 1] < v[i] && v[i + 1] < v[i])
      peaks.push_back(i + 1);
    if (v[i - 1] > v[i] && v[i + 1] > v[i])
      valleys.push_back(i + 1);
  }
}

void almostSorted(vector<int> v)
{
  size_t n{v.size()};

  vector<int> peaks;
  vector<int> valleys;
  findPeaksAndValleys(v, peaks, valleys);

  string op;

  if (peaks.empty() && valleys.empty())
  {
    cout << "yes\n";

    bool isDescOrder{v[0] > v[n - 1]};

    if (isDescOrder)
    {
      op = n <= 3 ? "swap" : "reverse";
      cout << op << " 1 " << n << "\n";
    }
  }
  else
  {
    size_t highest{0};
    size_t lowest{n};

    if (!peaks.empty())
      highest = peaks[0];

    if (peaks.size() == 1)
    {
      if (!valleys.empty())
        lowest = valleys.back();

      reverse(v.begin() + highest - 1, v.begin() + lowest);

      if (is_sorted(v.begin(), v.end()))
      {
        op = lowest - highest == 1 ? "swap" : "reverse";
        cout << "yes\n";
        cout << op << " " << highest << " " << lowest << "\n";
      }
      else
        cout << "no\n";
    }
    else if (peaks.size() == 2)
    {
      if (valleys.size() == 2)
        lowest = valleys.back();

      swap(v[highest - 1], v[lowest - 1]);

      if (is_sorted(v.begin(), v.end()))
      {
        cout << "yes\n";
        cout << "swap " << highest << " " << lowest << "\n";
      }
      else
        cout << "no\n";
    }
    else
      cout << "no\n";
  }
}

int main()
{
  vector<int> x{
      3, 1, 2};

  almostSorted(x);

  return 0;
}