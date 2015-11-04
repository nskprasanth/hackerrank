/**
  * https://www.hackerrank.com/challenges/sherlock-and-array
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
  int t;
  cin >> t;
  for (int nt=0;nt<t;++nt) {
    int n;
    cin >> n;
    int a[n], b[n];
    int sum=0;
    for (int i=0;i<n;++i) {
      cin >> a[i];
      b[i] = sum;
      sum+=a[i];
    }
    bool flag = false;
    for (int i=0;i<n;++i) {
      if (sum-a[i] == 2*b[i]) {
	cout << "YES" << endl;
	flag = true;
      }
    }
    if (!flag) {
      cout << "NO" << endl;
    }
  }
  return 0;
}

