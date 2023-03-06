#include <iostream>
using namespace std;

/*
-> Quando uma função é usada de forma recursiva podemos classificá-la como ÁRVORE
DE RECURSÃO
-> Esse algoritmo, por exemplo, é um código de complexidade de O(n)
-> O problema de algoritmos recursivos é o gasto de memória que o código faz de 
acordo com a quantidade de vezes que recursividade é usada
*/

int fatorial(int n){  // função que calcula o fatorial de um n° n
	
	if(n == 0)
		return 1;
	else
		return n * fatorial(n - 1);
	
}

int main(){  // função principal
	// declaração de var
	int n;
	
	//leitura do numero n
	cin >> n;
	
	//saida do fatorial de n
	cout << fatorial(n) << endl;
	
	return 0;
}