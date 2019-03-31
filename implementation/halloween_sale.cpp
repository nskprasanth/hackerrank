/**
  * https://www.hackerrank.com/challenges/halloween-sale/
  * Prasanth Kalapatapu
  * Mar 31, 2019
  */

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main () {
	int p, d, m, s;
	cin >> p >> d >> m >> s;

	int answer = 0;
	int hops_ptom = ceil(1.0 * (p-m)/d);
	int sumtom = (hops_ptom) * (2*p - (hops_ptom-1)*d) / 2;
	if (s >= sumtom) {
		answer = hops_ptom + (s-sumtom) / m;
	} else {
		s -= p;
		while (s >= 0) {
			++answer;
			p -= d;
			s -= p;
		}
	}

	ofstream fout(getenv("OUTPUT_PATH"));
	fout << answer << endl;
	fout.close();
	return 0;
}

