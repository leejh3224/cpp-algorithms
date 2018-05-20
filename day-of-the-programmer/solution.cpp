using namespace std;

string solve(int year)
{
  bool isJulianYear{year >= 1700 && year < 1918};
  bool isLeapYear{true};

  // you can't use static_cast to cast std::string type to int
  // instead use std::to_string (in string header)
  string y{to_string(year)};

  if (isJulianYear)
  {
    isLeapYear = year % 4 == 0;

    // it's ok to use + operator with string
    // or you can use append
    return isLeapYear ? "12.09." + y : "13.09." + y;
  }
  // transition from Juliean to Gregorian happend at 1918
  else if (year == 1918)
    return "26.09.1918";
  else
  {
    isLeapYear = (year % 400 == 0) ||
                 (year % 4 == 0 && year % 100 != 0);

    return isLeapYear ? "12.09." + y : "13.09." + y;
  }
}