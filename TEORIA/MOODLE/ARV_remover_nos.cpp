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

treenodeptr tMenor(treenodeptr &raiz)  // funcao que retorna o menor valor da arvore do lado direito
{
	treenodeptr t;
	t = raiz;
	if (t->esq == NULL) // encontrou o menor valor
	{
		raiz = raiz->dir;
		return t;
	}
	else  // continua a busca na subarvore esquerda
		return tMenor(raiz->esq);
}

int tRemove(treenodeptr &raiz, int x)  // funcao que romove o NÓ da arvore e realoca NULL ou outro NÓ
{
	/*
	-> A funcao retorna 0 caso tenha ocorrido sucesso
	-> Caso nao tenha conseguido remover retorna 1
	*/
	treenodeptr p;
	if (raiz == NULL) // arvore vazia
		return 1;
	if (x == raiz->info)
	{
		p = raiz;
		if (raiz->esq == NULL) // a raiz nao tem filho esquerdo
			raiz = raiz->dir;
		else if (raiz->dir == NULL) // a raiz nao tem filho direito
			raiz = raiz->esq;
		else // a raiz tem ambos os filhos
		{
			p = tMenor(raiz->dir);
			raiz->info = p->info;
		}
		delete p;

		return 0;
	}
	else if (x < raiz->info)
		return tRemove(raiz->esq, x);
	else
		return tRemove(raiz->dir, x);
}

void emOrdem (treenodeptr arvore)  // mostra os elemento em ordem crescente
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq);
		cout << arvore->info << " ";
		emOrdem(arvore->dir);
	}

}

int main()
{
	// declaração de var
	treenodeptr arvore = NULL;  // ponteiro apontando para a raiz da arvore
	/*
	-> Sempre apontar para NULL, se não o código da errado
	porque não poderemos inserir os valores na arvore
	*/
	int x;  // var que sera removida da arvore
	int aux;  // var aux de entrada de valores na arvore
	int resultado;  // guarda a resposta retonada pela funcao
	/*
	-> Caso a função retorne 0 = removeu o elemento
	-> Caso a função retorne 1 = não removeu o elemento
	*/

	// inserindo valores na arvore
	cin >> aux;
	while(aux != 0)
	{
		tInsere(arvore, aux);
		cin >> aux;
	}

	// entrada do valor que sera removido da arvore
	cin >> x;

	// chamada de funcao que realiza a remocao do elemento x
	resultado = tRemove(arvore, x);
	while(resultado == 0)
	{
		resultado = tRemove(arvore, x);  // garante a remocao de todos os elementos x
	}

	// saida de dados
	emOrdem(arvore);
	cout << endl;

	// deletando os dados da arvore
	tDestruir(arvore);

	return 0;
}
