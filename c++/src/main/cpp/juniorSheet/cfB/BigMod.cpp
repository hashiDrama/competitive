#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int mod(int b, int p, int m) {
	if (p == 0) {
		return 1;
	}
	if (p % 2 == 0) {
		int x = mod(b, p / 2, m);
		return (x * x) % m;
	}
	return (b % m * mod(b, p - 1, m)) % m;
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	freopen("../../error.txt", "w", stderr);
#endif
	int b, p , m;
	while (cin >> b >> p >> m) {
		cout << mod(b, p, m) << endl;
	}
	return 0;
}