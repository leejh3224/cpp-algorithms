/*
 * O(n^2) solution
 * 
 * 맨 처음 접근법은 각 큐브 스택 간에 어떤 조건이 만족하면 "골짜기"가 생긴다는 것을 알아채고,
 * 전체 면적을 구한 다음에 골짜기 부분을 빼주면 된다고 생각했다.
 * 그러나 정확한 면적을 구하는 코드를 작성하지 못했고, 다른 방법으로 접근하게 됐다.
 * 
 * 문제를 더 단순화시켜서
 * 1. 각 큐브 스택의 겹치지 않을 때의 총 면적을 구한다.
 * 2. 겹치는 면적은 연속된 두 큐브 스택 중 높이가 작은 큐브 스택의 높이값과 같다.
 * 3. 각 큐브 스택의 면적의 합에서 겹치는 면적 * 2를 빼주면 전체 표면적을 알 수 있다.
 * 
 * 반복문을 작성하는데 어려움이 있었다.
 * 겹치는 면적을 구하는 반복문을 하나로 만들고 싶었지만 범위가 다르기 때문에 각각으로 써줘야한다.
 * 앞으로 반복문을 쓸 때는 최대 최소 범위를 먼저 생각하고 사용하자.
 */
using height = int;

int calculateCubeSurfaceArea(height h)
{
  return h * 4 + 2;
}

int surfaceArea(vector<vector<int>> A)
{
  size_t H{A.size()};
  size_t W{A[0].size()};

  size_t total{0};
  size_t overlapped{0};

  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      total += calculateCubeSurfaceArea(A[i][j]);

  for (int i = 0; i < H; i++)
    for (int j = 0; j < W - 1; j++)
      overlapped += min(A[i][j], A[i][j + 1]);

  for (int i = 0; i < H - 1; i++)
    for (int j = 0; j < W; j++)
      overlapped += min(A[i][j], A[i + 1][j]);

  return total - 2 * overlapped;
}