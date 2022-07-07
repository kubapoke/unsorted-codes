#include<iostream>
using namespace std;

const M=1048576;
int tab[2097152];
//int tabp[2097152];
//int tabk[2097152];

void zerofill()
{
	for(int i=0; i<2097152; i++)
	tab[i]=0;
}

int fmax(int a, int b)
{
	
}
/*
void pairfill(int a, int b)
{
	if(a<1048576)
	{
		tabp[a*2]=tabp[a];
		tabk[a*2]=tabk[a]-b;
		
		tabp[a*2+1]=tabp[a]+b;
		tabk[a*2+1]=tabk[a];
	}
	
	pairfill(a*2, b/2);
	pairfill(a*2+1, b/2);
}
*/
int main()
{
	//tabp[1]=1;
	//tabk[1]=1048576;
	
	zerofill();
	
	int d, n, a, b, max;
	
	cin>>d>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>a>>b;
		
		max=fmax(a+M, a+b+M);
	}
	
	cout<<"bruh";
}
