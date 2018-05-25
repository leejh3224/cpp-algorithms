vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice)
{
  // code reference: https://codereview.stackexchange.com/questions/183790/hackerrank-leaderboard-challenge

  // remove duplicates
  scores.erase(unique(begin(scores), end(scores)), end(scores));

  // lambda expression
  auto locateRanking = [](const auto &s, int _newScore) {
    // lower_bound: first, last, value, compare
    // binary search is possible in this case because our score and alice vector is already sorted
    // returns iterator
    auto it = lower_bound(begin(s), end(s), _newScore, greater<int>());

    // it is iterator of element that has bigger or equal value to s
    // so in order to get rank, we simply add 1
    return distance(begin(s), it) + 1;
  };

  // convert alice's scores into her ranking
  for (auto &newScore : alice)
    newScore = locateRanking(scores, newScore);

  return alice;
}