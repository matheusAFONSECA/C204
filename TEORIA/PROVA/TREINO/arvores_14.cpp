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

void posOrdemEspaco(treenodeptr arvore)  // mostra os elemento em pos-ordem
{  	
	if (arvore != NULL)
	{
		posOrdemEspaco(arvore->esq);
		posOrdemEspaco(arvore->dir);
		cout << arvore->info << " ";
	}
}

treenodeptr tPesq(treenodeptr p, int x)  // faz a pesquisa de um elemento na ARVORE
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
	treenodeptr t = NULL;  // ponteiro aux
	int x;  // var aux p/ leitura
	int aux;  // var aux de entrada de valores na arvore
	
	// entrada de dados na arvore
	cin >> x;
	while(x != -1)
	{
		// pesquisa do elemento na arvore
		t = tPesq(arvore, x);
		
		if(t == NULL)  // condicao para o elemento nao estar na arvore
		{
			aux = x;
			tInsere(arvore, aux);  // insere os elemento na arvore
		}

		cin >> x;
	}
	
	// saida da arvore em pos-ordem
	posOrdemEspaco(arvore);
	cout << endl;
	
	// deletando os dados da arvore
	tDestruir(arvore);

	return 0;
}
