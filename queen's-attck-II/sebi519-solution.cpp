/*
 * sebi519의 솔루션 
 * 
 * o(n) solution : 장애물의 크기에 비례
 * Queen's attack 문제의 핵심은 
 * 8 방향 중에 장애물에 의해 막히는 방향이 있는 지 확인하고,
 * 만약 장애물에 의해 막힌다면 장애물과 퀸 간의 거리로 원래의 거리를 다시 조정하는 것이다.
 * 
 * 1. 각 방향마다 퀸과의 거리를 구한다. => 대각선 방향의 사각형의 갯수는 가장 인접한 두 방향의 사각형 갯수 중 작은 쪽임. 
 * 2. ne_sw_sum 혹은 se_nw_diff 를 이용하여 장애물이 대각선 상에 위치하는 지 알 수 있다.
 * 3. 이제 각 장애물마다 장애물이 위치가 퀸과 
 *      1) 수직방향 
 *      2) 수평방향 
 *      3) 대각선 방향 (기울기 1) 
 *      4) 대각선 방향 (기울기 -1) 
 *    중 어느 쪽인지를 알아보고,
 *    장애물의 위치에 따라 사각형의 갯수를 수정해준다.
 */
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
  auto north = n - r_q;
  auto south = r_q - 1;
  auto east = c_q - 1;
  auto west = n - c_q;
  auto north_west = min(north, west);
  auto north_east = min(north, east);
  auto south_east = min(south, east);
  auto south_west = min(south, west);

  const auto ne_sw_sum = r_q + c_q;
  const auto se_nw_diff = r_q - c_q;

  for (const auto &obstacle : obstacles)
  {
    auto r_o = obstacle[0];
    auto c_o = obstacle[1];
    auto distance_r = abs(r_o - r_q) - 1;
    auto distance_c = abs(c_o - c_q) - 1;

    if (c_q == c_o)
    {
      if (r_o > r_q)
        north = min(north, distance_r);
      else
        south = min(south, distance_r);
    }
    if (r_q == r_o)
    {
      if (c_o < c_q)
        east = min(east, distance_c);
      else
        west = min(west, distance_c);
    }
    if (r_o + c_o == ne_sw_sum)
    {
      if (r_o > r_q)
        north_east = min(north_east, distance_r);
      else
        south_west = min(south_west, distance_r);
    }
    if (r_o - c_o == se_nw_diff)
    {
      if (r_o > r_q)
        north_west = min(north_west, distance_r);
      else
        south_east = min(south_east, distance_r);
    }
  }

  return north + south + east + west + north_west + north_east + south_west + south_east;
}