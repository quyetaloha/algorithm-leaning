 // Palindrome
 // 3 Aug. 2017
 
 #include <iostream> // input /  output
 #include <fstream>  // files
 #include <windows.h>
 #include <cmath>
 // #include <algorithm>

 using namespace std;
 
 const int MN = 2002;
 
 const char *s;
 int n;
 
 int dd[MN][MN]; // Dem so lan goi ham D(i,j)
 int tt;
 
 int *a, *b; // a: dong duoi, b: dong tren
 
 
 // max len cn giu lai
 int D(int i, int j) {
		// dd[i][j]++;
		if (i > j) return 0;
		if (i == j) return 1;
		// i < j
		return (s[i] == s[j])  ? D(i+1,j-1) + 2 : max(D(i, j-1), D(i+1, j));
 }
 
 
 int Pal(const char *ss) {
	 // memset(dd, 0, sizeof(dd));
	 s = ss;
	 cout << s;
	 n = strlen(s);
	 cout << "\n len = " << n;
	 int k = n - D(0,n-1);
	 cout << "\n RESULT (Delete): " << k;
	 return k;
 }
 
 // Cai tien : mang 2 chieu dd
 int Pal2(const char *ss) {
	 memset(dd, 0, sizeof(dd));
	 int i, j;
	 s = ss;
	 //cout << s;
	 n = strlen(s);
	 cout << "\n len = " << n;
	 for (i = 0; i < n; ++i) dd[i][i] = 1;
	 for (i = n-2; i >= 0; --i)
			 for (j = i+1; j < n; ++j)
					dd[i][j] = (s[i] == s[j]) ? dd[i+1][j-1]+2
										 : max(dd[i][j-1], dd[i+1][j]);
	 


	 int k = n - dd[0][n-1];
	 cout << "\n RESULT (Delete): " << k;
	 return k;
 }
 
 // Cai tien : 2 mang 1 chieu dd
 int Pal1(const char *ss) {
	 int i, j;
	 s = ss;
	 // cout << s;
	 n = strlen(s);
	 cout << "\n len = " << n;
	 a = new int[(n+5)*sizeof(int)];
	 b = new int[(n+5)*sizeof(int)];
	 int *c;
	 
	 for (i = 0; i < n; ++i) a[i] = 0;
	 
	 a[n-1]  = 1;
	 
	 for (i = n-2; i >= 0; --i) { // lan i tao dong i: a->b
			 b[i] = 1;
			 for (j = i+1; j < n; ++j)
					b[j] = (s[i] == s[j]) ? a[j-1]+2
										 : max(b[j-1], a[j]);
			 c = a; a = b; b = c;
	 }
	 int k = n - a[n-1];
	 cout << "\n RESULT (Delete): " << k;
	 delete [] a;
	 delete [] b;
	 return k;
 }

 
 
 main() {
 	Pal2("habnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionah");
	//Go();
	Pal1("habnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionahhabnoaci*iahoionah");

		//----------------------------------
	  cout << "\n T H E   E N D.";
 }



