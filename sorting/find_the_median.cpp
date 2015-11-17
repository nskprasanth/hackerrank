/**
  * https://www.hackerrank.com/challenges/find-median
  *
  * Prasanth Kalapatapu
  * Sep 20, 2015
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
  vector<int> v;
  v.reserve(n);
  for (int i=0;i<n;++i) {
    int cur;
    cin >> cur;
    v.push_back(cur);
  }
  sort(v.begin(), v.end());
  cout << v[v.size()/2] << endl;
  return 0;
}

