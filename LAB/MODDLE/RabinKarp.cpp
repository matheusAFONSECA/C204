#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

void rabin_karp(char T[], char P[], int tamT, int tamP, int d, int q)
{

	int h; // valor utilizado para calculo de hash
	int p = 0; // padrao convertido para inteiro
	int t = 0; // texto convertido para inteiro
	int ultima = -1;  // ultima ocorrencia
	int k = 0;  // quantidade de vezes que achou-se o padrão

	for(int i = 0; i < tamP; i++)
	{
		p = (d * p + (P[i] - '0')) % q; // converte o padrao
		t = (d * t + (T[i] - '0')) % q; // converte o texto para o primeiro valor (t0)
	}

	h = (int)pow(d, tamP - 1) % q; // utilizado para calculo de hash

	for(int i = 0; i <= tamT - tamP; i++)
	{
		if(p == t) // Se encontrei um valor de hash valido
		{
			// Verifico se ha diferencas
			int j;
			for(j = 0; j < tamP; j++)
			{
				if(P[j] != T[i + j])
				{
					break;
				}
			}

			if(j == tamP){
				ultima = i;  // define a ultima posicao de ocorrencia do padrão
				k++;  // incremento na quantidade de ocorrências
			}
		}

		if(i < tamT - tamP) // se ainda nao cheguei no final
		{
			t = (d * ( t - (T[i] - '0') * h ) + (T[i + tamP] - '0')) % q; // atualizo o ti para ti+1
			if(t < 0) t += q;
		}
	}
	
	if(ultima != -1)
		cout << "Ultima ocorrencia: " << ultima << endl;
	
	cout << k << " ocorrencia(s)" << endl;	

}

int main()
{
	// declaração de var
	char texto[100];  // texto a ser procurado o padrao
	char padrao[100];  // padrao que sera procurado no texto
	int M;  // quantidade de caracteres do padrão
	int N;  // quantidade de caracteres do texto
	int i;  // contador

	// cardinalidade do alfabeto usado no texto, em outras palavras, qtd de caracteres diferentes utilizados
	int d = 10;
	// n?mero primo grande, para calcular os valores no hash
	int q = 13;

	// entrada da quantidade de caracteres do texto e do padrao
	do
	{
		cin >> N;
	}
	while(N < 0 && N > 100);
	
	do
	{
		cin >> M;
	}
	while(N < 0 && N > 100);
	
	// entrada do texto e do padrao
	cin >> texto;
	cin >> padrao;

	rabin_karp(texto, padrao, strlen(texto), strlen(padrao), d, q);

	return 0;
}
