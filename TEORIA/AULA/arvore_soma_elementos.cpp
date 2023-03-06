#include <iostream>
using namespace std;

struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};

typedef treenode* treenodeptr;  // redefinindo treenode como um ponteiro

void tInsere(treenodeptr &p, int x)  // funcao que insere um valor na arvore
{
	if(p == NULL)
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if(x < p->info)
		tInsere(p->esq, x);
	else
		tInsere(p->dir, x);
}

/*
-> posOrdem foi mudada para somaPosOrdem porque mudou-se a atividade que essa 
função realiza
	-> na posOrdem existe o cout da arvore->info
	-> na somaPosOrdem existe a soma da arvore->info
	
-> Sempre mudar o nome de uma função se a sua atividade principal for alterada
*/

void somaPosOrdem (treenodeptr arvore, int &s1)
{  	
	if (arvore != NULL)
	{
		somaPosOrdem(arvore->esq, s1);
		somaPosOrdem(arvore->dir, s1);
		s1 += arvore->info;
	}
}

// Retorna a soma dos elementos da arvore
int soma(treenodeptr arvore)
{
	int s1 = 0;  // soma dos elementos da arvore
	somaPosOrdem(arvore, s1);
	
	return s1;
}

int main()
{
	// declaração de var
	treenodeptr arvore = NULL;  // ponteiro apontando para a raiz da arvore
	/*
	-> Sempre apontar para NULL, se não o código da errado
	porque não poderemos inserir os valores na arvore
	*/
	int s;
	
	// inserindo elementos na arvore
	tInsere(arvore, 4);
	tInsere(arvore, 2);
	tInsere(arvore, 5);
	tInsere(arvore, 1);

	s = soma(arvore);
	
	cout << "soma = " << s << endl;

	return 0;
}
