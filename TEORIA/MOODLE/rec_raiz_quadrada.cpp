#include <iostream>
#include <iomanip>
using namespace std;

double potencia(double a, int n){  //fun��o que calcula a pot�ncia
	if(n == 0)  //caso em que o expoente vale 0
		return 1;
	else
		return a * potencia(a, n-1);
}

double raiz(int x, double x0, double e){  //fun��o recursiva que calcula a raiz
	double aux, aux1;  //var aux
	
	aux = (potencia(x0,2) - x);
	if(aux < 0)
		aux = aux * (-1);
	
	aux1 = (potencia(x0,2) + x) / (2*x0);
	
	if(aux <= e)
		return x0;
	else 
		return raiz(x, aux1, e);
}

int main(){
	//declara��o de vari�veis
	int x;  // base
	double x0;  // estimativa incial para raiz de x
	double e;  // limitante superior para o erro
	
	//entrada de dados
	cin >> x >> x0 >> e;
	
	//chamada de fun��o e sa�da de dados
	cout << fixed << setprecision(4);
	cout << raiz(x, x0, e) << endl;
	
	return 0;
}