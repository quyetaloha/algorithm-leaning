/*   abd
	Name: HUFFMAN.CPP
	Copyright:
	Author:
	Date: 08-08-17 10:01
	Description:
	  Ma Huffman
*/
	#include <iostream>
	#include <fstream>
	#include <windows.h>
	#include <cmath>
	#include <algorithm>

	using namespace std;
	
	const int MN = 300;
	int p[MN]; // bang tan xuat, trong so
	char chr[MN]; // cac ki tu khac nhau
	int n; // so ki tu khac nhau
	int h; // cay Huffman
	int l[MN], r[MN]; // cay trai, phai
	char * s;
	string code[128];
	int len; // len(input)
	bool mark[MN];
	string ecode;
	int id[MN];

	void Go() {
	 fflush(stdin);
	 if (cin.get() == '.') exit(0);
	}
	
	void TrongSo() {
		int i;
		n = 0;
		memset(p, 0, sizeof(p));
		for (i = 0; i < len; ++i) {
			 ++p[s[i]];
		}
		n = 0;
		// Kiem lai
		for (i = 0; i <= 255; ++i) {
				if (p[i] > 0) {
					 // cout << "\n " << char(i) << " : " << p[i];
					 ++n;
					 p[n] = p[i];
					 chr[n] = char(i);
					 id[chr[n]] = n;
				}
		}
		for (i = 1; i <= n; ++i)
			 cout << "\n " << i << ". " <<  chr[i] << ":" << p[i];
	}
	
	
	// Tim 2 dinh u, v co trong so min
	// va chua xet
	void Min2(int &u, int &v) {
		 int imin = 0;
		 p[imin] = 9999999999; // 10 so 9
		 int i;
		 for (i = 1; i <= h; ++i) {
				if (!mark[i]) {
					 if (p[i] < p[imin]) imin = i;
				}
		 }
		 u = imin;
		 // cout << "\n Scan 1, u = " << u;
		 mark[u] = true;
		 
		 imin = 0;
		 for (i = 1; i <= h; ++i) {
				if (!mark[i]) {
					 if (p[i] < p[imin]) imin = i;
				}
		 }
		 v = imin;
		 mark[v] = true;
		 // cout << "\n Min2 at : " << u << " " << v;
	}
	
	void HuffmanTree() {
		h = n;
		int i;
		int u, v;
		memset(mark, false, sizeof(mark));
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));

		for (i = 1; i < n; ++i) { // lap n-1 lan
				Min2(u, v);
				++h; p[h] = p[u]+p[v];
				l[u] = r[v] = h;

				cout << "\n " << h << "(" << u << "," << v << ")" << p[h];
		}
	}
	
	// sinh ma cho ki tu thu i
	void Gen(int i) {
			cout << "\n Generate code for " << chr[i];
			int j = i;
		  code[i] = "";
		  while (j != h) {
			 if (l[j] > 0) { // co cha
				 j = l[j];
				 code[i] = '1' + code[i];
		   }
		  else if (r[j] > 0) {
		  	  j = r[j];
					code[i] = '0' + code[i];
		    }
		  } // while
	}
	
	// sinh code cho n ki tu trong chr
	void GenCode() {
		int i;
		for (i = 1; i <= n; ++i) {
			Gen(i);
			cout << "\n " << code[i];
			// Go();
		}
		ecode = "";
		for (i = 0; i < len; ++i)
			 ecode += code[id[s[i]]];
		cout << "\n Encode: " << ecode;

	}
	
	void Huffman(char * ss) {
		s = ss;
	  cout << "\n Input: " << s;
	  len = strlen(s);
	  cout << "   len = " << len;
	  TrongSo();
	  HuffmanTree();
		GenCode();
		// Ti le nen

		cout << "\n Ti le nen: " << (ecode.length()+7)/8 << " vs " << strlen(s);
		
	}
	
	void HuffmanTree2() {
		h = n;
		int i;
		int u, v;
		memset(mark, false, sizeof(mark));
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		for (i = 1; i < n; ++i) { // lap n-1 lan
				Min2(u, v);
				++h; p[h] = p[u]+p[v];
				l[h] = u; r[h] = v;
				cout << "\n " << h << "(" << u << "," << v << ")" << p[h];
		}
	}
	
	// Bien doi ecode -> van ban
	// input : bang tan xuat
	void Decode() {
			HuffmanTree2();
			// doc tung bit tu code
			// 1 : trai; 0: phai; la xuat ki tu
			int nn = ecode.length();
			cout << "\n So bit " << nn << "\n -> ";
			int p; // parent
			p = h;
			for (int i = 0; i < nn; ++i) {
				 if (ecode[i] == '0') p = r[p];
				 else p = l[p];
				 if (p <= n) {
				    cout << chr[p];
				    p = h;
				 }
			} // for
	}
	
	/*--------------------------------------------
		 Home work: Nen file
		 Fencode(f1, f2);
		 Fdecode(f2, f3)
		 f1 = f3 ?
		 Doc f1 -> s
		 Day bit ghi dang byte  	----------------------------------------------*/
	
	
	main() {
		Huffman("noi*dong*nau*oc*noi*dat*nau*ech"); Go();
		Decode(); // code -> string
		
		Huffman("SamSung*Rac*Roi*nhu*Sung"); Go();
		Decode(); // code -> string
		
		cout << "\n T H E   E N D.";
		return 0;
	}

