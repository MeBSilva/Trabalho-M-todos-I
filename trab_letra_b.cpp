#include<iostream>
#include<new>
#include<math.h>
using std::cin; using std::cout; using std::nothrow;

float e = 2.7182818284590;
float a, d0, d1, e1, e2, fd, fdd, raiz, d_d0;

//Módulo
float module(float x){
    if (x < 0) {
        x = x*(-1);
    }
    return x;
}

//Funcao
float funcao(float a, float d){
    float x = pow(e, d);
    float y = pow(d, 2);
    float funcao = a*x - 4*y;
    return funcao;
}

//Derivada
float derivada(float a, float d){
    float derivada = a*(pow(e, d)) - 8*d;
    return derivada;
}

//X1 lisho
float new_d1(float d0) {
    float new_d1 = d0 - fd/fdd;
    return new_d1;
}

//main²
float pls(void){
    int iterMax, k;
    cin >> a;
    cin >> d0;
    cin >> e1;
    cin >> e2;
    cin >> iterMax;
    fd = funcao(a, d0);
    fdd = derivada(a, d0);
    if (module(fd) < e1){
        raiz = d0;
        cout << '\n' << raiz;
        return 0;
    }
    k = 1;
    for ( ; ; ){
        d1 = new_d1(d0);
        fd = funcao(a, d1);
        /*fdd = derivada(a, d1);*/ //sapoha é constante
        cout << '\n' << d1;
        cout << '\n' << k;
        cout << '\n' << funcao(a, d1);
        d_d0 = d1 - d0;
        if ((module(fd) < e1) || module(d_d0) < e2 || k >= iterMax){
            raiz = d1;
            cout << '\n' << raiz;
            return 0;
        }
        d0 = d1;
        k = k + 1;
    } 
    return 0;
}

//cleyton rasta
int main(void) {
    pls();
}

