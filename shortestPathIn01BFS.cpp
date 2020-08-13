#include<bits/stdc++.h>

using namespace std;

// shortest distance fron root node
int ZeroOneBFS(vector<vector<pair<int,int>>> graph, int nodes, int st){
    deque<int> Q;
    vector<int> dist(nodes+1,INT_MAX);
    Q.push_back(1);
    dist[1] = 0;

    while(!Q.empty()){
        int val = Q.front();
        Q.pop_front();
        for(int i = 0; i < graph[val].size(); i++){
            if(dist[graph[val][i].second] > dist[val] + graph[val][i].first){
                dist[graph[val][i].second] = dist[val] + graph[val][i].first;

                if(graph[val][i].first == 0)
                    Q.push_front(graph[val][i].second);
                else
                    Q.push_back(graph[val][i].second);

            }
        }
    }
    // for(int i = 0; i < nodes+1; i++){
    //     cout<<i<<" : "<<dist[i]<<"\n";
    // }
    // cout<<st<<" :" <<dist[st]<<"\n";
    return dist[st]; // return shortest distance to reach st from node 1;

}
int main(){
    static auto _ = [] { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } ();

    int nodes, edges, a, b, w, st;
    cin>> nodes>>edges;
    vector<vector<pair<int,int>>> graph(nodes+1);

    for(int i = 0; i < edges; i++){
        cin>>a>>b>>w;
        graph[a].push_back(make_pair(w,b));
        graph[b].push_back(make_pair(w,a));
    }
    cin>>st;
    cout<<"shortest distance from node 1 to "<<st<<" is: "<<ZeroOneBFS(graph,nodes,st)<<"\n";


    return 0;

}
