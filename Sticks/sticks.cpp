#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std; 
int number,cnt;
int *a,n;
bool *vis;

bool cmp(const int a,const int b)
{
    return a > b;
}
bool dfs(int k, int cur, int cur_n)
{
	int i,prev=0;
	if (cur_n==number)
		return true;
	if (cur==cnt)
		return dfs(0,0,cur_n+1);
	for (i=k;i<n;i++)
	{
		if (!vis[i]&&cur+a[i]<=cnt&&prev!=a[i])
		{
			vis[i]=true;
			prev=a[i];
			if (dfs(i+1,cur+a[i],cur_n))
				break;
			vis[i]=false;
			if (k==0)
				return false;
		}
	}
	if (i!=n)
	return true;
	else
	return false;
}

int main()
{
	while (cin>>n&&n)
	{
		int res=1;
		a=new int[n];
		vis=new bool[n];
		int sum=0;
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
			vis[i]=false;
			sum+=a[i];	
		}
		sort(a,a+n,cmp);
		for (cnt=a[0];cnt<=sum/2;cnt++)
		{
			if (sum%cnt)
				continue;
			number=sum/cnt;
			if (dfs(0,0,0))
				break;
		}
		if (cnt<=sum/2)
		cout<<cnt<<endl;
		else
		cout<<sum<<endl;
	}
	
	return 0;
}
