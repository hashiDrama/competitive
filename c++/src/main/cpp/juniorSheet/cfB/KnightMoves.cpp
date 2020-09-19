#include<bits/stdc++.h>
using namespace std;


int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

bool isValid(int r, int c){
	return r>=0 && c>=0 && r<8 && c<8;
}

int bfs(int sr, int sc, int tr, int tc){
	queue<int> q;
	q.push(sr);
	q.push(sc);

	int d[10][10];
	memset(d, -1, sizeof(d));
	d[sr][sc]=0;

	while(!q.empty()){
		int r = q.front(); q.pop();
		int c = q.front(); q.pop();

		if(r == tr && c == tc)
			return d[r][c];

		for(int k=0; k<8; k++){
			int nr = r+dx[k];
			int nc = c+dy[k];

			if(!isValid(nr, nc)) continue;
			if(d[nr][nc] == -1){
				q.push(nr);
				q.push(nc);

				d[nr][nc] = d[r][c]+1;
			}
		}
	}
	return -1;
}


int main(){

#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	freopen("../../error.txt", "w", stderr);
#endif

	string input;
	while(cin>>input){
		string s = input;
		cin>>input;
		string t = input;

		int sr = s[1]-'1';
		int sc = s[0]-'a';
		int tr = t[1]-'1';
		int tc = t[0]-'a';
		int moves = bfs(sr, sc, tr, tc);
		cout<<"To get from "<<s<<" to "<<t<<" takes "<<moves<<" knight moves."<<endl;
	}
	return 0;
}