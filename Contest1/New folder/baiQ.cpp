#include<iostream>
#include<queue>
using namespace std;

void xuly(int n){
	
	queue<int> q;
	if(n==0)
		return;
	else{
		q.push(1);
	}
	for(int i=1;i<=n;i++){
		int kq=q.front();
		q.pop();
		q.push(kq*10+0);
		q.push(kq*10+1);
		cout<<kq<<" ";
	}
	
}

main(){
	
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		xuly(n);
		cout<<endl;
	}
}
