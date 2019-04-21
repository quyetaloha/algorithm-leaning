/*
	Name: DivAndConq.CPP
	Copyright:
	Author:
	Date: 25-07-17 13:43
	Description:
	Divide and Conquer
	* Tim kiem nhi phan
	* Doan tong k min
*/

 #include <iostream>
 #include <windows.h>
 #include <time.h>


 
 using namespace std;
 
 const int MN = 1000;
 int a[] = { 0, 1, 0, 3, 0, 7, 0, 7, 3, 4, 0, 6, 0,  5,
             9, 1, 9, 9, 1, 17, 4, 6, 0,  2, 8, 0 };
 int s[MN];
 
 void Go() {
	 fflush(stdin);
	 if (cin.get() == '.') exit(0);
 }
 
 void PP(int x[], int d, int c, const char *msg = "") {
		 cout << msg;
		 for (int i = d; i <= c; ++i) cout << " " << i << "." << x[i];
 }
 
 // Nhan ki tu Y/N
 char YN() {
 	char ch;

	 do {
			fflush(stdin);
			cout << "[Y/N]: ";
	    ch = toupper(cin.get());
    } while (ch != 'Y' && ch != 'N');
    return ch;
 }
 
 // Tim nhi phan trong doan tru mat
	int Binsearch(int d, int c, const char *ques) {
	 int g;
	 char tl;
	 while (d < c) {
		 g = (d+c)/2;
		 cout << ques << g << " ?: ";
		 tl = YN();
		 if (tl == 'Y') d = g+1; else c = g;
	 } // d=c
	 return d;
	}
	
	// Tim nhi phan trong mang sap tang a[d..c]
	int Binsearch(int a[], int d, int c, int x) {
	 int g;
	 char tl;
	 while (d < c) {
		 g = (d+c)/2;
		 if (a[g] < x) d = g+1; else c = g;
	 } // d = c
	 return (a[d] == x ) ? d : -1;
	}
	
	void BirthDay() {

	 int thang = Binsearch(1,12, " \n Ban sinh sau thang ");

	 int ngay = Binsearch(1,31, " \n Ban sinh sau ngay ");
	 cout << "\n Den Ngay " << ngay << "  thang " << thang;
	 cout << "\n Toi se mang HOA den chuc mung ban!";
	}
	
// Sinh ngau nhien n phan tu sap tang
void Gen(int a[], int n) {
	srand(time(NULL));
	const int r = 10;
	const int rr = 100;
	a[0] = rand() % rr;
	for (int i = 1; i < n; ++i)
		a[i] = a[i-1]+(rand()%10);
}

// Sinh ngau nhien n phan tu sap tang
void Gent(int a[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
		a[i] = (rand()%1000);
}

 void Qsort(int a[], int d, int c){
		 int t = d, p = c, m = a[(d+c)/2];
		 int x;
		 while(t <= p) {
			 while(a[t] < m) ++t;
			 while(a[p] > m) --p;
			 if (t <= p) {
			 	x = a[t]; a[t] = a[p]; a[p] = x;
			 	++t; --p;
			 }
		 }
		 // d  p  t c
		 if (d < p) Qsort(a, d, p);
		 if (t < c) Qsort(a, t,c);
 }

int T1() {
		// int x  = Binsearch(1,31);
		// cout << "\n Ban da nghi so " << x;
		// BirthDay();
		int n = 100, d = 0, c = n-1;
		Gent(a,n);
		PP(a,0,n-1,"\n Init ");
		Qsort(a, 0, n-1);
		PP(a,0,n-1,"\n Now a: ");

		int x, v;
		while(1) {
			cout << "\n  x = "; cin >> x;
			cout << "\n Where ? " << Binsearch(a,d,c,x);
			Go();
		}
   	return 0;
 }
 
/*-----------------------------------------
		Tim so luong doan ngan nhat co tong k
		trong a[0..n-1]
-------------------------------------------*/
int	 Segment(int a[], int n, int k) {
		 // s[i] = +a[0..i]
		 s[0] = a[0];
		 int i,j;
		 int len, d; // d: so luong doan ngan nhat
		 for (i = 1; i < n; ++i) s[i] = s[i-1]+a[i];
		 PP(s, 0, n-1,"\n s: ");
		 
		 len = n+1; d = 0;
		 for (i = 0; i < n; ++i) {
				j = Binsearch(s, 0, n-1, s[i]+k);
				if (j != -1) {
				  // doan [i+1..j] ung vien
				  if (j-i < len) { len = j-i; d = 1; }
				  else if (j-i == len) ++d;

				}
		 }
		 cout << "\n Result: " << d;
		 return d;
	 }
	 
void T2() {
	int n = sizeof(a)/sizeof(int);
	cout << "\n " << n;
	PP(a, 0, n-1, "\n a: ");
	int k = 10;
	Segment(a, n, k) ;
	
}

	
 main() {
 	T1();
 	
	//---------------------------------
	cout << "\n T H E   E N D.";
 	return 0;
 }

