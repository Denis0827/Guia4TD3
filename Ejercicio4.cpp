#include <iostream>
#include <string>
#include <vector>
using namespace std;

int potencia_aux(int n, int desde, int hasta) {
      if (desde == hasta - 1) {
            return n;
      }
      else {
            int medio = (desde + hasta) / 2;
            int a = potencia_aux(n, desde, medio);
            int b = potencia_aux(n, medio, hasta);
            return a * b;
      }
}

int potencia(int n, int m) {
    return potencia_aux(n, 0, m);
}

int montaña_aux( vector<int> v, int desde, int hasta) {
    if ( v[desde] < v[desde + 1] && v[desde + 1] > v[desde + 2] ) {
        return v[desde + 1];
    }
    else {
        int medio = (desde + hasta) / 2;
        return montaña_aux(v, medio-1, hasta);
    }
}

int montaña(vector<int> v) {
    return montaña_aux(v, 0, v.size());
}

int main() {
    int res_a = potencia(2, 4);
    cout << "La potencia es " << res_a << endl;

    vector<int> b = {1, 2, 3, 4, 5, 6, 7, 2, 1};
    int res_b = montaña(b);
    cout << "El pico de la montaña es: " << res_b << endl;
}

