#include <list>

void emNivel(treenodeptr t)  // funcao que mostra o percurso por niveis da arvore
{
	treenodeptr n;
	list <treenodeptr> q;
	
	if(t != NULL)
	{
		q.push_back(t);
		while(q.empty() != true)
		{
			n = *q.begin();
			q.pop_front();
			if(n->esq != NULL)
				q.push_back(n->esq);
			if(n->dir != NULL)
				q.push_back(n->dir);
			
			cout << n->info << endl;
		}
	}
}