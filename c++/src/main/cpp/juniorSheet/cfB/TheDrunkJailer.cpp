#include <iostream>
using namespace std;

int main() {
#ifndef ONLIE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	freopen("../../error.txt", "w", stderr);
#endif
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		bool b[n];
		for(int i=0; i<n; i++)
			b[i] = false;
		int round = 1;
		while (round <= n) {
			for (int i = 0; i < n; i++) {
				if ((i + 1) % round == 0)
					b[i] = !b[i];
			}
			round++;
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (b[i]) count++;
		}
		cout << count << endl;
	}
	return 0;
}