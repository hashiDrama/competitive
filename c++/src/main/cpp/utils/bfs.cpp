/*
	BFS - Graph
*/

#include <bits/stdc++.h>

using namespace std;

template <typename T>
T myMax(T x, T y) {
	return (x > y) ? x : y;
}

/**
	BFS - Graph adjacency list
*/
void bfs(vector< vector< int > > & adjList, vector< bool > visited) {
	queue < int > q;

	q.push(0);
	visited[0] = true;
	int size, curr;
	while (!q.empty()) {
		size = (int)q.size();
		while (size-- > 0) {
			curr = q.front();
			q.pop();
			cout << (curr + 1) << "\t";
			for (int i = 0; i < (int) adjList[curr].size(); i++) {
				if (!visited[adjList[curr][i]]) {
					q.push(adjList[curr][i]);
					visited[curr] = true;
				}
			}
		}
		cout << endl;
	}
}

/**
	DFS - Graph(adjacency matrix)
*/
void dfs(int u, vector< vector< int > > & adjList, vector< bool> visited) {
	cout << (u + 1) << "\t";
	visited[u] = true;
	for (int i = 0; i < (int)adjList[u].size(); i++) {
		if (!visited[adjList[u][i]]) {
			dfs(adjList[u][i], adjList, visited);
		}
	}
}

bool testBipartiteness(vector< vector< int> > adjList, vector< bool> visited){
	queue< int> q;
	int size, curr;
	vector< char > color((int) adjList.size());
	for(int i=0; i<(int)adjList.size(); i++)
		color[i] = 'w';
	q.push(0);
	visited[0] = true;
	color[0] = 'b';
	while(!q.empty()){
		size = q.size();
		while(size-- > 0){
			curr = q.front();
			q.pop();

			for(int i=0; i<(int)adjList[curr].size(); i++){
				if(color[adjList[curr][i]] == color[curr]){
					return false;
				}
				if(!visited[adjList[curr][i]]){
					q.push(adjList[curr][i]);
					visited[adjList[curr][i]] = true;
					color[adjList[curr][i]] = (color[curr] == 'b') ? 'r' : 'b';
				}
			}
		}
	}
	return true;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	freopen("../error.txt", "w", stderr);
#endif

	int v, noOfEdges, t;
	cin >> v;
	vector< vector < int > > adjList(v);
	for (int i = 0; i < v; i++) {
		cin >> noOfEdges;
		for (int j = 0; j < noOfEdges; j++) {
			cin >> t;
			adjList[i].push_back(t);
		}
	}
	vector < bool> visited((int) adjList.size());

	for (int i = 0; i < (int) adjList.size(); i++) {
		visited.push_back(false);
	}
	
	cout<<"BFS: "<<endl;
	bfs(adjList, visited);
	cout<<"DFS: "<<endl;
	dfs(0, adjList, visited);
	cout<<endl;
	bool isBipartite = testBipartiteness(adjList, visited);
	cout<<"Is bipartite: "<<(bool)isBipartite<<endl;
	return 0;
}