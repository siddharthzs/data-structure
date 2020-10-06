#include<bits/stdc++.h>
using namespace std;


int topdown_dp(string A, string B){

    vector<vector<int>> dp(B.size(),vector<int>(A.size(),0));
    if(A[0] == B[0])
        dp[0][0] = 1;
    
    for(int i = 0; i < B.size(); i++){
        for(int j = 0; j < A.size();j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
    for(int i = 1; i < A.size();i++)
        if(A[i] == B[0])
            dp[0][i]+=(1+dp[0][i-1]);
    
    for(int i = 1; i < B.size();i++)
        if(B[i] == A[0])
            dp[i][0]+=(1+dp[i-1][0]);
            
    
    for(int i = 1; i < B.size(); i++){
        for(int j = 1; j < A.size(); i++){
            dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            if(A[j] == B[i])
                dp[i][j]+=1;
        }
    }
    return dp[B.size()-1][A.size()-1];
}

int recursion_dp(string A, string B){
    static 
    if(A.size() == 0 or B.size() == 0)
        return 0;
    
    
}




