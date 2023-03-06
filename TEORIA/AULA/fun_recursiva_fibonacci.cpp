#include <iostream>
using namespace std;

/*
-> Complexidade O(2^n)
-> não é a forma mais rápida (eficienciente) de fazer a sequência de fibonacci
*/

int fibonacci(int n){  // função aux que calcula a sequencia de fibonacci
	
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
	
}

int main(){  // função principal
	//declaração de var
	int n;
	
	//entrada de dados
	cin >> n;
	
	//saída de dados
	cout << fibonacci(n) << endl;
	
	return 0;
}
