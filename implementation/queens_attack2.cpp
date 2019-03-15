/**
 * https://www.hackerrank.com/challenges/queens-attack-2
 * Prasanth Kalapatapu
 * Mar 14, 2019
 */

#include <iostream>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	int r_q, c_q;
	cin >> r_q >> c_q;

	// Set initial boundaries in all 8 directions
	int r_left = r_q, c_left = 0;
	int r_right = r_q, c_right = n+1;
	int r_top = n+1, c_top = c_q;
	int r_bottom = 0, c_bottom = c_q;

	int r_left_top = r_q + min(n+1 - r_q, c_q);
	int r_left_bottom = r_q - min (r_q, c_q);
	int r_right_top = r_q + min(n+1 - r_q, n+1 - c_q);
	int r_right_bottom = r_q - min(r_q, n+1 - c_q);

	// Modify the boundaries if we run into any obstacles
	int r_cur, c_cur;
	for (int i=0;i<k;++i) {
		cin >> r_cur >> c_cur;

		if (r_cur == r_q && c_cur < c_q) { // left
			c_left = ((c_q - c_cur) < (c_q - c_left)) ? c_cur : c_left;
		} 
		else if (r_cur == r_q && c_cur > c_q) { // right
			c_right = ((c_cur - c_q) < (c_right - c_q)) ? c_cur : c_right;
		} 
		else if (c_cur == c_q && r_cur < r_q) { // bottom
			r_bottom = ((r_q - r_cur) < (r_q - r_bottom)) ? r_cur : r_bottom;
		} 
		else if (c_cur == c_q && r_cur > r_q) { // top
			r_top = ((r_cur - r_q) < (r_top - r_q)) ? r_cur : r_top;
		} 
		else if(r_cur > r_q && (r_cur - r_q) == (c_q - c_cur)) { // left top
			r_left_top = min (r_left_top, r_cur);
		}
		else if(r_cur < r_q && (r_q - r_cur) == (c_q - c_cur)) { // left bottom
			r_left_bottom = max (r_left_bottom, r_cur);
		}
		else if(r_cur > r_q && (r_cur - r_q) == (c_cur - c_q)) { // right top
			r_right_top = min (r_right_top, r_cur);
		}
		else if(r_cur < r_q && (r_q - r_cur) == (c_cur - c_q)) { // right bottom
			r_right_bottom = max (r_right_bottom, r_cur);
		}
	}

	long long total_attacks = 0;
	// left + right + top + bottom
	total_attacks += (c_q - c_left - 1) + (c_right - c_q - 1) + (r_top - r_q - 1) + (r_q - r_bottom - 1);
	// left_top + left_bottom
	total_attacks += (r_left_top - r_q - 1) + (r_q - r_left_bottom - 1); 
	// right_top + right_bottom
	total_attacks += (r_right_top - r_q - 1) + (r_q - r_right_bottom - 1);

	cout << total_attacks << endl;

}

