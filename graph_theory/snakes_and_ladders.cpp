/**
 * https://www.hackerrank.com/challenges/the-quickest-way-up
 * Prasanth Kalapatapu
 * Sep 11, 2015
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <map>
using namespace std;

int my_min(int a, int b, int c, int d, int e, int f) {
  int min1 = min(a,b);
  int min2 = min(c,d);
  int min3 = min(e,f);
  int final_min = (min1<min2) ? min(min1,min3) : min(min2,min3);
  return final_min;
}

int main() {
  int t;
  cin >> t;
  for (int nt=0;nt<t;++nt) {
    int num_ladders, num_snakes;
    cin >> num_ladders;
    map<int,int> ladders;
    int first, second;
    for (int i=0;i<num_ladders;++i) {
      cin >> first >> second;
      ladders[first] = second;
    }
    cin >> num_snakes;
    map<int,int> snakes;
    for (int i=0;i<num_snakes;++i) {
      cin >> first >> second;
      snakes[first] = second;
    }

    int moves[101];
    for (int i=0;i<101;++i) {
      moves[i] = INT_MAX;
    }
    moves[1] = 0;
    for(int i=2;i<=7;i++) {
      if(ladders.find(i) != ladders.end()) {
	moves[ladders[i]] = 1; 
      } else if (snakes.find(i) == snakes.end()){
	moves[i] = 1;
      }
    }

    for (int i=8;i<=100;++i) {
      int prev = my_min(moves[i-1], moves[i-2], moves[i-3], moves[i-4], moves[i-5], moves[i-6]);

      int cur_moves = (prev == INT_MAX) ? INT_MAX : prev+1;

      if(ladders.find(i) != ladders.end()) {
	moves[ladders[i]] = min(moves[ladders[i]], cur_moves);
      } else if (snakes.find(i) != snakes.end()) {
	if (cur_moves < moves[snakes[i]]) {
	  moves[snakes[i]] = cur_moves;
	  i = snakes[i];
	}
      } else {
	moves[i] = min(moves[i], cur_moves);
      }
    }
    /*for (int i=0;i<=100;++i) {
      cout << i << "=" << moves[i] << " ";
      }
      cout << endl;*/
    int result = (moves[100] == INT_MAX) ? -1 : moves[100];
    cout << result << endl;
  }
  return 0;
}

