#include<bits/stdc++.h>

using namespace std;

/*
// node 1 is the root of the tree
Input Testcase :
20
11 1
1 2
13 3
15 4
17 5
11 6
2 7
1 8
15 9
4 10
15 12
5 13
2 14
17 15
15 16
11 17
15 18
9 19
16 20
2
Output: The number of nodes at level x(2) = 3
*/

// hint: child level = parent level + 1
int breadthFirstSearch(vector<vector<int>> & graph, int l, int node){
    queue<int> Q;
    vector<bool> visited(node+1,false);
    vector<int> level(node+1,0);
    visited[1] = true;
    Q.push(1);
    level[1] = 1;
    while(!Q.empty()){
        int val = Q.front();
        Q.pop();
        for(int i = 0; i < graph[val].size(); i++){
            if(visited[graph[val][i]])
                continue;
            level[graph[val][i]] = level[val]+1;
            Q.push(graph[val][i]);
            visited[graph[val][i]] = true;
        }
    }
    int cnt = 0;
    for(int i = 1; i < node+1; i++){
        if(level[i] == l)
            cnt++;
    }
    return cnt;
}

int main(){
    static auto _ = [] { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } ();

    int edges, nodes, a, b, level;
    cin>> nodes;
    vector<vector<int>> graph(nodes+1);
    edges = nodes-1;
    for(int i = 0; i < edges; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin>>level;
    cout<<breadthFirstSearch(graph,level, nodes);


    return 0;

}
