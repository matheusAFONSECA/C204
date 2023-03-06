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

tPesq(treenodeptr p, int x)
{
	if (p == NULL) // elemento n~ao encontrado
		return NULL;
	else 
	if (x == p->info) // elemento encontrado na raiz
		return p;
	else if(x < p->info) // procura na sub ´arvore esquerda
		return tPesq(p->esq, x);
	else             // procura na sub ´arvore direita
		return tPesq(p->dir, x);
}

int main()
{
	treenodeptr arvore = NULL;  // ponteiro apontando para a raiz da arvore
	/*
	-> Sempre apontar para NULL, se não o código da errado
	porque não poderemos inserir os valores na arvore
	*/
	treenodeptr t = NULL;  // ponteiro aux

	// inserindo valores na arvore
	tInsere(arvore, 14);
	tInsere(arvore, 4);
	tInsere(arvore, 15);
	tInsere(arvore, 3);
	tInsere(arvore, 9);
	tInsere(arvore, 14);
	tInsere(arvore, 20);

	// atribuindo o ponteiro para o início da árvore
	t = arvore;
	cout << "arvore->info = " << arvore->info << endl;  // mostra o nó incial
	cout << "arvore->esq = " << arvore->esq << endl;  // mostra o endereço do nó da esquerda
	cout << "arvore->dir = " << arvore->dir << endl;  // mostra o endereço do nó da direita

	cout << "filho esquerdo = " << (arvore->esq)->info << endl;
	
	// mostrando o nó incial
	t = arvore;
	cout << t->info << endl;
	// mostrando o nó a esquerda do inicial
	t = t->esq;
	cout << t->info << endl;

	return 0;
}
