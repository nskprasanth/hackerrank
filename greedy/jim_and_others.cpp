/**
  * https://www.hackerrank.com/challenges/jim-and-the-orders
  * Prasanth Kalapatapu
  * Sep 4, 2015
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
  multimap<int, int> m;
  for (int i=0;i<n;++i) {
    int t, d;
    cin >> t >> d;
    m.insert(pair<int,int>(t+d, i+1));
  }
  for (multimap<int,int>::iterator it=m.begin(), end = m.end(); it!=end;++it) {
    cout  << it->second << " ";
  }
  cout << endl;
  // compute the delivery time values - put these values as keys and customer no.s as values in a multimap
  return 0;
}

