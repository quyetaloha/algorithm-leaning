#include<iostream>
#include<list>
#include<cmath>
using namespace std;
int n,dem=0;
list<int> lis;
void init(){
	cin>>n;dem=0;
}
bool ktngto(int k){
	for(int i=2;i<=sqrt(k);i++){
		if(k%i==0) return false;
	}
	return true;
}
int ngtotiep(int i){
	if(i==2) return 3;
	for(int j=i+2;;j++){
		if(ktngto(j)) return j;
	}
}
void tinh(){
	int nt=2;
	while(nt<n){
		if(n%nt==0)  lis.push_back(nt);
		else nt=ngtotiep(nt);
	}
}
int main(){
	int t;cin>>t;
	while(t--){
		init();
		tinh();
		list<int>::iterator it;
    	for( it =lis.begin()  ; it!=lis.end(); it++) {
        cout<<*it<<" " ;
    }
	}
}
