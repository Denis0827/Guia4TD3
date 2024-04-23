#include <iostream>
#include <string>
#include <vector>
using namespace std;

int suma(vector<int> v, int desde, int hasta) {
    if(desde == hasta-1) {
        return v[desde];
    } 
    else {
        int medio = (desde + hasta) / 2;
        int a = suma(v, desde, medio);
        int b = suma(v, medio, hasta);
        return a + b;
    }
}

bool mas_a_la_izquierda_aux( vector<int> v, int desde, int hasta ) {
    if (desde == hasta-2) {
        if (v[desde] > v[hasta-1]) {
            return true;
        } else {
            return false;
        }
    }
    else {
        int medio = (desde + hasta) / 2;
        if (suma(v, desde, medio) > suma(v, medio, hasta)) {
            bool a = mas_a_la_izquierda_aux(v, desde, medio);
            bool b = mas_a_la_izquierda_aux(v, medio, hasta);
            return true && a && b;
        } else {
            return false;
        }
    }
}

bool mas_a_la_izquierda(vector<int> v) {
    return mas_a_la_izquierda_aux(v, 0, v.size());
}

int main() {
    vector<int> a = {4, 2, 3, 7};
    bool res_a = mas_a_la_izquierda(a);
    if(res_a == true) {
        cout << "Esta mas a la izquierda." << endl;
    } else {
        cout << "No esta mas a la izquierda." << endl;
    }
}