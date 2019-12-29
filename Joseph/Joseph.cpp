#include <iostream>
using namespace std;

struct ring
{
	int number,flag;
	ring *prev,*next;
};

void construct(ring *a,int k)
{
	ring *cur;
	cur=new ring;
	cur=a;
	cur->number=1;
	cur->flag=0;
	for (int i=1;i<2*k;i++)
	{
		ring *tmp;
		tmp=new ring;
		tmp->number=i+1;
		tmp->flag=0;
		tmp->prev=cur;
		cur->next=tmp;
		cur=tmp;
	}
	cur->next=a;
	a->prev=cur;
}

int main(int argc, char** argv) {
	int a[]={2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,13482720};
	int k,i;
	cin>>k;
//	k=2;
//	while (k<=14)
//	{
//		ring *c;
//		c=new ring;
//		construct(c,k);
//		ring *tmp;
//		tmp=c->prev;
//		int cur=k+1;
//		while (true)
//		{
//			tmp=c->prev;
//			for (i=0;i<k;i++)
//			{
//				int p=cur%(2*k-i);
//				if (p==0) p=2*k-i;
//				for (int j=0;j<p;j++)
//				{
//					while (tmp->next->flag==1)
//					{
//						tmp=tmp->next;
//					}
//					tmp=tmp->next;
//				}
//				tmp->flag=1;
//				if (tmp->number<=k)
//				{
//					cur++;
//					for (int j=0;j<2*k;j++)
//					{
//						tmp->flag=0;
//						tmp=tmp->next;
//					}
//					break;
//				}
//			}
//			if (i>=k)
//			break;
//		}
//		cout<<cur<<",";
//		k++;
//	}
    while (k!=0)
    {
    	cout<<a[k-1]<<endl;
    	cin>>k;
	}
	return 0;
}
