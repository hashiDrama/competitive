#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> BigInt;

void Set(BigInt &a){
	while(a.size() > 1 && a.back() == 0) a.pop_back();
}

BigInt Integer(string s){
	BigInt ans;
	if(s[0] == '-') return ans;
	if(s.size() == 0) {
		ans.pb(0);
		return ans;
	}
	while(s.size()%9 != 0) s = '0'+s;
	for(int i=0; i<s.size(); i+=9){
		int v=0;
		for(int j=i; j<i+9; j++) {
			v = v*10 + (s[j] - '0');
		}
		ans.push_back(v);
	}
	Set(ans);
	return ans;
}

void Print(BigInt a){
	//Set(a);
	printf("%d", (a.size() == 0 ? 0 : a.back()));
	for(int i=a.size()-2; i>0; i--)
		printf("%9d", a[i]);
		printf("\n");
}

int main(){
	string s;
	s="123456789800";
	BigInt ans = Integer(s);
	Print(ans);
	// BigInt temp;
	// temp.push_back(1);
	// temp.push_back(2);
	for(int x : ans){
		cout<<x;
	}
	//Print(temp);
}