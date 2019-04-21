#include<iostream>
#include<string>
using namespace std;
int a[17],t,n,k,dem=0;
void init(){
	cin>>n>>k;
}
void print(){
	for(int i=1;i<=n;i++){
		cout<<char(a[i]+65);
	}
	cout<<endl;
}
bool check(){
	int count=0;
	for(int i=1;i<n;i++){
		if(a[i]==0){
			int j=i;
			int d=1;
			while(a[j]==a[j+1]){
				d++;
				j++;
				if(j==n) break;
			}
			i=i+d;
			if(d==k)	count++;
		}
		
	}
	if(count!=1) return false;
	
	return true;
}
void binary_dem(int i){
	for(int j=0;j<=1;j++){
		a[i]=j;
		if(i<n) binary_dem(i+1);
		else {
			if(check()) dem++;
		}
		
	}
}
void binary_in(int i){
	for(int j=0;j<=1;j++){
		a[i]=j;
		if(i<n) binary_in(i+1);
		else {
			if(check()) print();
		}
		
	}
}
int main(){
	
	init();
	binary_dem(1);
	cout<<dem<<endl;
	binary_in(1);

}
