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

// vetorial = 0 os pontos s�o colineares e n podemos fazer um tri�ngulo

int main()
{
	// declara��o de var
	ponto A, B, C;  // pontos de um triangulo
	float area;  // area do triangulo

	// entrada dos pontos do(s) triangulo(s)
	cin >> A.x >> A.y;
	cin >> B.x >> B.y;
	cin >> C.x >> C.y;

	// chamada da fun��o que calcula a area do triangulo
	area = area_triangulo(A, B, C);

	// saida das areas ou defini��o de nao formacao de triangulo
	if(area > 1)
		cout << "GOL!" << endl;
	else
	{
		cout << fixed << setprecision(2);
		cout << "NAO GOL!" << endl;
	}

	return 0;
}
