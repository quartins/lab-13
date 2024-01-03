#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double keep[],int n,double output[]){
    double arithemtic = 0 ,stand = 0,geometric = 1 ,harmonic = 0,max=keep[0] ,min = keep[0];
    for( int i = 0; i < n ; i++)
    {
        arithemtic += keep[i];
        geometric *= keep[i];
        harmonic += 1/keep[i];
        if(keep[i]>max) max = keep[i];
        else if(keep[i]<min) min = keep[i];
    }
    
    output[0] = arithemtic/n;

    for( int i = 0; i < n ; i++)
    {
        stand += pow(keep[i] - output[0], 2);
    }

    output[1] = sqrt(stand/n);
    output[2] = pow(geometric,1.0/n);
    output[3] = n/harmonic;
    output[4] = max ;
    output[5] = min ;

}