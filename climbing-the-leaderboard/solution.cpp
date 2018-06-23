/*
 * naive implementation uses nested for loops which has O(n^2) complexity
 * however we can improve it by using stl(standard template library)
 * for example, lower_bound offers binary search which is lot faster and less error prone than for loop
 */
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice)
{
  // code reference: https://codereview.stackexchange.com/questions/183790/hackerrank-leaderboard-challenge

  // remove duplicates
  scores.erase(unique(begin(scores), end(scores)), end(scores));

  // lambda expression
  auto locateRanking = [](const auto &scores, int aliceScore) {
    // lower_bound: first, last, value, compare
    // binary search is possible in this case because our score and alice vector is already sorted
    // returns iterator of element that has bigger or equal value to newScore(alice's score)
    auto it = lower_bound(begin(scores), end(scores), aliceScore, greater<int>());

    // it is iterator of element that has bigger or equal value to s
    // so in order to get rank, we simply add 1
    return distance(begin(scores), it) + 1;
  };

  // convert alice's scores into her ranking
  for (auto &aliceScore : alice)
    aliceScore = locateRanking(scores, aliceScore);

  return alice;
}