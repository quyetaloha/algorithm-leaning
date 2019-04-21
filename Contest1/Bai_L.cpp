#include<iostream>
using namespace std;
int s[100];
void  fibonaci(int n){
	s[1]=1,s[2]=1;;
	int i=3;
	while(i<=n){
		s[i]=s[i-2]+s[i-1];
		i++;
	}
		
}
char tinh(int n,int i){
	if(n==1)
		 return 'A'; 
	if(n==2)
		 return 'B';
	if(i>s[n-2]) {
		i-=s[n-2];
		n=n-1;
		return tinh(n,i);
	}
	else {
		n=n-2;return tinh(n,i);
	}
}
int main(){
	int t;cin>>t;
	while(t--){
		int n,i;cin>>n>>i;
		fibonaci(n);
		cout<<tinh(n,i);
	}
	
}
