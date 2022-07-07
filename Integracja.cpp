#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int i, m, d;
	
	cin>>i>>m>>d;
	
	if(i>m+d||m>i+d||d>i+m)
	{
		cout<<"NIE";
		return 0;
	}
	else
	{
		cout<<"TAK"<<"\n";
		
		while(i+m+d>0)
		{
			if((i>=m||i>=d)&&i>0)
			{
				cout<<"I";
				i--;
			}
			if((m>=i||m>=d)&&m>0)
			{
				cout<<"M";
				m--;
			}
			if((d>=i||d>=m)&&d>0)
			{
				cout<<"D";
				d--;
			}
		}
		
		
	}
	
}
