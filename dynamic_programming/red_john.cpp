/**
 * Problem: https://www.hackerrank.com/challenges/red-john-is-back
 * Author: Prasanth Kalapatapu
 * Oct 3, 2015
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int nCr(int n, int r) {
  int num=1, denom=1;
  for (int i=r;i>0;--i) {
    num *= (n-r+i);
    denom *= i;
  }
  return num/denom;
}

int get_primes(int n) {
  int a[n+1] = {0};
  for (int i=2;i<n+1;++i) {
    if (a[i] == -1) {
      continue;
    }
    for (int k=2;i*k<=n;++k) {
      a[i*k] = -1;
    }
  }
  int num=0;
  for (int i=2;i<=n;++i) {
    if (a[i] == 0) {
      ++num;
    }
  }
  return num;
}

int main() {
  int t; cin >> t;
  for (int nt=0;nt<t;++nt) {
    int n; cin >> n;
    int sum=0;
    for (int i=1;n/4;++i) {
      n-=4;
      sum+=nCr(n+i,i);
    }
    int m=sum+1;
    cout << get_primes(m) << endl;
  }
  return 0;
}

