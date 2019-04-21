 #include <iostream> // input /  output
 #include <fstream>  // files
 #include <windows.h>
 #include <cmath>
 using namespace std;
 //------------------------------
 const int MN = 1002;
 const char BL = 32;
 const char EMPTY = '#';
 const char EOL = '\0';
 const char PLUS = '+';
 const char MINUS = '-';
 const char MULT = '*';
 const char DIV = '/';
 const char OPEN = '(';
 const char CLOSE = ')';

 
 const char *OPS = "+-*/";
 const int OPSIZE = strlen(OPS);
 
 char s[MN];
 int n;
 int si;
 
 char pol[MN]; // plish form
 int pi;
 
 char ops[MN]; //operation stack
 int oi;
 
 void ToOps(char o) { ops[++oi] = o; }
 
 char TakeOps() { char o = ops[oi--]; return o; }
 
 char TopOps() { return ops[oi]; }

 void ToPol(char v) { pol[pi++] = v;  }
 
 void OpsToPol() { ToPol(TakeOps()); }
 
 bool IsVar(char x) { return x >= 'a' && x <= 'z'; }
 
 int Index(const char * s, char c) {
		char * p = strchr(s, c);
		return (p == NULL) ? -1 : p-s;
 }
 
 bool IsOps(char o) {
   int i = Index(OPS, o);
	 return (i >= 0 && i < OPSIZE);
 }
 
 bool IsOpsEmpty() { return ops[oi] == EMPTY; }
 
 int Deg(int op) {
		switch(op) {
		case MULT: return 100;
		case DIV: return 100;
		case PLUS: return 200;
		case MINUS: return 200;
		default: return 1000;
		}
 }


 void UpdateOps(char o) {
		while (Deg(TopOps()) <= Deg(o)) OpsToPol();
		ToOps(o);
 }
 
 void Polish() {
		si = 0;
		oi = 0; ops[oi] = EMPTY;
		pi = 0;
		int i;
		for (i = 0; i < n; ++i) {
			 if (IsVar(s[i])) { ToPol(s[i]); continue; }
			 if (IsOps(s[i])) {
			    UpdateOps(s[i]);
					continue;
			 }

		}

		while (!IsOpsEmpty()) OpsToPol();
		ToPol(EOL);
		cout << "\n POL = " << pol;
		ToOps(EOL);
		cout << "\n Ops = " << ops;

		
 }
 
 void Run(const char *ss) {
		int i;
		n = 0;
		for (i = 0; ss[i]; ++i) {
			 if (ss[i] != BL) s[n++] = ss[i];
		}
		s[n++] = EMPTY; s[n] = EOL;
		cout << "\n Input: " << s;
		Polish();
 }

 main() {
		Run("a+b*c-d/c*e");
	  cout << "\n T H E   E N D.";
 }



