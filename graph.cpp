
#include<iostream>
#include<fstream>
#include<windows.h>

using namespace std;

const char * fn = "GR1.INP";

int n;
int m; //number of edges

typedef struct Edge
{
	int x;
	int y;
} Edge;

const int MN = 1000;
Edge e[MN];	//array of edges
int d[MN];

void read()
{
	ifstream f(fn);
	f >> n;
	cout << "\n n = " << n;
	for(m = 1; true; ++m)
	{
		f >> e[m].x >> e[m].y;
		if(e[m].x == 0 && e[m].y == 0)
			break;
		cout << "\n " << e[m].x << " - " << e[m].y;
	}
	--m;
	f.close();
}

int find(int x)	//tim nhom truong cua x : i = d[i];
{
	while(d[x] != x)
		x = d[x];
	return x;
}

int Union(int x, int y)	//gop nhom chua x voi nhom co y
{
	int tx = find(x);
	int ty = find(y);
	if(tx == ty)
		return 0;
	if(tx < ty)
		d[ty] = tx;
	else
		d[tx] = ty;
	return 1;
}

void init()
{
	for(int i = 1; i <= n; ++i)
		d[i] = i;
}

int tplt()	//find - union technique
{
	init();
	int c = n;	//dem so tplt;
	for(int i = 1; i <= m; i++)
		c -= Union(e[i].x, e[i].y);
	return c;
}

void infoConnect()	//so tplt, liet ke nhom truong, cac thanh vien
{
	int s = tplt();
	cout << "\n Total " << s << " group(s).";
	for(int i = 1; i <= n; i++)
	{
		if(d[i] == i)
		{
			cout << "\n " << i << ": ";
			for(int j = i+1; j <= n; j++)
				if(find(j) == i)
					cout << " " << j;
		}
	}
}

int main(){
	read();
	cout << "\n Given Graph " << fn << " has " << n << " verticies and " << m << " edges";
	//cout << "\n So tplt: " << tplt();
	infoConnect();
	return 0;
}

