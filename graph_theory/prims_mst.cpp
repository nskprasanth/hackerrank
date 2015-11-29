/**
  * https://www.hackerrank.com/challenges/primsmstsub
  *
  * Prasanth Kalapatapu
  * Nov 29, 2015
 */
#include <iostream>
#include <climits>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  
  int graph[n+1][n+1];
  bool in_mst[n+1];
  int edge[n+1];

  for (int i=0;i<=n;++i) {
    edge[i] = INT_MAX;
    in_mst[i] = false;

    for (int j=0;j<=n;++j) {
      graph[i][j] = (i==j)?0:-1;
    }
  }

  for (int i=0;i<m;++i) {
    int x, y, r;
    cin >> x >> y >> r;
    if (graph[x][y]<0 || r<graph[x][y]) {
      graph[x][y] = graph[y][x] = r;
    }
  }
  int begin; cin >> begin;

  long long int sum_mst = 0;
  edge[begin] = 0; // add the begin node to MST
  int min = begin;

  for (int k=0;k<n;++k) {
    sum_mst += edge[min]; // add up the new edge

    in_mst[min] = true;
    
    int min_edge = INT_MAX, new_min = min;
    for (int i=1;i<=n;++i) {
      if (graph[min][i]>=0 && !in_mst[i] && graph[min][i]<edge[i]) {
	edge[i] = graph[min][i];
      }
      
      if (!in_mst[i] && edge[i]<min_edge) {
	new_min = i;
	min_edge = edge[i];
      }
    }
    min = new_min;
  }

  cout << sum_mst << endl;

  return 0;
}
