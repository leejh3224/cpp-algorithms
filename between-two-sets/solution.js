/*
 * 유클리드 호제법
 * 두 개의 정수 a, b 간에는 a = b * q + r (0 <= q < r) 이 성립한다.
 * 이를 이용하면 최대 공약수를 쉽게 찾을 수 있다.
 * ex) 24 15
 * 24 = 15 * 1 + 9
 * 15 = 9 * 1 + 6
 * 9 = 6 * 1 + 3
 * 6 = 3 * 2 + 0
 * 
 * 결국 맨 마지막에 남는 숫자는 3, 즉 gcd(최대공약수)는 3임을 알 수 있다.
 * 
 * 만약 숫자가 세 개 이상이라면 어떻게 구할까?
 * gcd(a, b, c) = gcd(gcd(a, b), c)와 같다.
 * 이렇게 순차적으로 구할 수 있다.
 */

function gcd(a, b) {
  const remainder = b % a

  // remainder가 0이 되면 재귀 탈출
  if (!remainder) {
    return a
  }
  return gcd(remainder, a)
}

function lcm(a, b) {
  // gcd로부터 lcm 구하기
  // least common multiple excercise: https://www.youtube.com/watch?v=znmPfDfsir8
  // [참고] lcm.png
  return a * b / gcd(a, b)
}

function getTotalX(a, b) {
  const LCM = a.reduce((acc, n) => lcm(acc, n))
  const GCD = b.reduce((acc, n) => gcd(acc, n))

  let count = 0

  for (let i = 1; i <= GCD / LCM; i++) {
    // GCD에 해당하는 수를 LCM의 i배한 수로 나눴을 때 딱 나눠 떨어지면 조건을 만족
    if (GCD % (LCM * i) === 0) {
      count += 1
    }
  }

  return count
}
