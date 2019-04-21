// DEVCPP
// Dat moi truong
#include <iostream>
#include <fstream>
#include <algorithm>
#include <windows.h>

using namespace std;
const int MN = 101;
int a[MN][MN]; // 1..100
const char * fn = "WATER.INP";
int n, m; // n dong, m cot
int tmax; // tang cao nhat

void Go() {
	fflush(stdin);
	if (cin.get() == '.') exit(0);
	
}

void Print(int a[], int d, int c, const char * msg) {
	cout << msg;
	for (int i = d; i <= c; ++i) cout << " " << a[i];
}

void Print(int a[][MN], int d1, int c1,
            int d2, int c2, const char * msg) {
	cout << msg;
	for (int i = d1; i <= c1; ++i)
	    Print(a[i], d2, c2, "\n ");
}

void Read() {
	 ifstream f(fn);
	 tmax = 0;
	 f >> n >> m; // n dong, m cot
	 cout << "\n " << n << " " << m;
	 for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				 f >> a[i][j];
				 tmax = max(tmax, a[i][j]);
			}
	 }
	 f.close();
	
}

// lien thong 4
// t-1 -> t
void Loang(int i, int j, int t) {
	 if (a[i][j] == t-1) {
			a[i][j] = t;
			if (j < m) Loang(i, j+1, t); // ke phai
			if (j > 1) Loang(i, j-1, t); // ke trai
			if (i > 1) Loang(i-1, j, t); // tren
			if (i < n) Loang(i+1, j, t); // duoi
	 }
	
}

// Luong nuoc o tang t
int Water(int t) {
	int i, j;
	// duyet 2 canh ngang
	for (j = 1; j <= m; ++j) {
		 if (a[1][j] == t-1) Loang(1, j, t);
		 if (a[n][j] == t-1) Loang(n, j, t);
	}
	
	// duyet 2 cot doc
	for (i = 1; i <= n; ++i) {
		 if (a[i][1] == t-1) Loang(i, 1, t);
		 if (a[i][m] == t-1) Loang(i, m, t);
	}
	//  Dem so o co nuoc
		 int s = 0;
		 for (i = 1; i <= n; ++i)
				for (j = 1; j <= m; ++j)
					 if (a[i][j] == t-1) {
							++s; a[i][j] = t; // dong bang
					 }
	return s;
}

void Run() {
	 Read();
	 Print(a, 1, n, 1, m, "\n Input: ");
	 cout << "\n tmax = " << tmax;
	 int s = 0, t;
	 for (t = 1; t <= tmax; ++t) {
			 s += Water(t);
			 cout << "\n Xu li tang " << t << ": s = " << s  ;
			 Print(a, 1, n, 1, m, "\n a: ");
			 // Go();
	 }
	 cout << "\n " << s;
}

void Son() {
	memset(a, 0, sizeof(a));
	 Read();
	 int s, i, j;
	 s = 0;
	 for (i = 1; i <= n; ++i)
		 for (j = 1; j <= m; ++j) {
				// dinh
				if (a[i][j] > 0) ++s;
				// xet 4 mat: trai, phai, tren, duoi
				if (a[i][j] > a[i][j-1]) s += a[i][j]-a[i][j-1];
				if (a[i][j] > a[i][j+1]) s += a[i][j]-a[i][j+1];
				if (a[i][j] > a[i-1][j]) s += a[i][j]-a[i-1][j];
				if (a[i][j] > a[i+1][j]) s += a[i][j]-a[i+1][j];
		 }
		cout << "\n DT can son = "  << s;
}

main() {
	 // Run(); // 26
	 Son();
	 return 0;
}


