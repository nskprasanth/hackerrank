/**
  * https://www.hackerrank.com/challenges/pangrams
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
  string s;
  getline(cin, s);
  bool flags[26];
  for (int i=0;i<26;++i) {
    flags[i] = false;
  }
  int count=0;
  for (int i=0;i<s.size() && count <26;++i) {
    int index;
    if (s[i]>='a' && s[i]<='z') {
      index = s[i]-'a';
    } else if (s[i]>='A' && s[i]<='Z') {
      index = s[i]-'A';
    } else {
      continue;
    }
    if (!flags[index]) {
      flags[index] = true;
      ++count;
    }
  }
  string output = (count == 26) ? "pangram" : "not pangram";
  cout << output << endl;
  return 0;
}

