	/*******************************************
	  
	********************************************/
	#include <iostream>
	#include <fstream>
	#include <windows.h>

	using namespace std;
	
	const char * fn = "CODE.INP";
	const int MN = 100;
	
	int n; // so ki tu
	
	char a[MN];
	
	
	void Go() {
		 fflush(stdin);
		 if (cin.get() == '.') exit(0);
	}
	
	void Read() {
	   ifstream f(fn);
				f >> n;
				if (f.fail()) {
					cout << "\n Unable open file " << fn;
					return;
				}
				cout << "\n n = " << n;
				int i, code, j;
				char ch;
				string s;
				memset(a, 0, sizeof(a));
				for (i = 1; i <= n; ++i) {
					 f >> ch >> s;
					 cout << "\n " << ch << " : |" << s << "|";
					 code = 1;
						for (j = 0; s[j]; ++j) {
							  code *= 2;
						   if (s[j] == '1') ++code;
						} // for j						
						   a[code] = ch;
						   cout << "  code = " << code << " : " << a[code];
				} // for i
				
				//for (i = 1; i <= 30; ++i) 
				  //if (a[i] != 0) cout <<"\n " << a[i]; 
				// Giai ma
				f >> s; 
				cout << "\n Decode: \n " << s << "  len = " << s.length() << "\n : "; 
				code = 1;
				for (j = 0; s[j]; ++j) {
					  code *= 2;
					  if (s[j] == '1') ++code;
					  if (a[code] > 0) {
					  	  cout << a[code];
					  	  code = 1;
					  }
				}
				f.close();	
	}

void Run() {
  Read();	
}

  main() {
  	 Run();
  	
	  //--------------------------------------------- 
		 cout << endl << " T H E   E N D . ";
	  return 0;       
	}
	
