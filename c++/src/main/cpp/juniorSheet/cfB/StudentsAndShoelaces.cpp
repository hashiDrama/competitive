#include <bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	freopen("../../error.txt", "w", stderr);
#endif
	int n,m, i1, i2;
	cin>>n>>m;
	vector<set<int> > adjList(n+1);
	for(int i=0; i<m; i++){
		cin>>i1>>i2;
		adjList[i1].insert(i2);
		adjList[i2].insert(i1);
	}
	int g_count = 0, temp;
	while(true){
		vector<int> v;
		for(int i=1; i<=n; i++){
			if(adjList[i].size() == 1)
				v.push_back(i);
		}
		for(int i=0; i<(int)v.size(); i++){
			set<int>::iterator it = adjList[v[i]].begin();
			adjList[v[i]].clear();
			adjList[*it].erase(v[i]);
		}

		if(v.size())
			g_count++;
		else
			break;
	}
	cout<<g_count;
	return 0;
}