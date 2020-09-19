#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define MP make_pair
#define sz(v) ((int)((v).size()))
#define rep(i, v) for(int i=0; i<sz(v); ++i)

const int OO = (int)1e6;

vector<int> BFS(int s, vector<vector<int> > & adjList) {
	vector<int> len(sz(adjList), OO);
	queue< pair<int, int> > q;
	q.push(MP(s, 0)), len[s] = 0;

	int cur, dep;
	while (!q.empty()) {
		pair<int, int> p = q.front();	 q.pop();
		cur = p.first, dep = p.second;

		rep(i, adjList[cur]) if (len[adjList[cur][i]] == OO)
			q.push(MP(adjList[cur][i], dep + 1)), len[adjList[cur][i]] = dep + 1;
	}

	return len;	//cur is the furthest node from s with depth dep
}



vector<int> BFS2(int s, vector<vector<int> > & adjList){
	vector<int> len(sz(adjList), OO);
	queue<int> q;
	q.push(s);
	len[s] = 0;
	int dep=0, cur=s, sz=1;
	for(;!q.empty(); ++dep,sz=q.size()){
		while(sz--){
			cur = q.front(), q.pop();
			rep(i,adjList[cur]){
				if(len[adjList[cur][i]] == OO){
					q.push(adjList[cur][i]);
					len[adjList[cur][i]]=dep+1;
				}
			}
		}
	}
	return len;   //cur is the furthest node from s with depth dep
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	freopen("../error.txt", "w", stderr);
#endif
	int n = 7;
	//cout<<"No of vertices: "<<endl;
	//cin>>n;
	vector<vector<int>> adjList(n);

	//adding  1->2,3
	adjList[0].pb(1);
	adjList[0].pb(2);

	//adding 2->4,5
	adjList[1].pb(3);
	adjList[1].pb(4);

	//adding 3->6,7
	adjList[2].pb(5);
	adjList[2].pb(6);

	vector<int> len = BFS2(0, adjList);
	cout << len.front() << endl;
	rep(i, len) {
		cout << len[i] + 1 << " ";
	}
	cout << endl;
	return 0;
}