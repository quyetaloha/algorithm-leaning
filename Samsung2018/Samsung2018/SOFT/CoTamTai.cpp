	/*************************************

	Name: COTAMTAI.CPP
	Copyright: 2018
	Author: Le Van Bom
	Date: 05-07-18 14:18
	Description:
	 Sap Blue-White-Read Flag

  *************************************/
  // Dat moi truong
  #include <iostream>
  #include <fstream>
  #include <windows.h>
  #include <time.h>

	using namespace std;
	
	const char * fn = "FLAG.INP";
	
	string s;
	int Mo;
	
	void Read() {
		ifstream f(fn);
		f >> s;
		cout << s;
		f.close();
	}
	
	// B = 1, W = 2, R = 3
	void ToNum() {
		for (int i = 0; s[i]; ++i)
			if (s[i] == 'B') s[i] = '1';
			else if (s[i] == 'W') s[i] = '2';
				else s[i] = '3';
	}
	
	// B = 1, W = 2, R = 3
	void ToChar() {
		for (int i = 0; s[i]; ++i)
			if (s[i] == '1') s[i] = 'B';
			else if (s[i] == '2') s[i] = 'W';
				else s[i] = 'R';
	}

	void Sort() {
			int len = s.length();
			// cout << "\n len = " << len;
			int t, p;
			char c;
			for (t = 0; t < len; ++t)
				 for(p = t+1; p < len; ++p)
						if (s[p] < s[t]) {
								c = s[t]; s[t] = s[p];
								s[p] = c;
						}
	}  // B W R
	
	int cr,cw,cb;
	
	void Count() {
		cr = cw = 0;
		for (int i = 0; s[i]; ++i)
			 if (s[i] == 'R') ++cr;
			 else if (s[i] == 'W') ++cw;
		cb = s.length() - cr - cw;
	}
	
	
	void SetFlag() {
		 s = "";
		 int i;
		 for (i = 0; i < cb; ++i) s += 'B';
		 for (i = 0; i < cw; ++i) s += 'W';
		 for (i = 0; i < cr; ++i) s += 'R';
		 
	}
	
	void Run2() {
		 Read();
		 Count();
		 cout << "\n " << cb << ":"<< cw << ":" << cr;
		 SetFlag();
		 cout << "\n Flag: " << s;
	}
	
	
	void Run() {
		Read();
		ToNum();
		Sort();
		ToChar();
		cout << "\n" << s;

	}
	
	main() { // Phong khach
		 Run2();
		//---------------------------------------------
		 cout << endl << " T H E   E N D . ";
		 
	  return 0;       
	}

	
