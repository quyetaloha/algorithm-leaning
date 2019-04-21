	/*************************************

	Name: BIN.CPP
	Copyright: 2018
	Author: Le Van Bom
	Date: 03-07-18 09:00
	Description:
		 Sort
		 Birtday with minimum Y/N questions

  *************************************/
  // Dat moi truong
  #include <iostream>
  #include <windows.h>
  #include <time.h>
  
  /*-----------------------------------
		 IBM: Ki nghe Clean Room
		 Phong rong: Sach

		 Mang 1 do vao phong: Ve sinh

		 Agile Method : Linh loi
		 
		 1 lenh / tim het loi
  
  ------------------------------------*/
  
	using namespace std;
	
	const int MN = 100000;
	
	int a[MN] = {12, 9, 7, 6, 6,
	             5, 1, 4, 20, 11,
							 56, 47, 12, 0, -1};
	
	void Print(int a[], int d, int c, const char * msg = "") {
			cout << msg;
			for (int i = d; i <= c; ++i)
			   cout << " " << a[i];
	}
	
	void Swap(int a[], int i, int j){
		 int x;
		 x = a[i]; a[i] = a[j]; a[j] = x;
	}
	
	void SwapSort(int a[], int d, int c) {
			int t, p;
			for (t = d; t <= c; ++t)
				 for (p = t+1; p <= c; ++p)
						if (a[p] < a[t]) Swap(a, t,p);
	}
	
	void BubbleSort(int a[], int d, int c) {
	 int t, p;
		 for (t  = d; t <= c; ++t)
				for (p = c; p > t; --p)
					if (a[p] < a[p-1]) Swap(a,p, p-1);
	}
	
	void Gen(int a[], int n) {
		 srand(time(NULL)); // Khoi tao bo sinh so nn
		 for (int i = 0; i < n; ++i)
			 a[i] = rand() % 100;
	}
	
	int DoanSo(int d, int c, const char * Question) {
			int g;
			char tl;
			while (d < c) {
				 g = (d+c) / 2;
				 cout << Question << g << " [Y/N] ?: ";

				 do {
						 fflush(stdin);
				     tl = toupper(cin.get()); // Y N
				   } while (tl != 'Y' && tl != 'N');
				 if (tl == 'Y') d = g+1;
				 else c = g;
			}
			// d = c = x
			// cout << "\n Ban da nghi so: " << d;
			return d;
	}
	
	
	
	void Test() {
		 int d = 0;
		 int c = MN-1;
		 Gen(a, c);

		 Print(a,d,c, "\n Init a: ");
		  // SwapSort(a, d, c);
		 BubbleSort(a, d, c);
		 Print(a,d,c, "\n After Sorted: ");
	}

	void BirthDay() {
		 int month = DoanSo(1, 12, "\n Ban sinh sau thang ");
		 int day = DoanSo(1, 31, "\n Ban sinh sau ngay ");
		 cout << "\n Your Bith day is " << day << " / " << month;

	}

	main() { // Phong khach
		 BirthDay();

		//---------------------------------------------
		 cout << endl << " T H E   E N D . ";
		 
	  return 0;       
	}

	
