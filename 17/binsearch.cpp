#include <bits/stdc++.h>

using namespace std;

int main() {
	int l = -1;
	int r = 10000;
	while (r - l > 1) {
		int m = (l + r) / 2;
		cout << m << endl;
		char x;
		cin >> x;
		cerr << "GOT SIGN " << x << endl;
		if (x == '=') {
			return 0;
		} else if (x == '>') {
			r = m;
		} else {
			l = m;
		}
	}
}