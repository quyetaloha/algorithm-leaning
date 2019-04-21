// GR.CPP: Operations on Graph
// Find - Union Method
 #include <iostream> // input /  output
 #include <fstream>  // files
 #include <windows.h>
 #include <cmath>
 // #include <algorithm>
 using namespace std;
 //------------------------------
 const char * fn = "GR.INP";
 const int CANH = 1;
 const int KHUNG = 2;
 const int CAU = 3;

 const int MN = 1002;
 typedef struct Canh {
		 int X,Y;
		 int Type; // CANH(1) KHUNG(2), 3: CAU(3)
 } Canh;
 
 //-----------------------------=
 int n; // the number of vertexes
 int m; // The number of edges
 int d[MN];
 Canh cc[MN]; // cac canh
 
 
 // Initialise : n groups
 // Everyone is self head
 void Init() {
		for (int i = 1; i <= n; ++i) d[i] = i;
 }
 
 // Nhom truong cua nhom chua x
 int Find(int x) {
	 while (d[x] != x) x = d[x];
	 return x;
 }
 
 // Gop nhom chua x voi nhom chua y
 int Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		if (x == y) return 0;
		if (x < y) d[y] = x;
		else d[x] = y;
		return 1;
 }
 
 int ConnectPathNumber() {
		ifstream f(fn);
		f >> n >> m;
		// cout << "\n So Dinh = " << n <<  "  So canh = " << m;
		Init();
		int i;
		int k = n;
		// for (i = 1; i <= n; ++i) cout << "\n " << d[i];
		int x, y;  // canh (x,y)
		for (i = 1; i <= m; ++i) {
		  f >> x >> y;
			// cout << "\n Xet canh thu " << i << ": " << x
			   //  << " - " << y;
			k -= Union(x,y);
		}
		f.close();
		return k;
 }

 // Connectivity test
 bool Connect() {
		return ConnectPathNumber() == 1;
 }
 
 // List all connected paths
 void List() {
	 int t = ConnectPathNumber();
	 cout << "\n Co  " << t << " thanh phan LT: ";
	 int i, j;
	 for (i = 1; i <= n; ++i) {
			if (d[i] == i) {
				cout << "\n * " << i << ": ";
				for (j = i+1; j <= n; ++j)
					 if (Find(j) == i) cout << j << " ";
			}
	 }
 }
 
 // Lien thong hoa
 void Connective() {
	  int t = ConnectPathNumber();
	  if (t == 1) {
	  	cout << "\n Mang da lien thong. Ko can noi them.";
	  	return;
	  }
	  cout << "\n Can noi them " << t-1 << " cap may: ";
	  for (int i = 2; i <= n; ++i)
			 if (Find(i) == i) cout << "\n 1 " << " - " <<
			  i;
 }
 
 void SpanTree() {
	 ifstream f(fn);
	 f >> n >> m;
	 int x, y;
	 int c;
	 Init();
	 c = 0;
	 cout << "\n CAY KHUNG GOM CAC CANH SAU ";
	 for (int i = 1; i <= m; ++i) {
			f >> x >> y;
			if (Union(x,y) == 1) {
				 ++c;
				 cout << "\n Canh " << c << ". " << x << " - " << y;
			}
	 }
	 f.close();
 }
 
 void Read() {
		ifstream f(fn);
		f >> n >> m;

		for (int i = 1; i <= m; ++i) {
		 f >> cc[i].X >> cc[i].Y;
		 cc[i].Type = CANH;
		}
		f.close();
		/*
		cout << "\n So dinh: " << n << "  So canh: " << m;
		for (int j = 1; j <= m; ++j)
		   cout << "\n Canh " << j << ". " << cc[j].X << " - "
			       << cc[j].Y << " (" << cc[j].Type << ")";
			       */
 }
 
 // bo canh b
 int STPLT(int b = 0) {
		Init();
		int k = n;
		for (int i = 1; i < b; ++i) {
			 k -= Union(cc[i].X, cc[i].Y);
  	}
  	for (int i = b+1; i <= m; ++i) {
			 k -= Union(cc[i].X, cc[i].Y);
  	}
	 return k;
 }
 
 // Tim cay khung qua mang cc
 void Khung() {
		Init();
		for (int i = 1; i <= m; ++i)
				if (Union(cc[i].X, cc[i].Y) == 1)
						 cc[i].Type = KHUNG;
 }
 
 // Liet ke moi cau trong yeu
 // Muon la cau thi phai la khung
 void ImpBridges() {
		Read();
		int i;
		int t = STPLT();
		cout << "\n t = " << t;
		Khung();
		cout << "\n CAC CAU: ";
		for (i = 1; i <= m; ++i) {
			 // Thu pha cau c
			 // Tinh lai so TPLT
			 if (cc[i].Type == KHUNG && STPLT(i) > t) {
				  cc[i].Type = CAU;
					cout << "\n " << cc[i].X << " - " << cc[i].Y;
				}
		}
 }
 
 main() {
		// cout << endl << Connect();
		// Connective();
		// SpanTree();
		// Read();
		ImpBridges();
	  cout << "\n T H E   E N D.";
 }



