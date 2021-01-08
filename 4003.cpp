#include<cstdio>
#include<iostream>
using namespace std;
int main(){

    int a[10005];
    int i=0;
    do{
        i++;
        cin>>a[i];
    }while(a[i]!=0);
    for(int x=2;x<=i;x++){
		int key=a[x];
		int j=x-1;
		while(j>=1&&key>a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;	
	} 
    for(int x=1;x<i;x++){
        cout<<a[x]<<' ';
    }

    return 0;
}
