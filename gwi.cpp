#include<bits/stdc++.h>
using namespace std;

struct st{
	int l, r, d;
}t[500000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, s, w=0, ilep=0, l=0, r=0;
	bool czyl=false, czycont=true;
	queue<int> kol;
	
	cin>>n>>s;
	
	for(int i=0; i<n-1; i++)
	{
		cin>>t[i].l>>t[i].r;
		t[i].d=abs(t[i].l-t[i].r);
		
		if(t[i].l<t[i].r&&i==0)
		czyl=true;
		
		if(t[i].l<=t[i].r)
		l++;
		else
		r++;
		
		if(czycont==true)
		{
			if(czyl==true)
			{
				if(t[i].l<t[i].r)
				ilep++;
				else
				czycont=false;
			}
			else
			{
				if(t[i].l>t[i].r)
				ilep++;
				else
				czycont=false;
			}	
		}
	}
	
	kol.push(s);
	
	int optpos=l+1, x=0;
	cout<<l<<" "<<optpos<<'\n';
	
	if(s==optpos)
	{
		int lc=optpos-1, rc=optpos+1;
		for(int i=0; i<n-1; i++)
		{
			if(t[i].l<=t[i].r)
			{
				w+=t[i].l;
				kol.push(lc);
				lc--;
			}
			else
			{
				w+=t[i].r;
				kol.push(rc);
				rc++;
			}
		}
		cout<<w<<'\n';
		while(!kol.empty())
		{
			cout<<kol.front()<<" ";
			kol.pop();
		}
	}
	else
	{
		if(s<optpos)
		{
			if(czyl==false||s>ilep)
			{
				for(int i=0; i<n-1; i++)
				{
					if(t[i].l>=t[i].r)
					break;
					w+=t[i].l;
					x++;
					kol.push(s-x);
				}
				w+=t[x].r;
				optpos++;
				kol.push(optpos);
				int lc=optpos-1, rc=optpos+1;
				while(lc<=s&&lc>=s-x)
				lc--;
				for(int i=1+x; i<n-1; i++)
				{
					if(t[i].l<=t[i].r)
					{
						w+=t[i].l;
						kol.push(lc);
						lc--;
						while(lc<=s&&lc>=s-x)
						lc--;
					}
					else
					{
						w+=t[i].r;
						kol.push(rc);
						rc++;
					}
				}
				cout<<w<<'\n';
				while(!kol.empty())
				{
					cout<<kol.front()<<" ";
					kol.pop();
				}
			}
			else
			{
				int minim=1000001;
				for(int i=0; i<ilep; i++)
				{
					minim=min(minim,t[i].r);
				}
				if(ilep==0)
				minim=t[0].r;
				
				for(int i=0; i<n-1; i++)
				{
					if(minim==t[i].r)
					break;
					w+=t[i].l;
					x++;
					kol.push(s-x);
				}
				w+=t[x].r;
				kol.push(optpos);
				int lc=optpos-1, rc=optpos+1;
				while(lc<=s&&lc>=s-x)
				lc--;
				for(int i=1+x; i<n-1; i++)
				{
					if(t[i].l<=t[i].r)
					{
						w+=t[i].l;
						kol.push(lc);
						lc--;
						while(lc<=s&&lc>=s-x)
						lc--;
					}
					else
					{
						w+=t[i].r;
						kol.push(rc);
						rc++;
					}
				}
				cout<<w<<'\n';
				while(!kol.empty())
				{
					cout<<kol.front()<<" ";
					kol.pop();
				}
			}
		}
		else
		{
			if(czyl==true||s<n+1-ilep)
			{
				for(int i=0; i<n-1; i++)
				{
					if(t[i].l<=t[i].r)
					break;
					w+=t[i].r;
					x++;
					kol.push(s+x);
				}
				w+=t[x].l;
				optpos--;
				kol.push(optpos);
				int lc=optpos-1, rc=optpos+1;
				while(rc>=s&&rc<=s+x)
				rc++;
				for(int i=1+x; i<n-1; i++)
				{
					if(t[i].l<=t[i].r)
					{
						w+=t[i].l;
						kol.push(lc);
						lc--;
					}
					else
					{
						w+=t[i].r;
						kol.push(rc);
						rc++;
						while(rc>=s&&rc<=s+x)
						rc++;
					}
				}
				cout<<w<<'\n';
				while(!kol.empty())
				{
					cout<<kol.front()<<" ";
					kol.pop();
				}
			}
			else
			{
				int minim=1000001;
				for(int i=0; i<ilep; i++)
				{
					minim=min(minim,t[i].l);
				}
				if(ilep==0)
				minim=t[0].l;
				
				for(int i=0; i<n-1; i++)
				{
					if(minim==t[i].l)
					break;
					w+=t[i].r;
					x++;
					kol.push(s+x);
				}
				w+=t[x].l;
				kol.push(optpos);
				int lc=optpos-1, rc=optpos+1;
				while(rc>=s&&rc<=s+x)
				rc++;
				for(int i=1+x; i<n-1; i++)
				{
					if(t[i].l<=t[i].r)
					{
						w+=t[i].l;
						kol.push(lc);
						lc--;
					}
					else
					{
						w+=t[i].r;
						kol.push(rc);
						rc++;
						while(rc>=s&&rc<=s+x)
						rc++;
					}
				}
				cout<<w<<'\n';
				while(!kol.empty())
				{
					cout<<kol.front()<<" ";
					kol.pop();
				}
			}
		}
	}	
}


