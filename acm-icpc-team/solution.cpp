/*
 * bitset은 stl의 container 중 하나로, 비트연산에 특화되어 있다.
 * 문제는 or 연산을 했을 때 비트의 갯수(1)가 얼마인지 알면 쉽게 구할 수 있다.
 * 그럴 때는 count를 사용하면 쉽게 구할 수 있다.
 */
vector<int> acmTeam(vector<string> topic)
{
  vector<int> answer;

  int maxTopics{0};

  // number of topics and its frequency
  map<int, int> numberOfTopicsTable;

  for (int i = 0; i < topic.size() - 1; i++)
  {
    for (int j = i + 1; j < topic.size(); j++)
    {
      // max input size is 500
      bitset<500> x(topic[i]);
      bitset<500> y(topic[j]);

      // count 1 from the result of or operation
      int numberOfTopics = static_cast<int>((x | y).count());

      numberOfTopicsTable[numberOfTopics]++;
      maxTopics = max(maxTopics, numberOfTopics);
    }
  }

  // from the table get the most frequent pair
  auto maxPair = *max_element(numberOfTopicsTable.begin(), numberOfTopicsTable.end(), [](auto &row1, auto &row2) {
    return row1.first < row2.first;
  });

  answer.push_back(maxTopics);
  answer.push_back(maxPair.second);

  return answer;
}