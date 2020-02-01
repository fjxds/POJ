#include <iostream>
using namespace std;

int DivNum(int n)
{
	int res=0;
	while (n%5==0)
	{
		n=n/5;
		res+=1;
	}
	return res;
 } 

int main(int argc, char** argv) {
	int flag=0;
	for (int n=1;n<=25;n++)
	{
		int res=0;
		for (int i=1;i<=n;i++)
		{
			res+=DivNum(i);
		}
		long long int temp=1;
		for (int k=1;k<=n;k++)
		{
			temp=temp*k;
		}
		int number=0;
		long long int tmp=temp;
		while (temp%10==0)
		{
			temp=temp/10;
			number++;
		}
		if (res!=number)
		{
			cout<<"incorrect! "<<n<<" "<<tmp<<" "<<res<<endl;
			flag=1;
		}
	}
	if (flag==0)
	cout<<"correct!"<<endl;
	return 0;
}
