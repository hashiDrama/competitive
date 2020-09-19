#include <iostream>
using namespace std;

double fact(int a){
	long long f = 1;
	int i;
	for(i=a; i>0; i--){
		f = f*(double)i;
	}
	return f;
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("../../input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("../../output.txt", "w", stdout);
	// for writing error to error.txt
	freopen("../../error.txt", "w", stderr);
#endif
	int n=5, m;
	cout<<fact(100)<<endl;
	// while(true){
	// 	cin>>n>>m;
	// 	if(n==0 && m ==0){
	// 		break;
	// 	}
	// 	long long combination = fact(n) / (fact(n-m)*fact(m));
	// 	cout<<n<<" things taken "<<m<<" at a time is "<<combination<<" exactly."<<endl;
	// }

}
