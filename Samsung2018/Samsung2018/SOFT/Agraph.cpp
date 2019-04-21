 // AGRAPH.CPP (Array)
 // Operations on undircted graph
 // Find - Union Method
 // Doc du lieu ghi mang
 // roi xu li
 // Tai su dung

  #include <iostream>
  #include <fstream>
  #include <windows.h>
  #include <cmath>
  #include <algorithm>
  using namespace std;
 //-------------------------------

  const char * fn = "gr.inp";
  const int MN = 101;
  int d[MN]; // lien ket cac dinh
  int n; // so dinh
  int m; // so canh

 const int EDGE = 1;
 const int STREE = 2; // canh thuoc spanning tree
 const int IBRIDGE = 3; // Important Bridge Cau trong yeu

 typedef struct EdgeType {
					 int X, Y; // End Points
					 int Type; // EDGE | STREE | IBRIDGE
        }  EdgeType;

 EdgeType e[MN]; // Array of Edges

 // Moi dinh la 1 nhom
 //  Tu minh lam nhom truong
 void Init() {
	for (int i = 1; i <= n; ++i) d[i] = i;
 }
 
 // Print edge array e[d..c]
 // Only edge satisfyes give type
 // return the number of trinted edges
 int Eprint(int d, int c, int type, const char *msg = "") {
			cout << msg;
			int s = 0;
			for (int i = d; i <= c; ++i) {
				if (e[i].Type == type) {
					 ++s;
			     cout << "\n " << i << ". "
				     << e[i].X << " - " << e[i].Y << ": "
						 << e[i].Type;
				}
			}
			return s;
 }

// Tim nhom truong
// cua nhom chua x
int Find(int x) {
	 while (d[x] != x) x = d[x];
	 return x;
}

int Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return 0;
	if (x < y) d[y] = x;
	else d[x] = y;
	return 1;
}

	//  So thanh phan lien thong
	// sau khi xoa canh thu c
 int ConnectedPath(int c = 0) {
	Init();
	int k; // so thanh phan lien thong
	int i;
	k = n;
	for (i = 1; i < c; ++i) {
	 // cout << "\n Xet canh " << x << " - " << y;
	 k -= Union(e[i].X, e[i].Y);
	}
	for (i = c+1; i <= m; ++i) {
	 // cout << "\n Xet canh " << x << " - " << y;
	 k -= Union(e[i].X, e[i].Y);
	}
 return k;
}

bool LienThong() {
	 return (ConnectedPath() == 1);
}

int LienThongHoa() {
	 int t = ConnectedPath();
	 if (t == 1) return 0;
	 // t > 1: noi them t-1 canh
	 cout << "\n Can noi them " << t-1 << " canh:";
	 for (int i = 2; i <= n; ++i)
			if (d[i] == i) cout << "\n 1 - " << i;
}

// Liet ke cac ConnectedPath
void List() {
	ifstream f(fn);
	f >> n >> m;
	// cout << "\n So dinh: " << n << "  So canh: " << m;
	Init();
	int k; // so thanh phan lien thong
	int x, y;
	int i;
	k = n;
	for (i = 1; i <= m; ++i) {
	 f >> x >> y;
	 // cout << "\n Xet canh " << x << " - " << y;
	 k -= Union(x,y);
	}
	f.close();
	cout << "\n DO THI CO " << k << " THANH PHAN LIEN THONG: ";
	for (i = 1; i <= n; ++i) {
	 if (d[i] == i) { // nhom truong i
		 cout << "\n Nhom Truong " << i << ": ";
		 for (x = i+1; x <= n; ++x)
				if (Find(x) == i) cout << x << " ";
   }
	}
}

// Read input data from file fn
 // to edge array e
 void Read() {
	 ifstream f(fn);
	 if (f.fail())  {
			cout << "\n Unable open input file " << fn;
			exit(1);
	 }
		f >> n >> m;
		cout << "\n Vertex: " << n << "  Edge: " << m;
		for (int i = 1; i <= m; ++i) {
			f >> e[i].X >> e[i].Y;
			e[i].Type = EDGE;
		}
		f.close();
		Eprint(1, m, EDGE, "\n After data reading: " );
 }
/*-------------------------------------
  Cay khung cay id inh nhat van
  giu cho do thi lien thong
  n dinh cay BT co n-1 canh
  1. Input la do thi lien thong: co cay khung
  2. Input ko lien thong: moi manh LT co 1 cay khung
  Rung khung
  2 tiep can
	TC1. Prim: loai dan canh: ko lam tang so ConnectedPath
	TC2. Kruskal: Them dan canh FU (cai dat)
	return
		so luong cay khung 1(cay khung) >1(rung khung)
  
  
  -------------------------------------- */
 int SpanningTree() {
	  Init();
		for (int i = 1; i <= m; ++i)
			 if (Union(e[i].X,e[i].Y)) e[i].Type = STREE;
		cout << "\n The edge belonging Spanning tree "
		<< "is marked by " << STREE;
		int s = Eprint(1, m, STREE);
		cout << "\n Total " << s << " Edge(s).";
		return s;
 }
 

  // Liet ke cac cau trong yeu
  // trong DT lien thong
  // Read phai lam truoc
  // List all Important Bredges
  // Only run after Read
  int ImportantBridges() {
		// Moi cau trong yeu deu thuoc cay khung
		int s = SpanningTree();
		// Scan
		for  (int i = 1; i <= m; ++i) {
			if (e[i].Type == STREE) {
				 if (ConnectedPath(i) > 1) e[i].Type = IBRIDGE;
			} // if
	  } // for
	  s = Eprint(1, m, IBRIDGE, "\n Result: ");
	  cout << "\n Total " << s << " Edge(s).";
	  return s;
  }
 

main() {
	Read();
	ImportantBridges();
	cout << "\n T H E   E N D.";
	return 0;
}
/*************************************
	ham he thong chu thuong
	abc_my
	
	user function Hoa
	HoaHau
	variable thuongThoi
	const HOA
*************************************/
