vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice)
{
  vector<int> lb{1};

  // firstly, save ranks in vector lb(leaderBoard)
  int rank{1};
  for (int i = 1; i < scores.size(); i++)
  {
    if (scores[i] != scores[i - 1])
      lb.push_back(++rank);
    else
      lb.push_back(rank);
  }

  vector<int> answer;
  for (int i = 0; i < alice.size(); i++)
  {
    for (int j = 0; j < scores.size(); j++)
    {
      if (alice[i] >= scores[j])
      {
        answer.push_back(lb[j]);
        break;
      }
      else if (j == scores.size() - 1 && alice[i] < scores[j])
      {
        answer.push_back(lb[j] + 1);
        break;
      }
    }
  }

  return answer;
}