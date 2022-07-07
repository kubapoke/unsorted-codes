#include<bits/stdc++.h>
using namespace std;

string a, b, s;
vector<int> dod[26];
int odp[10000000], ans=1e9;

vector<int> getZarr(string str)
{
    int n = str.length();
    vector<int> Z(n);
    int L, R, k;
 
    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i > R)
        {
            L = R = i;
 
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            k = i-L;
            
            if (Z[k] < R-i+1)
                Z[i] = Z[k];
 
            else
            {
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
    
    return Z;
}

vector<int> pi1, pi2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>a>>b;
	
	ans=a.size();
	
	s=a;
	s.append("#");
	s.append(b);
	
	//cout<<s<<"\n";
	
	pi1=getZarr(s);
	
	//for(auto u: pi1)
	//cout<<u<<" ";
	//cout<<"\n";
	
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	
	s=a;
	s.append("#");
	s.append(b);
	
	pi2=getZarr(s);
	
	reverse(pi2.begin()+a.size()+1,pi2.end());
	
	//for(auto u: pi2)
	//cout<<u<<" ";
	//cout<<"\n";
	
	for(int i=a.size()+1; i<pi1.size(); i++)
	{
		if(i+a.size()-1>=pi2.size())
		break;
		ans=min(ans, (int)a.size()-pi1[i]-pi2[i+(int)a.size()-1]);
	}
	
	cout<<max(ans,0);

}
