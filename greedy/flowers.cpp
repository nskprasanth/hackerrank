/**
  * https://www.hackerrank.com/challenges/flowers
  * Prasanth Kalapatapu
  * Sep 1, 2015
 */

/* Sample program illustrating input/output */
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){

  //Helpers for input and output

  int n, k;
  cin >> n >> k;
  vector<int> v;
  //int a[k] = {0};
  for(int i = 0; i < n; i++){
    int cur;
    cin >> cur;
    v.push_back(cur);
  }
  sort(v.begin(), v.end());

  int result =0, multiple = 0;
  for (int i=n-1,j=0;i>=0;--i,++j) {
    if (j%k == 0) {
      ++multiple;
    }
    result += multiple*v[i];
  }

  cout << result << endl;

  return 0;
}

