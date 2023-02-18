#include<bits/stdc++.h>
#define nl cout<<endl;
using namespace std;
typedef long long ll;
ll Max=INT_MIN,Min=INT_MAX;

vector<ll>graph[505];
ll Cost[505][505];
ll Distance_From_Hometown[505];
void Dijkstra(ll homeTown)
{
	  queue<int> cityQueue; 
       cityQueue.push(homeTown); 
       Distance_From_Hometown[homeTown] = 0;

        while (!cityQueue.empty())
        {
            int startingCity = cityQueue.front();
            cityQueue.pop(); 
            for (int i = 0; i < graph[startingCity].size(); i++)
            {
                int currentCity = graph[startingCity][i];
                ll maxCostFound = max(Distance_From_Hometown[startingCity],
                                   Cost[startingCity][currentCity]);
                if (Distance_From_Hometown[currentCity] > maxCostFound)
                {
                    Distance_From_Hometown[currentCity] = maxCostFound;
                    cityQueue.push(currentCity);
                }
            }
        }
	
}

void solve(ll Case)
{
	ll nm_city,nm_road;
	cin>> nm_city >> nm_road;
	
	memset(Cost,0,sizeof(Cost));
	for(ll i=0;i<=nm_city;i++)
	{
		Distance_From_Hometown[i] = INT_MAX;
	}
	for(ll i=0;i<=nm_city;i++)
	{
		graph[i].clear();
	}
	for(ll i=0;i<nm_road;i++)
	{
		ll source_city,des_city,roadcost;
		cin >> source_city >> des_city >> roadcost;

		if(!Cost[source_city][des_city])
		{
		   graph[source_city].push_back(des_city);
		   graph[des_city].push_back(source_city);
		   Cost[source_city][des_city]=roadcost;
		   Cost[des_city][source_city]=roadcost;
		}
		else
		{
		   Cost[source_city][des_city]=Cost[des_city][source_city]=min(roadcost,Cost[source_city][des_city]);
		}
	}
	ll Hometown;
	cin >> Hometown;
	
	Dijkstra(Hometown);
	cout<<"Case "<< Case << ":\n";
	for(ll i=0;i<nm_city;i++)
	{
		if(Distance_From_Hometown[i]==INT_MAX)
		{
			cout<<"Impossible\n";
		}
		else
		{
			cout<<Distance_From_Hometown[i]<<"\n";
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
	ll t,Case=1;
	cin>>t;
	while(t--)
	{
	 
	  solve( Case++);
	}
	return 0;
}
