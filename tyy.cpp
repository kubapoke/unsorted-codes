#include<bits/stdc++.h>
using namespace std;
int n, xa ,ya, xb, yb, xc, yc, xd, yd;

int main()
{
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd;
		
		int S1=(xc-xa)*(yb-ya)-(yc-ya)*(xb-xa);
		int S2=(xd-xa)*(yb-ya)-(yd-ya)*(xb-xa);
		int S3=(xa-xc)*(yd-yc)-(ya-yc)*(xd-xc);
		int S4=(xb-xc)*(yd-yc)-(yb-yc)*(xd-xc);
		
	//	cout<<S1<<" "<<S2<<" "<<S3<<" "<<S4<<"\n";
		
		if(((S1>0&&S2<0)||(S1<0&&S2>0))&&((S3>0&&S4<0)||(S3<0&&S4>0))) cout<<"TAK\n";
		else if(S1==0&&xc>=min(xa,xb)&&xc<=max(xa,xb)&&yc>=min(ya,yb)&&yc<=max(ya,yb)) cout<<"TAK\n";
		else if(S2==0&&xd>=min(xa,xb)&&xd<=max(xa,xb)&&yd>=min(ya,yb)&&yd<=max(ya,yb)) cout<<"TAK\n";
		else if(S3==0&&xa>=min(xc,xd)&&xa<=max(xc,xd)&&ya>=min(yc,yd)&&ya<=max(yc,yd)) cout<<"TAK\n";
		else if(S4==0&&xb>=min(xc,xd)&&xb<=max(xc,xd)&&yb>=min(yc,yd)&&yb<=max(yc,yd)) cout<<"TAK\n";
		else cout<<"NIE\n";
	}
}
