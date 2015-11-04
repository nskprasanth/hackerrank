/**
  * https://www.hackerrank.com/challenges/chief-hopper
  * Prasanth Kalapatapu
  * Oct 10, 2015
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_neg(long double enrg, long long cur) {
  return (enrg < (cur-enrg));
}

int main() {
  long long n, cur, ans;
  long double enrg;
  cin >> n;
  cin >> cur;
  ans = (cur%2) ? (1+cur/2) : cur/2;
  enrg = ans - (cur-ans);
  bool flag = (n==cur);
  for (int i=1;i<n;++i) {
    cin >> cur; 
    flag = flag & ((n-i) == cur);
    if (cur>enrg && is_neg(enrg, cur)) {
      long double temp = (cur%2) ? (1+cur/2) : cur/2;
      double power = pow(2,i);
      temp = max(temp, enrg+power);
      while ((int)(temp-enrg)%(int)power != 0) {
	++temp;
      }
      ans += (temp-enrg)/power;
      enrg = temp;
    }
    enrg += (enrg-cur);
  }
  if (flag) { cout << n << endl; }
  else { cout << ans << endl; }
  return 0;
}

