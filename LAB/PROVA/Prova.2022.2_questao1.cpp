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
	ponto H, V, P1, P2;  // H -> Heroi, V -> Vilao, P1 -> ponto 1 e P2 -> ponto 2 
	float area;  // area do triangulo

	// entrada das coordenadas do heroi, vilao e dos dois pontos de acao do poder
	cin >> H.x >> H.y;
	cin >> V.x >> V.y;
	cin >> P1.x >> P1.y;
	cin >> P2.x >> P2.y;
	
	// chamada da função que calcula a area do triangulo
	area = area_triangulo(H, P1, P2);
	/*
	-> Se a area do trinagulo for menor ou igual a 1 o vilao nao pode ser derrotado
	*/

	if(area > 1)  // condicao que o vilao eh derrotado
		cout << "Vilao derrotado" << endl;
	else
	{
		cout << "Chame reforcos" << endl;
	}

	return 0;
}
