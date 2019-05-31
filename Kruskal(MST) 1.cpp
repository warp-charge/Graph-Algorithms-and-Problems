#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define ll long long
int id[MAX],node,edge;
pair<ll,pair<ll,ll> > p[MAX];

void initi()
{
    for(int i=0;i<MAX;i++)
    {
        id[i]=i;
    }
}
int root(int x)
{
    while(id[x]!=x)
    {
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}
void union1(int x,int y)
{
    int p=root(x);
    int q=root(y);
    id[p]=id[q];
}
ll kruskal(pair<ll,pair<ll,ll> > p[])
{
    int x,y;
    ll cost,mincost=0;
    for(int i=0;i<edge;i++)
    {
        x=p[i].second.first;
        y=p[i].second.second;
        cost=p[i].first;
        if(root(x)!=root(y))
        {
            mincost+=cost;
            union1(x,y);
        }
    }
    return mincost;
}
int main()
{
    int x,y;
    ll wgt,cost,mincost;
    initi();
    cin>>node>>edge;
    for(int i=0;i<edge;i++)
    {
        cin>>x>>y>>wgt;
        p[i]={wgt,{x,y}};
    }
    sort(p,p+edge);
    mincost=kruskal(p);
    cout<<mincost;
    return 0;
}
