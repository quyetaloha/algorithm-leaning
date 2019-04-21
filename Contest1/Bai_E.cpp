#include<iostream>
#include<string>
using namespace std;
int a[20][20],kq[20],start,cost,mi,n,b[20];
bool chuaxet[20];
void init(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		chuaxet[i]={true};
	}
	start=1;kq[1]=1;chuaxet[start]=false;
	cost=0;mi=100000;
}
void Try(int i){
	
	for(int j=1;j<=n;j++){
		if(chuaxet[j]&&cost+a[kq[i-1]][j]<mi){
			kq[i]=j;
			chuaxet[j]=false;
			cost+=a[kq[i-1]][j];
			if(i==n){
				if(cost+a[kq[n]][kq[1]]<mi) mi=cost+a[kq[n]][kq[1]];
				for(int k=1;k<=n;k++)
					b[k]=kq[k];
	
				
			}
			else Try(i+1);
			chuaxet[j]=true;
			cost-=a[kq[i-1]][j];
		}
	}
		
}
int main(){
	init();
	Try(2);
	cout<<mi;
}
