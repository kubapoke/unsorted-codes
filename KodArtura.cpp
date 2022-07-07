#include <bits/stdc++.h>

using namespace std;

#define N_MAX 300000
#define BASE_MAX 31

int n, liczby[N_MAX], cnt, potegi2[BASE_MAX];
map<int, int, greater<int>> zlicz;
set<int> wartosci;
set<int> potegi2_2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(long i=0;i<BASE_MAX;i++)
    {
        potegi2[i]=(1<<i);
    }
    for(int i=0;i<n;i++)
    {
        cin>>liczby[i];
        if(wartosci.size()<=2)
        {
            wartosci.insert(liczby[i]);
        }
        zlicz[liczby[i]]++;
    }
    if(wartosci.size()==1)
    {
        for(long i=2;i<=2000000000;i*=2)
        {
            potegi2_2.insert(i);
        }
        int x=liczby[0];
        if(potegi2_2.find(x*2)!=potegi2_2.end())
        {
            cnt=n/2;
        }
    }
    else if(wartosci.size()==2)
    {
        for(long i=2;i<=2000000000;i*=2)
        {
            potegi2_2.insert(i);
        }
        int w1=0,w2=0;
        for(auto it=wartosci.begin();it!=wartosci.end();it++)
        {
            if(w1==0) w1=(*it);
            else if(w2==0) w2=(*it);
        }
        int suma=w1+w2;
        int ilew1=0,ilew2=0;
        for(int i=0;i<n;i++)
        {
            if(liczby[i]==w1) ilew1++;
            if(liczby[i]==w2) ilew2++;
        }
        if(potegi2_2.find(suma)!=potegi2_2.end())
        {
            cnt+=min(ilew1,ilew2);
            if(ilew1<ilew2) ilew1=0;
            else ilew2=0;
        }
        if(potegi2_2.find(w1*2)!=potegi2_2.end())
        {
            cnt+=ilew1/2;
        }
        if(potegi2_2.find(w2*2)!=potegi2_2.end())
        {
            cnt+=ilew2/2;
        }
    }
    else
    {
        for(auto it=zlicz.begin();it!=zlicz.end();it++)
        {
            // cout<<it->first<<" "<<it->second<<"\n";
            int potega=*lower_bound(potegi2, potegi2+BASE_MAX, it->first+1);
            // cout<<it->first<<" "<<potega<<"\n";
            int szukana = potega-it->first;
            if(szukana == it->first)
            {
                int ile=it->second/2;
                // cout<<it->first<<" "<<szukana<<" "<<ile<<"\n";
                cnt+=ile;
                it->second-=ile*2;
            }
            else if(zlicz.count(szukana))
            {
                int mini=min(it->second, zlicz[szukana]);
                // if(mini) cout<<it->first<<" "<<szukana<<" "<<mini<<"\n";
                zlicz[szukana]-=mini;
                it->second-=mini;
                cnt+=mini;
            }
        }
    }
    cout<<cnt;
    return 0;
}
