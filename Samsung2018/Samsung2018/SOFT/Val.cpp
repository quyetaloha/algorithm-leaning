/*
	Name: VAL.CPP
	Copyright:
	Author:
	Date: 25-07-17 08:38
	Description:
	Tinh tri cua bien dang string va dang ROM NUMERALS
*/
	#include <iostream>
	#include <fstream>
	#include <windows.h>
	#include <cmath>
	#include <algorithm>

	using namespace std;
	
	const char * ROM = "IVXLCDM";
	const int ROMSIZE = strlen(ROM);
	int val[] = {1, 5, 10, 50, 100, 500, 1000, 0};
	
	void Go() {
	 fflush(stdin);
	 if (cin.get() == '.') exit(0);
	}
	
	int Val(const char * s) {
	 int r = 0;
	 for (int i = 0; s[i]; ++i) r += s[i]-'a';
	 return r;
	}
	
	int Rindex(char c) { return strchr(ROM,c)-ROM; }
	
	/*--------------------------------------------------
		Qui tac: I=1 V=5 X=10 L=50 C=100 D=500 M=1000
	 AB = A+B neu A >= B
	 AB = B-A neu A < B
	 MMMCMXLVIII = 3948

	---------------------------------------------------*/
	int Rtoi(char * s) {
		int v = 0, v1, v2;
		int n = strlen(s);
		
		for (int i = 0; i < n; ++i) {
		  v1 = val[Rindex(s[i])];
		  v2 = (i == n-1) ? 0 : val[Rindex(s[i+1])];
		  if (v1 >= v2) v += v1; continue;
			// v1 < v2
			v += v2-v1; ++i;
		}
		return v;
	}
	
	/*-----------------------------------------
			int -> Rom
			4 9: IV=4, IX=9
			     XL=40 , XC=90
			     CD=400 , CM=900

				3948
				3000 MMM
				948 / 100 = 9 v = 48 CM
				48/10 = 4 8 XL
				8/1 8 0 VIII
			
	
	------------------------------------------*/
	char * Itor(int v, char *r) {
			int i, j = 0, k;
			int q;

			// Xet rieng hang 1000 M
			// 3948
			q = v/1000; v -= q*1000;
			for (i = 0; i < q; ++i) r[j++] = 'M';
			
			// MMM v = 948
			// v < 1000
			for (i = 4; i >= 0; i -= 2) { // duyet 100, 10, 1
			
				 if (v == 0) break;
				 
				 q = v/val[i]; v -= q*val[i];
				 
				 if (q < 4) {
					 for (k = 0; k < q; ++k) r[j++] = ROM[i];
					 continue;
				 }
				 
				 if (q == 4) { r[j++] = ROM[i]; r[j++] = ROM[i+1]; continue; }
				 // 723 / 100 q = 7, v = 23
				 if (q < 9) { r[j++] = ROM[i+1]; q -= 5;
						for (k = 0; k < q; ++k) r[j++] = ROM[i];
						}

				 if (q == 9) { r[j++] = ROM[i]; r[j++] = ROM[i+2]; continue;}
				 // IVXLCDM
				
			}
		r[j] = '\0';
		return r;
	}
	
	void T1() {
		char r[100];
		int v = 3948;
		
		cout << "\n " << v << " -> " << Itor(v,r);
		cout << " -> " << Rtoi(r); Go();

		v = 944;
		cout << "\n " << v << " -> " << Itor(v,r) << " -> " << Rtoi(r);
		

		for (int i = 1; i <= 5000; ++i) {
				cout << "\n " << i << " -> " << Itor(i,r) << " -> " << Rtoi(r); Go();
		}

	}
	
	
	main() {
		

		T1();
		
		cout << "\n T H E   E N D.";
		return 0;
	}

