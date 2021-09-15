#include <iostream>
#include <vector>

using namespace std;

const int VERTICES = 7;

int grafo[VERTICES][VERTICES];

int main(){
    //implementação do grafo

    int num_arestas = 7;

    for(int i = 0; i < VERTICES; i++){
        for(int j = 0; j < VERTICES; j++){
            grafo[i][j] = 0;
        }
    }

    int u, v;

    for(int i = 0; i < num_arestas; i++){
        cin>>u>>v;
        grafo[u][v] = 1;
        grafo[v][u] = 1;
    }


    for(int i = 0; i < VERTICES; i++){
        for(int j = 0; j < VERTICES; j++){
            cout<<grafo[i][j]<<" ";
        }
        cout<<endl;
    }

    //implementação bfs

    bool visitado[VERTICES];
    
    for(int i = 0; i < VERTICES; i++){
        visitado[i] = false;
    }

    int origem = 0;
    vector<int> pilha;

    visitado[origem] = true;
    pilha.push_back(origem);

    while(!pilha.empty()){
        int atual = pilha[0];
        pilha.erase(pilha.begin());

        for(int i = 0; i < VERTICES; i++){
            if(grafo[atual][i] == 1 && !visitado[i]){
                cout<<"inserindo "<<i<<endl;
                pilha.push_back(i);
                visitado[i] = true;
            }
        }
    }


/*
    int origem = 0;

    list<int> pilha;

    visitado[origem] = true;
    pilha.push_back(origem);

    while(!pilha.empty()){
        int atual = pilha.front();

        pilha.pop_front();

        for(int i = 0; i < VERTICES; i++){
            if(grafo[atual][i]) {
                cout<<"inserindo "<<i<<endl;
                pilha.push_back(i);
                visitado[i] = true;
            }
        }
    }

*/

/*
    list<int>::iterator it = pilha.begin();

    for(int i = 0; i < pilha.size(); i++){
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
*/

    return 0;
}
