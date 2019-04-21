/*
	Name:   MAPHUONG.CPP
	Copyright:
	Author:
	Date: 01-08-17 08:43

*/

 #include <iostream>  // ***
 //#include <time.h>
 //#include <fstream>
 #include <windows.h>
 //#include <cmath>
 //#include <algorithm>

 using namespace std;

 const int MN =  202;

 int a[MN][MN];
 
 int n;  // the size of Magic Table

 int k;  // n/2

 int s; // dac so
 
 char sm[MN]; // Format string for even magical table

 void Go() {
		fflush(stdin);
		if (cin.get() == '.') exit(0);
	}


 void Print(int x[], int d, int c, const char * msg = "")  {
		 cout << msg;
		 for (int i = d; i <= c; ++i) cout << " " << x[i];
 }

 void Print(int x[][MN], int d, int c, const char * msg = "")  {
		 cout << msg;
		 for (int i = d; i <= c; ++i) Print(x[i],d,c,"\n ");
 }

 void Err(int e, int v) {
		cout << "\n ERROR " << e << ": ";
		switch(e) {
			case 1: cout << " An Odd number is expected. But " << v;
							break;
			case 2: cout << " row " << v; break;
			case 3: cout << " colum " << v; break;
			case 4: cout << " diagonal " << v; break;
			case 5: cout << " An Even number is expected. But " << v;
							break;



		}  // switch
		exit(e);
 }

 void CheckRow(int i) {
		int d = 0;
		for (int j = 1; j <= n; ++j) d += a[i][j];
		if (d != s) Err(2, i);
 }

 void CheckColum(int i) {
		int d = 0;
		for (int j = 1; j <= n; ++j) d += a[j][i];
		if (d != s) Err(3, i);
 }

 void CheckDiagonals() {
		int c1 = 0, c2 = 0;
		for (int i = 1; i <= n; ++i) {
				c1 += a[i][i];
				c2 += a[i][n-i+1];
		}
		if (c1 != s) Err(4, 1);
		if (c2 != s) Err(4, 2);
 }

 // is n an Odd Number ?
 // n le n%2 = 1
 // <> 0: true; 0: false
 bool Odd(int n) { return n & 1; }

 void Check()  {
	 int i;
	 for (i = 1; i <= n; ++i) {
	   CheckRow(i); CheckColum(i);
	 }
	 CheckDiagonals();
 }

 void MPL(int size) {
		 n = size;
		 if (!Odd(n)) Err(1, n);
		 int i = 1, j = n/2+1;
		 memset(a, 0, sizeof(a)); // lau bang

		 a[i][j] = 1;
		 int nn = n*n;
		 s = (nn+1)*n/2;
		 cout << "\n S(" << n << ")  = " << s;
		 for (int k = 2; k <= nn; ++k) {
				// Next tim o (i,j) tiep theo
				--i; ++j;
				if (i < 1 && j > n) // NE: Den duoi
				{ i += 2; --j; }
				else if (i < 1) i = n; // N : Nhay du
				else if (j > n) j = 1; // E : Day trai
				else if (a[i][j] > 0) { i += 2; --j; } // V: Den duoi
				a[i][j] = k;
		 }
		 Print(a, 1, n, "\n RESULT: ");
		 // ++a[n/2][n-1];
		 // Print(a, 1, n, "\n CHANGE: ");
		 // cout << "\n " << n/2 << "  " << n-1;
		 Check();
 }

 // Ki thuat dat linh canh
 void MPL1(int size) {
 	n = size;
 	if (!Odd(n)) Err(1, n);
 	// xoa bang
 	memset(a, 0, sizeof(a));
 	int nn = n*n;
 	s = (nn+1)*n/2; // Dac so
 	cout << "\n S("<<n<<") = " << s;
 	// Dat linh canh
 	int N = nn+1; // North
 	int E = nn+2;
 	int NE = nn+3;
 	int i, j;
	 for (i = 1; i <= n; ++i) {
			a[0][i] = N;
			a[i][n+1] = E;
	 }
	 a[0][n+1] = NE;
	 // Xuat phat
	 i = 1; j = n/2+1;
	 a[i][j] = 1;
	 for (k = 2; k <= nn; ++k) {
		 // Tim cho dat k
		 // NE
		 --i; ++j;
		 if (a[i][j] == NE) { // den duoi
				 i += 2; --j;
		 }
		 else if (a[i][j] == N) i = n; // Nhay du
		 else if (a[i][j] == E) j = 1; // dich trai
		 else if (a[i][j] > 0) { // den duoi
			 i += 2; --j;
		 }
		 a[i][j] = k;
	 } //  for
	 Print(a, 1, n, "\n RESULT: ");
	 Check();
 }



 /*-----------------------------------------------
		MPC Ma phuong bac chan
		k = n/2 ; k2 = k/2
		Tao xau mau sm gom k ki tu T, N, D, B
		k2 T
		neu k le them DN
		dien them B cho len = k
		T: Doi xung tam: A(i,j) <-> C(n-i+1, n-j+1)
										 B(i, n-j+1) <-> D(n-i+1,j)
		D: doi xung doc A(i,j) <-> B(i, n-j+1)
		N: Doi xung ngang  A(i,j) <-> D(n-i+1,j)
		x' = n-x+1
		Lap k lan
			 * Dien dong i theo xau mau
		   * Quay xau mau qua phai 1 vi tri




 -------------------------------------------------*/
 int  Num(int i, int j) {return (i-1)*n+j; }

 void NumToij(int num, int &i, int &j) {
		--num; // Doi sang he 0..n-1
		i = num / n + 1;
		j = num % n + 1;
 }
 
 // Dien dong i theo xau mau sm
 void Row(int i) {
	 int k = n/2;
	 for (int j = 1; j <= k; ++j) {
			switch(sm[j]) {
				 case 'D': a[i][j] = Num(i, n-j+1);
				           a[i][n-j+1] = Num(i,j); break;
				 case 'N': a[i][j] = Num(n-i+1, j);
				           a[n-i+1][j]= Num(i,j); break;
				 case 'T': a[i][j]  = Num(n-i+1, n-j+1);
									 a[n-i+1][n-j+1] = Num(i,j);
									 a[i][n-j+1] = Num(n-i+1, j);
									 a[n-i+1][j] = Num(i,n-j+1); break;
				
			} // switch
	 	
	 }
 	
 }
 
