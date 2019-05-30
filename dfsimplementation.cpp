#include<bits/stdc++.h>
using namespace std;
vector<int> v[100];
bool visit[100];

void dfs(int s)
{

    int i;
    visit[s]=true;
    cout << s << " ";
    for(i=0;i<v[s].size();i++)
    {
        if(!visit[v[s][i]])
        dfs(v[s][i]);
    }
}

int main()
{
    int n,m,i,a,b;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1;i <= n;++i){
		visit[i] = false;
	}
    for(i=1;i<=n;i++)
    {
        if(visit[i]==false)
        dfs(i);
    }

}
