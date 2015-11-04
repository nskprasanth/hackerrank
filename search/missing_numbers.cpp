/**
  * https://www.hackerrank.com/challenges/missing-numbers
  * Prasanth Kalapatapu
  * Sep 2, 2015
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int,int> map1;
  for (int i=0;i<n;++i) {
    int cur;
    cin >> cur;
    if (map1.find(cur) == map1.end()) {
      map1[cur] = 0;
    } else {
      ++map1[cur];
    }
  }
  int m;
  cin >> m;
  map<int,int> map2;
  for (int i=0;i<m;++i) {
    int cur;
    cin >> cur;
    if (map2.find(cur) == map2.end()) {
      map2[cur] = 0;
    } else {
      ++map2[cur];
    }
  }
  for (map<int,int>::iterator it=map2.begin(), end=map2.end(); it!=end;++it) {
    if (map1.find(it->first) == map1.end()) {
      cout << it -> first << " ";
    } else if (map1[it->first] != it->second) {
      cout << it->first << " ";
    }
  }
  cout << endl;
  return 0;
}

