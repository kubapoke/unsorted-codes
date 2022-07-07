#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int z, n, a;
	register int naj=0, dnaj=0, tnaj=0, najm=0, dnajm=0;
	cin>>z;
	
	for(int i=0; i<z; i++)
	{
		naj=-1001, dnaj=-1001, tnaj=-1001, najm=1001, dnajm=1001;
		cin>>n;
		for(int i=0; i<n; i++)
		{
			cin>>a;
			
			if(a>=naj)
			{
				tnaj=dnaj;
				dnaj=naj;
				naj=a;
			}
			else if(a<naj && a>=dnaj)
			{
			tnaj=dnaj;
			dnaj=a;
			}
			else if(a>tnaj)
			tnaj=a;		
			else if(a<0 && a<=najm)
			{
				dnajm=najm;
				najm=a;
			}
			else if(a<0 && a<dnajm && a>najm)
			dnajm=a;
		}
		if(naj*dnaj*tnaj>naj*najm*dnajm || najm==1001 || dnajm==1001)
		cout<<naj*dnaj*tnaj<<"\n";
		else
		cout<<naj*najm*dnajm<<"\n";
	}
	
	return 0;
}
