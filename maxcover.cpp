#include <iostream>
#define MAX 10

using namespace std;

int graph[MAX][MAX], setA[MAX], setB[MAX];
int sizeA, sizeB;

bool bipartiteMatch(int u, bool *visited, int *check) {
   for (int i = 0; i < sizeA; i++) {
      if (graph[u][i] && !visited[i]) {
         visited[i] = true;
         if (check[i] < 0 || bipartiteMatch(check[i], visited, check)) {
            check[i] = u;
            return true;
         }
      }
   }
   return false;
}

int maxMatch() {
    int check[sizeA];
    bool visited[sizeA];

    for(int i = 0; i<sizeA; i++){
        check[i] = -1;
    }

    int result = 0;

     for (int u=0; u<sizeB; u++) {
        for(int i=0; i<sizeA; i++) {
            visited[i] = false;
        }
        if(bipartiteMatch(u, visited, check)) {
            result++;
     
        }    
    }

     cout<<"Matched vertices set = {";
     for(int i=0; i<sizeA; i++){
        cout<<"("<<setA[i]<<", "<<setB[check[i]]<<")";
        if(i != sizeA-1) cout<<", ";
     }
     cout<<"}";

     return result;
}

int main() {

    cout<<"\nEnter number of vertices in setA and setB of bipartite graph: ";
    cin>>sizeA>>sizeB;

    cout<<"\nEnter vertices of setA: ";
    for(int i=0; i<sizeA; i++) {
        cin>>setA[i];
    }
    
    cout<<"\nEnter vertices of setB: ";
    for(int i=0; i<sizeB; i++) {
        cin>>setB[i];
    }
    
    cout<<"\nEnter "<<sizeA<<" x "<<sizeB<<" adjacency matrix (A -> B):\n";
    for(int i=0; i<sizeA; i++){
        for(int j=0; j<sizeB; j++){
            cin>>graph[i][j];
        }
    }

    int ans = maxMatch();
    
    cout<<"\nMaximum number of matching: " <<ans <<"\n";

    return 0;
}
