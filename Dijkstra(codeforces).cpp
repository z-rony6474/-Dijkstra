#include<bits/stdc++.h>
#define nl cout<<endl;
#define First_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
typedef long long ll;
vector<pair<ll,ll>>graph[100005];
ll Distance_From_Hometown[100005];
ll parent[100005];
void Dijkstra(ll home)
{
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
	q.push({0,home});
	Distance_From_Hometown[home]=0;
	while(!q.empty())
	{
		ll s_city=q.top().second;
		ll d_scity=q.top().first;
		q.pop();
		//if (d_scity != Distance_From_Hometown[s_city]) continue;
	    for (int i = 0; i < graph[s_city].size(); i++)
	    {
	    	ll c_city = graph[s_city][i].first;
	    	ll r_cost = graph[s_city][i].second+Distance_From_Hometown[s_city];
	    	if(Distance_From_Hometown[c_city]>r_cost)
	    	{
	    		Distance_From_Hometown[c_city]=r_cost;
	    		parent[c_city]=s_city;
	    		q.push({r_cost,c_city});
	    	}
	    }
	}
}
void solve()
{
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<=n;i++)
	{
		Distance_From_Hometown[i] = 1e18;
	}
	for(ll i=0;i<=n;i++)
	{
		graph[i].clear();
	}
	for(ll i=0;i<m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
				
	}
	Dijkstra(1);
	if(Distance_From_Hometown[n]==1e18)
	{
		cout<<-1<<endl;return;
	}
	deque<ll>path;
	ll x=n;
	path.push_front(x);
	while(1)
	{
		if(parent[x]==1)
		{
			path.push_front(1);break;
		}
		path.push_front(parent[x]);
		x=parent[x];
	}
	for(auto it : path)
	{
		cout<<it<<" ";
	}nl;
}
int main()
{
	First_IO;
	solve();
	return 0;
}
// Alhamdulillah
