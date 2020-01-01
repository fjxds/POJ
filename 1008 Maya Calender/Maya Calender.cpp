#include <iostream>
#include <string>

using namespace std;

string haab[]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
string tzolkin[]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};


int main(int argc, char** argv) {
	int n;
	cin>>n;
	cout<<n<<endl;
	int a,b;
	string s;
	for (int i=0;i<n;i++)
	{
		cin>>a;
		getchar();
		getchar();
		cin>>s>>b;
		//cout<<a<<" "<<s<<" "<<b<<endl;
		int day=b*365;
		for (int j=0;j<19;j++)
		{
			if (s==haab[j])
			day+=20*j;
		}
		day+=a+1;
		//cout<<day<<endl;
		int year=day/260;
		if (day%260==0) year-=1;
		int index=(day-year*260)%13;
		if (index==0) index=13;
		int month=(day-year*260)%20;
		if (month==0) month=20;
		cout<<index<<" "<<tzolkin[month-1]<<" "<<year<<endl;
	}
	
	
	
	return 0;
}
