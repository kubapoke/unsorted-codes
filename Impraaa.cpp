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
			if(s!=1&&i>0&&(i>m&&i>d))
			{
				cout<<"I";
				i--;
				s=1;
			}
			else if(s!=2&&m>0&&(m>i&&m>d))
			{
				cout<<"M";
				m--;
				s=2;
			}
			else if(s!=3&&d>0&&(d>i&&d>m))
			{
				cout<<"D";
				d--;
				s=3;
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
			else if(i==m)
			{
				if(s==1||s==3)
				{
					cout<<"M";
					m--;
					s=2;
				}
				else if(s==2)
				{
					cout<<"I";
					i--;
					s=1;
				}
			}
			else if(i==d)
			{
				if(s==1||s==2)
				{
					cout<<"D";
					m--;
					s=3;
				}
				else if(s==3)
				{
					cout<<"I";
					i--;
					s=1;
				}
			}
			else if(m==d)
			{
				if(s==2||s==1)
				{
					cout<<"D";
					m--;
					s=3;
				}
				else if(s==3)
				{
					cout<<"M";
					i--;
					s=2;
				}
			}
			else break;
		}
		
		
	}
	
}
