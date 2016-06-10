/**
  * https://www.hackerrank.com/challenges/bear-and-workbook
  * Prasanth Kalapatapu
  * Jun 9, 2016
  */

#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int a[n];
  for (int i=0;i<n;++i) {
    cin >> a[i];
  }

  // 4 2 6 1 10
  int page=1, beg=0, end=0;
  int count=0;
  for (int chap=0;chap<n;++page) {

    bool chap_change = false;
    
    if (beg+k < a[chap]) {
      end=beg+k;
    } else {
      end = a[chap];
      ++chap;
      chap_change = true;
    }

    if (beg < page && page <=end) {
      ++count;
    }

    beg = chap_change ? 0:end;
  }
  cout << count << endl;
  return 0;
}
