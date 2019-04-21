	/*************************************

	 Find Union: Tim va gop
	 Init;
	 
  *************************************/
  // Dat moi truong
  #include <iostream>
  #include <fstream>
  #include <windows.h>
  // #include <time.h>
  
	using namespace std;
	
	const char * fn = "GR1.INP";
	const int MN = 200;
	// mang cac canh x - y
	
	typedef struct Edge {
										int x;
										int y;
									};

	Edge e[MN];
	
	int n; // so  dinh
	int m; // so canh
	int d[MN]; // d[i] = j (i) bam (j)
	
	void Read() {
		ifstream f(fn);
			f >> n;
			cout << "\n So dinh: " << n;
			m = 0;
			int i;
			for (i = 1; true; ++i) {
				 f >> e[i].x >> e[i].y;
				 if (e[i].x == 0 && e[i].y == 0) {
				    m = i-1;
						break;
		     }
				cout << "\n " << e[i].x << " - " << e[i].y;
			}
			// m = i-1;
		f.close();
		cout << "\n So canh: " << m;
	}
	
	void Init() {
	 for (int i = 1; i  <= n; ++i) d[i] = i;
	}
	
	// Tim nhom truong cua x
	int Find(int x) {
		 while (d[x] != x) x = d[x];
		 return x;
	}
	
	// Gop
	int Union(int x, int y) {
		 int tx = Find(x);
		 int ty = Find(y);
		 if (tx == ty) return 0;
		 if (tx < ty) d[ty] = tx;
		 else d[tx] = ty;
		 return 1;
	}
	
	int SoThanhPhanLT() {
		Init();
		int i;
		int s = n; // so TPLT
		for (i = 1; i <= m; ++i)
			 s -= Union(e[i].x, e[i].y);

			 /*
		for (i = 1; i <= n; ++i)
			 cout << "\n " << i << " bam " << d[i];
		// So TPLT = o Nhom = So NT
		// i la nhom truong <=> d[i] = i
		int s = 0;
		for (i = 1; i <= n; ++i)
			 if (d[i] == i) ++s;
			 */
			 
		return s;
	}
	
	// Lien thong hoa
	void Thi95() {
		Read();
		int s = SoThanhPhanLT();
		if (s == 1) {
		   cout << "\n  Ko noi. ";
		   return;
		 }
		 // s > 1
		 cout << "\n Noi them " << s-1 << " duong: ";
		 for (int i = 2; i <= n; ++i)
				 if (d[i] == i) cout << "\n  * 1 - " << i;
		
	}
	
	
	void Run() {
		Read();
		cout << "\n " << SoThanhPhanLT();
		
	}

	main() { // Phong khach
		//Run();
		Thi95();
		//---------------------------------------------
		 cout << endl << " T H E   E N D . ";
		 
	  return 0;       
	}

	
