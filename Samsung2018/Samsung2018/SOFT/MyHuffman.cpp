/*  abc
	Name: HUFFMAN.CPP
	Copyright:
	Author:
	Date: 08-08-17 10:01
	Description:
	  S2 Ma Huffman
*/
	#include <iostream>
	#include <fstream>
	#include <windows.h>
	#include <cmath>
	#include <algorithm>

	using namespace std;
	
	const int MN = 260;
	const int EN = 0;
	const int DE = 1;
	const char * s;
	int p[MN]; // weight = the appeart char in input string
	int len;
	int n; // so ki tu khac nhau trong s
	char chr[MN];
	int l[MN], r[MN]; // left child and right child
	int h; // Huffman root
	bool mark[MN];
	string code[MN];
	int id[MN]; // cho biet ki tu thu i trong chr
							// nam o dinh nao cua cay
	string ecode, dcode;
	
	void Go() {
		 fflush(stdin);
		 if (cin.get() == '.') exit(0);
	}
	
	// Tinh trong so = so lan xuat hien cua s[i]
	// n = so ki tu khac nhau trong s
	void TrongSo() {
		 int i;
		 memset(p, 0, sizeof(p));

		 for (i = 0; i < len; ++i) ++p[s[i]];
		 // co lai p
		 n = 0;
		 for (i = 0; i < 256; ++i)
				if (p[i] > 0) {
				  // cout << "\n " << (char)i << ":" << p[i];
				  ++n;
				  p[n] = p[i];
				  chr[n] = (char)i;
				  id[i] = n; // ki tu n la la thu may
				}
		  cout << "\n n = " << n;
		  for (i = 1; i <= n; ++i)
				 cout << "\n " << i << ". "<< chr[i] << ":" << p[i];
	}
	
	int Min() {
			int imin = 0, i;
		  for (i = 1; i <= h; ++i)
			   if (!mark[i]) {
				    if (p[i] < p[imin]) imin = i;
			   }
		 return imin;
	}
	
	void Min2(int & u, int & v) {
		u = Min(); mark[u] = true;
		v = Min(); mark[v] = true;
	}
	
	void HuffmanTree(int mode = EN) {
		int u, v, i;
		h = n;
		p[0] = 9999999999; // sentinel element
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		memset(mark, false, sizeof(mark)); // Danh dau dinh chua xu li
		for (i = 1; i < n; ++i) { // lap n-1 lan
			 Min2(u, v); // 2 min u and v
			 // cout << "\n " << u << "  " << v;
			 // u: trai, v = phai
			 ++h;	 p[h] = p[u]+p[v];
			 if (mode == 0) { l[u] = h; r[v] = h; }
			 else { l[h] = u; r[h] = v; }
			 cout << "\n " << h << "(" << u << "," << v << ") " << p[h];
		}
	}
	
	// Generate code for s[i]
	void Gen(int i) {
			int j = i;
			code[i] = "";
			cout << "\n sinh ma cho ki tu " << chr[i];
			while (j != h) {
					if (l[j] > 0) { // i la con trai
						 code[i] = '1'+code[i];
						 j = l[j];
				  }
				  else if(r[j] > 0) {
							 code[i] = '0'+code[i];
						  j = r[j];
				  }
		 }
		 cout << ": " << code[i];
	}
	// generate code foe each char in s
	void GenCode() {
		int i;
		 for (i = 1; i <= n; ++i) Gen(i);
		 ecode = "";
		 for (i = 0; i < len; ++i) {
				ecode += code[id[s[i]]];
		 }
		 cout << "\n -> " << ecode;
	}
	
	
	void Encode(const char * ss) {
		s = ss;
		cout << "\n  Input: |" << s << "|";
		len = strlen(s); cout << "   len = " << len;
		TrongSo();
		HuffmanTree();
		GenCode();
		cout << "\n Do nen: " << (ecode.length()+7)/8 << " vs " << strlen(s);
	}
	
	// ecode -> dcode
	// can: cay Huffman xuoi
	void Decode() {
		HuffmanTree(DE);
		dcode = "";
		int d = h;
		for (int i = 0; ecode[i]; ++i) {
			 if (ecode[i] == '1')  d = l[d];
			 else d = r[d];
			 if (d <= n) { dcode += chr[d]; d = h; }
		}
		cout << "\n -> |" << dcode << "|";
	}
	
	void FilePrint(const char *fn) {
		ifstream f(fn);
		if (f.fail()) {
			 cout << "\n Unable open file " << fn;
			 // return false;
		}

		char c;
		int i = 0;
		while (!f.fail()) {
			c = f.get(); cout << c;
			++i;
		}

	   f.close();
	   cout << "\n *** Total size: " << i;

	}
	
	bool FileCmp(const char *fn1, const char * fn2) {
		ifstream f(fn1);
		if (f.fail()) {
			 cout << "\n Unable open file " << fn1;
			 return false;
		}
		
		ifstream g(fn2);
		if (g.fail()) {
			 cout << "\n Unable open file " << fn2;
			 f.close();
			 return false;
		}
		char c1, c2;
		int i = 0;
		while (!f.fail() && !g.fail()) {
			c1 = f.get(); c2 = g.get();
			// cout << c1 << c2;
			++i;
			 if (c1 != c2) {
					cout << "\n Khac nhau tai ki tu " << i << ": " << c1 << " ? " << c2;
					 f.close(); g.close();
					 return false;
			 }
		}
	   f.close(); g.close();
		 return true;
	}
	
	main() {
		// Encode("Trong nhu tieng hac bay qua. Hihi: Duc nhu nuoc suoi moi sa nua voi!!!");
		// Encode("The Huffman code Ver. A37 is used every where...");
		// Go();
		// Decode(); // code -> string
		// cout << FileCmp("Huffman.cpp", "Huffman.cpp");

		cout << endl << FileCmp("Huffman.cpp", "MyHuffman.cpp");
		
		// FilePrint("Huffman.cpp");
		//---------------------------------------------
		cout << "\n T H E   E N D.";
		return 0;
	}
	
	/*---------------------------------------
		 HOME WORK
		 File Huffman
		 Encode f1 -> f2
		 Decode f2 -> f3
		 So sanh f1 f3 ?
		 
	
	
	------------------------------------------*/

