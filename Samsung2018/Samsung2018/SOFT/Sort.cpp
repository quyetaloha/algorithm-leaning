/*
	Name:   MULTISORT.CPP
	Copyright:
	Author:
	Date: 27-07-17 09:11
	Description:
	Divide and Conquer
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

void Qsort(int a[], int d, int c) {
	 int t = d, p = c, m = a[(d+c)/2];
	while(t <= p) {
	 while (a[t] < m) ++t;
	 while (a[p] > m) --p;
	 if (t <= p) {
	 	Swap(a, t, p);
	 	++t; --p;
	 }
  }
  // d--------p====t-------c
  if (d < p) Qsort(a, d, p);
  if (t < c) Qsort(a, t,c);
}

// Sinh ngau nhien
void Gen(int n) {
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
		 a[i] = rand() % 1000000;
}

void Bsort(int a[], int d, int c) {
	int t, p;
	for (t = d; t <= c; ++t)
		 for (p = c; p > t; --p)
				if (a[p] < a[p-1]) Swap(a,p,p-1);
	
}

 char YN() {
	 char ans;
	 do {
		 cout << " ? [Y/N]: ";
		 fflush(stdin);
		 ans = toupper(cin.get());
	 } while (ans != 'Y' && ans != 'N');
	 return ans;
 }

 // Tim nhi phan trong doan tru mat d..c
 int Binsearch(int d, int c, const char *ques) {
		 int g;
		 while (d < c) {
			 g = (d+c)/2;
			 cout << ques << g;
			 if (YN() == 'Y') d = g+1;
			 else c = g;
		 }
		 // d=c
		 return d;
 }


void BirthDay(){
	
	int thang =  Binsearch(1,12, "\n Ban sinh sau thang " );

	int ngay = Binsearch(1,31, "\n Ban sinh sau ngay ");
	

}


void TestSort() {
	
		int n = MN;
		cout << "\n Q U I C K   S O R T";
		Gen(n-1);
		Print(a, 0, 10, "\n Init: ");
		Qsort(a, 0, n-1);
		Print(a, 0, 10, "\n Now: ");
		cout << "\n\n B U B B L E    S O R T";
		
		Gen(n-1);
		Print(a, 0, 10, "\n Init: ");
		sort(a, a+n-1);
		Print(a, 0, 10, "\n Now: ");
	
}

 // Tim nhi phan trong mang duoc sap
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




void TestSearch() {

		int n = 100;
		cout << "\n Q U I C K   S O R T";
		Gen(n-1);
		// Print(a, 0, 10, "\n Init: ");
		Qsort(a, 0, n-1);
		Print(a, 0, n-1, "\n a: ");
		int x, v;
		while(1) {
		  cout << "\n x = ";
			fflush(stdin); cin >> x;
			if (x <  0) break;
			v = Binsearch(a, 0, n-1, x);
			if (v < 0) cout << "\n not exist.";
			else cout << "  " << v;
		}
}

void T2() {

		int n = 100;
		cout << "\n Q U I C K   S O R T";
		Gen(n-1);
		// Print(a, 0, 10, "\n Init: ");
		Qsort(a, 0, n-1);
		Print(a, 0, n-1, "\n a: ");
		int x;
		int i;
		for (i = 0; i < n; ++i) {
			cout << "\n " << a[i] << " ? " << Binsearch(a,0,n-1,a[i]);
			cout << "\n " << a[i]+1 << " ? " << Binsearch(a,0,n-1,a[i]+1);

			Go();
		}
			

		}

main(){
	// BirthDay();
	
	T2();
	
 //-----------------------------
 cout << " \n T H E   E N D .";
 return 0;
}

