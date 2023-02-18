// Problem: P - Missile Silos
// Contest: Virtual Judge - Week - 01
// URL: https://vjudge.net/contest/541000#problem/P
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define nl cout<<endl;
#define First_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
typedef long long ll;
const ll mx = 1e7;
ll dis[mx],n,s,m,ans,cnt,l;
vector<pair<ll,ll>>grp[mx];
void dijktra()
{
	for(ll i=1;i<=n;i++)
	{
		dis[i]=INT_MAX;
	}
	queue<ll>q;
	q.push(s);
	dis[s]=0;
	while(!q.empty())
	{
		ll tmp = q.front();
		q.pop();
		for(ll i=0;i<grp[tmp].size();i++)
		{
			ll x = grp[tmp][i].first;
			ll y = grp[tmp][i].second;
			if(dis[x]>dis[tmp]+y)
			{
				dis[x]=dis[tmp]+y;
				q.push(x);
			}
		}
	}
	for(ll i=1;i<=n;i++)
	{
		if(dis[i]==l)ans++;
	}
}
void solve()
{
	cin>>n>>m>>s;
	for(ll i=0;i<m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		grp[u].push_back({v,w});
		grp[v].push_back({u,w});
	}
	cin>>l;
	dijktra();
	for(ll i=1;i<=n;i++)
	{
		for(ll j=0;j<grp[i].size();j++)
		{
			ll u = grp[i][j].first;
			ll w = grp[i][j].second;
			if(dis[u]<l and l-dis[u]<w and w-(l-dis[u])+dis[i]>l)
			{
				ans++;
			}
			if(dis[u]<l and l-dis[u]<w and w-(l-dis[u])+dis[i]==l)
			{
				cnt++;
			}
		}
	}
	ans+=(cnt/2);
	cout<<ans<<endl;	
}
int main()
{
	First_IO; 
    solve();
	return 0;
}
// Alhamdulillah
