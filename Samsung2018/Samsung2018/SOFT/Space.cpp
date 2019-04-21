	/********************************
	Name: CODE.CPP
	Copyright: 2018
	Author: Le Van Bom
	Date: 02-07-18 14:43
	Description:
	Decoding know code of chaacter
	using binary tree
	
*************************************/
 // Dat  moi truong
 #include <iostream>
 #include <fstream>
 #include <windows.h>
 // #include <cmath>
 // #include <conio.h>
 const int MN = 1000;
	int a[MN+1];
	int n;
	
	using namespace std;

	// Lat doan a[d..c]
	// Lat(7, 800)
	// return so lan cau
	int Lat(int d, int c) {
		int x;
		int cau = 0;
		while (d < c) {
			x = a[d];
			a[d] = a[c];
			a[c] = x;
			++d; --c;
			cau += 3;
		}
		return cau;
	}
	
	void Init(int nn) {
		n = nn;
		for (int i = 1; i <= n; ++i) a[i] = i;
	}
	
	void Print(int d, int c, const char * msg = "") {
		 cout << msg;
		 for (int i = d; i <= c; ++i)
				 cout << " " << a[i];
	}
	
	void Wait() {
		 fflush(stdin);
		 if (cin.get() == '.') exit(0);
	}
	

void Test1() {
	 int t =  0;
		 int i = 500;
		 Init(1000);
		 // Print(1, n, "\n Init: ");Wait();
		 t += Lat(1,i);
		 // Print(1, 15); Wait();

		 t += Lat(i+1, n);

		 // Print(1, n); Wait();

		 t += Lat(1, n);
		 // Print(1, n);
		 cout << "\n Total: " << t;

	}

	// Chuyen truc tiep d khoi tu dau ve cuoi
  int Move(int d, int n) {
		 int i, j, x, t = 0, c = n-d;
		 for (i = 1; i <= d; ++i) {
				x = a[i];
				for (j = i + d; j <= n; j += d) {
					a[j-d] = a[j];	++t;
				}
				a[++c] = x; ++t;
		 }
		 cout << "\n Total " << t;
		 return t;
  }

void Test2() {
	n = 15;
	Init(n);
	Print(1, n, "\n Init: ");
	Move(2,n);
	Print(1, n, "\n Now: ");
	/*
	 1 2 3 4 5 6 7  8  9 10 11 12 13 14 15
	 3 4 5 6 7 8 9 10 11 12 13 14 15  1  2

	 1 2 3 4 5  6  7  8  9 10 11 12 13 14 15
   5 6 7 8 9 10 11 12 13 14 15  1  2  3  4
   */

	 

	
}

	main() {
		Test2();

		//--------------------------------------------- 
		 cout << endl << " T H E   E N D . ";
		 
	  return 0;       
	}
	
