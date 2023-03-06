#include <iostream>
using namespace std;

/*
-> Complexidade O(2^n)
-> n�o � a forma mais r�pida (eficienciente) de fazer a sequ�ncia de fibonacci
*/

int fibonacci(int n){  // fun��o aux que calcula a sequencia de fibonacci
	
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
	
}

int main(){  // fun��o principal
	//declara��o de var
	int n;
	
	//entrada de dados
	cin >> n;
	
	//sa�da de dados
	cout << fibonacci(n) << endl;
	
	return 0;
}
