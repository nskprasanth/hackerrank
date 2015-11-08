/**
  * https://www.hackerrank.com/challenges/closest-numbers
  * 
  * Prasanth Kalapatapu
  * Sep 1, 2015
  */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;


int main() {
  int n;
  cin >> n;
  vector<long long int> a;
  for (int i=0;i<n;++i) {
    int cur;
    cin >> cur;
    a.push_back(cur);
  }

  sort(a.begin(), a.end());

  long long int diff[n-1], min = INT_MAX;
  for(int i=0;i<n-1;++i) {
    diff[i] = abs(a[i]-a[i+1]);
    if (diff[i] < min) {
      min = diff[i];
    }
  }
  for (int i=0;i<n-1;++i) {
    if (diff[i] == min) {
      cout << a[i] << " " << a[i+1] << " ";
    }
  }
  cout << endl;
  return 0;
}

