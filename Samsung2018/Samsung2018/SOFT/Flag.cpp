	/*************************************

	Name: FLAG.CPP
	Copyright: 2018
	Author: Le Van Bom
	Date: 06-07-18 13:51
	Description:
	 Co Tam Tai BWR
  *************************************/
  // Dat moi truong
  #include <iostream>
  #include <fstream>
  #include <windows.h>
  #include <time.h>
  
	using namespace std;
	
	const char * fn = "FLAG.INP";
	
	string s;
	
	void ToNum() {
		for (int i = 0; s[i]; ++i)
			 if (s[i] == 'B') s[i] = '1';
				 else if (s[i] == 'W') s[i] = '2';
					 else s[i] = '3';
	}
	
	// Swap Sort
	// B R W
	void Sort() {
			int t, p, c;
			for (t = 0; s[t]; ++t)
				 for (p = t+1; s[p]; ++p)
						if (s[p] < s[t]) {
							c = s[p]; s[p] = s[t];
							s[t] = c;
						}
	}
	
	

	void Run() {
		 // Doc
		ifstream f(fn);
		f >> s;
		cout << "\n Given: " << s;
		// So hoa
		ToNum();
		Sort();
		//ToChar();
		 // Sort
		 // Phoi
		 cout << "\n Now: " << s;
		
	}
	
	
	void Run2() {
		ifstream f(fn);
		f >> s;
		cout << "\n Given: " << s;
		int cr = 0, cw = 0, cb = 0, i;
		for (i = 0; s[i]; ++i)
			 if (s[i] == 'B') ++cb;
				 else if (s[i] == 'W') ++cw;
						else ++cr;
		cout << "\n " << cb << ":" << cw << ":" << cr;
		// cr = i - cb - cw;
		s = "";
		for (i = 1; i <= cb; ++i) s += 'B';
		for (i = 1; i <= cw; ++i) s += 'W';
		for (i = 1; i <= cr; ++i) s += 'R';

		cout << "\n Now: " << s;

		
	}
	

	main() { // Phong khach
		Run2();
		//---------------------------------------------
		 cout << endl << " T H E   E N D . ";
		 
	  return 0;       
	}

	
