#include<iostream>
#include<string>
using namespace std;
int a[17],t,n,k;
void init(){
	cin>>n>>k;
}
void print(){
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	cout<<endl;
}
bool check(){
	int count=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1) count++;
		if(count>k) return false;
	}
	if(count!=k) return false;
	return true;
}
void binary(int i){
	for(int j=0;j<=1;j++){
		a[i]=j;
		if(i<n) binary(i+1);
		else {
			if(check()) print();
		}
		;
	}
}
int main(){
	cin>>t;
	while(t--){
		init();
		binary(1);
	}
	
}
