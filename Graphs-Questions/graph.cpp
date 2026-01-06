#include<iostream>
#include<vector>
using namespace std;

int main(){
    int m,n,u,v;
    cin>>m>>n;
    
    
    //Adjacency matrix
    
    // int adj[m+1][m+1];
    // for(int i=0;i<n;i++){
        //     cin>>u>>v;
        //     adj[u][v]=1;
        //     adj[v][u]=1;
        //     cout<<"Undirected edge is between "<<u<<" "<<v<<endl;
        // }
        
        
        //Adjacency List.
        
        vector<vector<int>>adj(m+1);
        for(int i=0;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=m;i++){
        cout<<"For node "<<i<<":";
        for(auto it:adj[i]){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
}