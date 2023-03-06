#include <iostream>

using namespace std;

int potencia(int a, int b){  // função recursiva que calcula a potencia
	
	if(b == 0)  // caso em que o expoente vale 0
		return 1;
	else if(b > 0)  
		return (a*potencia(a, b-1));  // chamada recursiva
}

int main()
{
	// declaração de var
	int a;  // base
	int n;  // expoente
	
	//entrada de dados
	cin >> a >> n;
	
	//saida de dados
	cout << potencia(a, n) << endl;

	return 0;
}
