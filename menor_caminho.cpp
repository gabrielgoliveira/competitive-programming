#include <bits/stdc++.h>

using namespace std;

// Variaveis Globais

int n, m; // n é a quantidade de vertices e m é a quantidade de arestas
vector <vector <int>> campo;
typedef pair<int, int> pi;


int buscaMenorCaminho(int origem, int destino){
  int distancia[n];
  bool visitado[n];

  for (int i = 0; i < n; i++) {
    // Inicializando as variaveis
    distancia[i] = 1e9;
    visitado[i] = false;
  }

  priority_queue<pi, vector<pi>, greater<pi> > fila; // fila de prioridade
  fila.push({0, origem}); // inserindo na fila peso do vertice inicial + o vertice inicial
  distancia[origem] = 0;

  while(!fila.empty()) {
    int vertice = fila.top().second; // recuperando o vertice
    int custo = fila.top().first; // recuperando o peso

    fila.pop();

    for (int i = 0; i < n; i++) {
      // Vamos olhar todos os nos adjacentes ao vertice
      if(campo[vertice][i] != 1e9) {
        // existe aresta de _vertice_ para _i_
        int u = i;
        int c = campo[vertice][i];

        if(distancia[u] > custo + c) {
          // inserir uma distancia menor
          distancia[u] = custo + c;
          fila.push({distancia[u], u});
        }
      }
    }
  }
/*
  for(int i = 0; i < n; i++) {
    cout<<"Custo de "<<origem<<" até "<<i<<" é : "<<distancia[i]<<endl;
  }
*/
  return distancia[destino-1];
}

int main(){
  do {
    //cout<<"Entrada N e M : ";
    cin>>n>>m; // numero de vertices, numero de arestas
    if(n == 0 && m == 0) {
      return 0;
    }
    campo.clear(); // limpando o campo
    for (int i = 0; i < n; i++) {
      // inicializando campo com distancias infinitas
      vector <int> temp;
      for (int j = 0; j < n; j++) {
        temp.push_back(1e9);
      }
      campo.push_back(temp);
    }
    int u, v, c;
    for (int i = 0; i < m; i++) {
      // lendo as distancias
      cin>>u>>v>>c; // origem, destino, custo
      //cout<<"Inserindo em "<<u-1<<" "<<v-1<<" "<<c<<endl;

      campo[u-1][v-1] = c;
    }
/*
    for (int i = 0; i < n; i++) {
      // imprimindo os campos
      for (int j = 0; j < n; j++) {
        cout<<campo[i][j]<<" ";
      }
      cout<<endl;
    }
*/
    int q;
    cin>>q;
    while(q--){
      // R : Remove rotas R X Y, sendo que X e Y são inteiros
      // I : Adiciona Rota, receber 3 inteiros u, v, w
      // P consulta da menor distancia da base de operação até X

      char letra;
      cin>>letra;
      if(letra == 'R') {
        // remove caminho
        cin>>u>>v;
        campo[u-1][v-1] = 1e9;
      } else if (letra == 'I') {
        // novo caminho
        cin>>u>>v>>c;
        campo[u-1][v-1] = c;
      } else if (letra == 'P') {
        // consulta menor caminho
        cin>>u;
        int menorDistancia = buscaMenorCaminho(0, u);
        //cout<<"Menor caminho da base até "<<u<<" é : "<<menorDistancia<<endl;
        cout<<menorDistancia<<endl;
      }
    }
  } while (n != 0 && m != 0);
 
  return 0;
}
