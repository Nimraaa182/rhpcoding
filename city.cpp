#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
using namespace std;
int main(){
int R;cin>>R; set<int> vis;
map<int,vector<pair<int,int>>> g;
while(R--){
    int src,dest,dist; cin>>src>>dest>>dist;
    g[src].push_back(make_pair(dest,dist));
    g[dest].push_back(make_pair(src,dist));
}
int st,end; cin>>st>>end;
priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
pq.push(make_pair(0,st));
while(!pq.empty())
{
    auto[currdist,city]=pq.top();pq.pop();
  if(vis.find(city) == vis.end()){
        vis.insert(city);
        if(city==end){
            cout<<currdist;
            return 0;
        }
        for(auto[oc,ocd]:g[city]){
             if(vis.find(oc) == vis.end()){
                pq.push(make_pair(currdist+ocd,oc));
            }
        }
    }
}
cout<<"no path exists from"<<st<<"to"<<end<<endl;
return 0;
}
