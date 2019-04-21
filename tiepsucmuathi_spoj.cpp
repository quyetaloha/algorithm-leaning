#include <iostream>
using namespace std;

int daythua(int n){
	int k=1;
	for(int i=1;i<=n;i++)
		k=k*i;
	return k;
}
int chop(int n, int k){
	return daythua(n)/(daythua(k)*daythua(n-k));
}
int main() {
	
	// your code here
	int n,m,t,kq=0;
	cin>>n>>m>>t;
	int i=1;
	while(i<m&&i<t){
		kq+= chop(m,i)*chop(n,t-i);
		i++;
	}
	cout<<kq;
	return 0;
}

