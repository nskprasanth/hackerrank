/**
  * https://www.hackerrank.com/challenges/coin-change
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
  int n, m;
  cin >> n >> m;
  int coins[m];
  for (int i=0;i<m;++i) {
    cin >> coins[i];
  }

  long long int table[n+1][m];
  for (int i=0;i<m;++i) {
    table[0][i] = 1;
  }
  for (int i=1;i<n+1;++i) {
    for (int j=0;j<m;++j) {
      int diff = i-coins[j];
      long long int n1 = (diff>=0) ? table[diff][j] : 0;
      long long int n2 = (j>0) ? table[i][j-1] : 0;
      table[i][j] = n1 + n2;
    }
  }
  cout << table[n][m-1] << endl;
  return 0;
}

