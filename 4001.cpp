#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int pf(int a){
	int x;
	if(sqrt(a)==int(sqrt(a))){
		x=1;
	}
	else{
		x=0;
	}
	return x;
}
int main(){
	
	int a;
	cin>>a;
	if(pf(a)==1){
		cout<<"Yes";
	}
	else{
		cout<<"No"; 
	}

	return 0;
}
