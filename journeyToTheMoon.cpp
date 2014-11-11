//Scored 30 out of 30 and passes all test cases
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main()
{ 
    int N, I;
    cin >> N >> I;
    vector<vector<int>> pairs(N);
    queue<int> Q;
    int colors[N];
    for(int i=0;i<N;i++)
        colors[i]=-1;
    
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }
    
    /** Write code to compute the result using N,I,pairs **/
    long long colorSize, otherSize=0, result = 0;
    int groupColor = 0;
    for (int i = 0; i < N; ++i){
        if(colors[i]==-1){
            //Colorify with BFS!
            colorSize=1;
            colors[i]=groupColor;
            Q.push(i);
            while(!Q.empty()){
                int a=Q.front();
                Q.pop();
                for(int j=0; j<pairs[a].size();j++){
                    int b = pairs[a][j];
                    if(colors[b]==-1){
                        colors[b]=groupColor;
                        colorSize++;
                        Q.push(b);
                    }
                }
            }
            result += otherSize*colorSize;
            otherSize += colorSize;
            groupColor++;
        }
    }
    
    cout << result << endl;
    return 0;
}
