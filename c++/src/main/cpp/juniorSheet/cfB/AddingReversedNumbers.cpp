#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
using namespace std;


void format(string &s){
	int i=0; 
	while(i<s.length() && s[i]=='0')
		i++;
	s = s.substr(i);
}

string add(string a, string b){
	string larger = a.length()>b.length() ? a : b;
	string smaller = a.length() < b.length() ? a : b;
	cout<<larger<<" "<<smaller<<endl;

	char* result = new char[larger.length()+1];
	int i, carry = 0, sum;
	for(i = 0; i<smaller.length(); i++){
		sum = 0;
		sum = (larger[i]-'0') + (smaller[i] - '0');
		sum += carry;
		result[i] = sum/10;
		carry = sum%10;
		cout<<i<<": "<<result<<endl;
	}
	cout<<result<<endl;
	while(i<larger.length()){
		sum = 0;
		sum = (larger[i]-'0') + carry;
		result[i] = sum/10;
		carry = sum%10;
		i++;
	}
	if(carry > 0){
		result[i] = carry;
	}
	return string(result);
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	freopen("../../error.txt", "w", stderr);
#endif

	string a, b;
	cin>>a>>b;
	cout<<a<<" "<<b<<endl;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	cout<<a<<" "<<b<<endl;
	format(a);
	format(b);
	cout<<a<<" "<<b<<endl;
	string result = add(a, b);
	cout<<result<<endl;
	format(result);
	cout<<result<<endl;
	return 0;
}