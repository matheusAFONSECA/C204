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

treenodeptr tPesq(treenodeptr p, int x)  // faz uma pesquisa de um elemento na ARV
{
	if (p == NULL) // elemento não encontrado
		return NULL;
	else if (x == p->info) // elemento encontrado na raiz
		return p;
	else if(x < p->info) // procura na sub arvore esquerda
		return tPesq(p->esq, x);
	else             // procura na sub arvore direita
		return tPesq(p->dir, x);
}

void preOrdem (treenodeptr arvore)  // mostra os elemento em pre-ordem
{  	
	if (arvore != NULL)
	{
		cout << arvore->info << endl;
		preOrdem(arvore->esq);
		preOrdem(arvore->dir);
	}
}

void emOrdem (treenodeptr arvore)  // mostra os elemento em ordem
{  	
	if (arvore != NULL)
	{
		emOrdem(arvore->esq);
		cout << arvore->info << endl;
		emOrdem(arvore->dir);
	}
}

void posOrdem (treenodeptr arvore)  // mostra os elemento em pos-ordem
{  	
	if (arvore != NULL)
	{
		posOrdem(arvore->esq);
		posOrdem(arvore->dir);
		cout << arvore->info << endl;
	}
}

int main()
{
	// declaração de var
	treenodeptr arvore = NULL;  // ponteiro apontando para a raiz da arvore
	/*
	-> Sempre apontar para NULL, se não o código da errado
	porque não poderemos inserir os valores na arvore
	*/
	
	// inserindo valores na arvore
	tInsere(arvore, 4);
	tInsere(arvore, 2);
	tInsere(arvore, 5);
	tInsere(arvore, 1);

	// fazendo a saida da arvore
	cout << "Pre-ordem: " << endl;
	preOrdem(arvore);
	cout << endl;
	cout << "Em ordem: " << endl;
	emOrdem(arvore);
	cout << endl;
	cout << "Pos-ordem: " << endl;
	posOrdem(arvore);
	cout << endl;

	return 0;
}
