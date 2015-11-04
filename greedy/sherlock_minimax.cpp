/**
  * https://www.hackerrank.com/challenges/sherlock-and-minimax
  * Prasanth Kalapatapu
  * Sep 3, 2015
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int n;
  cin >> n;
  vector<int> v;
  v.reserve(n);
  for (int i=0;i<n;++i) {
    int cur;
    cin >> cur;
    v.push_back(cur);
  }
  sort(v.begin(), v.end());

  /*for (int i=0;i<n;++i) {
    cout << v[i] << " ";
    }
    cout << endl;*/

  int p, q;
  cin >> p >> q;
  int mx = -1, max_num;
  if (q<v[0]) {
    cout << p << endl;
  } else if (p>v[n-1]) {
    cout << q << endl;
  } else {
    if (p<v[0]) {
      max_num = p;
      mx = v[0]-p;
    }
    if (q>v[n-1] && (q-v[n-1])>mx) {
      mx = q-v[n-1];
      max_num=q;
    }
    for (int i=0;i<n-1;++i) {
      int mid = (v[i]+v[i+1])/2;
      if (mid>q && v[i]<=q) {
	mid = q;
      } else if (mid<p && v[i+1]>=p) {
	mx=v[i+1]-p;
	max_num = p;
      }
      if (mid>=p && mid<=q && (mid-v[i])>mx) {
	mx = mid-v[i];
	max_num = mid;
      }
    }
    cout << max_num << endl;
  }

  return 0;
}

