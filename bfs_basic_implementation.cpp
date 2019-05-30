#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v[50];
bool visit[50];

void bfs(ll s)
{
    queue<ll> q;
    q.push(s);
    visit[s]=true;
    while(!q.empty())
    {
        ll p=q.front();
        q.pop();
        cout<<p<<" ";
        for(ll i=0;i<v[p].size();i++)
        {
            if(!visit[v[p][i]])
            {
                q.push(v[p][i]);
                visit[v[p][i]]=true;
            }
        }
    }
}
int main()
{
    ll n,e,i,m,p;
    cin>>n>>e;
    for(i=0;i<e;i++)
    {
        cin>>m>>p;
        v[m].push_back(p);
        v[p].push_back(m);
    }
    for(i=1;i<=n;i++)
    {
        visit[i]=false;
    }
    for(i=1;i<=n;i++)
    {
        if(!visit[i])
        {
            bfs(i);
        }
    }

}
