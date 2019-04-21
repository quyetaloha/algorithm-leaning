/*
	Name:   SEGMENT.CPP
	Copyright:
	Author:
	Date: 27-07-17 09:11
	Description:
		 cac doan co tong k
*/

 #include <iostream>
 #include <time.h>
 #include <fstream>
 #include <windows.h>
 #include <cmath>
 #include <algorithm>



 using namespace std;

 const int MN = 300000;

 int a[] = { 0, 0, 3, 0, 7,
             0, 0,  3, 0, 0,
						 1, 2, 0,  5, 0,
						 5, 0, 4, 0, 0,
						 6, 0,  6, 0, 0 };
						 
 int s[100];
 // s[i] = +a[0..i]
 // 0,0,3,3,10,10,10,13,13,13,14,16,16,21,21,26,...
 // s sap tang
 // s[i] = a1 + ai
 // s[i]+k xuat hien tai s[j]
 // s[j] = s[i] +k
 // k = s[j]-s[i] = a[i+1]+...+a[j]
 int n;
 int k;
 int L, R;

 void Go() {
	 fflush(stdin);
	 if (cin.get() == '.') exit(0);
	 
 }

void Print(int a[], int d, int c, const char *msg = "") {
	 cout << msg;
	 for (int i = d; i <= c; ++i) cout << " " << a[i];
}

 // Xoa ac so 0 o 2 dau [L-R]
 void Del0(int &LL, int &RR) {
		LL = L; RR = R;
		while(a[LL] == 0) ++LL;
		while(a[RR] == 0) --RR;
 }
 
 void List () {
		n = sizeof(a) / sizeof(int);
		cout << n; // Scan a[0..n-1]
		Print(a, 0, n-1, "\n Init: ");
		// int L, R;
		k = 10;
		int d = 0, LL, RR;
		L = R = 0;
		int s = a[L];
		while (R < n) {
			if (s == k) { ++d;
			   Del0(LL,RR);
				 cout << "\n " << LL << " - " << RR;
			              s -= a[L++]; }
			else { if (s < k) { s += a[R++]; }
			        else // s > k
			          { s -= a[L++]; }
			      }
		}
		// R = n
		cout << "\n L = " << L << " R = " << R << " vs " << n;
		--R;
		if (s > k) {
		  for (; L <= R; ++L) {
				 s -= a[L];
				 ++L;
				 if (s == k) { ++d;
			   Del0(LL,RR);
				 cout << "\n " << LL << " - " << RR;
			}
		}

			
		  }
		// xet tiep L
		
		cout << "\n Total " << d;
 }
 
 int Binsearch(int a[], int d, int c, int x) {
	 int g;
	 while(d < c) {
			g = (d+c)/2;
			if (a[g] < x) d = g+1;
			else c = g;
	 }
	 // d = c
	 return (a[d] == x) ? d : -1;
 }
 
 // Chia de tri
 void List2() {
 	int i, j, d = 0;
 	k = 10;
 	int n = sizeof(a)/sizeof(int);
 	s[0] = a[0];
 	for (i = 1; i < n; ++i) s[i] = s[i-1]+a[i];
 	Print(a, 0, n-1, "\n Init a: ");
 	Print(s, 0, n-1, "\n      s: ");
 	for (i = 0; i < n; ++i) {
		 j = Binsearch(s, i+1, n-1, s[i]+k);
		 if (j >= i) {
				++d; cout << "\n Doan " << d << " [" << i+1 << " - " << j << "]";
		 }
 	}
		cout << "\n Total " << d;
 }
 
 
 main(){
 	List2();

 //-----------------------------
 cout << " \n T H E   E N D .";
 return 0;
}

