//Inefficent, would be more efficent to compute the size
//of each node once and store that, but this does work
//as-is by calling the getSize() function for every child.
//Works, scored 28/28 with all 10 test cases in 0.02s runtime
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct edge{
  int src;
  int dst;
};

int getSize(int root, const vector<edge> &edges){
    int result = 0;
    
    for(int i=0; i<edges.size(); i++){
        if(edges[i].src == root){
            result+=getSize(edges[i].dst, edges);
        }
    }
    
    return result+1;
}

int edgesRemovable(int root, const vector<edge> &edges){
    int result = 0;
    
    for(int i=0; i<edges.size(); i++){
        if(edges[i].src == root){
            result += edgesRemovable(edges[i].dst, edges);
            int cSize = getSize(edges[i].dst, edges);
            if(cSize%2==0){
                result++;
            }
        }
    }
    
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int numV, numE;
    cin>>numV>>numE;
    vector<edge> edges;
    edge tempE;
    for(int i =0; i<numE; i++){
        cin>>tempE.dst>>tempE.src;
        edges.push_back(tempE);
    }
    
    //Assumes that edges[0].src is the root
    cout<<edgesRemovable(edges[0].src, edges);
    
    return 0;
}
