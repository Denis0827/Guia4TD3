#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cantidad_ocurrencias_aux(string s, const vector<string> &v, int desde, int hasta) {
      if ( desde == hasta - 1  ) {
            if ( v[desde] == s) {
                  return 1;
            } else {
                  return 0;
            }
      }
      else {
            int medio = (desde + hasta) / 2; 
            int a = cantidad_ocurrencias_aux(s, v, desde, medio); 
            int b = cantidad_ocurrencias_aux(s, v, medio, hasta); 
            return a + b;
      }
}

int cantidad_ocurrencias(string s, const vector<string> &v) {
    return cantidad_ocurrencias_aux(s, v, 0, v.size());
}

void multiplicar_todos_aux(vector<int> &v, int n, int desde, int hasta) {
      if ( desde == hasta - 1 ) {
            v[desde] = v[desde] * n;
            return ;
      } 
      else {
            int medio = (desde + hasta) / 2;
            multiplicar_todos_aux(v, n, desde, medio);
            multiplicar_todos_aux(v, n, medio, hasta);
            return ;
      }
}

void multiplicar_todos(vector<int> &v, int n) {
    return multiplicar_todos_aux(v, n, 0, v.size());
}


int main() {
    vector<string> b = {"Hola", "Chau", "Hola", "Hola"};
    int res_b = cantidad_ocurrencias("Hola", b);
    cout << "La cantidad de ocurrencias es " << res_b << endl;
    
    vector<int> e = {1, 2, 4};
    multiplicar_todos(e, 2);
    cout << "El vector multiplicado queda: " << e[0] << ", " << e[1] << ", " << e[2] << endl;
}
