/**
  * Problem Statement: https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence
  * Author: Prasanth Kalapatapu
  * Nov 2, 2015
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
  int a[n], b[m];
  for (int i=0;i<n;++i) {
    cin >> a[i];
  }
  for (int j=0;j<m;++j) {
    cin >> b[j];
  }

  int data[n+1][m+1];
  for (int i=0;i<=n;++i) {
    data[i][0] = 0;
  }
  for (int i=0;i<=m;++i) {
    data[0][i] = 0;
  }

  for (int i=1;i<=n;++i) {
    for (int j=1;j<=m;++j) {
      if (a[i-1] == b[j-1]) {
	data[i][j] = 1+data[i-1][j-1];
      } else {
	data[i][j] = max(data[i][j-1], data[i-1][j]);
      }
    }
  }

  vector<int> v;
  int i=n;
  int j=m;
  while(data[i][j] != 0) {

    if (data[i][j] > data[i][j-1]) {
      if (data[i][j] > data[i-1][j]) {
	v.push_back(b[j-1]);
	--j;
      }
      --i;
    } else {
      --j;
    }
  }
  for (int i=v.size()-1;i>=0;--i) {
    cout << v[i] << " ";
  }
  cout << endl;
  return 0;
}

