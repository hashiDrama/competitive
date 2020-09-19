#include <bits/stdc++.h>
using namespace std;


int main(){

#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	freopen("../../error.txt", "w", stderr);
#endif

	int x0, y0, x1, y1, n;
	cin>>x0>>y0>>x1>>y1>>n;

	set<pair<int, int> > pts;
	int r, a, b;
	for(int i=0; i<n; i++){
		cin>>r>>a>>b;
		for(int j=a; j<=b; j++){
			pts.insert({r, j});
		}
	}

	int dx[] = {1, 0, -1, 0, -1, 1, -1, 1};
	int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

	map<pair< int, int>, int> len;
	queue<pair<int, int> > q;

	pair<int, int> start = {x0, y0};
	q.push(start);
	len[start] = 0;

	int dep = 0, sz=1;
	pair<int, int> cur;
	for(; !q.empty(); dep++, sz = q.size()){
		while(sz--){
			cur = q.front();
			q.pop();

			for(int k=0; k<8; k++){
				int nr = cur.first + dx[k];
				int nc = cur.second + dy[k];

				pair<int, int> np = {nr, nc};
				if(pts.count(np) == 0 || len.count(np) != 0)
					continue;

				if(np.first == x1 && np.second == y1){
					cout<< dep+1;
					return 0;
				}

				q.push(np);
				len[np] = dep+1;
			}
		}
	}
	cout<<-1;
	return 0;

}