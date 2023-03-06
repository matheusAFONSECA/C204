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

void desOrdem (treenodeptr arvore)  // mostra os elemento em ordem decrescente
{  	
	if (arvore != NULL)
	{
		desOrdem(arvore->dir);
		cout << arvore->info << endl;
		desOrdem(arvore->esq);
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
	
	// entrada de dados na arvore
	cin >> x;
	while(x != -1){
		aux = x;
		tInsere(arvore, aux);
		
		cin >> x;
	}

	// chamada da função
	desOrdem(arvore);
	
	// deletando os dados da arvore
	tDestruir(arvore);

	return 0;
}
