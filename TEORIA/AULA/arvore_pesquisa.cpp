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

treenodeptr tPesq(treenodeptr p, int x)
{
	if (p == NULL) // elemento não encontrado
		return NULL;
	else 
		if (x == p->info) // elemento encontrado na raiz
			return p;
		else 
			if(x < p->info) // procura na sub arvore esquerda
				return tPesq(p->esq, x);
			else             // procura na sub arvore direita
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
	int x;  // var aux p/ leitura

	// inserindo elementos na arvore
	tInsere(arvore, 14);
	tInsere(arvore, 4);
	tInsere(arvore, 15);
	tInsere(arvore, 3);
	tInsere(arvore, 9);
	tInsere(arvore, 14);
	tInsere(arvore, 20);

	// leia um x
	cin >> x;
	
	// verifique se X existe na arvore
	t = tPesq(arvore, x);
	
	if(t != NULL)
		cout << "Encontrado" << endl;
	else
		cout << "Nao encontrado" << endl;

	return 0;
}
