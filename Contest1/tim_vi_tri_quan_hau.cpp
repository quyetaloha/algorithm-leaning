#include<iostream>
#include<string>
using namespace std;
#define n 5
int hau[n];
int cot[n],cheo1[2*n-1],cheo2[2*n-1];
int count;
void consequence_print(){
	for(int i=0;i<n;i++){
		for(int j=0;j<hau[i];j++){
			cout<<" .";
		}
		cout<<" x";
		for(int j=hau[i]+1;j<n;j++){
			cout<<" .";
		}
		cout<<endl;
	}
	cout<<endl;
}
void init(){
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
			if(i==n-1) consequence_print();
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

}
