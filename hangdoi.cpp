#include<iostream>
#include<queue>

using namespace std;
int main(){
	queue <string> q;
	q.push("1");
	int t;cin>>t;
	while(t--){
		int n;
		cin>>n;
		while(n--){
			string k=q.front();q.pop();
		cout<<k<<" ";
		string c=k;
		q.push(k+"0");
		q.push(k+"1");
		}
		
	}
	
	system("pause");
}
