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

int menorEmOrdem (treenodeptr arvore, int &i)  // procura o menor elemento
{  	
	if (arvore != NULL)
	{
		menorEmOrdem(arvore->esq, i);
		if(i == 0)
		{
			i = arvore->info;
			return i;
		}
	}
}

int maiorEmOrdem (treenodeptr arvore, int &k)  // procura o maior elemento 
{  	
	if (arvore != NULL)
	{
		maiorEmOrdem(arvore->dir, k);
		if(k == 0)
		{
			k = arvore->info;
			return k;
		}
	}
}

int menor(treenodeptr arvore){
	int i = 0;  // var aux de controle
	int menor1;  // menor elemento da arvore
	
	// chama a função que busca pelo menor elemento da arvore
	menor1 = menorEmOrdem(arvore, i);
	
	return menor1;
}

int maior(treenodeptr arvore){
	int k = 0;  // var aux de controle
	int maior1;  // menor elemento da arvore
	
	// chama a função que busca pelo menor elemento da arvore
	maior1 = maiorEmOrdem(arvore, k);
	
	return maior1;
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
	int Maior;  // maior elemento da arvore
	int Menor;  // menor elemento da arvore
	
	// entrada de dados na arvore
	cin >> x;
	while(x != -1){
		aux = x;
		tInsere(arvore, aux);
		
		cin >> x;
	}

	// chamada da função
	Maior = maior(arvore);
	Menor = menor(arvore);
	
	// saida de dados
	cout << Menor << " e " << Maior << endl;
	
	// deletando os dados da arvore
	tDestruir(arvore);

	return 0;
}
