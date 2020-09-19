#include <bits/stdc++.h>
using namespace std;

/**
	Checks a win configuration.
*/
bool is_win(string config) {
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

/**
	This is a special way of solving this problem since this thinking may not occurr naturally to coder at the time of contest.
	Normally, one might have solved each step and checked with board string and if matches then returned yes.
*/
bool playAndCheck(string board) {
	string start = ".........";

	queue< pair< string, bool> > qu;
	qu.push({start, 1});

	bool ans = 0;
	while (!qu.empty()) {
		string cur = qu.front().first;
		bool cur_player = qu.front().second;
		qu.pop();

		if (cur == board) {
			ans = 1;
			break;
		}

		if (is_win(cur)) continue;
		for (int i = 0; i < 9; i++) {
			if (cur[i] == '.') {
				cur[i] = cur_player ? 'X' : 'O';
				if (cur[i] ==  board[i])
					qu.push({cur, 1 ^ cur_player});
				cur[i] = '.';
			}
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	freopen("../../error.txt", "w", stderr);
#endif
	int t;
	cin >> t;
	while (t-- > 0) {
		string board = "";
		for (int i = 0; i < 3; i++) {
			string row;
			cin >> row;
			board += row;
		}
		if(playAndCheck(board))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}
