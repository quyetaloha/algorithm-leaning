/*
	Name: BIEUTHUC1.CPP
	Copyright:
	Author:
	Date: 25-07-17 13:43
	Description:
		Tinh tri cua bieu thuc voi bien don
		Dung ngan xep
*/

 #include <iostream>
 #include <windows.h>
 #include <time.h>
 
 using namespace std;
 
 const int MN = 1000;
 
 const char BL = 32;
 const char PLUS = '+';
 const char MINUS = '-';
 const char MULT = '*';
 const char DIV = '/';
 const char SIGN = '~';
 const char EOL = '\0';
 const char EMPTY = '#';
 const char OPEN = '(';
 const char CLOSE = ')';


 
 const char * OPS = "+-*/~";

 
 char pol[MN]; // Dang Balan
 int pi; // index cua pol
 
 int t[MN]; // stack phase 2
 int ti;
 
 char ops[MN];
 int oi;
 
 
 char s[MN];
 
 void Err(int e, char c = BL) {
	 cout << "\n ERROR " << e;
	 switch(e) {
			case 1: cout << " Divide by zero."; break;
			case 2: cout << " Unexpected symbol " << c; break;
			case 3: cout << " Expected " << c; break;


	 	
	 } // sw
	 exit(e);
 }
 
 bool Var(char c) { return c >= 'a' && c <= 'z'; }
 
 bool Ops(char c) { return strchr(OPS,c) != NULL; }
 
 void InsPol(char c) { pol[pi++] = c; }
 
 void InsOps(char c) { ops[++oi] = c; }
 
 // Lay noc cua ops
 char TakeOps() { char c = ops[oi--]; return c; }
 
 // xem noc cua ops
 char TopOps() { return ops[oi]; }
 
 // chuyden noc ops qua pol
 void OpsToPol() { InsPol(TakeOps()); }
 


 int Deg(char c) {
		switch(c) {
		  case PLUS : return 500;
		  case MINUS: return 500;
			case MULT : return 300;
			case DIV : return 300;
			case SIGN : return 100;
			default : return 1000;
		}
 }
 
 void Operator(char c) {
		 while(Deg(TopOps()) <= Deg(c)) OpsToPol();
		 InsOps(c);
 }


 void Close(char c) {
	 while(Ops(TopOps())) OpsToPol();
	 if (TopOps() != OPEN) Err(3, OPEN);
	 TakeOps();
 }
 

 // Duyet kiem tra cu phap
 // chuyen qua pol
 /*-------------------------------------
		Deg () 1 ngoi  +- uu tien bac nho

		a+b*c                 +*
		pol: abc*+
		Gap phep toan: lay ngon ops co bac <= bac xuat sang pol
		nap phep toan moi

		- doi thanh ~ duy nhat tai dau BT
		-a+b  a~b+
		a+(-d...)
		-b*()/()
		+x-y
 
 ---------------------------------------*/
 bool PlusOrMinus(char c) {
 	if (c != PLUS && c != MINUS) return false;
 	// c = + , -
 	if (c == MINUS) InsOps(SIGN);
 	return true;
 }
 
 void Phase1() {
		oi = 0; pi = 0;   InsOps(EMPTY);
		int i = 0;
		if (PlusOrMinus(s[i])) ++i;
		
		for (; s[i]; ++i) {
			 if (Var(s[i])) { InsPol(s[i]); continue; }
			 if (Ops(s[i])) { Operator(s[i]); continue; }
			 if (s[i] == OPEN) { InsOps(OPEN);
			    if (PlusOrMinus(s[i+1])) ++i; continue; }
			 if (s[i] == CLOSE) { Close(s[i]); continue; }
			 Err(2,s[i]);

			
		}
		// Lay not cac phep toan
		while (Ops(TopOps()))  OpsToPol();
		InsPol(EOL);
		cout << "\n POL = " << pol;
 	
 }
 
 // Thuc hien bieu thuc dang BL
 void Phase2() {
		// strcpy(pol, s);
		cout << "\n Input: " << pol;
		ti = 0;
		for (int i = 0; pol[i]; ++i) {
				// cout << s[i];
				if (Var(pol[i])) t[++ti] = pol[i]-'a';
				switch(pol[i]) {
					 case PLUS: t[ti-1] += t[ti]; --ti; break;
					 case MINUS: t[ti-1] -= t[ti]; --ti; break;
					 case MULT: t[ti-1] *= t[ti]; --ti; break;
					 case DIV: if (t[ti] == 0) Err(1);
					           t[ti-1] /= t[ti]; --ti; break;
					 case SIGN: t[ti] = -t[ti]; break;
				} // sw
			
		}   // for
 	
 	cout << "\n RESULT :  " << t[ti];
 }
 
 
 void Run(const char * ss) {
		// chuyen ss sang s bo BL
		int i, j = 0;
		for (i = 0; ss[i]; ++i)
			 if (ss[i] != BL) s[j++] = ss[i];
		s[j] = EOL;
		
		cout << "\n " << ss;
		cout << "\n Input: " << s;
		 Phase1();
		// strcpy(pol,"da+cb-*ze*b+ze*-/");
		
		 Phase2();
 	
 }
 
void T1() {
	// Phase2("da+cb-*ze*b+ze*-/"); // (d+a)*(c-b)/(z*e+b-z*e) 3
	
}

	
 main() {
 	
	 Run("    -a + b * c - d/e  ");
	 Run("    (a + b * c) - (-d *e) ");
	 
	 Run("    a + b * c - d/e  ");
	 Run("    (a + b * c - d/e) - (a + b * c - d/e)   ");
	 Run("    (a + b * c - d/e) + (a + b * c - d/e)   ");
	 Run("    (a + b * c - d/e)*f + (a + b * c - d/e)*c   ");



	 

	 Run("  (  a + b) *( c -d  )");
 	
	//---------------------------------
	cout << "\n T H E   E N D.";
 	return 0;
 }

