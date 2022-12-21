#include <bits/stdc++.h>
using namespace std; 
#define ll long long 
int main(){
    int n,m;
    cin>> n;
    vector<vector<pair<int,ll> > >g(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            if(x < 1e5)g[i].push_back(make_pair(j, x));
        }
    }
    vector<ll>dis(n, 1e12);
    vector<int> p(n, -1);

    for(int i = 0;i< n-1;i++){
       for(int j=0;j<n;j++){
           for(auto k:g[j]){
                ll node=k.first,c=k.second;
                if(dis[node] > c + dis[j]){
                    dis[node] = c + dis[j];
                    p[node] = j;
                }
           }
       }
    }


    bool flag=false;
    for(int i = 0;i < n;i++){
       for(auto j:g[i]){
          ll int node=j.first,c=j.second;
          if(dis[node]>c+dis[i]){
             dis[node]=c+dis[i];
             p[node]=i;
             flag=true;
          }
            
          if(flag){
            vector<int >cycle;
            vector<bool>vis(n,false);

            while(!vis[i]){
                vis[i] = true;
                i = p[i];
            }

        

            int u = i;
            cycle.push_back(u);
            u = p[u];
            while(u != i){
                cycle.push_back(u);
                u=p[u];
            }
            cycle.push_back(u);
            cout << "YES\n" << cycle.size() << endl;

            for(int pos = cycle.size() - 1; pos >= 0; pos--)cout<<cycle[pos] + 1<<" ";
            return 0;
        }
       }
    }   

    if(!flag)cout<<"NO\n";
}