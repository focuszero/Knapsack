#include "knapsack.h"

typedef pair<int,int> Item;

//Métodos Públicos

//constructor de knapsack, genera un problema de la mochila con parametros dados de capacidad y de item con sus respectivos pesos y beneficios
Knapsack::Knapsack(int m, vector<Item> items){

	size_mochila = m;
	n_items = items;
}

//dada una instancia de Knapsack, devuelve la capacidad W de la mochila
int Knapsack::capacidadMochila(){
	return size_mochila;
}

//dada una instancia de Knapsack, devuelve un vector con los ítems a seleccionar para meter en la mochila
vector<Item> Knapsack::items(){
	return n_items;
}

/* Backtracking para fuerza bruta, adentro llamo a una auxiliar FuerzaBrutaRecur que calcula la solución
	de forma recursiva	*/

pair<int,int> Knapsack::FuerzaBruta(){
	int benefMax = 0;
	int pesoAct = 0;
	int paso = 0;
	int benefAct = 0;
	int contadorRecur = 0;
	Knapsack::FuerzaBrutaRecur(paso, pesoAct, benefAct, benefMax, contadorRecur);
	return make_pair(benefMax,contadorRecur);

}
/* La recursión para fuerza bruta, el paso representa el número de item 
   "paso-1" para el que decido si meter o no, pesoActual es un parámetro que guarda el peso total de los ítems
   de la solución parcial, benefActual guarda el beneficio total de los ítems de mi solución parcial,
   benefMax es una variable que guarda el beneficio máximo de las soluciones recorridas hasta el momento,
   contadoRecur cuenta cuántas llamadas recursivas se hacen
*/
void Knapsack::FuerzaBrutaRecur(int paso, int &pesoActual, int &benefActual, int &benefMax, int &contadorRecur){

	if(paso == this->items().size()){
		if((pesoActual <= this->Knapsack::capacidadMochila()) && (benefActual > benefMax)){
			benefMax = benefActual;
		}

	}else{
			contadorRecur = contadorRecur + 2;
			FuerzaBrutaRecur(paso + 1, pesoActual, benefActual, benefMax, contadorRecur);
			int pesoActualizado = pesoActual + (this->items()[paso]).first;
			int benefActualizado = benefActual + (this->items()[paso]).second;
			FuerzaBrutaRecur(paso + 1, pesoActualizado, benefActualizado, benefMax, contadorRecur);
	}
}

	/* Backtracking con poda de factibilidad, adentro llamo a una auxiliar BTPodaFactRecur que calcula la solución
	de forma recursiva	*/

pair<int,int> Knapsack::BTpodaFactibilidad(){
	int benefMax = 0;
	int pesoAct = 0;
	int paso = 0;
	int benefAct = 0;
	int contadorRecur = 0;
	Knapsack::BTpodaFactRecur(paso, pesoAct, benefAct, benefMax, contadorRecur);
	return make_pair(benefMax,contadorRecur);
}

/* La recursión para backtracking con poda de factibilidad, el paso representa el número de item 
   "paso-1" para el que decido si meter o no, pesoActual es un parámetro que guarda el peso total de los ítems
   de la solución parcial, benefActual guarda el beneficio total de los ítems de mi solución parcial,
   benefMax es una variable que guarda el beneficio máximo de las soluciones recorridas hasta el momento,
   contadoRecur cuenta cuántas llamadas recursivas se hacen
*/
void Knapsack::BTpodaFactRecur(int paso, int &pesoActual, int &benefActual, int &benefMax, int &contadorRecur){

	if(paso == this->items().size()){
		if(benefActual > benefMax){
			benefMax = benefActual;
		}

	}else{
		if(pesoActual + (this->items()[paso]).first <= this->capacidadMochila()){
			contadorRecur = contadorRecur + 2;
			BTpodaFactRecur(paso + 1, pesoActual, benefActual, benefMax, contadorRecur);
			int pesoActualizado = pesoActual + (this->items()[paso]).first;
			int benefActualizado = benefActual + (this->items()[paso]).second;
			BTpodaFactRecur(paso + 1, pesoActualizado, benefActualizado, benefMax, contadorRecur);
		}else{
			contadorRecur++;
			BTpodaFactRecur(paso + 1, pesoActual, benefActual, benefMax, contadorRecur);
		}
	}
}

/* programacion dinamica "bottom-up", guardo los valores en una matriz de (n+1)*(W+1)
*/
int Knapsack::DynamicProgramming(){
	int tamMochi = this->Knapsack::capacidadMochila();
	int cantItems = this->Knapsack::items().size();
	vector <vector<int> > matrizDynamic;
	for(int i = 0; i <= cantItems; i++){
			vector<int> filaI;
		for(int j = 0 ; j <= tamMochi; j++){
			filaI.push_back(0);
		}
		matrizDynamic.push_back(filaI);
	}
	//método bottom-up
   for (int i = 0; i <= cantItems; i++){
       for (int j = 0; j <= tamMochi; j++){
           if(i==0 || j==0){
               matrizDynamic[i][j] = 0;
           }else if (this->Knapsack::items()[i-1].first <= j){
                 matrizDynamic[i][j] = max(this->Knapsack::items()[i-1].second + matrizDynamic[i-1][j-this->Knapsack::items()[i-1].first], matrizDynamic[i-1][j]);
           }else{
                 matrizDynamic[i][j] = matrizDynamic[i-1][j];
       	   }
       	}   
    }   
 
   return matrizDynamic[cantItems][tamMochi];
}

//Funciones Auxiliares

//función que devuelve el máximo entre dos números
int max(int a, int b){
	int res = b;
	if(a > b){
		res = a;
	}
	return res;
}

