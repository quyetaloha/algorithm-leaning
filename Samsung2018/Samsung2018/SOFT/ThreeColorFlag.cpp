/*
	Name: ThreeColorFlag.CPP
	Copyright: X
	Author:
	Date: 05-07-18 08:17
	Description: Sap thanh BLUE(X)WHITE(W)RED(R)
*/
	#include <iostream>
	#include <fstream>
	#include <windows.h>
	// #include <cmath>
	// #include <algorithm>

	using namespace std;
	
	const char * fn = "BWR.INP";
	
	string s;
	
	void Read() {
		ifstream f(fn);
		f >> s;
		f.close();
		cout << s;
	}
	
	void SoHoa() {
		for (int i = 0; s[i]; ++i) {
			 if (s[i] == 'B') s[i] = '1';
			 else if (s[i] == 'W') s[i] = '2';
			 else s[i] = '3';
		}
	}
	
	void HoaSo() {
		for (int i = 0; s[i]; ++i) {
			 if (s[i] == '1') s[i] = 'B';
			 else if (s[i] == '2') s[i] = 'W';
			 else s[i] = 'R';
		}
	}
	
	void Sort() {
			int t, p, len = s.length();
			char c;
			cout << "\n len = " << len;
			for (t = 0; t < len; ++t)
					for (p = t+1; p < len; ++p)
							if (s[p] < s[t]) {
								c = s[p]; s[p] = s[t];
								s[t] = c;
							}
							
	}   // B = 1, W = 2, R = 3 WR,  B < R < W

void Run1() {
		Read(); // Doc input -> s
		SoHoa(); // B = 1, W = 2, R = 3
		Sort();
		HoaSo();
		cout << "\n " << s;
}

int cb, cw, cr;

void Count() {
	 cb = cw = 0;
	 for (int i = 0; s[i]; ++i)
			if (s[i] == 'B') ++cb;
			else if (s[i] == 'W') ++cw;
	cr = s.length() - cb - cw;
}

void Color() {
	 int i;
	 s = "";
	 for (i = 0; i < cb; ++i) s += 'B'; // BLUE
	 for (i = 0; i < cw; ++i) s += 'W';
	 for (i = 0; i < cr; ++i) s += 'R';
	 
	
}

void Run2() {
	 Read();
	 Count();
	 cout << "\n " << cb << ":" << cw << ":" << cr;
	 Color();
	 cout << "\n Flag: " << s;

}

	main() {
		Run2();
		cout << "\n T H E   E N D.";
		return 0;
	}

