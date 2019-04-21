/*
	Name: COMSTR.CPP
	Copyright:
	Author:
	Date: 03-08-17 14:23
	Description:
		Max len of common substring u and v
*/
	#include <iostream>
	#include <fstream>
	#include <windows.h>
	#include <cmath>
	#include <algorithm>

	using namespace std;

	const int MN = 1005;
	 const char * u, * v;
	 int n, m; // len of u and v
	 
	 int d[MN][MN];
	 int a[MN];

	
	void Go() {
	 fflush(stdin);
	 if (cin.get() == '.') exit(0);
	}
	

	int D(int i, int j) {
		 if (i >= n) return 0;
		 if (j >= m) return 0;
		 if (u[i] == v[j]) return D(i+1, j+1)+1;
		 return max(D(i+1, j), D(i, j+1));
	}
	
	int CS(const char * uu, const char * vv) {
			u = uu; v = vv;
			n = strlen(u); m = strlen(v);
			cout << "\n Input u: " << u << " : " << n;
			cout << "\n Input v: " << v << " : " << m;
      int r = D(0,0);
      cout << "\n THE RESULT: " << r;
      return r;
	}
	
	// mang 2 chieu
	int CS2(const char * uu, const char * vv) {
			u = uu; v = vv;
			n = strlen(u); m = strlen(v);
			cout << "\n Input u: " << u << " : " << n;
			cout << "\n Input v: " << v << " : " << m;
			memset(d, 0, sizeof(d));
			int i, j;
			for (i = n-1; i >= 0 ;--i) {
				 for (j = m-1; j >= 0; --j)  {
						d[i][j] = (u[i] == v[j]) ? d[i+1][j+1]+1
						          : max(d[i][j+1], d[i+1][j]);
					} // for j
			} // for i
      int r = d[0][0];
      cout << "\n THE RESULT: " << r;
      return r;
	}
	
	// Dang tien
	// d[i][j] = d[i-1][j-1] + 1, if u[i] == v[j]
	// else max(d[i][j-1], d[i-1][js])
	// mang 1 chieu
	int CS1(const char * uu, const char * vv) {
			u = uu; v = vv;
			n = strlen(u); m = strlen(v);
			cout << "\n Input u: " << u << " : " << n;
			cout << "\n Input v: " << v << " : " << m;
			memset(a, 0, sizeof(a));
			int i, j;
			// Tinh truoc dong 0
			for (j = 0; j < m; ++j)  {
						a[j] = (u[0] == v[j]) ? 1 : 0;
			} // for j

			int t1, t2;
			for (i = 1; i < n ;++i) {  			// j = 0
				t1 = 0; t2 = a[0];
				a[0] = (u[i] == v[0]) ? t1+1 : max(t1, a[0]);
				// t1 = a[
				for (j = 1; j < m; ++j)  {
					 t1 = a[j-1]; t2 = a[j];
						// tinh a qua a
						a[j] = (u[i] == v[j]) ? t1+1
						          : max(a[j-1], t2);
					} // for j
			} // for i
      int r = a[m-1];
      cout << "\n THE RESULT: " << r;
      return r;
	}
	
	
	
	main() {
		
		 // CS("lopsamsuthisamsabsucdn","adlopbcsanmascung");
				CS2("aaaaaaaaaa1234aaaaaaaaaaaaaaaaaaabbbbbbbbbbb123sam123sungabsennnnnngiaeeeelwwaqqoaaaaaaaaa",
				    "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb123sam123sungabsennnnnngiaeeeelwwaqqo"); // 12
				CS1("aaaaaaaaaa1234aaaaaaaaaaaaaaaaaaabbbbbbbbbbb123sam123sungabsennnnnngiaeeeelwwaqqoaaaaaaaaa",
				    "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb123sam123sungabsennnnnngiaeeeelwwaqqo"); // 12

				    cout << endl << strlen("bbbbbbbbbbb123sam123sungabsennnnnngiaeeeelwwaqqo");
		
		cout << "\n T H E   E N D.";
		return 0;
	}

