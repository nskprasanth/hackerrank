/**
  * https://www.hackerrank.com/challenges/mark-and-toys
  * Prasanth Kalapatapu
  * Sep 4, 2015
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
  long long n, k; 
  cin >> n >> k;
  vector<int> prices;
  for(int i = 0; i < n; i++)
  {
    int p; cin >> p;
    prices.push_back(p);
  }

  int answer = 0;
  int sum = 0;

  sort(prices.begin(), prices.end());
  for (int i=0;i<prices.size();++i) {
    if (sum+prices[i] <= k) {
      sum += prices[i];
      ++answer;
    } else {
      break;
    }
  }

  cout << answer << endl;

  return 0;
}

