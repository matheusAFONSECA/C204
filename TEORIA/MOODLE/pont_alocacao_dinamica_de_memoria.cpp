#include <iostream>
#include <iomanip>

using namespace std;

struct dados{
	// declaração de var
	int nota1;  // nota da prova 1
	int nota2;  // nota da prova 2
    int nota3;  // nota da prova 3
	int nota4;  // nota da prova 4
	float media;  // guarda a média das provas
};

int main(){
	// declaração de var
    dados *v;  // fazendo um ponteiro que faz alocação dinâmica de memória
    
    v = new dados;
    
    //entrada das notas
    cin >> v->nota1 >> v->nota2 >> v->nota3 >> v->nota4;

    // calculo e saída da media do aluno
    v->media =  (v->nota1 + v->nota2 + v->nota3 +  v->nota4)/4.0;
    cout << fixed << setprecision(2);
    cout << v->media << endl;
    
    delete[] v;
    
    return 0;
}