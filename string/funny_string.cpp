/**
  * https://www.hackerrank.com/challenges/funny-string
  * Prasanth Kalapatapu
  * Sep 5, 2015
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int nt=0;nt<t;++nt) {
    string s;
    cin >> s;
    int n = s.size();
    bool isFunny = true;
    for(int i=0;i<n/2;++i) {
      char ch1 = s[i];
      char ch2 = s[i+1];

      char ch3 = s[n-i-1];
      char ch4 = s[n-i-2];

      if (abs(ch1-ch2) != abs(ch3-ch4)) {
	isFunny = false;
	break;
      }
    }
    if (isFunny) {
      cout << "Funny" << endl;
    } else {
      cout << "Not Funny" << endl;
    }
  }
  return 0;
}

