/**
  * https://www.hackerrank.com/challenges/the-love-letter-mystery
  * Prasanth Kalapatapu
  * Sep 6, 2015
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
    int count=0;
    int n = s.size();
    for (int i=0;i<n/2;++i) {
      if (s[i] == s[n-i-1]) {
	continue;
      } else {
	count += abs(s[i] - s[n-i-1]);
      }
    }
    cout << count << endl;
  }
  return 0;
}

