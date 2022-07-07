#include<bits/stdc++.h>
using namespace std;

bool lenCompare(const string &a, const string &b)
{
	if(a.size()==b.size())
	return(a<b);
	return(a.size()<b.size());
}

int a, b, t, r, c, checked[1002][1002];
char pocz, kon, tab[1002][1002];
bool czy[26], startdir, LorD[1002][1002];
string s, temps;
long long p1=31, p2=43, mod1=1e9+7, mod2=1e9+207, pN1[1002], pN2[1002];
pair<long long,long long> hH[1002][1002], hV[1002][1002], cHash;
map<char,int> znaki, testznaki;
set<string, decltype(lenCompare)*> toppos(lenCompare), botpos(lenCompare);
set<string>pos;
set<string>::iterator it, iv;

void init()
{
	pN1[0]=1; pN2[0]=1;
	
	for(int i=1; i<=1001; i++)
	{
		pN1[i]=(pN1[i-1]*p1)%mod1;
		pN2[i]=(pN2[i-1]*p2)%mod2;
	}
	
	for(int i=1; i<=1001; i++)
	{
		for(int j=1001; j>=1; j--)
		{
			hV[i][j].first=(tab[i][j]*p1+hV[i][j+1].first*p1)%mod1;
			hV[i][j].second=(tab[i][j]*p2+hV[i][j+1].second*p2)%mod2;
		}
	}
	
	for(int j=1; j<=1001; j++)
	{
		for(int i=1001; i>=1; i--)
		{
			hH[i][j].first=(tab[i][j]*p1+hH[i+1][j].first*p1)%mod1;
			hH[i][j].second=(tab[i][j]*p2+hH[i+1][j].second*p2)%mod2;
		}
	}
}

pair<long long, long long> gethashV(int x, int y, int len)
{
	long long ans1, ans2;
	ans1=(hV[x][y].first-hV[x][y+len].first*pN1[len])%mod1;
	if(ans1<0)
	ans1+=mod1;
	ans2=(hV[x][y].second-hV[x][y+len].second*pN2[len])%mod2;
	if(ans2<0)
	ans2+=mod2;
	
	return(make_pair(ans1,ans2));
}

