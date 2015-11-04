/**
  * https://www.hackerrank.com/challenges/two-strings
  * Prasanth Kalapatapu
  * Sep 10, 2015
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
    string s1, s2;
    cin >> s1 >> s2;
    int c1[26], c2[26];
    for (int i=0;i<26;++i) {
      c1[i] = c2[i] = 0;
    }
    for (int i=0;i<s1.size();++i) {
      ++c1[s1[i]-'a'];
    }
    for (int i=0;i<s2.size();++i) {
      ++c2[s2[i]-'a'];
    }
    bool match = false;
    for (int i=0;i<26;++i) {
      if (c1[i] & c2[i]) {
	match = true;
      }
    }
    string output = match ? "YES" : "NO";
    cout << output << endl;
  }
  return 0;
}

