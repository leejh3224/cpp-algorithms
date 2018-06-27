/*
 * 맨 처음에 생각해낸 솔루션
 * 
 * 1. 퀸이 있는 방향에서부터 8방향으로 한 걸음씩 가본다.
 * 2. 이제 temp_c, temp_r에 퀸의 위치를 저장하고 isBlocked 함수를 통해 다음 방향이 막혔는지를 확인
 * 3. isBlocked 함수는 isOutOfBorder 함수를 통해 다음 움직임이 체스판 밖으로 나가는지 확인,
 * 그리고 isBlocked 함수는 any_of를 통해 다음 위치가 장애물과 만나는지를 체크
 * 4. 이제 다음 움직임이 막히지 않는다면 답을 증가시키고,
 * temp_r과 temp_c를 움직임에 맞게 수정해줌
 * 5. 각 방향마다 반복적으로 검사함 ex) <----- Q ----->
 * 
 * 문제점: 
 *  제출 과정에서 Timeout이 발생했는데,
 *  이는 queensAttack 함수가 blocked 인지 아닌지를 확인할 때마다
 *  모든 obstacles 를 일일히 확인하기 때문 (n = 5, k = 3 기준 40 회까지 증가)
 *  => obstacles의 크기 k가 커질 수록 처리 시간이 기하급수적으로 증가.
 * 
 * 교훈:
 *  무작정 반복문을 쓰기 보다는 좌표와 거리 개념이 나오는 문제이므로 가급적 문제를
 *  단순화해서 푸는 접근법이 필요함.
 */
bool isOutOfBorder(int n, int r, int c, vector<int> &move)
{
  return (r + move[0] > n || r + move[0] <= 0) ||
         (c + move[1] > n || c + move[1] <= 0);
}

bool isBlocked(int n, int r, int c, vector<int> &move, vector<vector<int>> &obstacles)
{
  bool outOfBorder = isOutOfBorder(n, r, c, move);
  bool noObstacles = obstacles.size() == 0;

  if (noObstacles)
    return outOfBorder;
  else
    return any_of(obstacles.begin(), obstacles.end(), [&n, &r, &c, &move, &outOfBorder](vector<int> o) {
      return (r + move[0] == o[0] && c + move[1] == o[1]) || outOfBorder;
    });
}

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
  int answer{0};

  vector<vector<int>> moves{
      {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}};

  for (auto move : moves)
  {
    int temp_r{r_q};
    int temp_c{c_q};

    while (!isBlocked(n, temp_r, temp_c, move, obstacles))
    {
      answer += 1;
      temp_r += move[0];
      temp_c += move[1];
    }
  }

  return answer;
}