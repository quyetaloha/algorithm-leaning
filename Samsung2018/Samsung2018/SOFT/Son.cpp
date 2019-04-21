// Son cac cot
#include <iostream> // input / output
#include <fstream>  // files
#include <windows.h>
#include <cmath>
#include <algorithm>

using namespace std;

const char * fn = "SON.INP";
const int MN = 102;

int a[MN][MN]; // cot
int n, m; // n dong, m cot

// Hien thi 1 dong x[d..c] ken chu thich
void Print(int x[], int d, int c, const char *msg = "") {
	 cout << msg;
	 for (int i = d; i <= c; ++i) cout << " " << x[i];
}

void Print(int x[][MN], int d1, int c1,
           int d2, int c2, const char *msg = "") {
	 cout << msg;
	 for (int i = d1; i <=  c1; ++i)
			 Print(a[i], d2, c2, "\n ");
}
	

void Read() {
	int i, j;
	memset(a, 0, sizeof(a));
	// Print(a, 0, 10, 0, 10, "\n Init: ");
	// Print(a[0], 1, 10, "\n row 1: " );
	// Print(a[10], 1, 10, "\n row 10: " );
	ifstream f(fn);
	f >> n >> m;
	cout << "\n n = " << n << "  m = " << m;
	for (i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j)
			f >> a[i][j];
	f.close();
	Print(a, 1, n, 1, m, "\n Input a: ");
}

void Run() {
	Read();
	int s = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			 if (a[i][j] > 0) ++s; // noc
			 if (a[i][j] > a[i-1][j]) s += a[i][j]-a[i-1][j]; // bac
			 if (a[i][j] > a[i+1][j]) s += a[i][j]-a[i+1][j]; // Nam
			 if (a[i][j] > a[i][j+1]) s += a[i][j]-a[i][j+1]; // Dg
			 if (a[i][j] > a[i][j-1]) s += a[i][j]-a[i][j-1]; // Tay
		}
	cout << "\n Total: " << s;
 }

main() {

	Run();
	cout << "\n T H E   E N D.";
	return 0;
}

