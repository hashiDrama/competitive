#include <bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	freopen("../../error.txt", "w", stderr);
#endif
	
	int tb, tc, s, d;
	cin>>tb>>tc>>s>>d;

	int ans = 0;
	if(s<d){
		ans = (d-s-1) * tb + (d-s)*2 * tc;
	}else{
		ans = (s-d+1)*tb + (s-d)*2*tc;
	}
	cout<<ans;
	return 0;
}