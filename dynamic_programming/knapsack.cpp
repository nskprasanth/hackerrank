/**
  * Problem: https://www.hackerrank.com/challenges/unbounded-knapsack
  * Author: Prasanth Kalapatapu
  * Oct 4, 2015
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
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i=0;i<n;++i) {
      cin >> a[i];
    }
    sort (a, a+n);

    int b[k+1] = {0};
    int max=0, local_max;
    for (int i=1;i<=k;++i) {
      local_max=0;
      for (int j=0;j<n && a[j]<=i;++j) {
	if(a[j]+b[i-a[j]] > local_max) {
	  local_max = a[j]+b[i-a[j]];
	}
      }
      b[i] = local_max;
    }
    cout << b[k] << endl;
  }
  return 0;
}

