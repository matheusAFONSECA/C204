#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

struct treenode
{
	float info;
	treenode *esq;
	treenode *dir;
};

typedef treenode* treenodeptr;  // redefinindo treenode como um ponteiro

void tInsere(treenodeptr &p, float x)  // funcao que insere um valor na arvore
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

float calcMedia(treenodeptr arvore)  // retorna a media das folhas da arvore
{
	// declaração de var
	float soma;  // funcao que guarda a soma das variáveis
	int i;  // contador
	list<treenodeptr> q; // fila auxiliar
	treenodeptr n = arvore; // ponteiro para varrer a árvore

	soma = 0;
	i = 0;
	if (arvore != NULL)
	{
		q.push_front(n);
		while (!q.empty())
		{
			n = q.front();
			q.pop_front();
			if (n->esq != NULL)
				q.push_back(n->esq);
			if (n->dir != NULL)
				q.push_back(n->dir);
			if(n->esq == NULL && n->dir == NULL)
			{
				soma = soma + n->info;  // vai somando os elementos conforme faz o
				// percurso em nivel
				i++;  // incremento na quantidade de elementos
			}
		}
	}

	// calculo da media
	soma = soma / i;

	return soma;
}

int main()
{
	// declaração de var
	treenodeptr arvore = NULL;  // ponteiro apontando para a raiz da arvore
	/*
	-> Sempre apontar para NULL, se não o código da errado
	porque não poderemos inserir os valores na arvore
	*/
	float x;  // var aux p/ leitura
	float aux;  // var aux de entrada de valores na arvore
	float m;  // media dos valores da arvore

	// entrada de dados na arvore
	cin >> x;
	while(x != -1)
	{
		aux = x;
		tInsere(arvore, aux);  // insere os elemento na arvore

		cin >> x;
	}

	// chamando a função que realiza a soma dos valores da arvore e retorna a media
	m = calcMedia(arvore);

	// saida da media
	cout << fixed << setprecision(2);
	cout << "media = " <<  m << endl;

	// deletando os dados da arvore
	tDestruir(arvore);

	return 0;
}
