#include<iostream>
#include <string.h>
#include<bits/stdc++.h>
#include <algorithm>
#include<vector>
#include <cmath>
using namespace std;
/*
Write a program to implement the following graph algorithms:
1. Breadth First Search (BFS)
2. Depth First Search (DFS)
3. Minimum Spanning Tree (Kruskal and Prim)
4. Dijkstra's Shortest Path Algorithm
*/
unordered_map<int, list<pair<int,int>>> graph2(int n,int m,vector<vector<int>> &edges){
    unordered_map <int,list<pair<int,int>>> adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    return adj;
}

vector<vector<int>> graph1(int n,int m,vector<vector<int>> &edges){
    vector<vector<int>> adj(n);   
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

void printGraph1(const vector<vector<int>> &adj) {
    for(int i = 0; i < adj.size(); i++) {
        cout << i << ": ";
        for(int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

vector<int> BFS(int start,int n,int m,vector<vector<int>> &edges){
    vector<vector<int>> ans = graph1(n,m,edges);
    unordered_map<int,bool> visit;
    queue<int> q;
    vector<int> result;

    q.push(start);
    visit[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(int i : ans[node]){
            if(!visit[i]){
                visit[i] = true;
                q.push(i);
            }
        }
    }
    return result;
}

vector<int> DFS(int start,int n,int m,vector<vector<int>> &edges){
    vector<vector<int>> ans = graph1(n,m,edges);
    unordered_map<int,bool> visit;
    stack<int> s;
    vector<int> result;
    s.push(start);
    visit[start] = true;
    while(!s.empty()){
        int node = s.top();
        s.pop();
        result.push_back(node);
        for(int i : ans[node]){
            if(!visit[i]){
                visit[i] = true;
                s.push(i);
            }
        }
    }
    return result;
}

vector<int> dj_algo(vector<vector<int>> &edges,int vertices,int edge,int source){
    unordered_map <int, list<pair<int,int>>> adj;
    for(int i=0;i<edge;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> dist(vertices, INT_MAX); 
    set<pair<int,int>> st;
    dist[source] = 0;
    st.insert({0, source});
    while(!st.empty()){
        auto top = *st.begin();
        st.erase(st.begin()); 
        int node = top.second;
        int distance = top.first;
        for (auto neighbour : adj[node]){
            int new_dist = distance + neighbour.second;
            if(new_dist < dist[neighbour.first]){
                auto x = st.find({dist[neighbour.first], neighbour.first});
                if(x != st.end()) st.erase(x);
                dist[neighbour.first] = new_dist;
                st.insert({new_dist, neighbour.first});
            }
        }
    }
    return dist;
}
vector<pair<int,int>> prims_algo(int root,int vertex,int edge,vector<vector<int>> &edges){
    unordered_map <int,list<pair<int,int>>> adj;
    for(int i=0;i<edge;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    set <pair<int,int>> key;            
    vector<bool> mst(vertex, false);
    vector<int> parent(vertex,-1);
    vector<int> minWeight(vertex, INT_MAX);
    minWeight[root] = 0;
    key.insert({0, root});
    vector<pair<int,int>> result;        
    while(!key.empty()){
        auto node = *(key.begin());      
        key.erase(key.begin());
        int u = node.second;
        mst[u] = true;
        if(parent[u] != -1){             
            result.push_back({parent[u], u});
        }
        for(auto nbr: adj[u]){
            int v = nbr.first;
            int w = nbr.second;
            if(!mst[v] && w < minWeight[v]){
                if(minWeight[v] != INT_MAX){
                    key.erase({minWeight[v], v});
                }
                minWeight[v] = w;
                parent[v] = u;
                key.insert({minWeight[v], v});
            }
        }
    }
    return result;
}
void print_prim(const vector<pair<int,int>> &mstEdges) {
    cout << "MST Edges:\n";
    for(auto &p : mstEdges) {
        cout << p.first << " -- " << p.second << "\n";
    }
}
void printGraph2(unordered_map<int, list<pair<int,int>>> &adj) {
    for (auto &node : adj) {
        cout << node.first << " -> ";
        for (auto &nbr : node.second) {
            cout << "(" << nbr.first << ", weight=" << nbr.second << ") ";
        }
        cout << endl;
    }
}
// DISJOINT SET
void makeset(vector<int> &parent,vector<int> &rank,int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}
int find_parent(vector<int> &parent,int node){
    if(parent[node]==node){
        return parent[node];
    }
    return parent[node]=find_parent(parent,parent[node]);
}
void union_set(int u,int v,vector<int> &parent,vector<int> &rank){
    u=find_parent(parent,u);
    v=find_parent(parent,v);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}
#include <algorithm>
bool cmp(const vector<int> &a,const vector<int> &b){
    return a[2]<b[2];
}
int kruskal_algo(vector<vector<int>> &edges,int vertex,int edge){
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(vertex);
    vector<int> rank(vertex);
    makeset(parent,rank,vertex);
    int min_weight=0;
    for(int i=0;i<edge;i++){
        int u=find_parent(parent,edges[i][0]);
        int v=find_parent(parent,edges[i][1]);
        int w=edges[i][2];
        if(u!=v){
            min_weight+=w;
            union_set(u,v,parent,rank);
        }
    }
    return min_weight;
}
/*---------------------------------------------------------------------------------------------------*/
/*
Given an undirected graph G(V, E) with V representing the number of vertices numbered from 0 to V-1
and E representing the number of edges, what is the task? Each edge connects two vertices u and v.
Task: Determine the number of connected components in the graph.*/
void visited(int i,unordered_map <int,list<int>> &adj,vector<bool> &visit){
    visit[i]=true;
    for(auto nbr: adj[i]){
        if(!visit[nbr]){
            visited(nbr,adj,visit);
        }
    }
}
int graph_traversal_count(int n,int m,vector<vector<int>> &edges){
    int ans=0;
    unordered_map<int, list<int>> adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visit(n,false);
    for(int i=0;i<n;i++){
        if(!visit[i]){
            ans++;
            visited(i,adj,visit);
        }
    }
    return ans;
}
/*You are given a weighted grid size of m x n. Each cell contains a non-negative cost. Interpret the grid as a
graph where each cell is a node and edges exist between adjacent horizontal/vertical cells with weights
equal to the destination cell cost.
Task: Determine the minimum total cost from (0,0) to (m-1,n-1) using Dijkstra.
*/
vector<int> shortest_path_grid(int start,int v,int e,vector<vector<int>> &edges){
    unordered_map <int,list<pair<int,int>>> adj;
    for(int i=0;i<e;i++){
        int a=edges[i][0];
        int b=edges[i][1];
        int w=edges[i][2];
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    vector<int> dist(v, INT_MAX);
    priority_queue<
    pair<long long,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> q;
    dist[start]=0;
    q.push({dist[start],start});
    while(!q.empty()){
        int node=q.top().second;
        int node_dist=q.top().first;
        q.pop();
        for(auto i:adj[node]){
            if(node_dist+i.second<dist[i.first]){
                dist[i.first]=node_dist+i.second;
                q.push({dist[i.first],i.first});
            }
        }
    }
    return dist;
}
/*You are given a directed weighted graph G(V, E) and an array times[] where times[i] = (u, v, w) represents
an edge from node u to node v with weight w.
Task: Given a starting node K, find how long it takes for all nodes to receive the signal*/
int network_delay(int start,int v,int e,vector<vector<int>> &edges){
    unordered_map <int,list<pair<int,int>>> adj;
    for(int i=0;i<e;i++){
        int a=edges[i][0];
        int b=edges[i][1];
        int w=edges[i][2];
        adj[a].push_back({b,w});
    }
    vector<int> dist(v+1, INT_MAX);
    priority_queue<
    pair<long long,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> q;
    dist[start]=0;
    q.push({dist[start],start});
    while(!q.empty()){
        int node=q.top().second;
        int node_dist=q.top().first;
        q.pop();
        for(auto i:adj[node]){
            if(node_dist+i.second<dist[i.first]){
                dist[i.first]=node_dist+i.second;
                q.push({dist[i.first],i.first});
            }
        }
    }
    int ans=0;
    for(int i=0;i<v;i++){
        if(dist[i]==INT_MAX) return -1;
        ans= max(ans,dist[i]);
    }
    return ans;
}
/*You are given a 2D grid of size M x N consisting of characters '0' and '1'. A group of connected '1's
horizontally or vertically represents a piece of land, forming an island.
Task: Count the total number of islands present in the grid using BFS/DFS.*/
void no_of_island2(int row,int col,vector<vector<int>> &visit,vector<vector<int>> &edges){
    queue<pair<int,int>> q;
    visit[row][col]=1;
    q.push({row,col});
    int n=edges.size();
    int m=edges[0].size();
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int delr=-1;delr<=1;delr++){
            for(int delc=-1;delc<=1;delc++){
                int nr=r+delr;
                int nc=c+delc;
                if((nr>=0 && nr<n) && (nc>=0&&nc<m)){
                    if(edges[nr][nc]==1 && visit[nr][nc]!=1){
                        visit[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
    
}
int no_of_island(int v,int e,vector<vector<int>> &edges){
    int count=0;
    vector<vector<int>> visit(v,vector<int>(e,0));
    for(int row=0;row<v;row++){
        for(int col=0;col<e;col++){
            if(!visit[row][col] && edges[row][col]==1){
                count++;
                no_of_island2(row,col,visit,edges);
            }
        }
    }
    return count;
}
int main(){
    int v=3, e=3;
    vector<vector<int>> edges = {
        {1,1,0},{0,1,0},{1,0,1}
    };
    cout<<no_of_island(v,e,edges);
    return 0;
}