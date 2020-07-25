#include<bits/stdc++.h>

using namespace std;

/*
Testcase Input:
        4 5
        1 2 7
        1 4 6
        4 2 9
        4 3 8
        2 3 6
    Output: 
        19
*/

void initailize(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++)
        arr[i] = i;
}

int root(vector<int>& diset, int x){
    while(diset[x] != x){
        x = diset[x];
    }
    return x;
}

void make_union(vector<int>& diset, int x, int y){
    int p = root(diset,x);
    int q = root(diset,y);
    diset[p] = diset[q];
}

int kruskal_algo(vector<pair<int,pair<int,int>>>& p, vector<int>& disjoint_map){
    int weight, x, y, mcost = 0;
    for(int i = 0; i < p.size(); i++){
        weight = p[i].first;
        x = p[i].second.first;
        y = p[i].second.second;

        if(root(disjoint_map,x) != root(disjoint_map,y)){
            mcost+= weight;
            make_union(disjoint_map,x,y);
        }
    }

    return mcost;
}


int main(){
    static auto _ = [] { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } ();

    int nodes, edges, x, y, weight, miniCost = 0;

    cin>>nodes>>edges;

    vector<pair<int,pair<int,int>>> p(edges);
    vector<int> disjoint_map(nodes+1);
    initailize(disjoint_map);



    for(int i = 0; i < edges; i++){
        cin>>x>>y>>weight;
        p.push_back(make_pair(weight,make_pair(x,y)));
    }

    sort(p.begin(),p.end());

    miniCost = kruskal_algo(p,disjoint_map);

    cout<<miniCost<<"\n";

    return 0;
}
