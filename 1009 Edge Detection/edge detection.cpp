#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#define size 1000
using namespace std;

class Map
{
public:
	int code;
	int pos;
};
//int size=1000;
int InMap[size][2];
int k=0;
int total=0;
int width;
Map outMap[size*8];
int cmp(const void*a, const void*b)
{
	Map* x=(Map*)a;
	Map* y=(Map*)b;
	return x->pos-y->pos;
}

int GetValue(int pos)
{
	int p=0,i=0;
	while (p<pos)
	{
		p+=InMap[i++][1];
	}
	return InMap[i-1][0];
}
int GetCode(int pos)
{
	int row=(pos-1)/width;
	int col=(pos-1)%width;
	int maxAbs=0;
	int value=GetValue(pos);
	for (int i=row-1;i<=row+1;i++)
	{
		for (int j=col-1;j<=col+1;j++)
		{
			int tpos=i*width+j;
			if (i<0||j<0||j>=width||tpos>=total||tpos==pos-1)
			continue;
			int tcode=GetValue(tpos+1);
			if (abs(tcode-value)>maxAbs)
			maxAbs=abs(tcode-value);
		}
	}
	return maxAbs;
}

int main()
{
	while (cin>>width && width)
	{
		int y,t;
		int pairNum=0;
		total=0;
		while (cin>>y>>t&&t)
		{
			InMap[pairNum][0]=y;
			InMap[pairNum++][1]=t;
			total+=t;
		}
		cout<<width<<endl;
		k=0;
		int pos=1;
		for (int q=0;q<=pairNum;q++)
		{
			int row=(pos-1)/width;
			int col=(pos-1)%width;
			for (int i=row-1;i<=row+1;i++)
			{
				for (int j=col-1;j<=col+1;j++)
				{
					int tpos=i*width+j;
					if (i<0||j<0||j>=width||tpos>=total)
					continue;
					outMap[k].pos=tpos+1;
					outMap[k++].code=GetCode(tpos+1);
				}
			}
			pos+=InMap[q][1];
		}
		qsort(outMap,k,sizeof(Map),cmp);
		Map temp=outMap[0];
		for (int i=0;i<k;i++)
		{
			if (temp.code==outMap[i].code)
			continue;
			cout<<temp.code<<" "<<outMap[i].pos-temp.pos<<endl;
			temp=outMap[i];
		}
		cout<<temp.code<<" "<<total-temp.pos+1<<endl;
		cout<<"0 0"<<endl;
	}
	cout<<0<<endl;
	return 0;
}
