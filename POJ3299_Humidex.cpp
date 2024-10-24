//POJ 3299 Humidex 
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double DH2T(double D, double H){
    double tmp = 5417.753000 / 273.160000;
    double e = 6.110000 * exp(tmp * D / (D + 273.160000));
    double h = 0.555500 * (e - 10.000000);
    double T = H - h;
    return T;
}

double DT2H(double D, double T){
    double tmp = 5417.753000 / 273.160000;
    double e = 6.110000 * exp(tmp * D / (D + 273.160000));
    double h = 0.555500 * (e - 10.000000);
    double H = T + h;
    return H;
}

double TH2D(double T, double H){
    double h = H - T;
    double e = h / 0.555500 + 10.000000;
    double exp_index = log(e / 6.110000);
    double D = 1.000000 / (1.000000 / 273.160000 - exp_index / 5417.7530000) - 273.160000;
    return D;
}

int main(){
    char c1, c2;
    double n1, n2;
    double T, H, D;
    cin>>c1;
    while (c1 != 'E'){
        cin>>n1>>c2>>n2;

        if(c1 == 'T' && c2 == 'D'){
            T = n1;
            D = n2;
            H = DT2H(D, T);
        }

        else if(c1 == 'D' && c2 == 'T'){
            D = n1;
            T = n2;
            H = DT2H(D, T);
        }


        else if(c1 == 'D' && c2 == 'H'){
            D = n1;
            H = n2;
            T = DH2T(D, H);
        }

        else if(c1 == 'H' && c2 == 'D'){
            H = n1;
            D = n2;
            T = DH2T(D, H);
        }

        else if(c1 == 'T' && c2 == 'H'){
            T = n1;
            H = n2;
            D = TH2D(T, H);
        }

        else if(c1 == 'H' && c2 == 'T'){
            H = n1;
            T = n2;
            D = TH2D(T, H);
        }

        printf("T %.1lf D %.1lf H %.1lf\n", T, D, H);

        cin>>c1;
    }
    

    return 0;
}
