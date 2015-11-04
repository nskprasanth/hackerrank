/**
  * https://www.hackerrank.com/challenges/anagram
  * Prasanth Kalapatapu
  * Sep 7, 2015
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
    if (s.size()%2 == 1) {
      cout << -1 << endl;
      continue;
    }
    int c1[26], c2[26];
    for (int i=0;i<26;++i) {
      c1[i] = c2[i] = 0;
    }
    for (int i=0;i<s.size()/2;++i) {
      ++c1[s[i]-'a'];
    }
    for (int i=s.size()/2; i<s.size();++i) {
      ++c2[s[i]-'a'];
    }
    int count=0;
    for (int i=0;i<26;++i) {
      if (c1[i]!=c2[i]) {
	count += abs(c1[i]-c2[i]);
      }
    }
    cout << count/2 << endl;
  }
  return 0;
}

