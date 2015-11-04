/**
  * https://www.hackerrank.com/challenges/board-cutting
  * Prasanth Kalapatapu
  * Oct 11, 2015
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
  unsigned long long int rem = pow(10,9)+7;
  for (int nt=0;nt<t;++nt) {
    int m, n;
    cin >> m >> n;
    long long int a[m-1], b[n-1];
    for (int i=0;i<m-1;++i) {
      cin >> a[i];
    }
    for (int i=0;i<n-1;++i) {
      cin >> b[i];
    }
    sort (a, a+m-1);
    sort (b, b+n-1);

    long long int v=1, h=1;
    unsigned long long int sum=0;
    // 1 1 2 3 4
    // 1 2 4
    int i=m-2, j=n-2;
    while(i>=0 && j>=0) {
      if (a[i]>=b[j]) {
	sum = (sum+a[i]*v)%rem;
	++h;
	--i;
      } else {
	sum = (sum+b[j]*h)%rem;
	++v;
	--j;
      }
    }
    while (i>=0) {
      sum = (sum+a[i]*v)%rem;
      --i;
    }
    while (j>=0) {
      sum = (sum+b[j]*h)%rem;
      --j;
    }
    cout << sum << endl;
  }
  return 0;
}

