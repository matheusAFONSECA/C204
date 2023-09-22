#include <iostream>
#include <cstring>

using namespace std;

void calcula_LPS(int lps[], char P[], int tamP)
{
	// tamanho do maior prefixo que tambem eh sufixo anterior
    int tam = 0;
    
	lps[0] = 0; // caso base
	
    // o loop calcula lps[i] para i = 1 ate tamP-1 
    int i = 1; 
    while (i < tamP)
	{ 
        if (P[i] == P[tam]) // se encontrar uma letra que bate tanto como prefixo quanto como sufixo
		{
            tam++; // aumento o tamanho do maior prefixo que tambem eh sufixo
            lps[i] = tam; // salvo o valor para esse prefixo
            i++; // vou para o proximo prefixo
        } 
        else // (p[i] != p[tam]) se encontrar uma letra que nao bate como prefixo e sufixo
        {
            if (tam != 0) // se o tamanho do maior prefixo que tambem eh sufixo atual for diferente de 0
			{
                tam = lps[tam - 1]; // volto pro maior prefixo que tambem eh sufixo considerando o prefixo anterior
                // Note que neste caso nao incrementamos o 'i'
			}
            else // se o tamanho do maior prefixo que tambem eh sufixo atual for 0
            { 
                lps[i] = 0; // o maior prefixo que tambem é prefixo agora vale 0
                i++; // vou para o proximo prefixo
            } 
        } 
    }			
}

void kmp(char T[], char P[],int tamT, int tamP)
{
	int lps[tamP]; // vetor que indica para onde voltarei no padrao quando ocorrer um mismatch
				   // lps -> indica o tamanho do maior sufixo de p[0...i] que tambem eh prefixo de p[0...i] (exceto a string inteira)
	
	calcula_LPS(lps, P, tamP);
	
    int j = 0;  // j eh tamanho do meu match atual, ONDE EU ESTOU NO MEU PADRAO
    int i = 0;  // posicao no texto
    int k = 0;  // contador de quantidade
    
    while(i < tamT)
	{
        if(T[i] == P[j]) // match
		{
			j++;
			i++;
			if(j == tamP) // encontrei o padrao no texto na posicao (i-tamP) até i
			{
			   	j = lps[j-1];
			   	k++;  // incremento de quantidade
		   	}
		}
		else // mismatch
		{
			if(j != 0) // se ocorreu mismatch depois de j matchs
				j = lps[j-1];
			else // mismatch na comparacao da primeira letra
				i++;
		}
		
    }
    
    if(k == 1)
    	cout << P << ": " << k << " VEZ" << endl;
    if(k > 1)
    	cout << P << ": " << k << " VEZES" << endl;
    if(k == 0)
    	cout << P << " NAO APARECE NA MUSICA" << endl;
}

 

int main(){
//    KMP ENCONTRA PADRÃO NO TEXTO
//    MAIOR PREFIXO QUE BATE COM O SUFIXO , QUE NAO SAO DO MSM TAMANHO
	char P[100]; // P -> padrao

	// texto base
    char T[] = "(POKEMON! TEMOS QUE PEGAR) ISSO EU SEI PEGA-LOS EU TENTAREI! (POKEMON!) JUNTOS TEREMOS QUE O MUNDO DEFENDER! POKEMON! (TEMOS QUE PEGA-LOS) ISSO EU SEI PEGA-LOS EU TENTAREI VAI SER GRANDE A EMOCAO POKEMON! TEMOS QUE PEGAR TEMOS QUE PEGAR!";
    
    cin.getline(P, 100);  // entrada do padrão
	if(strlen(P) != 1)  // condição para fazer a pesquisa do padrao
		kmp(T, P,strlen(T),strlen(P));
	
    while(strlen(P) != 1)
	{
		cin.getline(P, 100);  // entrada do padrão
		
		if(strlen(P) != 1)  // condição para fazer a pesquisa do padrao
    		kmp(T, P,strlen(T),strlen(P));
	}
    
    return 0;
}