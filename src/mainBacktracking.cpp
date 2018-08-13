#include <iostream>
#include "knapsack.h"

using namespace std;


int main(){
    
    int capacidad;
    int cantItems;
    vector<pair<int,int> > items;

    cin >> cantItems >> capacidad ;

    for(int j = 1; j <= cantItems; j++){
        int pesoI;
        int beneficioI;
        cin >> pesoI >> beneficioI ;
        items.push_back(make_pair(pesoI, beneficioI));
    }

    Knapsack mochila = Knapsack(capacidad, items);

     cout << mochila.Knapsack::BTpodaFactibilidad().first << endl;
    

    return 0;
}