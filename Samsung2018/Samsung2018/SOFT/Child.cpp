// DEVCPP
// Dat moi truong
#include <iostream>
#include <windows.h>
// #include <cmath>
#include <algorithm>

using namespace std;

int a[2000] = {1, 3, 7, 9, 10,
               18, 2, 7, 4, 1,
							 17, 6, 20, 13, 9};


/**************************************
		Xuat phat tu chuong trinh rong
		Ko loi IBM clean Room Technology
		1/1 1 lenh / 1 lan
		Agile Method = PP linh loi
		Tham bien giup cho ham linh hoat
		Dong qui Qui ve mot moi
***************************************/

void Print(int a[], int d, int c, const char * msg = "") {
	cout << msg;
	for (int i = d; i <= c; ++i) cout << " " << a[i];
}

void Swap(int a[], int i, int j) {
	int c = a[i];
	a[i] = a[j];
	a[j] = c;
}

void Sort(int a[], int d, int c) {
	int t, p;
	for (t = d; t <= c; ++t)
		 for (p = t+1; p <= c; ++p)
				if (a[p] < a[t]) Swap(a, p, t);
}

// Bubble Sort
void Bsort(int a[], int d, int c) {
	 for (int t = d; t <= c;  ++t)
			for (int p = c; p > t; --p)
				 if (a[p] < a[p-1]) Swap(a, p, p-1);
}

/*-------------------------------------
	Array Scanning Duyet mang
	->
	<-
	-> <-
	A|||||||||||||||B
	
	1 2 3 4 5
	1 4 3 2 5
	-------------------------------------*/
void Inv(int a[], int d, int c) {
	while (d < c) {
		Swap(a, d, c);
		++d; --c;
	}
}

int Rhythm(int a[], int d, int c) {
	int g, t, b;
	const int KEU = 1;
	// int r;
	g = t = b = 0;
	for (int i = d+1; i <= c; ++i) {
		 if (a[i] == a[i-1]) b = KEU;
		 else if (a[i] > a[i-1]) t = KEU;
		 else g = KEU;
	}
	b = 4*g + 2*t + b;
	return (b < 6) ? b : 0;
}


main() {
	 int n = 15;
	 int d = 0;
	 int c = n-1;
	 Print(a, d, c, "\n Before Sorting: ");
	 cout << endl  << Rhythm(a, d, c); // 0
	 
 	 Bsort(a, d, c);
		Print(a, d, c, "\n After Sorting: ");
		cout << endl << Rhythm(a, d, c); // 3
		// Lat mang
		Inv(a, d, c);
		Print(a, d, n-1, "\n After Inversting: ");
		cout << endl << Rhythm(a, d, c); // 5

	 // cout << "\n  HELLO WORLD !"; // Chao doi
	 return 0;
}



