#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;

int isPrimo(long long int n){
    long long int raiz = sqrt(n);
    int flag = 1;
    for(long long int j = 2; j <= raiz; j++){
        if(n%j == 0 && n!=j) {
            flag = 0;
            break;
        }
    }

    if(flag == 1) {
        return true;
    }
    return false;
}

int main()
{
    vector < long long int > lista;
    vector < vector <long long int > > mults;
    map < long long int, int > calcPrimo;

    long long int temp = 0;
    int in;

    while(temp != -1){
        // leitura dos valores
        cin >> temp;
        if(temp == -1) continue;
        lista.push_back(temp);
    }

    int n = lista.size();
    mults.resize(n);

    for(int i = 0; i < n; i++) {
         
        int a = 2;
        long long int atual = lista[i];
        long long int limite_superior = sqrt(lista[i]);
        
        if(isPrimo(atual)){
            calcPrimo[atual] = 1;
            mults[i].push_back(atual);
            continue;
        } else {
            calcPrimo[atual] = -1;
        }
        
        while(a <= atual) {
            if(calcPrimo[a] == 0) {
                
                /* Para evitar recalculo, vamos usar a estrutura de dados map para armazenar os primos já calculados
                **  -1 -> não é primo 
                **   1 é primo e 
                **   0 não foi calculado ainda
                */
                
                if(isPrimo(a)){
                    calcPrimo[a] = 1;
                } else {
                    calcPrimo[a] = -1;
                }
            }
            
            if(atual%a == 0 && calcPrimo[a] == 1) {
                mults[i].push_back(a);
                atual = atual/a;
            }
            if(atual%a != 0){
                a++;
            }
        }
    }
    
    for(int i = n-1; i >=0; i--) {
        for(int j = 0; j < mults[i].size(); j++) cout << mults[i][j]<<" ";
        cout << endl;
    }
    
    return 0;
}
