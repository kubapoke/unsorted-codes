#include<iostream>
using namespace std;

int main()
{
	long long n, w=0, d=0;
	
	cin>>n;
	
	while(n>0)
	{
		for(int i=2; i*i<=n; i++)
		{
			if(n%i==0)
			{
				d=i;
				i=n;
			}
		}
		
		if(d>1)
		n=d;
		else
		n--;
			
		w++;
		d=0;
		
		cout<<n<<endl;
	}
	
	if(w>4)
	cout<<"4";
	else
	cout<<w;
	
	return 0;
}
