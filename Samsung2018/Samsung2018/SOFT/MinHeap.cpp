/*
	Name: MinHeap
	Copyright:
	Author:
	Date: 01-08-17 12:04
	Description:
*/
 #include <iostream>
// #include <fstream>
 #include <windows.h>
 //#include <cmath>
 //#include <algorithm>
 #include <time.h>
 
 using namespace std;

 //------------------------------

 const int MN = 1002;
 const char BL = 32;
 const char EOL = '\0';
 
 int h[MN];
 int hi;

 int a[MN];
 
 void Go() {
	 fflush(stdin);
	 if (cin.get() == '.') exit(0);
 }
 
 void PP(int a[], int d, int c, const char *msg) {
	 cout << msg;
	 for (int i = d; i <= c; ++i) cout << BL << a[i];
 }
 
 void Init() { hi = 0; }
 
 // Tu h[i] di len
 void Up(int i) {
	 int p, c; // parent p, child c
	 int v = h[i];
	 c = i;
	 while (true) {
		 if (c == 1)  break;
		 p = c/2;
		 if (h[p] <= v) break;
		 // h[p] > v
		 h[c] = h[p]; c = p;
	 }
	 h[c] = v;
 }
 
 // Tu h[i] di xuong
 void Down(int i) {
	 int p, c; // parent p, child c
	 int v = h[i];
	 p = i; // c = p/2;
	 while (true) {
		 c = 2*p;
		 if (c > hi) break;
	   if (c < hi) { if (h[c] > h[c+1]) c = c+1; }
		 if (h[c] >= v) break;
		 // h[c] < v
		 h[p] = h[c];  p = c;
	}
	h[p] = v;
 }
 

 void Ins(int v) {
	 ++hi; h[hi] = v; Up(hi);
 }
 
 int TakeMin() {
		int r = h[1];
		h[1] = h[hi];
		--hi;
		Down(1);
		return r;
 }
 
 void Update(int i, int v) {
		if (i < 1 || i > hi) return;
		if (v == h[i]) return;
		if (v < h[i]) {
			h[i] = v; Up(i);
			return;
		}
		// v > h[i]
		h[i] = v; Down(i);
 }
 
 // Tao min heap tu a[d..c]
 void Gen(int a[], int d, int c) {
	 Init();
	 for (int i = d; i <= c; ++i) Ins(a[i]);
 }
 
 void T1() {
	 int n = 10;
	 int i, v;
	 srand(time(NULL));
	 // Init();
	 for (i = 1; i <= n; ++i) {
	    a[i] = rand() % 50 + 1;
	    // cout << "\n Ins " << a[i];
	    // Ins(a[i]);
	    // PP(h, 1, hi, "\n h: "); Go();
	 }
	  
	 PP(a, 1, n, "\n Init a: ");
	 // PP(h, 1, n, "\n Init h: ");
	 int oldh;
	 
	 while(true) {
			cout << "\n ------------------------------";
			Gen(a, 1, n);
			PP(h, 1, n, "\n h: ");
			cout << "\n Ins i v: " ;
			fflush(stdin);
			cin >> i >> v;
			if (v < 0) return;
			cout << "\n Update h[" << i << "] = " << v;
			oldh = h[i]; h[i] = v;
			PP(h, 1, n, "\n New h: ");
			h[i] = oldh;
			Update(i, v);
			PP(h, 1, n, "\n Now h: ");
			cout << "\n Sort:";
	    while (hi > 0) {
			  cout << TakeMin() << BL;
	    }
	 }
 }
 
 
 
 main() {
 	T1();
 	

	  cout << "\n T H E   E N D.";
 }



