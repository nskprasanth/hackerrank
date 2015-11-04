/**
  * https://www.hackerrank.com/challenges/stockmax
  * Prasanth Kalapatapu
  * Sep 12, 2015
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
  // 1 3 1 2
  for (int nt=0;nt<t;++nt) {
    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;++i) {
      cin >> a[i];
    }

    unsigned long long int stocks = 0;
    unsigned long long int profit = 0;
    unsigned long long int cur_max = a[n-1];
    for (int i=n-2;i>=0;i--) {
      if (a[i]<=cur_max) {
	++stocks;
	profit -= a[i];
      } else {
	profit += (unsigned long long int)(stocks * cur_max);
	stocks = 0;
	cur_max = a[i];
      }
    }
    if (stocks) {
      profit += (unsigned long long int)(stocks*cur_max);
      stocks = 0;
    }
    cout << profit << endl;
  }
  return 0;
}

