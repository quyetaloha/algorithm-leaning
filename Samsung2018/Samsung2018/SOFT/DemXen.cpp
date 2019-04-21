	/*************************************

	Name: DEMXE.CPP
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
	
	const int TAI = 1;
	const int CON = 2;
	const int BUYT = 3;
	const int MAY = 4;
	const int OTHER = 0;
	const int MN = 5;
	int xe[MN];


	void Count() {
		 char ch;
		 memset(xe, 0, sizeof(xe));
		 while(true) {
			 cout << "\n Xe Tai  [t]: " << xe[TAI];
			 cout << "\n Xe Con  [c]: " << xe[CON];
			 cout << "\n Xe Buyt [b]: " << xe[BUYT];
			 cout << "\n Xe May  [m]: " << xe[MAY];
			 cout << "\n Thoat:  [.]: ";
			 cout << "\n ---------------------- ";
		   cout << "\n Get: ";

			 fflush(stdin); ch = tolower(cin.get());
			 switch(ch) {
					case '.': return;
					case 't': ++xe[TAI]; break;
					case 'c': ++xe[CON]; break;
					case 'b': ++xe[BUYT]; break;
					case 'm': ++xe[MAY]; break;
					default: ++xe[OTHER]; break;
			 }
		 }
	}

	main() { // Phong khach
		 Count();
		 cout << "\n Xe khac: " << xe[OTHER];

		//---------------------------------------------
		 cout << endl << " T H E   E N D . ";
		 
	  return 0;       
	}

	
