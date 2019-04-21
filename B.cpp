#include <iostream> 
using namespace std;
int a[20],n,k,count,i=0;
string t[1005];
void init ()
{
    cin >> n >> k;
} 
void output()
{
	int dem = 0;
    for(int i=0;i<=n-k;i++){
    	if(a[i]==0){
    		int kt = 0;
    		for(int j = i+1;j<i+k;j++){
    			if(a[i]!=a[j]){
    				kt = 1;
				}
			}
			if(kt==0) {
				dem++;
			}
		}
    	
	}
	if(dem==1){
		count++;
		string temp ="";
		for(int i = 0;i<n;i++){
			if(a[i]==1) temp+="B";
			else temp +="A";
		}
		t[i++] = temp;
	}
	
}
 
void tim(int i)
{
    for(int j=0;j<=1;j++)
    {
        a[i]=j;
        if(i==n-1)  
            output();
        else
            tim(i+1);
    }
}
 
int main()
{	
	init();
    tim(0);
	cout << count << endl;
	for(int j = 0;j<i;j++){
		cout << t[j] << endl;
	} 
}
