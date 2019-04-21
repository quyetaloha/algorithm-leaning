#include<iostream>
#include<cmath>
using namespace std;
int d;
int tinh(int n,long k){
	// vi tri o giua
	if(k==d) return n;
	else{
		if(k>d) {
			k-=d;
			n--;d/=2;
			return tinh(n,k);
		}
		if(k<d) {
				n--;d/=2;
				return tinh(n,k);
			}
	}
}
int main(){
	
	int t;cin>>t;
	while(t--){
		int n;
		long k;
		cin>>n>>k;
		d=pow(2,n-1);
		
			cout<<tinh(n,k)<<endl;
			
	}
	
}