// Dien dong i theo xau mau sm
 void Row1(int i) {
	 int ip = n-i+1, jp, numij;
	 for (int j = 1; j <= k; ++j) {
			 jp  = n-j+1; numij = Num(i,j);
			switch(sm[j]) {
				 case 'D': a[i][j] = Num(i, jp); // A <-> B
				           a[i][jp] = numij;
									 break;
				 case 'N': a[i][j] = Num(ip, j); // A <-> D
				           a[ip][j]= numij;
									 break;
				 case 'T': a[i][j]  = Num(ip, jp);  // A <-> C
									 a[ip][jp] = numij;
									 a[i][jp] = Num(ip,j);  // B <-> D
									 a[ip][j] = Num(i, jp);
									 break;
			} // switch
	 }
 }
 
 // abcd -> dabc
 void QuaySm() {
	 char c = sm[k];
	 for (int i = k; i > 1; --i) sm[i] = sm[i-1];
	 sm[1] = c;
 }

 void MPC(int size) {
		n = size;
		if (Odd(n)) Err(5, n);
		int nn = n*n;
		s = (nn+1)*n/2;
		cout << "\n S(" << n << ") = " << s;
		// Dien bang
		int i, j;
		for (i = 1; i <= n; ++i)
			for (j = 1; j <= n; ++j)
				 a[i][j] = Num(i,j); // (i-1)*n+j
		Print(a, 1,  n, "\n Init a: ");
		/*
		for (k = 1; k <= nn; ++k) {
			NumToij(k, i, j);
			cout << "\n " << k << " in cell " << i <<  ":" << j;
		}
		*/
		k = n/2;
		int k2 = k/2;
		// Tao xau mau sm[1..k] T D N
		// k2 T
		sm[0] = '#';
		for (i = 1; i <= k2; ++i) sm[i] = 'T';
		// k le them DN
		j = k2;
		if (Odd(k)) { sm[++j] = 'D'; sm[++j] = 'N'; }
		// Dien B cho du k ki tu
		for (i = j+1; i <= k; ++i) sm[i] = 'B';
		sm[k+1] = '\0';
		cout << "\n Xau mau : " << sm;
		for (i = 1; i <= k; ++i) {
			 Row1(i);
			 QuaySm();
		}
		Print(a, 1, n, "\n RESULT: ");
		Check();
 }


 void MP(int size) {
		if (size == 2) { cout << "\n Not exist: " << size; return; }
		if (Odd(size)) MPL1(size); else MPC(size);
 }
 
 main() {
		for (int i = 1; i <= 100; ++i) {
		   MP(i); Go();
		 }
 //-----------------------------
 cout << " \n T H E   E N D .";
 return 0;
 }

