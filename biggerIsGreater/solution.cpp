/*
 * 문제의 핵심은 "next permutation"을 어떤 식으로 구할 것인가이다.
 * 
 * 이에 대한 stackoverflow의 좋은 답변
 * (https://stackoverflow.com/questions/11483060/stdnext-permutation-implementation-explanation)이 있는데,
 * 
 * ```
 * Let's look at some permutations:
 * 몇 가지 경우를 먼저 살펴보자.
 * 
 *  1 2 3 4
 *  1 2 4 3
 *  1 3 2 4
 *  1 3 4 2
 *  1 4 2 3
 *  1 4 3 2
 *  2 1 3 4
 *  ...
 * 
 * How do we go from one permutation to the next?
 * 어떻게 하면 다음 순열로 넘어갈 수 있을까?
 * 
 * Firstly, let's look at things a little differently. 
 * 먼저 문제를 다른 시각에서 접근할 필요가 있다.
 * 
 * We can view the elements as digits and the permutations as numbers. 
 * 각 요소를 한 자리 숫자로, 각 순열을 숫자로 볼 수 있는데,
 * 
 * Viewing the problem in this way we want to order the permutations/numbers in "ascending" order.
 * 이렇게 생각하면 각 순열을 구하는 문제는 숫자를 "오름차순"으로 보는 것과 같다. (즉, 다음 숫자가 더 커지는 순서대로 정렬한다는 뜻)
 * 
 * When we order numbers we want to "increase them by the smallest amount". 
 * 우리가 숫자를 정렬할 때는 숫자를 "최소한"으로 증가시키고 싶어하는 것이다.
 * 
 * For example when counting we don't count 1, 2, 3, 10, ... 
 * 예를 들어 일반적으로 숫자를 셀 때 1, 2, 3, 10... 이런 식으로 세지는 않는다.
 * 
 * because there are still 4, 5, ... in between and although 10 is larger than 3, there are missing numbers which can be gotten by increasing 3 by a smaller amount. 
 * 왜냐하면 그 사이에 4, 5, ...가 있기 때문에 10이 3보다 크지만 그렇게 하지 않는다.
 * 
 * In the example above we see that 1 stays as the first number for a long time as there are many reorderings of the last 3 "digits" which "increase" the permutation by a smaller amount.
 * 위의 예시에서 우리는 가장 왼쪽의 1이 오랫동안 움직이지 않는 걸 알 수 있는데, 이는 나머지 3 자리가 조금씩 증가하면서 다음 순열로 넘어가기 때문이다.
 * 
 * So when do we finally "use" the 1? 
 * 그렇다면 언제 1을 사용하게 될까?
 * 
 * When there are only no more permutations of the last 3 digits.
 * 그건 1을 제외한 나머지 3자리로 더 이상 큰 순열을 만들 수 없을 때일 것이다.
 * 
 * And when are there no more permutations of the last 3 digits? 
 * 그렇다면 나머지 3 자리로 더 이상 큰 순열을 만들 수 없게 되는 때가 언제일까?
 * 
 * When the last 3 digits are in descending order.
 * 그건 바로 나머지 3 자리가 "내림차순"으로 정렬되어 있을 때이다.
 *
 * Aha! This is key to understanding the algorithm. 
 * 아하! 이게 바로 이 알고리즘을 이해하는 핵심 포인트다.
 * 
 * We only change the position of a "digit" when everything to the right is in descending order 
 * 각 자리 수의 위치가 바뀌는 때는 오직 그 자리 수보다 작은 수(오른쪽에 위치한 수)가 "내림차순"으로 정렬되어 있을 때 뿐이다.
 * 
 * because if it isn't in descending order then there are still more permutations to go (ie we can "increase" the permutation by a smaller amount).
 * 즉, 내림차순으로 정렬돼있지 않다는 것은 아직 조금씩 크기를 더 늘릴 수 있다는 말이 되기 때문이다.
 * 
 * 이제 자신보다 작은 자리의 숫자가 모두 내림차순으로 정렬되어 있을 때 다음 순열로 어떻게 넘어가는지 살펴보자.
 * 
 * We see that when everything to the right of a digit is in descending order, 
 * 만약 자신보다 작은 자리의 숫자가 모두 내림차순으로 정렬되어 있다면,
 * 
 * we find the next largest digit and put it in front and then put the remaining digits in ascending order.
 * 자신보다 조금 더 큰 (next largest) 자리의 수를 찾아 자신과 자리를 바꾼다. 그리고 나머지 자리 수들은 "오름차순"으로 재정렬한다.
 * 
 * Algorithm 헤더에 next_permutation이 있으므로 직접 구현할 필요는 없다.
 * 그러나 어떤 원리로 동작하는지 이해한다면 사용에 큰 도움이 될 것이다.
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string biggerIsGreater(string w)
{
  for (auto it = w.end() - 1; it != w.begin(); it--)
  {
    // j는 자신보다 한 자리 큰 숫자
    auto j = it - 1;

    // k는 끝
    auto k = w.end();

    // 만약 자신보다 작은 자리의 숫자가 더 크다면
    if (*j < *it)
    {
      // 끝에서부터 자신보다 큰 요소를 찾고,
      // 이렇게 할 수 있는 이유는 나머지 부분이 "내림차순"으로 정렬돼있기 때문
      while (*--k < *j)
        ;

      // 자신보다 조금 더 큰 자리와 j를 바꿈.
      swap(*j, *k);

      // 오름차순으로 정렬
      reverse(it, w.end());

      return w;
    }
  }

  /*
   * ex) dkhc
   * d보다 작은 khc는 내림차순으로 정렬돼있다.
   * 그러므로 j = d, k = h(d보다 크고 k보다 작은 글자)가 되며,
   * 
   * 먼저 j와 k가 위치를 바꾸고,
   * j의 다음 요소인 k부터 끝까지 오름차순으로 정렬한다.
   * 
   * 만약 *j < *it인 상황이 없다면 자신이 가장 큰 순열이라는 의미이므로 no answer를 반환
   */

  return "no answer";
}

int main()
{
  string x = biggerIsGreater("xoojiggdcyjrupr");

  cout << x << "\n";

  return 0;
}