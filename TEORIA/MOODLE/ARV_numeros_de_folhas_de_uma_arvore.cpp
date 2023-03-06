#include <iostream>
#include <iomanip>
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

void folhaPosOrdem(treenodeptr arvore, int &i1)
{  	
	if (arvore != NULL)
	{
		folhaPosOrdem(arvore->esq, i1);
		folhaPosOrdem(arvore->dir, i1);
		if(arvore->esq == NULL && arvore->dir == NULL)
		{
			i1++;
		}
	}
}

int contaFolhas(treenodeptr arvore)  // calcula a quantidade de folhas da arvore
{
	int i1 = 0;  // quantidade de folhas na arvore
	
	folhaPosOrdem(arvore, i1);
	
	return i1;
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
	int i;  // quantidade de folhas na arvore
	/*
	-> uma folha é quando um nó possui a esquerda e direita NULL
	*/
	int aux;  // var aux de entrada de valores na arvore

	// entrada de dados na arvore
	cin >> x;
	while(x != -1){
		aux = x;
		tInsere(arvore, aux);
		
		cin >> x;
	}
	
	// chamada da função que realiza o calculo da quantidade de folhas
	i = contaFolhas(arvore);
	
	// saida da quantidade de folhas
	cout << i << endl;
	
	// deletando os dados da arvore
	tDestruir(arvore);
	
	return 0;
}
