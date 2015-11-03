/**
  * Problem: https://www.hackerrank.com/challenges/candies
  * Author: Prasanth Kalapatapu
  * Sep 25, 2015
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
  int ratings[n];
  int candies[n];
  for (int i=0;i<n;++i) {
    cin >> ratings[i];
  }
  candies[0]=1;
  for (int i=1;i<n;++i) {
    if (ratings[i]>ratings[i-1]) {
      candies[i] = candies[i-1]+1; 
    } else {
      candies[i]=1;
    }
  }
  for (int i=n-2;i>=0;--i) {
    if (ratings[i]>ratings[i+1]) {
      candies[i] = max(candies[i], candies[i+1]+1);
    }
  }
  int sum = 0;
  for (int i=0;i<n;++i) {
    sum+=candies[i];
  }
  cout << sum << endl;
  return 0;
}

