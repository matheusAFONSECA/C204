#include <iostream>
using namespace std;

/*
-> Quando uma fun��o � usada de forma recursiva podemos classific�-la como �RVORE
DE RECURS�O
-> Esse algoritmo, por exemplo, � um c�digo de complexidade de O(n)
-> O problema de algoritmos recursivos � o gasto de mem�ria que o c�digo faz de 
acordo com a quantidade de vezes que recursividade � usada
*/

int fatorial(int n){  // fun��o que calcula o fatorial de um n� n
	
	if(n == 0)
		return 1;
	else
		return n * fatorial(n - 1);
	
}

int main(){  // fun��o principal
	// declara��o de var
	int n;
	
	//leitura do numero n
	cin >> n;
	
	//saida do fatorial de n
	cout << fatorial(n) << endl;
	
	return 0;
}