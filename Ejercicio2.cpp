#include <iostream>
#include <string>
#include <vector>
using namespace std;

int productoria(const vector<int> &v) {
      if ( v.size() == 1 ) {
            return v[0];
      } else {
            vector<int> eliminar_ultimo = {v.begin(), v.end()-1};
            return v[v.size() - 1] * productoria(eliminar_ultimo);
      }
}

int cantidad_ocurrencias(string s, const vector<string> &v) {
      if ( v.size() == 1 ) {
            if ( v[0] == s) {
                  return 1;
            } else {
                  return 0;
            }
      }
      else {
            vector<string> eliminar_ultimo = {v.begin(), v.end()-1};
            if ( v[v.size() - 1] == s ) {
                  return 1 + cantidad_ocurrencias(s, eliminar_ultimo); 
            } else {
                  return 0 + cantidad_ocurrencias(s, eliminar_ultimo);
            }
      }
}

int contar_coincidencias(const vector<int> &v) {
      if ( v.size() == 1 ) {
            if ( v[0] == 0 ) {
                  return 1;
            } else {
                  return 0;
            }
      }
      else {
            vector<int> eliminar_ultimo = {v.begin(), v.end()-1};
            if ( v[v.size()-1] == v.size()-1 ) {
                  return 1 + contar_coincidencias(eliminar_ultimo);
            } else {
                  return 0 + contar_coincidencias(eliminar_ultimo);
            }
      }
}

vector<int> agregar_elem_ultimo(int elem, vector<int> v) {
      vector<int> res = {};

      int i = 0;
      while(i < v.size()) {
            res.push_back(v[i]);
            i = i + 1;
      }

      res.push_back(elem);

      return res;
}

vector<int> solo_positivos(const vector<int> &v) {
      if ( v.size() == 1 ) {
            if ( v[0] > 0 ) {
                  return {v[0]};
            } else {
                  return {}; 
            }
      }
      else {
            vector<int> eliminar_ultimo = {v.begin(), v.end()-1};
            if ( v[v.size()-1] > 0 ) {
                  return agregar_elem_ultimo(v[v.size()-1], solo_positivos(eliminar_ultimo));
            } else {
                  return solo_positivos(eliminar_ultimo);
            }
      }
}

void multiplicar_todos(vector<int> &v, int n) {
      if ( v.size() == 1 ) {
            v[0] = v[0] * n;
            return ;
      } 
      else {
            v[v.size()-1] = v[v.size()-1] * n;
            v.pop_back(); // Por qué me sigue funcionando?
            multiplicar_todos(v, n);
            return ;
      }
}


int main() {
    vector<int> a = {1, 2, 3, 4};
    int res_a = productoria(a);
    cout << "La productoria es " << res_a << endl;

    vector<string> b = {"Hola", "Chau", "Hola", "Hola"};
    int res_b = cantidad_ocurrencias("Hola", b);
    cout << "La cantidad de ocurrencias es " << res_b << endl;

    vector<int> c = {0, 1, 2, 4, 5};
    int res_c = contar_coincidencias(c);
    cout << "Contar coincidencias es " << res_c << endl;

    vector<int> d = {-1, 2, 4, 5, -2, -3};
    vector<int> res_d = solo_positivos(d);
    cout << "El vector con solo positivos es " << res_d[0] << ", " << res_d[1] << ", " << res_d[2] << endl;

    vector<int> e = {1, 2, 4};
    multiplicar_todos(e, 2);
    cout << "El vector multiplicado queda: " << e[0] << ", " << e[1] << ", " << e[2] << endl;
}