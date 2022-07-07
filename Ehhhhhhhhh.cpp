#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int a, b, n, count=0, d, m, dw=1, mw=1, pocz, kon, sr;
	
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
		
		if(c=='A')
		{
			pocz=1; kon=b; sr=(pocz+kon)/2;
			
			count=ams[m-1]+d;
			
			while(bms[sr]<count || bms[sr-1]>=count)
			{
				if(bms[sr]<count)
				{
					pocz=sr+1;
					sr=(pocz+kon)/2;
				}
				else
				{
					kon=sr-1;
					sr=(pocz+kon)/2;
				}
			}
			mw=sr;
			
			dw=count-bms[mw-1];
		}	
		else
		{
			pocz=1; kon=a; sr=(pocz+kon)/2;
			
			count=bms[m-1]+d;
			
			while(ams[sr]<count || ams[sr-1]>=count)
			{
				if(ams[sr]<count)
				{
					pocz=sr+1;
					sr=(pocz+kon)/2;
				}
				else
				{
					kon=sr-1;
					sr=(pocz+kon)/2;
				}
			}
			mw=sr;
			
			dw=count-ams[mw-1];
		}
		
		cout<<dw<<" "<<mw<<"\n";
	}
	
	
	return 0;
}


