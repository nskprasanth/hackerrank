/**
  * Problem: https://www.hackerrank.com/challenges/maxsubarray
  * Author: Prasanth Kalapatapu
  * Oct 3, 2015
  */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
  int t; cin >> t;
  for (int nt=0;nt<t;++nt) {
    int n; cin >> n;
    long long csum=0, ncsum=0, max=INT_MIN, minNeg= INT_MIN;
    for (int i=0;i<n;++i) {
      int cur; cin >> cur;

      if (csum<0) {
	csum=0;
      }
      csum+=cur;
      if (csum>max) { max = csum; }

      if (cur>0) {
	ncsum+=cur;
      } else if(cur>minNeg) {
	minNeg=cur;
      }
    }
    if (ncsum==0) {
      ncsum = minNeg;
    }
    cout << max << " " << ncsum << endl;
  }
  return 0;
}

