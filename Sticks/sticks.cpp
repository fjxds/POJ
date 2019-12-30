#include<iostream>//深搜学习(经典)
#include<cstdio>//深搜可以作为面临多种选择时的不断尝试
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 105;
int arr[maxn];//储存木棒长度
bool vis[maxn];//木棒是否被使用了
int n;//有n个数
bool cmp(const int a,const int b)
{
    return a > b;
}//由大到小排列(因为合并后的木棒肯定是比最长的木棒长)   相当于小剪枝
int cnt,num;//cnt为木棒最小 num为合并后的木棒数
bool dfs(int k,int cur,int c_num)//从第k根木棒开始尝试,当前合并的木棒长为cur,c_num为已经整理好的木棒数
{
    if(c_num==num)
        return true;//说明已经完成
    if(cur==cnt)
        return dfs(0,0,c_num+1);//重新更新
    int i,prev = 0;//剪枝 eg 5 5 2 1 如果5不能，同理后一个5也不能完成
    for(i=k;i!=n;++i)
    {
        if(!vis[i]&&arr[i]+cur<=cnt&&prev!=arr[i])//剪枝    未被访问
        {
            prev = arr[i];
            vis[i] = true;
            if(dfs(i+1,cur+arr[i],c_num))
                break;//如果满足条件
            vis[i] = false;//回溯
            if(k==0)//剪枝
                return false;//剪枝
        }
    }
    if(i!=n)
        return true;
    else
        return false;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n&&n)
    {
        int sum = 0;//总的长度
        for(int i=0;i!=n;++i)
        {
            cin>>arr[i];//输入木棒对应长度
            sum += arr[i];
        }
        sort(arr,arr+n,cmp);
        //sum / 2是有可能俩木棒合并为一根
        //cout<<sum/2<<endl;
        for(cnt = arr[0];cnt<=sum/2;++cnt)
        {
            if(sum % cnt)
                continue;//cnt必定是为sum的因数的
            num = sum /cnt;//木棒的根数
            memset(vis,false,sizeof(vis));//每次尝试时更新
            if(dfs(0,0,0))
                break;//找到合适的长度
        }
        if(cnt>sum/2)
            cout<<sum<<endl;
        else
            cout<<cnt<<endl;
    }
}
