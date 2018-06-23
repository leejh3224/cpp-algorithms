string appendAndDelete(string s, string t, int k)
{
  // 문제 해결의 포인트를 잡는 게 생각보다 까다로움.
  // 1. 가장 긴 공통 문자열 찾기 => 둘 중 길이가 작은 문자열을 기준으로 비교
  // 2. 최대 횟수와 최소 횟수 구하기
  // 3. 문제의 조건 잘 살피기
  //  - 문제에서 빈 문자열은 삭제 작업을 해도 빈 문자열이라는 힌트를 줬으므로
  //  - maxK를 넘어서는 순간 상관 x (계속 빈 문자열에 삭제 작업하면 되므로)
  //  - 다만 문제는 minK인데 문제에서 "정확하게" k회만큼 작업을 실시한다고 했으므로 조금 까다로움
  //  - minK 회만큼 실행하고 나서, 작업 횟수를 소모하면서 문자열을 동일하게 유지하는 방법은 한 번 추가 그리고 한 번 삭제임
  //  - 즉, minK 회만큼 실행 이후에는 2번씩 작업을 해야 같은 결과를 유지할 수 있음 (홀수번 남을 경우 지우고-붙이고가 안 됨)
  //  - 그러므로 k - minK % 2 == 0를 만족해야함을 알 수 있음
  // 포인트는 문제를 잘 읽는 것. 그리고 minK와 maxK의 성질을 파악하는 것임.
  int longestCommonParagraph{0};

  for (int i = 0; i < min(s.length(), t.length()); i++)
  {
    if (s[i] == t[i])
      longestCommonParagraph++;
    else
      break;
  }

  int maxK = s.length() + t.length();
  int minK = s.length() + t.length() - 2 * longestCommonParagraph;

  if (k >= maxK || (k >= minK && (k - minK) % 2 == 0))
    return "Yes \n";
  else
    return "No \n";
}
