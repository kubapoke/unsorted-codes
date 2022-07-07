#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int i, m, d, s;
	
	cin>>i>>m>>d;
	
	if(i>m+d||m>i+d||d>i+m)
	{
		cout<<"NIE";
		return 0;
	}
	else
	{
		cout<<"TAK"<<"\n";
		
		while(1)
		{
			if(s!=1&&i>0&&(i>=m&&i>=d))
			{
				cout<<"I";
				i--;
				s=1;
			}
			else if(s!=2&&m>0&&(m>=i&&m>=d))
			{
				cout<<"M";
				m--;
				s=2;
			}
			else if(s!=3&&d>0&&(d>=i&&d>=m))
			{
				cout<<"D";
				d--;
				s=3;
			}
			//
			else if(i>=m&&i>=d&&m>=d&&m>0)
			{
				cout<<"M";
				m--;
				s=2;
			}
			else if(i>=m&&i>=d&&d>=m&&d>0)
			{
				cout<<"D";
				d--;
				s=3;
			}
			else if(m>=i&&m>=d&&i>=d&&i>0)
			{
				cout<<"I";
				i--;
				s=1;
			}
			else if(m>=i&&m>=d&&d>=i&&d>0)
			{
				cout<<"D";
				d--;
				s=3;
			}
			else if(d>=i&&d>=m&&i>=m&&i>0)
			{
				cout<<"I";
				i--;
				s=1;
			}
			else if(d>=i&&d>=m&&m>=i&&m>0)
			{
				cout<<"M";
				m--;
				s=2;
			}
			else if(i==d==m&&i>0)
			{
				if(s==1)
				{
					cout<<"M";
					m--;
					s=2;
				}
				else if(s==2)
				{
					cout<<"D";
					d--;
					s=3;
				}
				else if(s==3)
				{
					cout<<"I";
					i--;
					s=1;
				}
			}
			else break;
		}
		
		
	}
	
}
