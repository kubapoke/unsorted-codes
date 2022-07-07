#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int s1=0, s2=0, g1=0, g2=0, p1=0, p2=0, n, a;
	bool tie=false;
	
	cin>>n;
	
	//set
	for(int i=0; i<n; i++)
	{
		cin>>a;
		
		if(a==1)
		p1++;
		else
		p2++;
		
		
		if(tie==false)
		{
			if(p1>=4&&p1>=p2+2)
			{
				g1++;
				p1=0;
				p2=0;
			}
			else if(p2>=4&&p2>=p1+2)
			{
				g2++;
				p1=0;
				p2=0;
			}
		}
		else if(tie==true)
		{
			if(p1>=7&&p1>=p2+2)
			{
				p1=0;
				p2=0;
				tie=false;
				s1++;
				g1=0;
				g2=0;
			}
			else if(p2>=7&&p2>=p1+2)
			{
				p1=0;
				p2=0;
				tie=false;
				s2++;
				g1=0;
				g2=0;
			}
		}
		
		if(g1==6&&g2==6)
		tie=true;
		else if(g1==6&&g2!=5)
		{
			s1++;
			g1=0;
			g2=0;
		}
		else if(g2==6&&g1!=5)
		{
			s2++;
			g1=0;
			g2=0;
		}	
	}
	
	if(s1==2)
	cout<<"PIERWSZY";
	else
	cout<<"DRUGI";
	
}
