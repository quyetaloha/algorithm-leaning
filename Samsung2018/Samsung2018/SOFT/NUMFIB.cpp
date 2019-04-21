
/*
	Name: FIB.CPP (devcpp)
	Copyright: 2017
	Author: Le Van Bom
	Date: 18-07-17 13:56
	Description:
	    FIBONACCI SEQUENCES
	    Some hard Problems on Fibonacci Sequences
	   So f1 = a, f2 = b
	   sinh f1f2...fn
	   cho k Tim chu so k trong day
	   x = 1; y = 3; z = 4
	   t = 13471118294776123
	   a = 1, b = 3. n = 10 , k = 10 : 9
	   n = 200
*/

 #include <iostream>
 #include <fstream>
 #include <windows.h>
 #include <cmath>
 #include <algorithm>
 #include <string.h>

 
	using namespace std;
	
	const int MN = 2000;
	const char EOL = '\0';
	
	char x[MN];
	//int lenx;
	
	char y[MN];
	//int leny;

	char z[MN];
//	int lenz;
	
	char t[MN];
	// int lent;

	void Go() {
			fflush(stdin);
			if (cin.get() == '.') exit(0);
	}
	
	
	 // z = x + y;
	void Add() {
		 int lenx = strlen(x);
		 int leny = strlen(y);
		 int len = min(lenx, leny);
		 int i;
		 int c = 0;
		 int k;
		 
		 for (i = 0; i < len; ++i) {
				k = (x[i]-'0') + (y[i]-'0') + c;
				if (k < 10) { c = 0; z[i] = k+'0'; }
				else { c = 1; z[i] = (k % 10)+'0'; }
		 }
		 i = len;
   	 while (i < lenx) {
			   k = (x[i]-'0') + c;
				if (k < 10) { c = 0; z[i] = k+'0'; }
				else { c = 1; z[i] = (k % 10)+'0'; }
				++i;
		 }
		 
		 while (i < leny) {
				k = (y[i]-'0') + c;
				if (k < 10) { c = 0; z[i] = k+'0'; }
				else { c = 1; z[i] = (k % 10)+'0'; }
				++i;
		 }
		 
		 if (c > 0) z[i++] = '1';
		 z[i] = EOL;

	}
	
	// a = 123  4 0
	int ToStr(int a, char x[]) {
		 int len = 0;
		 do {
				x[len++] = (a % 10)+'0';
				a /= 10;
		 } while (a > 0);
		 return len;
	}
	
	// Cho chu so k trong xau x viet nguoc
	char Get(const char *x, int k) {
		 return x[strlen(x)-k];
	}
	
	// Tim ki tu thu k trong day fn
	char NumFib(int a, int b, int k, int n) {
		ToStr(a,x);
		ToStr(b,y);
		cout << "\n x = " << x;
		cout << "\n y = " << y;
		if (n == 1) return Get(x,k);
		if (n == 2) return Get(y,k);
		strcat(t,x); strcat(t,y);
		cout << "\n t = " << t; Go();
		
		for (int i = 3; i <= n; ++i) {
				cout << "\n x = " << x;
		    cout << "\n y = " << y;
				Add();
				cout << "\n z = " << z;
				strcat(t,z);
				cout << "\n t = " << t; Go();
				strcpy(x,y);
				strcpy(y,z);
				
				// strcat(t,x,y);
		}
	}

	main() {
		cout << "\n " << NumFib(9999, 1789, 10, 10); // 9
		 cout << "\n T H E   E N D.";
		 return 0;
	}
	
	/*-------------------------------------------
		 9499
		 6893
		 -----
		16392
		
		9949
		3986
		-------
		29361

		Cach giai khac?
		
		3 4 7 11 18 29 47 76 123 199
	
	--------------------------------------*/
