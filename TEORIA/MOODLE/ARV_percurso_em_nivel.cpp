#include <iostream>
#include <list>
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

void emNivel(treenodeptr t)  // funcao que mostra o percurso por niveis da arvore
{
	treenodeptr n;
	list <treenodeptr> q;
	
	if(t != NULL)
	{
		q.push_back(t);
		while(q.empty() != true)
		{
			n = *q.begin();
			q.pop_front();
			if(n->esq != NULL)
				q.push_back(n->esq);
			if(n->dir != NULL)
				q.push_back(n->dir);
			
			cout << n->info << endl;
		}
	}
}

// SEMPRE CHAMAR ESSA FUNCAO AO FINAL DO CODIGO
void tDestruir (treenodeptr &arvore)  // função que deleta a arvore da memoria do processador
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}

int main()
{
	// declaração de var
	treenodeptr arvore = NULL;  // ponteiro apontando para a raiz da arvore
	/*
	-> Sempre apontar para NULL, se não o código da errado
	porque não poderemos inserir os valores na arvore
	*/
	int x;  // var aux p/ leitura
	int aux;  // var aux de entrada de valores na arvore

	cin >> x;
	while(x != -1){
		aux = x;
		tInsere(arvore, aux);
		
		cin >> x;
	}	
	
	// chamada de funcao que faz o percurso em nivel
	emNivel(arvore);
	
	// deletando os dados da arvore
	tDestruir(arvore);

	return 0;
}
