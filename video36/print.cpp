#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void print(vector<vector<bool>> &adj_max){
    for(int i=0;i<adj_max.size();i++){
        for(int j=0;j<adj_max[0].size();j++){
            cout<<adj_max[i][j]<<" ";
        }
        cout<<endl;
    }
}
void print(map<int,list<int>> &adj_list){
    for(auto kv_pair: adj_list){
        cout<<kv_pair.first<<": {";
        for(auto v: kv_pair.second){
            cout<<v<<",";
        }
        cout<<"}"<<endl;
    }
}

int main() {
    vector<vector<int>> edges = {
            {0,1},
            {1,2},
            {1,3},
            {3,4}
    };

    vector<vector<bool>> adj_max(5,vector<bool>(5,false));
    map<int,list<int>> adj_list;

    for(auto edge:edges){
        adj_max[edge[0]][edge[1]] = true;
        adj_max[edge[1]][edge[0]] = true;
    }

    for(auto edge : edges){
        adj_list[edge[0]].push_back(edge[1]);
        adj_list[edge[1]].push_back(edge[0]);
    }

    print(adj_max);
    cout<<endl;

    print(adj_list);

    return 0;
}