	/*
		Name:   TOPOSORT.CPP
		Copyright:
		Author:
		Date:
		Description: 10-08-17 14:00
		 	Sort theo cau hinh
			 Lap lich
	*/

 	#include <iostream>
 	#include <time.h>
 	#include <fstream>
 	#include <windows.h>
 	#include <cmath>
 	#include <algorithm>

	using namespace std;

	const int MN = 300;
	const char * fn = "TOPO.INP";
	
	int d[MN]; //  dinh voi bac vao
	int n; // number of Vertexes
	int r[MN]; //  result chua trat tu topo
	
	bool c[MN][MN]; // adjanced matrix
		// c[i][j]  = 1: (i) -> (j);
		// c[i][j] = 0: ko lien quan
		
	void Go() {
	 	fflush(stdin);
	 	if (cin.get() == '.') exit(0);
 	}

	void Print(int a[], int d, int c, const char *msg = "") {
	 	cout << msg;
	 	for (int i = d; i <= c; ++i) cout << " " << a[i];
	}

	void Print(int a[][MN], int d, int c,
	           const char * msg = "") {
			cout << msg;
			for (int i = d; i <= c; ++i) Print(a[i], d, c, "\n ");
	}
	
	void Printc() {
			// cout << msg;
			for (int i = 1; i <= n; ++i) {
				 cout << "\n ";
				 for  (int j = 1; j <= n; ++j)
			       cout << c[i][j];
			}
	}
	
	void Read() {
		 memset(c, 0, sizeof(c));
		 memset(d, 0, sizeof(d));
		 ifstream f(fn);
		 if (f.fail()) {
				cout << "\n Unable open input file " << fn;
				exit(1);
		 }
		 f >> n;
		 
		 cout << "\n The number of Ver. " << n;
		 int x, y;
		 for ( ;true; ) {
			 f >> x >> y;
			 cout << "\n " << x << " <- " << y;
			 c[y][x] = 1; // y -> x: y phai hoan thanh truoc x
			 ++d[x];
			 if (x+y == 0) break;
		 }
		 
		 f.close();
		 Print(d, 1, n, "\n Indegree: ");
		 Printc();
	}
	
	// Tim dinh troc trong so cac dinh chua danh dau
	// d[i] : 0, > 0   < 0
	int Troc() {
		for (int i = 1; i <= n; ++i)
			 if (d[i] == 0) return i;
		return -1;
	}
	
	void ThaoKhop(int t) {
		 for (int j = 1; j <= n; ++j)
				if (c[t][j]) --d[j];
	}
	
	bool TopoSort() {
		 Read();
		 int j;
		 for (int i = 1; i <= n; ++i) {
				j = Troc();
				if (j < 0) {
					 cout << "\n That bai: co chu trinh. ";
					 return false;
				}
				// co dinh troc
				// cout << " " << j;
				r[i] = j;
				ThaoKhop(j);
				d[j] = -1;
		 }
	}
	
main() {
	
	if (TopoSort()) Print(r, 1, n, "\n RESULT: ");
	
 //-----------------------------
 cout << " \n T H E   E N D .";
 return 0;
}

