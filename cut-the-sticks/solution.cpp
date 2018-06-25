/*
 * 문제 자체는 어렵지 않았으나 erase-remove-remove_if의 사용법을 정확히 몰라서 헷갈림
 * remove 함수와 remove_if 함수의 동작원리를 이해해보자.
 * 
 * remove 함수는 인자로 1. 시작 범위 2. 끝 범위 3. 지울 값을 받는다.
 * 그리고 remove 함수는
 * 1. 내부적으로 지울 값들을 맨끝으로 이동시킨다 (move 사용)
 * 2. 이제 이동시키고 난 후의 vector에서 이동시킨 개수 만큼의 값들로 채워넣는다.
 * 3. 순서만 바뀌고 요소의 개수는 바뀌지 않았다.
 * 
 * 예시)
 * vector<int> a {10, 2, 3, 3, 2};
 * 
 * remove(a.begin(), a.end(), 3); => 100 2 2 ? ?
 * 
 * {100, 2, 2, 3, 2} => 마지막 두 요소는 원래 vector의 마지막 두 요소를 가져옴
 * => remove 함수의 리턴값은 복사하는 값 중에서 처음으로 가르키는 값 (3, 2) 중에서 3
 * 
 * 그러므로 만약 제거된 값들을 출력하고 싶지 않다면 a.end() iterator를 remove가 가르키는 값으로 다시 할당해줘야한다.
 * 
 * 즉, 아래와 같이 되는 것이다.
 * 100 2 2 3 2
 *         ^
 *   remove가 반환한 iterator
 * 
 *           ^
 *        arr.end()
 * 
 * 다음은 erase
 * 
 * erase는 파라미터를 한 개 혹은 두 개를 받는데,
 * 하나를 받으면 정확히 iterator에 해당되는 요소를 제거함 (크기 줄어듬)
 * 
 * 두 개를 받으면 첫 번째는 범위 시작, 두 번째는 범위 끝인데, 끝 범위는 포함한되고 첫 범위는 포함
 * 
 * 예시)
 * {100, 2, 3, 2}
 * 
 * erase(a.begin()); => {2, 3, 2}
 * 
 * erase(a.begin(), a.begin() + 2); => {3, 2}
 * 
 * 이제 erase와 remove 혹은 remove_if를 같이 사용하는 경우를 생각해보자.
 * 
 * vector<int> a {1, 2, 3, 4, 5, 6};
 * 
 * a.erase(
 *  remove_if(a.begin(), a.end(), [](int n) {
 *    return n % 2 == 0;
 *  }),
 *  a.end()
 * )
 * 
 * 결과: {1, 3, 5}
 * 
 * 이런 식으로 vector 크기를 줄이는 erase를 같이 사용하면 직관적인 결과를 얻을 수 있다.
 */
vector<int> cutTheSticks(vector<int> arr)
{
  vector<int> answer;

  while (arr.size())
  {
    arr.erase(
        remove_if(arr.begin(), arr.end(), [](int stick) {
          return stick == 0;
        }),
        arr.end());

    if (arr.size() > 0)
      answer.push_back(arr.size());

    int minStick = *min_element(arr.begin(), arr.end());

    for (auto &stick : arr)
      stick -= minStick;
  }

  return answer;
}