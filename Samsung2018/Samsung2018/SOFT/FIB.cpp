 /*
	Name: FIB.CPP
	Copyright: VII/2017
	Author: Le Van Bom
	Date: 20-07-17 08:42
	Description:
	Cac day Fibonacci
 */

 #include "Mydef.h"

 const int MN = 50;
 int len[MN];

 // Tinh a = C(k-1) va b = C(k)
 // 2 so fib ke nhau tu k-1
 // day chua
 // k >= 1              0:0 1:1 2:1 2
 void Fib2(int k, int &a, int &b) {
		 a = 0; b = 1;
		 if (k <= 2) return;
		 // k = 3...
		 int c;
		 for (int i = 3; i <= k; ++i) {
				c = a+b;
				a = b;
				b = c;
		 }
 }

	// biet i, fi = a, va f(i+1)=b.
	// Tinh fn
	// Biet 2 so fib ke nhau tai i
	// Tinh fn
	int Fib(int i, int a, int b, int n) {
			 if (n == i) return a;
			 if (n == i+1) return b;
			 int c;
			 if (n > i+1) {
					for (int k = i+2; k <= n; ++k) {
							c = a+b; a = b; b = c;
					}
					return c;
			 }
			 // n < i
			for (int k = i-1; k >= n; --k) {
							c = b-a; b = a; a = c;
			}
	    return c;
	}
	
  // biet i, fi = a, j, fj = b
  // tinh fn
  int Fib(int i, int a, int j, int b, int n) {
		 int t;
		 if (i > j) {
				t = i; i = j; j = t;
				t = a; a = b; b = t;
		 }
		 // i < j

		 int ck1, ck;
		 Fib2(j-i, ck1, ck);
		 int x = (b - a*ck1) / ck;
		 return Fib(i, a, x, n);
  }
  
  /*---------------------------------------------
		 SFib: string Fibonacci
		 1. buu 3
		 2. chinh 5
		 3. buuchinh 8
		 4. chinhbuuchinh 13
		 5. buuchinhchinhbuuchinh 21
		 6. chinhbuuchinhbuuchinhchinhbuuchinh 34
		 7.  buuchinhchinhbuuchinhchinhbu
		     uchinhbuuchinhchinhbuuchinh  55
		     k = 10
     char Fib(a, b, n, k)
		 Fib("buu", "chinh", 7, 10) = h
		 k = 1...M Fib("buu", "chinh", 7, k)
		 k 10 chu so
		 
		 Cay lan tan de an kho treo
		 Cay leo teo de treo kho an
		 
  -----------------------------------------------*/

	// Phuong an nho
	char Fib1(const char *a, const char *b, int n, int k) {
		string x, y, z;
		int i;
		x = "";
		for (i = 0; a[i]; ++i) x += a[i];
		y = "";
		for (i = 0; b[i]; ++i) y += b[i];
		if (n == 1) return x[k];
		if (n == 2) return y[k];
		for (i = 3; i <= n; ++i) {
				z = x + y; x = y; y = z;
		}
		// cout << "\n z = " << z << " ****  " << z[k-1];
		// cout << "\n len " << z.length() << "***" << z[k-1];
		return z[k-1];
	}
	
	//  Truy hoi
	
		char Fib(const char *a, const char *b, int n, int k) {
			len[1] = strlen(a); len[2] = strlen(b);
			//cout << "\n " << len[1] << " " << len[2];
			//if (n == 1) return a[k];
			//if (n == k) return b[k];
			for (int i = 3; i < n; ++i)
				 len[i] = len[i-2] + len[i-1];
			while(n > 2) {
				// (n) = (n-2) + (n-1)
				if (k <= len[n-2]) { n -= 2; }
				else { k -= len[n-2]; n -= 1;  }
			}
			
			char r;
			r = (n == 1) ? a[k-1] : b[k-1];
			// cout << "\n " << r;
			// n = 1 | 2
			return r;
	}


	void T1() {
		 int n;
		 cout << endl;
		 for (n = -10; n <= 10; ++n) {
				cout << " " << Fib(-2, -7,7,23,n);
		 	
		 }
	cout << "\n " << Fib(-2, -7, 7, 23, 9); // = 60
  cout << "\n " <<  Fib(7, 23, -2, -7, 9); // = 60
  cout << "\n " << Fib(-2, -7, 7, 23, -5); // = 31
	}

void T2() {
	for (int i = 1; i <= 1028; ++i) {
		if (Fib1("buu", "chinh", 20, 1028) !=
		    Fib("buu", "chinh", 20, 1028)) {
				cout << "\n ERR " << i;
		}
	}
	cout << "\n TESTED.";
}

 main(){

	T2();

	
	cout << "\n T  H  E    E  N  D  .";
	return 0;
}

