#include <iostream>
#include <list>
using namespace std;

int main()
{
	// declaracao de var
	int x;  // var aux de entrada de valores na lista
	list <int> q;  // lista que guarda os valores de entrada
	int i;  // contador
	int aux;  // var aux para varredura nos valores
	
	// entrada de dados
	for(i = 0; i < 4; i++){
		cin >> x;
		q.push_back(x);  // inserindo elementos na lista
	}
	
	// saida de dados
	for(i = 0; i < 4; i++){
		aux = *q.begin();
		cout << aux << endl;
		q.pop_front();  // retirando o primeiro elemento da lista
	}
	
	return 0;
}