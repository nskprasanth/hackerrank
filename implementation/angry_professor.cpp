/**
  * https://www.hackerrank.com/challenges/angry-professor
  * Prasanth Kalapatapu
  * Sep 14, 2015
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
    int n, k, cur;
    int count = 0;
    cin >> n >> k;
    for (int i=0;i<n;++i) {
      cin >> cur;
      if (cur<=0) {
	++count;
      }
    }
    if (count<k) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}

