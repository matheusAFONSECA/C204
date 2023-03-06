#include <iostream>
#include <list>
using namespace std;

bool encontrar(list<int> lista, int x)  // funcao auxiliar de pesquisa na lista
{
	int aux;  // var aux
	
	while(!lista.empty())
	{
		aux = *lista.begin();
		if(x == aux)
			return true;
		else
			lista.pop_front();
	}
	
	return false;
}

int main()
{
	// declaracao de var
	list <int> lista;
	int x;  // numero que sera procurado
	int aux;  // var aux
	bool resultado;  // guarda o resultado da pesquisa

	// entrada de dados na lista
	cin >> aux;
	while(aux != 0)
	{
		lista.push_back(aux);
		cin >> aux;
	}

	// entrada de valor a ser pesquisado
	cin >> x;

	// chamada de funcao recursiva
	resultado = encontrar(lista, x);

	// saida de dados
	if(resultado == true)
		cout << "Encontrado" << endl;
	else
		cout << "Nao encontrado" << endl;

	return 0;
}
