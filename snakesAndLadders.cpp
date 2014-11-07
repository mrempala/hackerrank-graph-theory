//Assumptions: a snake/ladder cannot end on a square that another snake/ladder begins on.
//Method Summary:
//Create the graph of an empty board with the only way to move is with the dice.
//Read in snakes and ladders, replacing correspondong edges in the board with the new destination.
//Perform a breadth first serach keeping track of the depth.
//Return the depth once square 100 is landed on.
//Scored: 20 out of 20 with success on all 6 test cases with 0.03s runtime
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct edge {
  int src;  
  int dst;
};

struct vertexAndDepth{
    int pos;
    int depth;
};

int snakesLaddersBFS(vector<edge> edges){
    vertexAndDepth initial;
    vertexAndDepth current;
    vertexAndDepth tempQ;
    initial.pos = 1;
    initial.depth = 0;
    queue<vertexAndDepth> BFSqueue;
    BFSqueue.push(initial);
    
    int visited[101];
    for(int i =0; i<101; i++)
        visited[i] = 0;
    
    while(!BFSqueue.empty()){
        current = BFSqueue.front();
        BFSqueue.pop();
        for(int i=0; i<edges.size(); i++){
             if(edges[i].src == current.pos){
                  //Check if reached square 100
                  if(edges[i].dst == 100){
                     return current.depth+1;
                  }
                 
                 else{
                     if(visited[edges[i].dst] == 0){
                         visited[edges[i].dst]++;
                         tempQ.pos = edges[i].dst;
                         tempQ.depth = current.depth + 1;
                         BFSqueue.push(tempQ);
                     }
                 }
             }
        }
    }
    
    //Return failure as a solution was not found
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int numTests;
    char dummyChar;
    cin>>numTests;
    
    for(int i=0; i<numTests; i++){
        //Build empty board
        vector<edge> edges;
        edges.clear();
        edge tempE;
        for(int i = 1; i<100; i++){
            for(int j=1; j<=6; j++){
                tempE.src = i;
                tempE.dst = i+j;
                if(tempE.dst <= 100){
                    edges.push_back(tempE);
                }
            }
        }

        //Read in snakes and ladders
        int numSnakes, numLadders;
        cin>>numLadders>>dummyChar>>numSnakes;
        for(int i=0; i<numLadders+numSnakes; i++){
            cin>>tempE.src>>dummyChar>>tempE.dst;
            for(int i=0; i<edges.size();i++){
                if(tempE.src == edges[i].dst){
                    edges[i].dst=tempE.dst;
                }
            }
        }
        
        //Perform a Breadth First Search
        int ans = snakesLaddersBFS(edges);
        cout<<ans<<'\n';
        
    }
    return 0;
}
