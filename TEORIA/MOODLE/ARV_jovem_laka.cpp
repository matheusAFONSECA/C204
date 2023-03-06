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

void posicaoPreOrdem (treenodeptr arvore, int &PRE, int cidade, int &x)  // posicao da cidade pelo percurso pre-ordem
{
	if (arvore != NULL)
	{
		if(arvore->info == cidade)
			x = PRE;
		else
			PRE++;
		posicaoPreOrdem(arvore->esq, PRE, cidade, x);
		posicaoPreOrdem(arvore->dir, PRE, cidade, x);
	}
}

void posicaoEmOrdem (treenodeptr arvore, int &EM, int cidade, int &x)  // posicao da cidade pelo percurso em-ordem
{
	if (arvore != NULL)
	{
		posicaoEmOrdem(arvore->esq, EM, cidade, x);
		if(arvore->info == cidade)
			x = EM;
		else
			EM++;
		posicaoEmOrdem(arvore->dir, EM, cidade, x);
	}
}

void posicaoPosOrdem (treenodeptr arvore, int &POS, int cidade, int &x)  // posicao da cidade pelo percurso pos-ordem
{
	if (arvore != NULL)
	{
		posicaoPosOrdem(arvore->esq, POS, cidade, x);
		posicaoPosOrdem(arvore->dir, POS, cidade, x);
		if(arvore->info == cidade)
			x = POS;
		else
			POS++;
	}
}

int melhorCaminho(treenodeptr arvore, int cidade)  // funcao que retorna o melhor caminho
{
	int PRE = 0;  // posicao da cidade no percurso de pre-ordem
	int EM = 0;   // posicao da cidade no percurso de em-ordem
	int POS = 0;  // posicao da cidade no percurso de pos-ordem
	int aux = 0;  // var aux

	// chamada de funcoes aux de posicao da cidade nos percursos
	posicaoPreOrdem(arvore, PRE, cidade, aux);
	PRE = aux;
	posicaoEmOrdem(arvore, EM, cidade, aux);
	EM = aux;
	posicaoPosOrdem(arvore, POS, cidade, aux);
	POS = aux;

	if(PRE < POS && PRE < EM)   // caso em que em-ordem eh mais perto
		aux = 1;
	else if(EM < POS && EM < PRE)  // caso em que em-ordem eh mais perto
		aux = 2;
	else if(POS < PRE && POS < EM)   // caso em que em-ordem eh mais perto
		aux = 3;
	
	return aux;
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
	int cidade;  // cidade onde esta o chocolate
	int melhor;  // melhor caminho

	// entrada de dados na arvore
	cin >> x;
	while(x != -1)
	{
		aux = x;
		tInsere(arvore, aux);

		cin >> x;
	}

	// entrada da cidade
	cin >> cidade;

	// chamada de função de busca do melhor caminho
	melhor = melhorCaminho(arvore, cidade);

	// saida de dados
	// 1 = Pre, 2 = Em, 3 = Pos
	if(melhor == 1)
	{
		cout << "Pre" << endl;
	}
	else if(melhor == 2)
	{
		cout << "Em" << endl;
	}
	else if(melhor == 3)
	{
		cout << "Pos" << endl;
	}

	// deletando os dados da arvore
	tDestruir(arvore);

	return 0;
}
