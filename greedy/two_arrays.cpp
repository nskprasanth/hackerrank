/**
  * https://www.hackerrank.com/challenges/two-arrays
  * Prasanth Kalapatapu
  * Sep 2, 2015
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
    vector<int> v1, v2;
    for (int i=0;i<n;++i) {
      int cur; 
      cin >> cur;
      v1.push_back(cur);
    }
    for (int i=0;i<n;++i) {
      int cur; 
      cin >> cur;
      v2.push_back(cur);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    bool flag = true;
    for (int i=0;i<n;++i) {
      if (v1[i] + v2[n-i-1] < k) {
	flag = false;
	break;
      }
    }
    string result = flag ? "YES" : "NO";
    cout << result << endl;
  }
  return 0;
}

