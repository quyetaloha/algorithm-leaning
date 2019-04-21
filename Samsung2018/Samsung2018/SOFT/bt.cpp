/*
	Name: BT.CPP
	Copyright:
	Author:
	Date: 25-07-17 08:38
	Description:
	Tinh tri cua bieu thuc
	Dang don gian a..z, +, - , *, /
	Stack
*/
	#include <iostream>
	#include <fstream>
	#include <windows.h>
	#include <cmath>
	#include <algorithm>

	using namespace std;
	
	const int MN = 1000;
	const char PLUS = '+';
	const char MINUS = '-';
	const char MULT = '*';
	const char DIV = '/';
	const char SIGN = '~';
	const char EMPTY = '#';
	const char OPEN = '(';
	const char CLOSE = ')';
	const char EOL = '\0'; // ket dong
	
	const char BL = 32;
	
	const char* OPS = "+-*/";

	char pol[MN]; // Polish form
	int pi;
	
	char ops[MN]; // satck cac phep toan
	int oi;
	
	int st[MN]; // stack tinh toan
	int sti; // index of st
	
	char s[MN]; // input
	
	void Go() {
		 fflush(stdin);
		 if (cin.get() == '.') exit(0);
	}
	
	void Err(int e, char c = BL) {
			cout << "\n ERROR " << e;
			switch(e) {
				 case 1: cout << " unexpected symbol: " << c;
									break;
									
				 case 2: cout << " expected  " << c;
									break;
				 case 3:
									break;
				 case 4:
									break;

			}
			exit(e);
	}
	
	
	// c la bien ?
	bool Var(char c) { return c >= 'a' && c <= 'z'; }
	
	bool Ops(char c) { return strchr(OPS,c) != NULL; }
	
	// nap c vao stack ops
	void InsOps(char c) { ops[++oi] = c; }
	
	void InsPol(char c) { pol[pi++] = c; }
	
	// Xuat: lay ngon ops
	char TakeOps() { char c = ops[oi--]; return c; }
	
	// Nhin ngon ops
	char TopOps() { return ops[oi]; }
	
	// Lay phep toan tren ngon ops dua sang pol
	void OpsToPol() { InsPol(TakeOps()); }
	
	// Bac cua phep toan operation
	int Deg(char o) {
		switch(o) {
			 case PLUS: return 300;
			 case MINUS: return 300;
			 case MULT: return 200;
			 case DIV : return 200;
			 case SIGN : return 100;
			 default : return 1000;
		}
	}
	
	// Gap phep toan
	// Lay het ngon st ops bac <= bac (c)
	// nap c
	void Operator(int c) {
		 while (Deg(TopOps()) <= Deg(c)) OpsToPol();
		 InsOps(c);
	}
	
	// (+-..    )
	void Close() {
		 while(Ops(TopOps())) OpsToPol();
		 if (TopOps() != OPEN) Err(2,OPEN);
		 TakeOps(); // bo (
	}
	
	bool PlusOrMinus(char c) {
		if (c != PLUS && c != MINUS) return false;
		// c = + | -
		if (c == PLUS) return true;
		// pm = -
		InsOps(SIGN);
		return true;
	}
	
	void Phase1() {
		pi = 0;   oi = 0; InsOps(EMPTY);
		int i = 0;
		// while (s[i] == BL) ++i;
		if (PlusOrMinus(s[i])) ++i;
		for (; s[i]; ++i) {
			 if (Var(s[i]))  { InsPol(s[i]); continue; }
			 if (s[i] == BL)   continue;
			 if (Ops(s[i])) { Operator(s[i]); continue; }
			 if (s[i] == OPEN) {
			    InsOps(OPEN);
			    // ++i; while (s[i] == BL) ++i;
					if (PlusOrMinus(s[i+1])) ++i;
					continue;
			 }
			 if (s[i] == CLOSE) { Close(); continue; }
			 Err(1, s[i]);
		}
		// vet not ops
		while  (Ops(TopOps())) OpsToPol();
		
		InsPol(EOL);
	}
	
	// Execution
	int Phase2() {
		sti = 0;
		int i;
		cout << "\n Input: " << pol << endl;
		for (i =  0; pol[i]; ++i) {
				// cout << pol[i];
				if (Var(pol[i])) { st[++sti] = pol[i]-'a'; continue; }
				switch(pol[i]) {
					case PLUS: st[sti-1] += st[sti]; --sti; break;
					case MINUS: st[sti-1] -= st[sti]; --sti; break;
					case MULT: st[sti-1] *= st[sti]; --sti; break;
					case DIV: st[sti-1] /= st[sti]; --sti; break;
					case SIGN: st[sti] = -st[sti]; break;
				} // switch
		}
		return st[1];
	}
	
	void Run(char * ss) {
		int i, j;
		j = 0;
		for (i = 0; ss[i]; ++i)
			 if (ss[i] != BL) s[j++] = ss[i];
		s[j] = EOL;
		cout << "\n Input: " << s;
		Phase1(); // ss -> pol
		// int v = Phase2(); // thuc hien pol
		cout << "\n Polish Form: " << pol;
		int v = Phase2();
		cout << "\n Result: " << v;
		
	}
	
	void T1() {
		 Run("-b*d"); // bd+ 4
		 Go();
		 
		 Run("  (   -  b  +  d  )   "); // bd+ 4
		 Go();
		 
		 Run("(b+d)*(-d-b)"); // bd+d~b-* -16
		 Go();
		 
		 Run("(b+d)*(-d-b) - ((b+d)*(-d-b))"); // ....
		 Go();
		 
		 Run("(b+d)*(-d-b) + ((b+d)*(-d-b))");
		 Go();
		 
		 Run("((b  +   d)*(-d-  b)) * ((b+d)*(-d-b))");
		 Go();
	}
	
	
	main() {
		
		T1();
		
		cout << "\n T H E   E N D.";
		return 0;
	}

