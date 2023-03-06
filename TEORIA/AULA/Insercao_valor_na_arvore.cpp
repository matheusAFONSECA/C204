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

int main()
{
	treenodeptr arvore = NULL;  // ponteiro apontando para a raiz da arvore
								/*
								-> Sempre apontar para NULL, se não o código da errado
								porque não poderemos inserir os valores na arvore
								*/
	
	treenodeptr p;  // ponteiro aux
	int x;  // aux para a entrada de dados
	
	cin >> x;
	
	// inserindo valores na arvore
	while(x != 0)
	{
		tInsere(arvore, x);  // inserindo elementos na arvore
		cin >> x;
	}
	
	// "navegando" pelos nós da arvore
	p = arvore;
	
	cout << "Raiz: " << p->info << endl;
 
    p = p->esq;
    
    cout << p->info << endl;

	p = p->dir;
    
    cout << p->info << endl;
		
	return 0;
}