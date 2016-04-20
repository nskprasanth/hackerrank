/**
  * https://www.hackerrank.com/challenges/maximise-sum
  * Prasanth Kalapatapu
  * Apr 20, 2016
  */ 

#include <iostream>
#include <set>
using namespace std;

long long max(long long a, long long b, long long c) {
  if (a>b) {
    return (a>c)?a:c;
  } else {
    return (b>c)?b:c;
  }
}

int main() {
  int t;
  cin >> t;

  while(t--) {
    int n;
    long long m;
    cin >> n;
    cin >> m;
    long long a[n];

    for (int i=0;i<n;++i) {
      cin >> a[i];
      a[i] = a[i]%m;
    }

    long long sum=0;
    set<long long> prev_set;
    long long max_sum = -1;

    for (int i=0;i<n;++i) {
      sum+=a[i];
      sum=sum%m;

      set<long long>::iterator itup = prev_set.upper_bound(sum);
      long long upb = -1;
      if (itup != prev_set.end()) {
	upb = m + sum - *itup;
      }
      max_sum = max(max_sum, sum, upb);

      prev_set.insert(sum);
    }

    cout << max_sum << endl;

  }
}
