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

void mediaPosOrdem (treenodeptr arvore, float &media1, int &i)
{  	
	if (arvore != NULL)
	{
		mediaPosOrdem(arvore->esq, media1, i);
		mediaPosOrdem(arvore->dir, media1, i);
		media1 += arvore->info;
		i++;
	}
}

// Retorna a soma dos elementos da arvore
float media(treenodeptr arvore)
{
	int i = 0;
	float media1 = 0;  // soma dos elementos da arvore
	mediaPosOrdem(arvore, media1, i);
	
	// calculo da media
	media1 = media1 / i;
	
	return media1;
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
	float m;  // soma dos valores da arvore

	// entrada de dados na arvore
	cin >> x;
	while(x != -1){
		aux = x;
		tInsere(arvore, aux);  // insere os elemento na arvore

		cin >> x;
	}
	
	// chamando a função que realiza a soma dos valores da arvore
	m = media(arvore);
	
	// saida da media
	cout << fixed << setprecision(2);
	cout << "media: " <<  m << endl;
	
	// deletando os dados da arvore
	tDestruir(arvore);
	
	return 0;
}
