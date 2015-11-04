/**
  * https://www.hackerrank.com/challenges/play-game
  * Author: Prasanth Kalapatapu
  * Oct 10, 2015
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long int min(unsigned long long a, unsigned long long b, unsigned long long c) {
  return (a<b) ? min (a,c) : min(b,c);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n; cin >> n;
    unsigned int a[n];
    for (int i=0;i<n;++i) {
      cin >> a[i];
    }
    if (n==1) {
      cout << a[0] << endl;
    } else if (n==2) {
      cout << a[0] + a[1] << endl;
    } else {
      unsigned long long int b[n];
      b[n-1] = a[n-1];
      b[n-2] = a[n-1] + a[n-2];
      b[n-3] = a[n-3] + b[n-2];
      double sum= a[n-1]+a[n-2]+a[n-3];
      for (int i=n-4;i>=0;--i) {
	sum+=a[i];
	unsigned long long int min_val = min(b[i+1], b[i+2], b[i+3]);
	b[i] = sum-min_val;
      }
      cout << b[0] << endl;
    }
  }
  return 0;
}

