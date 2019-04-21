	/*
		Name:   MULTISORT.CPP
		Copyright:
		Author:
		Date:
		Description: 10-08-17 14:00
		 	Sort da hinh
	*/

 	#include <iostream>
 	#include <time.h>
 	#include <fstream>
 	#include <windows.h>
 	#include <cmath>
 	#include <algorithm>

	using namespace std;

	const int MN = 300000;

	int a[MN];

 	void Go() {
	 	fflush(stdin);
	 	if (cin.get() == '.') exit(0);
 	}

	void Print(int a[], int d, int c, const char *msg = "") {
	 	cout << msg;
	 	for (int i = d; i <= c; ++i) cout << " " << a[i];
	}

	void Swap(int a[], int i, int j) {
		int c = a[i]; a[i] = a[j]; a[j] = c;
	}

	// Quick Sort with function pointer cmp
	void Qsort(int a[], int d, int c, bool (*cmp)(int, int)) {
	 	int t = d, p = c, m = a[(d+c)/2];
	 	while (t <= p) {
		 	while (cmp(a[t],m)) ++t;
		 	while (cmp(m,a[p])) --p;
		 	if (t <= p) {Swap(a,t,p); ++t; --p; }
   	}
   	if (d < p) Qsort(a, d, p, cmp);
   	if (t < c) Qsort(a, t, c, cmp);
	}

	bool S1(int x, int y) { return x < y; }
	
	bool S2(int x, int y) { return x%10 < y%10; }
	
	// Sum of Digits of x
	// 1234 0 -> 123 4 -> 12 7 -> 1 9 -> 0 10
	// bin 1010111 = 5
	int H(int x, int b = 10) {
		int t = 0;
		while (x != 0) {
			 t += x % b;
			 x /= b;
		}
		return t;
	}
	
	// [1][2][3][4] --> [4][3][2][1]
	// lay phai ghep phai
	// 4321
	int Inv(int x) {
		 int y = 0;
		 while(x != 0) {
				 y = y*10 + (x%10);
				 x /= 10;
		 }
		 return y;
	}
		
	bool S3(int x, int y) { return H(x) < H(y); }
	
	bool S4(int x, int y) { return H(x,2) < H(y,2); }

	// Hien thi dang nhi phan
	void P2(int x) {
		 do {
				cout << (x & 1);
				x >>= 1;
		 } while (x);
	}
	
	// Sinh ngau nhien
	void Gen(int n) {
		srand(time(NULL));
		for (int i = 0; i < n; ++i)
		 	a[i] = rand() % 10000;
	}

	void T1() {
		 int n = 30;
		 Gen(n);
		 // Print(a, 0, n-1, "\n Init a: ");
		 cout << "\n Bin Init: ";
		 for (int i = 0; i < n; ++i) {
			 cout << " " << a[i] << ":"; P2(a[i]);
		 }
		 Qsort(a, 0, n-1, S4);
		 Print(a, 0, n-1, "\n Sort a: ");
	}

		void T2() {
		 int n = 30;
		 Gen(n);

		 for (int i = 0; i < n; ++i)
				cout << " " << a[i] << ":" << Inv(a[i]);
	}


main() {
	
	 // T2();
	 cout << Inv(12345) << " " << Inv(-123);
	
 //-----------------------------
 cout << " \n T H E   E N D .";
 return 0;
}

