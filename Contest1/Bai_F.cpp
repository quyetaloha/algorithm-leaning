#include<iostream>
using namespace std;
int n;
int tien[10]={1000,500,200,100,50,20,10,5,2,1};
int kq;
void init(){
	cin>>n;
	kq=0;
}
void tinh(){
	int i=0;
	while(n!=0){
		kq+=n/tien[i];
		n%=tien[i];
		i++;
	}
}
int main(){
	int t;cin>>t;
	while(t--){
		init();
		tinh();
		cout<<kq<<endl;
	}
}
