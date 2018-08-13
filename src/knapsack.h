
#include <string>
#include <utility>
#include <ostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int,int> Item;

class Knapsack{

	private :

	unsigned int size_mochila;

	vector<Item> n_items;


	public :

	Knapsack(int capacidad_m, vector<Item> items);

	int capacidadMochila();

	vector<Item> items();

	pair<int,int> FuerzaBruta();

	void FuerzaBrutaRecur(int paso, int &pesoActual, int &benefAct, int &benefMax, int &contadorRecur);

	pair<int,int> BTpodaFactibilidad();

	void BTpodaFactRecur(int paso, int &pesoActual, int &benefAct, int &benefMax, int &contadorRecur);

	int DynamicProgramming();


};