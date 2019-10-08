#include<iostream>
#include<new>
#include<math.h>

using std::cin; using std::cout; using std::nothrow;

float e = 2.7182818284590;
float a, d0, d1, d2, e1, e2, fd0, fd1, fd2, raiz, d_d0, d2_d1;

//Módulo
float module(float x){
    if (x < 0) {
        x = x*(-1);
    }
    return x;
}

//Funcao
/*float funcao(float a, float d){
    float x = pow(e, d);
    float y = pow(d, 2);
    float funcao = a*x - 4*y;
    return funcao;
}
*/
float funcao(float a, float d){
    float funcao = pow(d, 3) - 9*d + 3;
    return funcao;
}


//X1 lisho
float new_d2(float d0, float d1) {
    float new_d2 = d1 - fd1/((fd1-fd0)/(d1-d0));
    return new_d2;
}

//main²
float pls(void){
    int iterMax, k;
    cin >> a;
    cin >> d0;
    cin >> d1;
    cin >> e1;
    cin >> e2;
    cin >> iterMax;
    fd0 = funcao(a, d0);
    if (module(fd0) < e1){
        raiz = d0;
        cout << '\n' << raiz;
        return 0;
    }
    fd1 = funcao(a, d1);
    d_d0 = d1 - d0;
    if ((module(fd1) < e1) || (module(d_d0) < e2)){
        raiz = d1;
        cout << '\n' << raiz;
        return 0;
    }
    k = 1;
    for ( ; ; ){
        fd0 = funcao(a, d0);
        fd1 = funcao(a, d1);
        d2 = new_d2(d0, d1);
        fd2 = funcao(a, d2);
        cout << '\n' << d2;
        cout << '\n' << k;
        cout << '\n' << funcao(a, d2);
        d2_d1 = d2 - d1;
        if ((module(fd2) < e1) || module(d2_d1) < e2 || k >= iterMax){
            raiz = d2;
            cout << '\n' << raiz;
            return 0;
        }
        d0 = d1;
        d1 = d2;
        k = k + 1;
    } 
    return 0;
}

//cleyton rasta
int main(void) {
    pls();
}

