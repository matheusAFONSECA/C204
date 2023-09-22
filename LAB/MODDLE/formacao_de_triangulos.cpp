#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct ponto
{
	float x;
	float y;
};
typedef ponto vetor;

vetor cria_vetor(ponto A, ponto B)
{
	vetor AB;
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	return AB;
}

float vetorial(vetor A, vetor B)
{
	float v;
	v = A.x * B.y - A.y * B.x;
	return v;
}

float escalar(vetor A, vetor B)
{
	float e;
	e = A.x * B.x + A.y * B.y;
	return e;
}

float area_triangulo(ponto A, ponto B, ponto C)
{
	vetor AB;
	vetor AC;
	float area;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	area = fabs(vetorial(AB, AC)) / 2;
	return area;
}

// vetorial = 0 os pontos são colineares e n podemos fazer um triângulo

int main()
{
	// declaração de var
	int n;  // quantidade de triangulos
	ponto A, B, C;  // pontos de um triangulo
	int i;  // contador
	float area[100];  // area dos triangulos

	// entrada da quantidade de pontos
	cin >> n;

	// entrada dos pontos do(s) triangulo(s)
	for(i = 0; i < n; i++)
	{
		cin >> A.x >> A.y;
		cin >> B.x >> B.y;
		cin >> C.x >> C.y;

		// chamada da função que calcula a area do triangulo
		area[i] = area_triangulo(A, B, C);
	}

	// saida das areas ou definição de nao formacao de triangulo
	for(i = 0; i < n; i++)
	{
		if(area[i] == 0)
			cout << "Nao formam triangulo" << endl;
		else{
			cout << fixed << setprecision(2);
			cout << area[i] << endl;
		}
	}

	return 0;
}
