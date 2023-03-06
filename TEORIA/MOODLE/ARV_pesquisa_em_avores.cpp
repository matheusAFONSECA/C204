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
	int i;  // contador
	int aux;  // var aux de entrada de valores na arvore

	// quantidade de valores a serem inseridos
	cin >> x;

	// inserindo valores na arvore
	for(i = 0; i < x; i++)
	{
		cin >> aux;
		tInsere(arvore, aux);
	}


	// Entrada do valor a ser procurado
	cin >> x;

	// verifique se o valor existe na arvore
	t = tPesq(arvore, x);

	if(t != NULL)
		cout << "Encontrado" << endl;
	else
		cout << "Nao encontrado" << endl;
	
	// deletando os dados da arvore
	tDestruir(arvore);

	return 0;
}
