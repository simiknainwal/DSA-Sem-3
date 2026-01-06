#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfs(int V, vector<vector<int>>adj){
        queue<int>q;
        vector<int>visited(V+1,0);
        visited[1]=1;
        q.push(1);
        vector<int>bfs;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            cout<<node<<" ";
            for(auto it:adj[node]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push(it);
                }
            }
            }
            return bfs;

}

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

    bfs(m,adj);

    // for(int i=1;i<=m;i++){
    //     cout<<"For node "<<i<<":";
    //     for(auto it:adj[i]){
    //         cout<<it<<" ";
    //     }
    //     cout<<"\n";
    // }
}