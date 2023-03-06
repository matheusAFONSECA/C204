#include <iostream>
#include <iomanip>

using namespace std;

struct dados{
	// declara��o de var
	int nota1;  // nota da prova 1
	int nota2;  // nota da prova 2
    int nota3;  // nota da prova 3
	int nota4;  // nota da prova 4
	float media;  // guarda a m�dia das provas
};

int main(){
	// declara��o de var
    dados *v;  // fazendo um ponteiro que faz aloca��o din�mica de mem�ria
    
    v = new dados;
    
    //entrada das notas
    cin >> v->nota1 >> v->nota2 >> v->nota3 >> v->nota4;

    // calculo e sa�da da media do aluno
    v->media =  (v->nota1 + v->nota2 + v->nota3 +  v->nota4)/4.0;
    cout << fixed << setprecision(2);
    cout << v->media << endl;
    
    delete[] v;
    
    return 0;
}