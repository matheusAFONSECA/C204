#include <iostream>
#include <iomanip>

using namespace std;

struct dados
{
	// declaração de var
	int nota1;  // nota da prova 1
	int nota2;  // nota da prova 2
	int nota3;  // nota da prova 3
	int nota4;  // nota da prova 4
	float media;  // guarda a média das provas
};

int main()
{
	// declaração de var
	int tam;  // define a quantidade de entradas
	dados *v;  // fazendo um ponteiro que faz alocação dinâmica de memória
	int i;  // contador
	float media_geral = 0;  // calcula a media geral dos alunos

	//entrada da quantidade de pessoas
	cin >> tam;

	//definindo o tamnho do vetor
	v = new dados[tam];

	//entrada das notas
	for(i = 0; i < tam; i++)
	{
		cin >> v[i].nota1 >> v[i].nota2 >> v[i].nota3 >> v[i].nota4;
		v[i].media =  (v[i].nota1 + v[i].nota2 + v[i].nota3 +  v[i].nota4) / 4.0;
	}

	// calculo e saida da media geral
	for(i = 0; i < tam; i++)
		media_geral = media_geral + v[i].media;
    media_geral = media_geral/tam;
	cout << fixed << setprecision(2);
	cout << media_geral << endl;

	// delentando a memória
	delete[] v;

	return 0;
}
