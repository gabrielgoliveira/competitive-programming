/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 
using namespace std;

int isPrimo(int n){
    int raiz = sqrt(n);
    int flag = 1;
    for(int j = 2; j <= raiz; j++){
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
    vector<int> lista;
    vector<vector<int>> mults;
    map<int, int> calcPrimo;
    int temp = 0;
    while(temp != -1){
        // leitura dos valores
        cin>>temp;
        lista.push_back(temp);
    }
    int n = lista.size();
    mults.resize(n);
    for(int i = 0; i < n; i++) {
         
        int a = 2, atual = lista[i];
        int limite_superior = sqrt(lista[i]);
        
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
        for(int j = 0; j < mults[i].size(); j++) cout<<mults[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}
