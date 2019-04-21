/*
	Name: PALIN.CPP
	Copyright:
	Author:
	Date: 25-07-17 08:38
	Description:
	Palindrome : xo it nhat k ki tu
	de thu duoc xau doi xung

*/
	#include <iostream>
	#include <fstream>
	#include <windows.h>
	#include <cmath>
	#include <algorithm>

	using namespace std;
	 const int MN = 2001;

	 char s[MN];
	 int n;
	 
	 int dd[MN][MN];
	 
	
	// max len cua palin khi xet s[i..j]
	int D(int i, int j) {
		 // ++dd[i][j];
		 if (i > j) return 0;
		 if (i == j) return 1;
		 // i < j
		 if (s[i] == s[j]) return D(i+1, j-1)+2;
		 return max(D(i, j-1), D(i+1, j));
	}
	
	int Pal() {
		n = strlen(s);
		cout << "\n " << s;
		cout << "\n len = " << n;
		int k = n - D(0,n-1);
		cout << "\n k = " << k;
		// memset(dd, 0, sizeof(dd));
		return n - D(0,n-1);
	}
	
	int Pal2() {
		n = strlen(s);
		cout << "\n " << s;
		cout << "\n len = " << n;
		memset(dd, 0, sizeof(dd));
		// cheo chinh
		int i, j;
		for (i = 0; i < n; ++i) dd[i][i] = 1;
		for (i = n-2 ; i >= 0; --i) {
			 for (j = i+1; j < n; ++j)
					dd[i][j] = (s[i]==s[j]) ? dd[i+1][j-1] + 2
					            : max(dd[i][j-1], dd[i+1][j]);
		}
		int k = n - dd[0][n-1];
		cout << "\n RESULT PAL2: "  << k;
		return k;
	}
	
	// dung 2 mang 1 chieu
	
	int Pal1() {
		int *a, *b, *c;
		n = strlen(s);
		cout << "\n " << s;
		cout << "\n len = " << n;
		a = new int[n*sizeof(int)+12]; // [MN];
		b = new int[n*sizeof(int)+12];
		int i, j;
		for (i = 0; i < n; ++i) a[i]  = 0;
		a[n-1] = 1;
		for (i = n-2; i >= 0; --i) {
		   // tinh b qua a
			 b[i] = 1;
			 for (j = i+1; j < n; ++j)
					b[j] = (s[i] == s[j]) ? a[j-1]+2 : max(b[j-1], a[j]);
			 c = a;
			 a = b;
			 b = c;
		}
		int k = n-a[n-1];
		cout << "\n RESULT PAL1: "  << k;
		delete [] a ;
		delete [] b;
		return k;
	}
	
	main() {
		
		strcpy(s,"aaaaaaaaaaaaaaaaaaaaabbb7baa8ababaa1abb2bba3aaa1abb2bba3aa4a*a5aaa6bbb7baa8ababaa1abb2bba3aa4a*a5aaa6bbb7bbb7baa8ababaa1abb2bba3aaa1abb2bba3aa4a*a5aaa6bbb7baa8ababaa1abb2bba3aa4a*a5aaa6bbb7aaaaaaaaaaaaaaaaaaaa"); // baa8ababaa1abb2bba3aa4a*a5aaa6");


		Pal2();
		cout << "\n-------------------------------------------";
		Pal1();
		
		// Pal("aa1abb2bba3aa4a*a5aaa6bbb7baa8abab"); // 5
		

		cout << "\n T H E   E N D.";
		return 0;
	}

