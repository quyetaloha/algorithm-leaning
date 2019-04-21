#include<iostream>
using namespace std;
typedef struct Edge {
	
};
const int MN=500;
Edge e[MN];
int d[MN];

int find(int x){
	while(d[x]!=x) x=d[x];
}
void Init(){
	for(int i=1;i<=n;i++){
		d[i]=i;
	}
}
//gop nham co x voi nhom co y
int union(int x,int y){
	int tx=find(x);
	int ty=find(y);
	if(tx==ty) return 0;
	if(tx<ty) d[ty]=
	
	
}
//so thanh phan lien thong
int TPLT(){
	Init();
	int c=n;
	for(int i=1;i<=m;i++){
		c-=Union(e[i]).x,e[i].y);
	}
}
int main(){
	Read();
	cout<<TPLT();
}
