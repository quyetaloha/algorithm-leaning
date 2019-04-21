 /*
	Name: FIB.CPP
	Copyright: VII/2017
	Author: Le Van Bom
	Date: 20-07-17 08:42
	Description:
	Cac day Fibonacci
 */

 #include "Mydef.h"

 /*----------------------------------------------
		int f1 = a, f2 = b;
		sinh fn
		viet lien f1..fn
		? chu so thu k =  ?
		1. 8
		2. 4
		3. 12
		4. 16
		5. 28
		6. 44
		7. 72
		8. 116
		9. 188
		10. 304
		------------
		841216284472116188304
		? 7 : 2
		

 
 
 ------------------------------------------------*/

 // 1234
 string ToStr(int a) {
		 string s = "";
			// 1234 -> 4 3 2 1
			do {
				 s = char((a % 10) + '0') + s;
				 a /= 10;
			}  while (a != 0);
		return s;
 }
 
 char Fib1(int a, int b, int n, int k) {
		int c, i;
		if (n == 1) return ToStr(a)[k];
		if (n == 2) return ToStr(b)[k];
		string s = "";
		s += ToStr(a);
		s += ToStr(b);
		for (i = 3; i <= n; ++i) {
		   c = a+b; a = b; b = c;
		   s += ToStr(c);;
		}
		return s[k-1];
 }

 // Cai dat Big numbers +

 main(){
		// for (int a = 0; a <= 13; ++a)
			 // cout << "\n "   << a << " -> " << ToStr(a);
	// T1();
	char *s = "841216284472116188304";
	int n = strlen(s);
	cout << "\n " << s << "\n ";
	for (int i = 1; i <= n; ++i)
	   cout << Fib1(8, 4, 10, i);

	
	cout << "\n T  H  E    E  N  D  .";
	return 0;
}

