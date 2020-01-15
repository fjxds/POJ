#include <iostream>
#include <algorithm>
using namespace std;

int type[25];
int cus[25];
int sol[4];
int k,t,num,total;
int taken[25];

int DFS(int *a, int pos, int cur, int number,int &flag)
{
	if (cur<0||pos>=t||number>4)
	return -1;
	if (cur==0&&number<=4)
	{
//		a[number++]=type[pos];
//		taken[pos]++;
//		for (int i=0;i<=pos;i++)
//		cout<<taken[i]<<" ";
//		cout<<endl;
		int numb=0;
		for (int i=0;i<=pos;i++)
		{
			if (taken[i]!=0)
			numb++;
		}
		//taken[pos]--;
		if (total==number&&num==numb&&sol[number-1]==type[pos])
		flag=1;
		if (numb>num||(numb==num&&number<4&&sol[number]!=0))
		{
			for (int i=0;i<number;i++)
			sol[i]=a[i];
			num=numb;
			total=number;
			for (int i=number;i<4;i++)
			sol[i]=0;
			flag=0;
		}
		return 0;
	}
	a[number]=type[pos];
	taken[pos]++;
	int re1=DFS(a,pos,cur-type[pos],number+1,flag);
	taken[pos]--;
	int re2=DFS(a,pos+1,cur,number,flag);
	//cout<<re1<<" "<<re2<<endl;

	if (re1<0&&re2<0)
	return -1;
	return 0;
}

int main(int argc, char** argv) {
	int temp[4];
	int n,m;
	int flag=0;
	while (true)
	{
		while (cin>>n&&n)
		{
			type[t++]=n;
		}
		sort(type,type+t);
		while (cin>>m&&m)
		{
			cus[k++]=m;
		}
		if (t==0&&k==0) break;
		for (int i=0;i<k;i++)
		{
			for (int j=0;j<4;j++)
			sol[j]=0;
			num=0;
			total=0;
			for (int j=0;j<t;j++)
			{
				taken[j]=0;
			}
			flag=0;
			int res=DFS(temp,0,cus[i],0,flag);
			if (res==0)
			{
				if (flag==1)
				{
					cout<<cus[i]<<"("<<num<<"): tie"<<endl;
				}
				else{
					cout<<cus[i]<<"("<<num<<"):";
					for (int j=0;j<total;j++)
					{
						cout<<" "<<sol[j];
					}
				cout<<endl;
				}
			}
			if (res<0)
			{
				cout<<cus[i]<<" ---- none"<<endl;
			}
		}
		t=0;
		k=0;
	}
	return 0;
}