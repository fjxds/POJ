#include <iostream>
using namespace std;

void merge(int *a,int start, int mid, int end, int &count)
{
	int *tmp;
	tmp=new int[end-start+1];
	int cur=0;
	int left=start,right=mid+1;
	while (left<=mid&&right<=end)
	{
		if (a[left]<=a[right])
		{
			tmp[cur++]=a[right++];
		}
		else
		{
			count+=end-right+1;
			tmp[cur++]=a[left++];
		}
	}
	if (left<=mid)
	{
		for (int i=left;i<=mid;i++)
		{
			tmp[cur++]=a[i];
		}
	}
	if (right<=end)
	{
		for (int i=right;i<=end;i++)
		{
			tmp[cur++]=a[i];
		}
	}
	for (int i=start;i<=end;i++)
	{
		a[i]=tmp[i-start];
	}
}

void mergecount(int *a,int start, int end, int &count)
{
	int mid=(start+end)/2;
	if (start<end)
	{
		mergecount(a,start,mid,count);
		mergecount(a,mid+1,end,count);
		merge(a,start,mid,end,count);
	}
}


int main(int argc, char** argv) {
	int n,m,count;
	cin>>n>>m;
	char **a;
	int *b,*counts;
	a=new char*[m];
	counts=new int[m];
	for (int i=0;i<m;i++)
	{
		a[i]=new char[n];
		b=new int[n];
		cin>>a[i];
		for (int j=0;j<n;j++)
		{
			if (a[i][j]=='A')
			b[j]=0;
			if (a[i][j]=='C')
			b[j]=1;
			if (a[i][j]=='G')
			b[j]=2;
			if (a[i][j]=='T')
			b[j]=3;
		}
		int count=0;
		mergecount(b,0,n-1,count);
		counts[i]=count;
	}
	//delete b;
	int index=0;
	int cur=-1;
	for (int j=0;j<m;j++)
	{
		index=0;
		cur=-1;
		for (int i=0;i<m;i++)
		{
			if (cur==-1)
			{
				if (counts[i]!=-1)
				{
					cur=counts[i];
					index=i;
				}
			}
			if (counts[i]!=-1&&cur>counts[i])
			{
				cur=counts[i];
				index=i;
			}
		}
		counts[index]=-1;
		cout<<a[index]<<endl;
	}	
	return 0;
}
