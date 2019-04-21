#include <iostream> 
using namespace std;
int a[20],n,k;
void init ()
{
    cin >> n >> k; //nhap n;
} 
void output()
{
	int dem = 0;
    for(int i=0;i<n;i++)
    if(a[i]==1) dem++;
    if(dem==k){
    	for(int i=0;i<n;i++)
    	cout << a[i];
    	cout << endl;
	}
	
}
 
void tim(int i)
{
    for(int j=0;j<=1;j++)
    {
        a[i]=j;
        if(i==n-1)   //n?u tìm d?n x i cu?i cùng thì xu?t ra ket qu?
            output();
        else
            tim(i+1); // chua tìm d?n i cu?i thì tang i lên
    }
}
 
int main()
{
	int test;
	cin >> test;
	while(test--){
	init();
    tim(0);
	}
    
}
