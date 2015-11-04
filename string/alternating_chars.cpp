/**
  * https://www.hackerrank.com/challenges/alternating-characters
  * Prasanth Kalapatapu
  * Sep 2, 2015
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
    int count = 0;
    char prev = s[0];
    for (int i=1;i<s.size();++i) {
      if (s[i] == prev) {
	++count;
      }
      prev = s[i];
    }
    cout << count << endl;
  }
  return 0;
}

