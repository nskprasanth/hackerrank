/**
 * https://www.hackerrank.com/challenges/non-divisible-subset/
 * Prasanth Kalapatapu
 * Aug 9, 2018
 */

#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int counts[k] = {0};
  int cur;
  for (int i=0;i<n;++i) {
    cin >> cur;
    ++counts[cur%k]; // group them by remainder of k
  }

  // only one multiple of k can be in the final subset
  int maxSubset = (counts[0] > 0) ? 1 : 0;

  int loopEnd = (k%2 == 0) ? k/2-1 : k/2;
  for (int i=1; i<= loopEnd;++i) {
    // only one group between i or k-i can be kept; include the bigger subset
    maxSubset += max(counts[i], counts[k-i]);
  }

  // if k is even, only one of the numbers with remainder k/2 can be included
  maxSubset += (k%2==0 && counts[k/2]>0) ? 1:0; 

  cout << maxSubset << endl;
  return 0;
}
