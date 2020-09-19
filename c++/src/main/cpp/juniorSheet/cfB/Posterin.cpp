#include <bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	freopen("../../error.txt", "w", stderr);
#endif
	int N, ans=0;
	cin>>N;
	int d[N], h[N];
	stack<int> s;
	for(int i=0; i<N; i++){
		cin>>d[i]>>h[i];
		if(s.empty()){
			ans++;
			s.push(h[i]);
		}else if(s.top() < h[i]){
			s.push(h[i]);
			ans++;
		}else{
			while(s.top() > h[i]){
				s.pop();
				if(s.empty())
					break;
			}
			if(s.empty()){
				s.push(h[i]);
				ans++;
			}else{
				if(s.top() == h[i])
					continue;
				else{
					s.push(h[i]);
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}