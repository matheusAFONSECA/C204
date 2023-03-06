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

void primoPosOrdem (treenodeptr arvore, int &j)  // conta os numeros primos em pos-ordem
{
	int i;  // contador
	int aux = 0;  // var aux de contagem da quantidade de numeros divisiveis
	if (arvore != NULL)
	{
		primoPosOrdem(arvore->esq, j);
		primoPosOrdem(arvore->dir, j);
		for(i = 1; i <= arvore->info; i++)
		{
			if(arvore->info % i == 0)  // condicao para ser divisivel
				aux++;
		}
		if(aux == 2)  // divisivel somente por dois numeros = numero primo
			j++;
	}
}

int contarPrimos(treenodeptr arvore)  // funcao que conta a quantidade de primos na arvore
{
	int j = 0;  // contador da quantidade de primos

	primoPosOrdem(arvore, j);

	return j;
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
	int primo;  // quantidade de primos na arvore

	// entrada de dados na arvore
	cin >> x;
	while(x != -1)
	{
		aux = x;
		tInsere(arvore, aux);

		cin >> x;
	}

	// chamada de funcao de calculo de numeros primos
	primo = contarPrimos(arvore);

	// saida de dados
	cout << primo << " numeros primos" << endl;

	// deletando os dados da arvore
	tDestruir(arvore);

	return 0;
}
