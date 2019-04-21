#include<iostream>
#include<string>
using namespace std;
int n;
int hau[11];
int cot[11],cheo1[21],cheo2[21];
int count;
void init(){
	cin>>n;
	for(int i=0;i<n;i++){
		cot[i]=1;
	}
	for(int i=0;i<2*n;i++){
		cheo1[i]=1;
		cheo2[i]=1;
	}
	count=0;
}
void backtracking(int i){
	for(int j=0;j<n;j++){
		if(cot[j]&&cheo1[i+j]&&cheo2[j-i+n]){
			hau[i]=j;
			cot[j]=0;
			cheo1[i+j]=0;
			cheo2[j-i+n]=0;
			if(i==n-1) count++;
			else backtracking(i+1);
			cot[j]=1;
			cheo1[i+j]=1;
			cheo2[j-i+n]=1;
		}
	}
		
}
int main(){
	
	init();
	backtracking(0);
	cout<<count;
}
