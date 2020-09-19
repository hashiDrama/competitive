#include <iostream>
using namespace std;

int main(){
#ifndef ONLIE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	freopen("../../error.txt", "w", stderr);
#endif

	int a,b,c,d;

	cin>>a>>b>>c>>d;
	while(a<c){
		if(a+b >= c){
			a=c;
			break;
		}
		a += b;
		c -= d;
	}
	cout<<a<<endl;
	return 0;
}