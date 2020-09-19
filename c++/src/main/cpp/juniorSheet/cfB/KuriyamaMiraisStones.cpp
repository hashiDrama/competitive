#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	freopen("../../error.txt", "w", stderr);
#endif

	int n;
	cin>>n;
	long long a[n], b[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
		b[i] = a[i];
	}
	sort(b, b+n);
	for(int i=1; i<n; i++){
		a[i] += a[i-1];
		b[i] += b[i-1];
	}
	int q;
	cin>>q;
	int type, l, r;
	while(q-- > 0){
		cin>>type>>l>>r;
		if(type == 1){
			if(l==1)
				cout<<a[r-1]<<endl;
			else
				cout<<(a[r-1]-a[l-2])<<endl;
		}else{
			if(l==1)
				cout<<b[r-1]<<endl;
			else
				cout<<(b[r-1]-b[l-2])<<endl;
		}
	}
	return 0;
}