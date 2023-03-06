#include <iostream>
#include <list>
using namespace std;

int soma(list<int> lista)  // retorna a soma dos numeros da lista
{
	int aux = 0;  // var aux
	
	while(!lista.empty())
	{
		aux = aux + (*lista.begin());
		lista.pop_front();
	}
	
	return aux;
}

int main()
{
	// declaracao de var
	list <int> lista;
	int aux;  // var aux
	int resultado;  // guarda o retorno da funcao soma

	// entrada de dados na lista
	cin >> aux;
	while(aux != 0)
	{
		lista.push_back(aux);
		cin >> aux;
	}

	// chamada de funcao de soma
	resultado = soma(lista);

	// saida de dados
	cout << resultado << endl;

	return 0;
}
