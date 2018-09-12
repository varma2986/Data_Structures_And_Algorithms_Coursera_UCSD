#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>
using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

//Get the maximum value of the string expression
//Even characters are digits . Odd characters are expressions +,-,*,/
long long get_maximum_value(const string &exp) {
  int length = exp.size();
  int digitcount = (length + 1) / 2;
  long long minValueArray[digitcount][digitcount];
  long long maxValueArray[digitcount][digitcount];
  memset(minValueArray,0,sizeof(minValueArray)); // initialize to 0
  memset(maxValueArray,0,sizeof(maxValueArray));
  for (int i = 0; i < digitcount; i++)
  {
      //Use stoll to discard the whitespaces
      minValueArray[i][i] = std::stoll(exp.substr(2*i,1));
      maxValueArray[i][i] = std::stoll(exp.substr(2*i,1));
  }

  for (int s = 0; s < digitcount - 1; s++)
  {
      for (int i = 0; i < digitcount - s - 1; i++)
      {
          int j = i + s + 1;
          long long minVal = LLONG_MAX; //practically equal to +infinity
          long long maxVal = LLONG_MIN; //practically equal to -infinity

          //Using the lagorithm in the lecture videos, get the min and max values for the input exp between ith number and jth number
          for (int k = i; k < j; k++ )
          {
              long long a = eval(minValueArray[i][k],minValueArray[k + 1][j],exp[2 * k + 1]);
              long long b = eval(minValueArray[i][k],maxValueArray[k + 1][j],exp[2 * k + 1]);
              long long c = eval(maxValueArray[i][k],minValueArray[k + 1][j],exp[2 * k + 1]);
              long long d = eval(maxValueArray[i][k],maxValueArray[k + 1][j],exp[2 * k + 1]);
              minVal = min(minVal,min(a,min(b,min(c,d))));
              maxVal = max(maxVal,max(a,max(b,max(c,d))));
          }
          minValueArray[i][j] = minVal;
          maxValueArray[i][j] = maxVal;
      }
  }

  return maxValueArray[0][digitcount - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
