#include <bits/stdc++.h>

using namespace std;

int main() {
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int x;
	fin >> x;
	while (true) {
		int a;
		cin >> a;
		cerr << a << '\n';
		if (a == x) {
			cout << "=" << endl;
			return 0;
		} else if (a > x) {
			cout << '>' << endl;
		} else {
			cout << '<' << endl;
		}
	}
}