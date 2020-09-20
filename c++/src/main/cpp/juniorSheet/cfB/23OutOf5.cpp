#include <bits/stdc++.h>
using namespace std;


bool isPossible(int total, int a[5], int i){
	if(i == 5)
		return total == 23;
	return isPossible(total + a[i], a, i+1)
	|| isPossible(total - a[i], a, i+1)
	|| isPossible(total * a[i], a, i+1);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	freopen("../../error.txt", "w", stderr);
#endif
	while(true){
		int a[5];
		bool allZero = true;
		for(int i=0; i<5; i++){
			cin>>a[i];
			if(a[i] != 0)
				allZero = false;
		}
		if(allZero)
			break;
		if(isPossible(a[0], a, 1))
			cout<<"Possible"<<endl;
		else
			cout<<"Impossible"<<endl;
	}
	return 0;
}