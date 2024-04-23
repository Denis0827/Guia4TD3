#include <iostream>
#include <string>
#include <vector>
using namespace std;

int productoria_aux(const vector<int> & v, int desde, int hasta) {
    if (desde == hasta-1) {
        return v[desde];
    } else if (desde == hasta-2) {
        return v[desde] * v[hasta-1];
    } else if (desde == hasta-3) {
        return v[desde] * v[hasta-1] * v[hasta-2];
    }
    else {
        int medio = desde + (hasta - desde) / 3;
        int medio2 = medio + (hasta - desde) / 3;
        int a = productoria_aux(v, desde, medio);
        int b = productoria_aux(v, medio, medio2);
        int c = productoria_aux(v, medio2, hasta);
        return a * b * c;
    }
}

int productoria(const vector<int> &v) {
    return productoria_aux(v, 0, v.size());
}

int main() {
    vector<int> a = {2, 2, 2, 2, 2, 2};
   
    int res_a = productoria(a);
    cout << "La productoria es " << res_a << endl;
    
}