#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main(){
#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	freopen("../../error.txt", "w", stderr);
#endif

	int n, k;
	cin>>n>>k;
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	int a[n+1];
	for(int i=1; i<=n; i++){
		cin>>a[i];
		a[i] += a[i-1];
	}
	int mn = INT_MAX, idx=0;
	for(int i=1; i<=n-k; i++){
		if(mn > a[i+k-1]-a[i-1]){
			mn = a[i+k-1]-a[i-1];
			idx = i;
		}
	}

	cout<<idx<<endl;
	return 0;
}