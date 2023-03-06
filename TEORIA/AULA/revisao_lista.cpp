#include <iostream>
#include <list>
using namespace std;

int main()
{
	// declaracao de avr
	list <int> lista;  // lista do tipo inteira
	int x;  // var aux para adicionar elemento na lista
	
	x = 10;
	lista.push_back(x);  // insere elemento x no final
	// lista.push_back(nome_da_variavel) -> insere o elemento no final da lista
	
	x = 23;
	lista.push_back(x);
	
	x = *lista.begin();  // ponteiro que aponta para o incio da lista
	cout << x << endl;
	
	lista.pop_front();  // remove o primeiro elemento da minha lista
	
	x = *lista.begin();
	cout << x << endl;
	
	return 0;
}