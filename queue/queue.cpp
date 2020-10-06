#include<bits/stdc++.h>

using namespace std;

/*
    Queue
        constructor
        empty
        size
        front
        push
        emplace
        pop
        swap

*/

class myQueue{
    private:
        vector<int> Q;
    public:
        myQueue(){
            
        }

        bool empty(){
            if(Q.size() == 0)
                return true;
            return false;
        }
        int size(){
            return Q.size();
        }
        int front(){
            return Q.back();
        }
        void push(int x){
            Q.push_back(0);
            for(int i = Q.size()-2; i>=0;i--){
                Q[i+1] = Q[i]; 
            }
            Q[0] = x;

        }
        void pop(){
            Q.resize(Q.size()-1);
        }
}
int main(){
    static auto _ = [] { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } ();




    return 0;

}
