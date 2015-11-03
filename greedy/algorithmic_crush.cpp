/**
  * Problem: https://www.hackerrank.com/challenges/crush
  * Author: Prasanth Kalapatapu
  * Oct 1, 2015
  */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  long long int* num = new long long int[n+1];

  for (int i=1;i<=n;++i) {
    num[i] = 0;
  }

  for (int nm=0;nm<m;++nm) {
    int a,b,k;
    cin >> a >> b >> k;
    num[a] += k;
    if (b!=n) { num[b+1] -= k; }
  }

  long long max = 0, sum=0;
  for (int i=1;i<=n;++i) {
    sum+=num[i];
    if (sum>max) {
      max=sum;
    }
  }

  cout << max << endl;
  return 0;
}

