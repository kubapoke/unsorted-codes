#include<iostream>
using namespace std;

int main()
{
	int k, a;
	
	cin>>k;
	
	for(int i=0; i<k; i++)
	{
		cin>>a;
		if(a>9)
		cout<<"00"<<endl;
		else if(a==0 || a==1)
		cout<<"01"<<endl;
		else if(a==2)
		cout<<"02"<<endl;
		else if(a==3)
		cout<<"06"<<endl;
		else if(a==4)
		cout<<"24"<<endl;
		else if(a==5 || a==6 || a==8)
		cout<<"20"<<endl;
		else if(a==7)
		cout<<"40"<<endl;
		else if(a==9)
		cout<<"80"<<endl;
	}
	
	return 0;
}
