
/*
	Name: FIB.CPP (devcpp)
	Copyright: 2017
	Author: Le Van Bom
	Date: 18-07-17 13:56
	Description:
	    FIBONACCI SEQUENCES
	    Some hard Problems on Fibonacci Sequences
	    
	    Chet song can chu ko ai chet song sau
	 f1 = x = buu, f2 = y = chinh
	 trong fn ki tu thu k = ?
	 1. abc 3
	 2. 12345 5
	 3. abc12345 8
	 4. 12345abc12345 13
	 5. abc1234512345abc12345  21
	 6. 12345abc12345abc1234512345abc12345  34
	 7. abc1234512345abc1234512345abc12345abc1234512345abc12345
			 55
		n = 7 , k = 15 // b
	   Truy hoi
*/

 #include <iostream>
 #include <fstream>
 #include <windows.h>
 #include <cmath>
 #include <algorithm>
 
	using namespace std;
	
	int len[40];

	void Go() {
			fflush(stdin);
			if (cin.get() == '.') exit(0);
	}

  string ToStr(const char * a) {
		string s = "";
		for (int i = 0; a[i]; ++i) {
			 s += a[i];
		}
		return s;
	}
	
	// Cho biet ki tu thu k
	// trong fn xuat phat a, b
	char Sfib1(const char * a, const char * b, int n, int k) {
		 string x = ToStr(a), y = ToStr(b), z;
		 //  << "\n " << x << " " << y;
		 if (n == 1) return x[k-1];
		 if (n == 2) return y[k-1];
		 for (int i = 3; i <= n; ++i) {
				z = x + y;
				x = y;
				y = z;
		 }
		 return z[k-1];
	}
	
	char Sfib(const char * a, const char *b, int n, int k) {
		 len[1] = strlen(a); len[2] = strlen(b);
		 int i;
		 for (i = 3; i <= n; ++i) len[i] = len[i-2]+len[i-1];
		 // truy hoi
		 while (n > 2) {
				if (k <= len[n-2]) n -= 2;
				else { k -= len[n-2]; --n;  }
		 }
		 
		 return (n == 1) ? a[k-1] : b[k-1];
	}
	
	
	main() {
		
		// string s = "abc1234512345abc1234512345abc12345abc1234512345abc12345";
		//int kk 37; // = s.length();
		
		// cout << "\n " << s << "\n ";
		 int k = 1034;
		 
		//for (int k = 1; k <= kk; ++k)
		cout << endl << Sfib("abc","12345",47,k);

		// cout << "\n " ;
		// for (int k = 1; k <= kk; ++k)
			cout << endl << Sfib1("abc","12345",47,k);


		 cout << "\n T H E   E N D.";
		 return 0;
	}
	
	/*-------------------------------------------
		 -45s  28 -17 11 -6 5  -1  4 3 7
	
	
	--------------------------------------*/
