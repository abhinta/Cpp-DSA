/*
Code : Get Path - BFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
*/
#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
vector<int> getPath_bfs(int ** edges, int V, int v1, int v2, bool * visited){
    vector<int> ans;
    if(v1 == v2){
    	ans.push_back(v1);
        return ans;
    }
    queue<int> pending;
    pending.push(v1);
    visited[v1] = true;
    unordered_map<int, int> um;
    
    while(!pending.empty()){
        int front = pending.front();
        pending.pop();
        
        if(front == v2)
            break;
        
        for(int i = 0; i < V; i++){
            if(edges[front][i]){
                if(visited[i])
                    continue;
                pending.push(i);
                um[i] = front;
                visited[i] = true;
            }
        }
    }
    if(um.count(v2) == 0)
        return ans;
    
    ans.push_back(v2);
    int curr = v2;
    while(curr != v1){
        curr = um[curr];        
        ans.push_back(curr);
    }
    return ans;
}
int main() {
    int V, E;
    cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */
	int ** edges = new int*[V];
    for(int i = 0 ; i < V; i++){
        edges[i] = new int[V]();
    }
    for(int i = 0 ; i < E; i++){
        int f, s;
        cin>>f>>s;
        edges[f][s] = edges[s][f] = 1;
    }
    bool *visited = new bool[V]();
    
    int v1, v2;
    cin>>v1>>v2;
    
    
    vector<int> ans = getPath_bfs(edges, V, v1, v2, visited);
    for(int x: ans){
        cout<<x<<" ";
    }
  return 0;
}