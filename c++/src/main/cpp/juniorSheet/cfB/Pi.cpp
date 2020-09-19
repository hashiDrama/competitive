#include <iostream>
#include <math.h>

using namespace std;

int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b, a%b);
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	freopen("../../error.txt", "w", stderr);
#endif

	while(true){
		int n;
		cin>>n;
		if(n==0)break;
		int a[n];
		for(int i=0; i<n; i++)
			cin>>a[i];
		double t = (double) (n*(n-1))/2;
		int pairs = 0;
		for(int i=0; i<n-1; i++){
			for(int j=i+1; j<n; j++){
				if(gcd(a[i],a[j]) == 1) pairs++;
			}
		}
		if(pairs != 0){
			double ans = sqrt((6*t)/pairs);
		printf("%.6f\n", ans);
		}else{
			cout<<"No estimate for this data set."<<endl;
		}
	}
}