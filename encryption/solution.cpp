/*
 * 이 문제의 핵심은 사실 f와 c를 어떻게 구할 것인가 하는 것이다.
 * 조건은 sqrt(n) <= f <= c 여야한다는 것인데,
 * 의외로 간단히 sqrt 취한 뒤에 각 수를 버림, 올림하면 가능하다.
 * 
 * 또 각 단어마다 공백을 넣어야하는 경우 저런 식으로 j loop이 끝날 때마다 공백을 넣어주면 된다.
 */
string encryption(string s)
{
  string str;
  int n = s.length();
  int f = floor(sqrt(n));
  int c = ceil(sqrt(n));

  for (int i = 0; i < c; i++)
  {
    for (int j = 0 + i; j < s.length(); j += c)
      str += s[j];
    str += " ";
  }

  return str;
}