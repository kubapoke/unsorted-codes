#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int a, b, n, count=0, d, m, dw=1, mw=1;
	
	register char c;
	
	cin>>a>>b;
	
	int ams[a+1], bms[b+1];
	
	ams[0]=0;
	bms[0]=0;
	
	//miesi¹ce arbuzan
	for(int i=1; i<=a; i++)
	{
		cin>>ams[i];
		ams[i]+=ams[i-1];
	}
	
	//miesi¹ce bananitów
	for(int i=1; i<=b; i++)
	{
		cin>>bms[i];
		bms[i]+=bms[i-1];
	}
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>d>>m>>c;
		dw=1; mw=1;
		
		switch(c)
		{
			case 'A':
			count=ams[m-1]+d;	
			
			for(int j=1; bms[j]<count; j++)
			mw++;
				
			dw=count-bms[mw-1];
			break;
			
			case 'B':
			count=bms[m-1]+d;	
			
			for(int j=1; ams[j]<count; j++)
			mw++;
			
			dw=count-ams[mw-1];
			break;	
		}
		
		cout<<dw<<" "<<mw<<"\n";
	}
	
	
	return 0;
}
