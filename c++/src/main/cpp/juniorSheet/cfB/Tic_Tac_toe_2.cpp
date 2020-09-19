#include <bits/stdc++.h>
using namespace std;

/**
	Checks a win configuration.
*/
bool is_win(string config) {
	bool is_full = true;
	for (int i = 0; i < 9; i++) {
		if (config[i] == '.') {
			is_full = false;
			break;
		}
	}
	if (is_full)
		return true;

	bool rows =
	    (config[0] != '.' && config[0] == config[1] && config[1] == config[2]) ||
	    (config[3] != '.' && config[3] == config[4] && config[4] == config[5]) ||
	    (config[6] != '.' && config[6] == config[7] && config[7] == config[8]);

	bool cols =
	    (config[0] != '.' && config[0] == config[3] && config[3] == config[6]) ||
	    (config[1] != '.' && config[1] == config[4] && config[4] == config[7]) ||
	    (config[2] != '.' && config[2] == config[5] && config[5] == config[8]);

	bool diags =
	    (config[0] != '.' && config[0] == config[4] && config[4] == config[8]) ||
	    (config[2] != '.' && config[2] == config[4] && config[4] == config[6]);

	return rows || cols || diags;
}

void pre_calc(set<string> & valid) {
	queue<pair< string, bool> > state_q;
	string start = ".........";
	state_q.push({start, 1});

	while (!state_q.empty()) {
		string c_state = state_q.front().first;
		bool c_player = state_q.front().second;
		state_q.pop();

		if (is_win(c_state))continue;
		for (int i = 0; i < 9; i++) {
			if (c_state[i] == '.') {
				string n_state = c_state;
				n_state[i] = c_player ? 'X' : 'O';
				valid.insert(n_state);
				state_q.push({n_state, 1 ^ c_player});
			}
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	freopen("../../error.txt", "w", stderr);
#endif

	set<string> valid;
	pre_calc(valid);

	string input;
	while (true) {
		cin >> input;
		if (input != "end") {
			if (valid.find(input) != valid.end() && is_win(input))
				cout << "valid";
			else
				cout << "invalid";
			cout << endl;
		}else{
			break;
		}
	}
	return 0;
}