#include<iostream>
using namespace std;

int main()
{
	long long n, w=0, d=0;
	
	cin>>n;
	
	while(n>0)
	{
		for(int i=1; i*i<=n; i++)
		{
			if(n/i>d&&n%i==0&&n/1!=n)
			d=n/i;
			if(i>d&&n%i==0&&i!=n)
			d=i;
		}
		
		if(d>1)
		n=n/d;
		else
		n--;
			
		w++;
		d=0;
		
		cout<<n<<endl;
	}
	
	cout<<w;
	
	return 0;
}