pair<long long, long long> gethashH(int x, int y, int len)
{
	long long ans1, ans2;
	ans1=(hH[x][y].first-hH[x+len][y].first*pN1[len])%mod1;
	if(ans1<0)
	ans1+=mod1;
	ans2=(hH[x][y].second-hH[x+len][y].second*pN2[len])%mod2;
	if(ans2<0)
	ans2+=mod2;
	
	return(make_pair(ans1,ans2));	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>a>>b;
	c=a*b;
	
	for(int i=1; i<=a; i++)
	{
		cin>>s;
		for(int j=1; j<=b; j++)
		{
			tab[i][j]=s[j-1];
			znaki[s[j-1]]++;
		}
	}
	
	pocz=tab[1][1];
	kon=tab[a][b];
	r=znaki.size();
	t=0;
	
	init();
	
	for(int j=1; j<=b; j++)
	{
		temps.push_back(tab[1][j]);
		testznaki[tab[1][j]]++;
		if(czy[tab[1][j]-'a']==false && znaki[tab[1][j]]%testznaki[tab[1][j]]==0)
		{
			t++;
			czy[tab[1][j]-'a']=true;
		}
		else if(czy[tab[1][j]-'a']==true && znaki[tab[1][j]]%testznaki[tab[1][j]]!=0)
		{
			t--;
			czy[tab[1][j]-'a']=false;
		}
		
		if(tab[1][j]==kon && t==r && c%j==0)
		toppos.insert(temps);
	}
	
	t=0; temps.clear(); testznaki.clear();
	for(int i=0; i<26; i++)
	czy[i]=false;
	
	for(int i=1; i<=a; i++)
	{
		temps.push_back(tab[i][1]);
		testznaki[tab[i][1]]++;
		if(czy[tab[i][1]-'a']==false && znaki[tab[i][1]]%testznaki[tab[i][1]]==0)
		{
			t++;
			czy[tab[i][1]-'a']=true;
		}
		else if(czy[tab[i][1]-'a']==true && znaki[tab[i][1]]%testznaki[tab[i][1]]!=0)
		{
			t--;
			czy[tab[i][1]-'a']=false;
		}
		
		if(tab[i][1]==kon && t==r && c%i==0)
		toppos.insert(temps);
	}
	
	//for(it=toppos.begin(); it!=toppos.end(); it++)
	//cout<<*it<<" ";
	//cout<<"\n\n";
	
	t=0; temps.clear(); testznaki.clear();
	for(int i=0; i<26; i++)
	czy[i]=false;
	
	for(int j=b; j>=1; j--)
	{
		temps.insert(0,1,tab[a][j]);
		testznaki[tab[a][j]]++;
		if(czy[tab[a][j]-'a']==false && znaki[tab[a][j]]%testznaki[tab[a][j]]==0)
		{
			t++;
			czy[tab[a][j]-'a']=true;
		}
		else if(czy[tab[a][j]-'a']==true && znaki[tab[a][j]]%testznaki[tab[a][j]]!=0)
		{
			t--;
			czy[tab[a][j]-'a']=false;
		}
		
		if(tab[a][j]==pocz && t==r && c%(b-j+1)==0)
		botpos.insert(temps);
	}
	
	t=0; temps.clear(); testznaki.clear();
	for(int i=0; i<26; i++)
	czy[i]=false;
	
	for(int i=a; i>=1; i--)
	{
		temps.insert(0,1,tab[i][b]);
		testznaki[tab[i][b]]++;
		if(czy[tab[i][b]-'a']==false && znaki[tab[i][b]]%testznaki[tab[i][b]]==0)
		{
			t++;
			czy[tab[i][b]-'a']=true;
		}
		else if(czy[tab[i][b]-'a']==true && znaki[tab[i][b]]%testznaki[tab[i][b]]!=0)
		{
			t--;
			czy[tab[i][b]-'a']=false;
		}
		
		if(tab[i][b]==pocz && t==r && c%(a-i+1)==0)
		botpos.insert(temps);
	}
	
	//for(it=botpos.begin(); it!=botpos.end(); it++)
	//cout<<*it<<" ";
	
	it=toppos.begin(); iv=botpos.begin();
	
	while(it!=toppos.end() && iv!=botpos.end())
	{
		if(*it==*iv)
		{
			pos.insert(*it);
			it++; iv++;
		}
		else if(it->size()<iv->size())
		it++;
		else if(it->size()>iv->size())
		iv++;
		else if(*it<*iv)
		it++;
		else if(*it>*iv)
		iv++;	
	}
	
	//for(it=pos.begin(); it!=pos.end(); it++)
	//cout<<*it<<" ";
	
	//cout<<gethashH(1,2,3).first<<" "<<gethashH(1,1,3).second<<"\n"<<gethashV(2,1,3).first<<" "<<gethashV(1,1,3).second;
	
	if(pos.size()==0)
	{
		cout<<"0";
		return 0;
	}
	
	s=*pos.begin();
	
	if(s.size()>b)
	startdir=true;
	else
	for(int j=1; j<=b, j<=s.size(); j++)
	{
		if(tab[1][j]!=s[j-1])
		startdir=true;
	}
	
	//cout<<startdir;
	
	if(startdir==false)
	cHash=gethashV(1,1,s.size());
	else
	cHash=gethashH(1,1,s.size());
	
	//cout<<cHash.first<<" "<<cHash.second<<"\n";
	if(cHash==gethashV(1,1,s.size()))
	{
		for(int i=1; i<=a; i++)
		for(int j=1; j<=b; j++)
		{
			if(checked[i][j]==0)
			{
				//cout<<i<<" "<<j<<":  "<<gethashH(i,j,s.size()).first<<" "<<gethashH(i,j,s.size()).second<<"   "<<gethashV(i,j,s.size()).first<<" "<<gethashV(i,j,s.size()).second<<"\n";
				
				if(gethashV(i,j,s.size())==cHash&&checked[i][j+1]==0)
				{
					for(int z=j; z<j+s.size(); z++)
					{
						checked[i][z]++;
					}
				}
				else if(gethashH(i,j,s.size())==cHash&&checked[i+1][j]==0)
				{
					for(int z=i; z<i+s.size(); z++)
					{
						LorD[z][j]=true;
						checked[z][j]++;
					}
				}
				else
				{
					cout<<"0";
					return 0;
				}
			}
		}
	}
	else
	{
		for(int i=1; i<=a; i++)
		for(int j=1; j<=b; j++)
		{
			if(checked[i][j]==0)
			{
				//cout<<i<<" "<<j<<":  "<<gethashH(i,j,s.size()).first<<" "<<gethashH(i,j,s.size()).second<<"   "<<gethashV(i,j,s.size()).first<<" "<<gethashV(i,j,s.size()).second<<"\n";
				
				if(gethashH(i,j,s.size())==cHash&&checked[i+1][j]==0)
				{
					for(int z=i; z<i+s.size(); z++)
					{
						LorD[z][j]=true;
						checked[z][j]++;
					}
				}
				else if(gethashV(i,j,s.size())==cHash&&checked[i][j+1]==0)
				{
					for(int z=j; z<j+s.size(); z++)
					{
						checked[i][z]++;
					}
				}
				else
				{
					cout<<"0";
					return 0;
				}
			}
		}
	}
	
	for(int i=1; i<=a; i++)
	{
		for(int j=1; j<=b; j++)
		cout<<LorD[i][j];
		cout<<"\n";
	}
	
}
