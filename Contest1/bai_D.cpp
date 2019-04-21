#include<iostream>
#include<string>
using namespace std;
int a[11][11],hau[11];
int cot[11],cheo1[21],cheo2[21];
int count;
void init(){
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<8;i++){
		cot[i]=1;
	}
	for(int i=0;i<2*8;i++){
		cheo1[i]=1;
		cheo2[i]=1;
	}
	count=0;
}
void check(){
	int tong=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(hau[i]==j) tong+=a[i][j];
		}
	}
	if(tong>count) count=tong;
}
void backtracking(int i){
	for(int j=0;j<8;j++){
		if(cot[j]&&cheo1[i+j]&&cheo2[j-i+8]){
			hau[i]=j;
			cot[j]=0;
			cheo1[i+j]=0;
			cheo2[j-i+8]=0;
			if(i==7) check();
			else backtracking(i+1);
			cot[j]=1;
			cheo1[i+j]=1;
			cheo2[j-i+8]=1;
		}
	}
		
}
int main(){
	int t;cin>>t;
	while(t--){
		init();
		backtracking(0);
		cout<<count<<endl;
	}
	
}
