#include <iostream>
using namespace std;
int a[4][4]={

                {0, 20, 35, 10},

                {20 ,0 ,90 ,50},

                {35 ,90, 0, 12},

                {10 ,50 ,12 ,0},

               

}// ma tran ke vo huong co trong so

,n;// so luong dinh

bool b[5]={false};// mang danh dau

int kq[10],bestConfig[10]={0};// mang tam, va mang luu cau hinh tot nhat

int mi=32000,cost=0;// gia tri thap nhat khi di qua cac dinh va gia tri tam

int start;// dinh bat dau

void Try(int i);

void Output()// ham xuat cac gia tri

{

               for(int i=0;i<n;i++){

                	cout<<bestConfig[i]+1<<"->";

                }
				cout<<bestConfig[0]+1<<endl;

                cout<<"Chi phi: "<<mi<<endl;

}

int main()

{

                n=4;

                //cout<<"Vi tri ban dau: ";

                start=1;//cin>>start;

                start--;

                kq[0]=start;b[start]=true;

                Try(1);// bat dau goi tu dinh dau tien di,khi bang n thi dung

                Output();

}

void Try(int i)

{

                //neu i == n thi kiem tra de xem phai la cau hinh tot hon thi luu lai

                if(i==n)

                {

                	 if(cost+a[kq[i-1]][kq[0]]<mi)

                     {

                         mi=cost+a[kq[i-1]][kq[0]];

                         for(int k=0; k < n;k++)

                         bestConfig[k]=kq[k];

                    }

                }

                else

                {

                                for(int j=0;j<n;j++)// duyet qua cac dinh co the di qua

                                {

                                                // neu chua di qua va gia tri con cho phep

                                                if(b[j]==false && cost+a[kq[i-1]][j] < mi)

                                                {

                                                                //ghi nho lai ket qua

                                                                kq[i]=j;

                                                                b[j]=true;

                                                                cost+=a[kq[i-1]][j];

                                                                //goi de qui den buoc tiep theo
																if(i==n){
																	if(cost+a[kq[i-1]][kq[0]]<mi)

														                     {
														
														                         mi=cost+a[kq[i-1]][kq[0]];
														
														                         for(int k=0; k < n;k++)
														
														                         bestConfig[k]=kq[k];
														
														                    }
														
																	
																}
                                                                Try(i+1);

                                                                //xoa bo ghi nho

                                                                b[j]=false;

                                                                cost-=a[kq[i-1]][j];

                                                }

                                }

                }

}
