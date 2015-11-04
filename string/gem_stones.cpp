/**
  * https://www.hackerrank.com/challenges/gem-stones
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
  int n;
  cin >> n;
  int count[26];
  for (int i=0;i<26;++i) {
    count[i]=0;
  }
  string s;
  for (int i=0;i<n;++i) {
    cin >> s;
    for (int i=0;i<26;++i) {
      if (s.find('a'+i) != string::npos) {
	++count[i];
      }
    }
  }
  int gems = 0;
  for (int i=0;i<26;++i) {
    if (count[i] == n) {
      ++gems;
    }
  }
  cout << gems << endl;
  return 0;
}

