#include<bits/stdc++.h>
using namespace std;
int n,cot[100]={0},cheo1[200] = {0},cheo2[200]={0},d=0,a[100][100] = {0};
void backtracking(int i){
	if(i==n+1){
		d++;
		return;
	}
	for(int j = 1;j<=n;j++){
		if(cot[j]==0 && cheo1[i+j]==0 && cheo2[i-j+n]==0){
			cot[j] = 1;
			cheo1[i+j] = 1;
			cheo2[i-j+n] = 1;
			a[i][j] = 1;
			backtracking(i+1);
			cot[j] = 0;
			cheo1[i+j] = 0;
			cheo2[i-j+n] = 0;
			a[i][j] = 0;
		}
	}
}
int main(){
	cin >> n;
	backtracking(1);
	cout << d;
}


