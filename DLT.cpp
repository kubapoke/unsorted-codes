#include<bits/stdc++.h>
using namespace std;
string a,b;
bool st=false;
int hold;
char w[70];

int main()
{
	for(int i=0; i<50; i++)
	{
		cin>>a>>b;
		for(int j=0; j<70; j++)
		{
			hold=0;
			if(j<a.size())
			w[j]+=a[a.size()-1-j]-48;
			if(j<b.size())
			w[j]+=b[b.size()-1-j]-48;
			if(w[j]>2)
			{
				hold=1;
				w[j]-=3;
			}
			w[j]+=48;
			if(hold==1)
			w[j+1]++;
		}
		st=false;
		for(int j=69; j>=0; j--)
		{
			if(w[j]!='0')
			st=true;
			if(st==true)
			cout<<w[j];
		}
		cout<<"\n";
		for(int j=0; j<70; j++)
		w[j]=0;
	}
}
