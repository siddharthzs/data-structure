#include<bits/stdc++.h>

using namespace std;

/*
Testcase
    Input:
        4 5
        1 2 7
        1 4 6
        4 2 9
        4 3 8
        2 3 6
    Output:
        19
*/


typedef pair<int,int> pii;

int prims_algo(vector<vector<pii>>& pset, vector<int>& visited, int startNode){
    // priority_queue<PII, vector<PII>, greater<PII> >
    priority_queue<pii,vector<pii>,greater<pii>> Queue;
    pii tpair;
    int x,cost = 0;

    Queue.push(make_pair(0, startNode));

    while(!Queue.empty()){
        tpair = Queue.top();
        Queue.pop();
        x = tpair.second;
        //checking for cycle
        if(visited[x])
            continue;

        cost+=tpair.first;
        visited[x] = 1;

        for(int i = 0; i < pset[x].size();i++){
            if(visited[pset[x][i].second])
                continue;
            Queue.push(pset[x][i]);
        }

    }

    return cost;

}


int main(){
    static auto _ = [] { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } ();

    int nodes, edges, x, y, weight, minCost = 0;
    cin>>nodes>>edges;

    vector<int> visited(nodes+1,0);
    vector<vector<pii>> adjgraph(nodes+1);

    for(int i = 0; i < edges; i++){
        cin>>x>>y>>weight;
        // pset.push_back(make_pair(weight,make_pair(x,y)));
        adjgraph[x].push_back(make_pair(weight,y));
        adjgraph[y].push_back(make_pair(weight,x));
    }

    minCost = prims_algo(adjgraph,visited,1);
    cout<<minCost<<"\n";


    return 0;

}
