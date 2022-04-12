#include <bits/stdc++.h>
#include <cmath>

using namespace std;

vector<float> conjunto;
vector<bool> conjuntoUm;

int subsetSum (int n){
  int a;
	float p;
	int c = 0;
	float soma = 0;

	//Atribuindo ao vetor Conjunto, as raizes de 1 a N
  for(int i = 1; i <= n; i++) {
    p = sqrt(i);
    conjunto.push_back(p);
  }

	//Encontrando o somatorio das raizes de 1 a N
	for (int i = 0; i <= n; i++) {
		soma += conjunto[i];
	}

	cout<<"A somatoria do conjunto S é = "<<soma<<endl;
	
	//Encontrando a função topo, da metade da soma
	c = ceil (soma/2) ;
	cout<<"Considerando a capacidade de cada bipartição proxima de : "<<c<<endl;
	// Imprimindo tabela Item Peso
  cout<<"Item -> Peso "<<endl;
  for(int i = 0; i < n; i++) {
    cout<<i+1<<" -> "<<conjunto[i]<<endl;
  }
  cout<<endl;
  //Instanciando uma matriz n+1 por c+1
  float matriz[n+1][c+1];

  //Inicialização das linhas
  for (int i = 0; i < n+1; i++) {
    // Para capacidade zero o conjunto vazio é solução
    matriz[i][0] = 1;
  }

  // Aplicando subset-sum para achar uma solução proxima da capacidade definida como sum/2.
  for (int b = 1; b < c+1; b++) {
    matriz[0][b] = 0; // Toda capacidade != 0 não tem solução com conjunto vazio

    for (int i = 1; i < n+1; i++) {
			//Capturando a solução S da linha anterior
			//Com capacidade b
      float s = matriz[i-1][b];

			//Capturando o peso do elemento escolhido
      float peso_i = conjunto[i-1];

			/** Se a solução vale zero e o peso é menor que
			** a capacidade, então a gente verifica se existia
      ** uma solução sem aquele elemento e com a capacidade
      ** reduzida pelo peso dele, como estamos tratando de numeros
      ** reais, estamos arredondando o numero para testar a capacidade
      ** fazendo uma aproximação.
      **/
      if(s == 0 && peso_i <= b) {
        s = matriz[i-1][int(b-peso_i)];
      }

			//Atribui a solução adquirida para a
			//posição da matriz
      matriz[i][b] = s;
    }
  }

	//Percorrendo a matriz n+1 por c+1 e imprimindo-a
  cout<<"Matriz Resultado do Subset Sum : "<<endl;
  for(int i = 0; i < n+1; i++) {
    for(int j = 0; j < c+1; j++) {
      cout<<matriz[i][j]<<" ";
    }
    cout<<endl;
  }

	//Iniciando o vetor booleano que identifica que
	//o elemento aparece no conjunto 1,
	//com falso em todas as posições
	for (int i = 0; i< n; i++){
		conjuntoUm.push_back(false);
	}

	

	//Iniciando j com o valor da capacidade
	int j = c;

	//Percorrendo a matriz n+1 por c+1
	//Para encontrar os elementos que estão na solução
	//O vector booleano conjuntoUm, diz se o elemento
	//Esta presente no conjunto um ou não
  vector <float> A;
  vector <float> B;
	for (int i = n; i >= 1 && j>0; i--){
    /*
      cout<<endl;
      cout<<"Valor de i : "<<i<<endl;
      cout<<"Valor de j : "<<j<<endl;
      cout<<"Acessando a coluna : "<<j<<" da matriz"<<endl;
    */
		if (matriz[i][j] != matriz[i-1][j]){
			conjuntoUm[i-1] = true;
      A.push_back(conjunto[i-1]);
			j-= conjunto[i-1];
		}
	}

  // Imprime o Conjunto A
  cout<<endl<<"Os elementos do primeiro conjunto serão:"<<endl;
  cout<<"A = {";
  for(int i = 0; i < A.size(); i++) {
    if(i != A.size() -1) {
      cout<<A[i]<<", ";
    } else {
      cout<<A[i]<<"}";
    }
  }

	cout<<endl;

  float sumA = 0, sumB = 0;

  /*  Percorre nosso conjunto verificando os 
  ** valores que estão em A e os valores que estão em B
  ** fazendo tambem os respectivos somatorios.
  */
	for (int i=0; i<n; i++) {
		if (!conjuntoUm[i]){
      // Está no conjunto B
			B.push_back(conjunto[i]);
      sumB += conjunto[i];
		} else {
      // Está no conjunto A
      sumA += conjunto[i];
    }
  }
  // Imprime o conjunto   B
  cout<<endl<<"Os elementos do segundo conjunto serão:"<<endl;
  cout<<"B = {";
  for(int i = 0; i < B.size(); i++) {
    if(i != B.size() -1) {
      cout<<B[i]<<", ";
    } else {
      cout<<B[i]<<"}";
    }
  }

  float dif = sumA-sumB;
	cout<<endl;
  cout<<"-------------------------------------------------------"<<endl;
	cout<<"Somatorio dos elementos em A : "<<sumA<<endl;
  cout<<"Somatorio dos elementos em B : "<<sumB<<endl;
  cout<<"Diferença da soma de A e B : "<<(dif >= 0 ? dif : dif*(-1))<<endl;
  cout<<"-------------------------------------------------------"<<endl;

  return 0;
}

int main(){
  int n;
  clock_t start, end;
  start = clock();
  cout<<"Digite o valor de n : ";
  cin>>n;
  subsetSum(n);
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo de execução : " << fixed << time_taken << setprecision(5);
  cout << " sec " << endl;
  cout << "Para n = "<<n<<endl;
  return 0;
}
