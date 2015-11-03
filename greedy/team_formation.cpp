/**
  * Problem Statement - https://www.hackerrank.com/challenges/team-formation
  * Nov 2, 2015
  * Author: Prasanth Kalapatapu
  */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

void print(const map<long long, multiset<int> >& hash) {
  for (map<long long, multiset<int> >::const_iterator it=hash.begin(), end=hash.end(); it!=end;++it) {
    cout << it->first << ": [";
    const multiset<int>& myset = it->second;
    for (multiset<int>::const_iterator sit=myset.begin(), send=myset.end(); sit!=send; ++sit) {
      cout << *sit << " ";
    }
    cout <<"]" << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    if (n==0) {
      cout << 0 << endl;
      continue;
    }

    vector<long long> v;
    long long cur;
    for (int i=0;i<n;++i) {
      cin >> cur;
      v.push_back(cur);
    }
    sort(v.begin(), v.end());

    map<long long, multiset<int> > hash;
    for (int i=0;i<v.size();++i) {
      long long cur = v[i];
      map<long long, multiset<int> >::iterator it = hash.find(cur-1);
      if (it == hash.end()) {
	hash[cur].insert(1);
      } else {
	multiset<int>& myset = hash[cur-1];
	multiset<int>::iterator set_iter = myset.begin();

	hash[cur].insert(1+*set_iter);

	myset.erase(set_iter);
	if(myset.empty()) {
	  hash.erase(it);
	}
      }
    }

    int ans = pow(10,5)+1;
    for (map<long long, multiset<int> >::const_iterator it=hash.begin(), end=hash.end(); it!=end;++it) {
      int cur=*(it->second.begin());
      if (cur<ans) {
	ans=cur;
      }
    }

    //print(hash);
    //cout << endl;
    cout << ans << endl;
  }
  return 0;
}

