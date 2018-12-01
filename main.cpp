/*
*/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

void promedio();

int main()
{
   promedio();
}

void promedio(){
    ifstream txt ("numeros.txt", ios::in);
    string nota;
    double nota_f=0 ,suma=0, prom=0, prom2=0, mediana=0,  m1=0, m2=0, moda=0;
    //marca de clase de los intervalos
    double mc1=(1,0+1,9)/2.0; //1,45
    double mc2=(2,0+2,9)/2.0; //2,45
    double mc3=(3,0+3,9)/2.0; //3,45
    double mc4=(4,0+4,9)/2.0; //4,45
    double mc5=(5,0+5,9)/2.0; //5,45
    double mc6=(6,0+7,0)/2.0; //6,5
    long long c=0, c1=0, c2=0 , c3=0, c4=0, c5=0, c6=0, d1=0, d2=0;
    while(!txt.eof()){
        txt >> nota;
        nota[1]='.';
        nota_f = (double)atof(nota.c_str());
        suma = suma + nota_f;
        c++;
        //calculo la frecuencias de los intervalos
        if (nota_f == 1.0 || nota_f == 1.1 || nota_f == 1.2 || nota_f == 1.3 || nota_f == 1.4 || nota_f == 1.5 || nota_f == 1.6 || nota_f == 1.7 || nota_f == 1.8 || nota_f == 1.9 ){
            c1++;
        }
        if (nota_f == 2.0 || nota_f == 2.1 || nota_f == 2.2 || nota_f == 2.3 || nota_f == 2.4 || nota_f == 2.5 || nota_f == 2.6 || nota_f == 2.7 || nota_f == 2.8 || nota_f == 2.9 ){
            c2++;
        }
        if (nota_f == 3.0 || nota_f == 3.1 || nota_f == 3.2 || nota_f == 3.3 || nota_f == 3.4 || nota_f == 3.5 || nota_f == 3.6 || nota_f == 3.7 || nota_f == 3.8 || nota_f == 3.9 ){
            c3++;
        }
        if (nota_f == 4.0 || nota_f == 4.1 || nota_f == 4.2 || nota_f == 4.3 || nota_f == 4.4 || nota_f == 4.5 || nota_f == 4.6 || nota_f == 4.7 || nota_f == 4.8 || nota_f == 4.9 ){
            c4++;
        }
        if (nota_f == 5.0 || nota_f == 5.1 || nota_f == 5.2 || nota_f == 5.3 || nota_f == 5.4 || nota_f == 5.5 || nota_f == 5.6 || nota_f == 5.7 || nota_f == 5.8 || nota_f == 5.9 ){
            c5++;
        }
        if (nota_f == 6.0 || nota_f == 6.1 || nota_f == 6.2 || nota_f == 6.3 || nota_f == 6.4 || nota_f == 1.5 || nota_f == 1.6 || nota_f == 1.7 || nota_f == 1.8 || nota_f == 6.9 ||  nota_f == 7.0 ){
            c6++;
        }

    }
    txt.close();
    prom = (suma/c);
    //promedio con marca de clase
    prom2 = (double)( (mc1*c1) + (mc2*c2) + (mc3*c3) + (mc4*c4) + (mc5*c5) + (mc6*c6) )/c;
    //f_acumulada = (c1+c2+c3+c4+c5+c6);
    //delta de la mediana
    m1 = (double)(c/2);//frecuencia total/2
    m2 = (double)(c1+c2+c3);//frecuencia acumulada anterior
    mediana =  4,0 + 0.9*((double)(m1- m2)/c4); //formula del formulario estadistica utem
    //delta para calcular la moda
    d1= c6-c5;//frecuencia en el intervalo - la frecuancia anterior
    d2= c6-0; //frecuencia en el intervalor + la frecuencia del proxima
    moda = 6.0 + 1.0*( (double)d1/(d1+d2) ); //formula del formulario estadistica utem
    cout << "suma total de elementos ===> " << suma << endl;
    cout << "cantidad total de elementos ===> " << c << endl;
    cout << "promedio total de elementos ===> " << prom << endl;
    cout << "promedio todal utilizando marca de clase: " << prom2 << endl;
    cout << "frecuencia de notas rango 1.0 - 1,9 ===> " << c1 << endl;
    //cout << "porcentaje rango 1.0 - 1.9 ===> " << (c1*100)/c << endl <<endl; //15.8348%
    cout << "frecuencia de notas rango 2.0 - 2,9 ===> " << c2 << endl;
    //cout << "porcentaje rango 2.0 - 2.9 ===> " << (c2*100)/c; << endl << endl; //16.6658%
    cout << "frecuencia de notas rango 3.0 - 3,9 ===> " << c3 << endl;
    //cout << "porcentaje rango 3.0 - 3.9 ===> " << (c3*100)/c; << endl << endl; //16.6659%
    cout << "frecuencia de notas rango 4.0 - 4,9 ===> " << c4 << endl;
    //cout << "porcentaje rango 4.0 - 4.9 ===> " << (c4*100)/c; << endl << endl; //16.6673% se encuentra el 50% => 65.83%
    cout << "frecuencia de notas rango 5.0 - 5,9 ===> " << c5 << endl;
    //cout << "porcentaje rango 6.0 - 6.9 ===> " << (c5*100)/c; << endl << endl; //16.6675
    cout << "frecuencia de notas rango 6.0 - 7,0 ===> " << c6 << endl; // aqui se encuentra la moda
    //cout << "porcentaje rango 2.0 - 2.9 ===> " << (c6*100)/c; << endl << endl; //17.5005
    cout << "mediana de los elementos ===> " << mediana << endl; //5.004
    cout << "moda de los elementos ===> " << moda << endl;
}
