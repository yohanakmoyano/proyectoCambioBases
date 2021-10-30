#include <math.h>
#include "convert.h"
#include <stdlib.h>
#include <stdio.h>

//--------Métodos de conversión----------


/*
    Retorna el resultado de la conversión utilizando el método de la división
    para la parte entera.
*/

char * division_partEnt(char * cadenaEnt,int origen, int destino){

    char *cadena_retornar = malloc(sizeof(4));
    int retornar[4];

    int num=0;
    int cant=0;
    int entero=0;
    int r=0;
    int q=0;

    while(cadenaEnt[r]!='\0'){
        cant++;
        r++;
    }

    while(cadenaEnt[q]!='\0'){
        entero=cadenaEnt[q]-'0';
        num=num+entero*pow(10,cant-1);
        cant--;
        q++;
    }

    int resultado=1;
    int resto=0;
    int cantArreglo=0;
    for(int z=0; z<5 && resultado!=0; z++){
        resultado=num/destino;
        resto=num%destino;
        retornar[z]=resto;
        num=resultado;
        cantArreglo++;
    }

    int s=0;
    for(int j=cantArreglo-1;j>=0;j--){
        if(retornar[j]==10) {
            cadena_retornar[s]=65;
        }

        if(retornar[j]==11) {
            cadena_retornar[s]=66;

        }

        if(retornar[j]==12) {
            cadena_retornar[s]=67;
        }

        if(retornar[j]==13) {
            cadena_retornar[s]=68;
        }

        if(retornar[j]==14) {
            cadena_retornar[s]=69;
        }

        if(retornar[j]==15) {
            cadena_retornar[s]=70;
        }

        if(retornar[j]==1) {
            cadena_retornar[s]=49;
        }

        if(retornar[j]==2) {
            cadena_retornar[s]=50;
        }

        if(retornar[j]==3) {
            cadena_retornar[s]=51;
        }

        if(retornar[j]==4) {
            cadena_retornar[s]=52;
        }

        if(retornar[j]==5) {
            cadena_retornar[s]=53;
        }

        if(retornar[j]==6) {
            cadena_retornar[s]=54;
        }

        if(retornar[j]==7) {
            cadena_retornar[s]=55;
        }

        if(retornar[j]==8) {
            cadena_retornar[s]=56;
        }

        if(retornar[j]==9) {
            cadena_retornar[s]=57;
        }

        s++;
      }

    return cadena_retornar;
}

//ParteEnteraAuxiliar

char * division_partEntAuxiliar(int decimal,int destino){

    char *cadena_retornar = malloc(sizeof(4));
    int retornar[4];

    int resultado=1;
    int resto=0;
    int cantArreglo=0;

    for(int z=0; z<5 && resultado!=0; z++){
        resultado=decimal/destino;
        //printf("El resultado es: %i \n",resultado);
        resto=decimal%destino;
        //printf("El resto es: %i \n",resto);
        retornar[z]=resto;
        decimal=resultado;
        cantArreglo++;
    }

    int s=0;
    for(int j=cantArreglo-1;j>=0;j--){
        if(retornar[j]==10) {
            cadena_retornar[s]=65;
        }

        if(retornar[j]==11) {
            cadena_retornar[s]=66;

        }

        if(retornar[j]==12) {
            cadena_retornar[s]=67;
        }

        if(retornar[j]==13) {
            cadena_retornar[s]=68;
        }

        if(retornar[j]==14) {
            cadena_retornar[s]=69;
        }

        if(retornar[j]==15) {
            cadena_retornar[s]=70;
        }

        if(retornar[j]==1) {
            cadena_retornar[s]=49;
        }

        if(retornar[j]==2) {
            cadena_retornar[s]=50;
        }

        if(retornar[j]==3) {
            cadena_retornar[s]=51;
        }

        if(retornar[j]==4) {
            cadena_retornar[s]=52;
        }

        if(retornar[j]==5) {
            cadena_retornar[s]=53;
        }

        if(retornar[j]==6) {
            cadena_retornar[s]=54;
        }

        if(retornar[j]==7) {
            cadena_retornar[s]=55;
        }

        if(retornar[j]==8) {
            cadena_retornar[s]=56;
        }

        if(retornar[j]==9) {
            cadena_retornar[s]=57;
        }

        s++;
      }

    return cadena_retornar;

}



/*
    Retorna el resultado de la conversión utilizando el método de la multiplicación
    para la parte entera.
*/
int multiplicacion_partEnt(char * cadenaEnt,int origen){

    int suma=0;
    int sumaParcial=0;
    char caracter=0;
    int cant=0;
    int j=0;

    while(cadenaEnt[j]!='\0'){
        cant++;
        j++;
    }

    int exponente=cant-1;
    int i=0;

    while(cadenaEnt[i]!='\0'){
        caracter=cadenaEnt[i];

        if(caracter=='a' || caracter=='A'){
            sumaParcial=pow(origen,exponente);
            suma=suma+ 10*sumaParcial;
        }

        if(caracter=='b' || caracter=='B'){
            sumaParcial=pow(origen,exponente);
            suma=suma+ 11*sumaParcial;
        }

        if(caracter=='c' || caracter=='C'){
            sumaParcial=pow(origen,exponente);
            suma=suma+ 12*sumaParcial;
        }

        if(caracter=='d' || caracter=='D'){
            sumaParcial=pow(origen,exponente);
            suma=suma+ 13*sumaParcial;
        }

        if(caracter=='e' || caracter=='E'){
            sumaParcial=pow(origen,exponente);
            suma=suma+ 14*sumaParcial;
        }

        if(caracter=='f' || caracter=='F'){
            sumaParcial=pow(origen,exponente);
            suma=suma+ 15*sumaParcial;
        }

        if(caracter>='0' && caracter<='9'){
            sumaParcial=pow(origen,exponente);
            int num = caracter - '0';
            suma=suma+(num*sumaParcial);
        }

        i++;
        exponente--;
    }

    return suma;
}

/*
    Retorna el resultado de la conversión utilizando el método de la multiplicación
    para la parte fraccionaria.
*/
char * multiplicacion_partFrac(char * cadenaFrac,int origen, int destino){

    char *cadena_retornar = malloc(sizeof(4));
    int cant=0;
    int cantDig=0;
    int j=0;

    while(cadenaFrac[j]!='\0'){
        cant++;
        cantDig++;
        j++;
    }

    int q=0;
    int entero=0;
    int num=0;

    while(cadenaFrac[q]!='\0'){
        entero=cadenaFrac[q]-'0';
        num=num+entero*pow(10,cant-1);
        cant--;
        q++;
    }

    double num_convertir=num*pow(10,-cantDig);

    int pe=0;
    double pf=0.0;
    double resultado=0;
    int retornar[4];

    for(int i=0;i<4;i++){
        resultado=num_convertir*destino;

        pe=(int)resultado;
        pf=resultado-pe;
        retornar[i]=pe;
        num_convertir=pf;
    }

    for(int k=0;k<4;k++){
        if(retornar[k]==10) {
            cadena_retornar[k]=65;
        }

        if(retornar[k]==11) {
            cadena_retornar[k]=66;
        }

        if(retornar[k]==12) {
            cadena_retornar[k]=67;
        }

        if(retornar[k]==13) {
            cadena_retornar[k]=68;
        }

        if(retornar[k]==14) {
            cadena_retornar[k]=69;
        }

        if(retornar[k]==15) {
            cadena_retornar[k]=70;
        }

        if(retornar[k]==1) {
            cadena_retornar[k]=49;
        }

        if(retornar[k]==2) {
            cadena_retornar[k]=50;
        }

        if(retornar[k]==3) {
            cadena_retornar[k]=51;
        }

        if(retornar[k]==4) {
            cadena_retornar[k]=52;
        }

        if(retornar[k]==5) {
            cadena_retornar[k]=53;
        }

        if(retornar[k]==6) {
            cadena_retornar[k]=54;
        }

        if(retornar[k]==7) {
            cadena_retornar[k]=55;
        }

        if(retornar[k]==8) {
            cadena_retornar[k]=56;
        }

        if(retornar[k]==9) {
            cadena_retornar[k]=57;
        }
    }

    return cadena_retornar;
}

//Metodo Auxiliar
char * multiplicacion_partFracAuxiliar(double decimal,int destino){

    char *cadena_retornar = malloc(sizeof(4));
    printf("el decimal ingresado es %f \n",decimal);

    int pe=0;
    double pf=0.0;
    double resultado=0;
    int retornar[4];

    for(int i=0;i<4;i++){
        resultado=decimal*destino;

        pe=(int)resultado;
        pf=resultado-pe;
        retornar[i]=pe;
        decimal=pf;
    }

    for(int k=0;k<4;k++){
        if(retornar[k]==10) {
            cadena_retornar[k]=65;
        }

        if(retornar[k]==11) {
            cadena_retornar[k]=66;
        }

        if(retornar[k]==12) {
            cadena_retornar[k]=67;
        }

        if(retornar[k]==13) {
            cadena_retornar[k]=68;
        }

        if(retornar[k]==14) {
            cadena_retornar[k]=69;
        }

        if(retornar[k]==15) {
            cadena_retornar[k]=70;
        }

        if(retornar[k]==1) {
            cadena_retornar[k]=49;
        }

        if(retornar[k]==2) {
            cadena_retornar[k]=50;
        }

        if(retornar[k]==3) {
            cadena_retornar[k]=51;
        }

        if(retornar[k]==4) {
            cadena_retornar[k]=52;
        }

        if(retornar[k]==5) {
            cadena_retornar[k]=53;
        }

        if(retornar[k]==6) {
            cadena_retornar[k]=54;
        }

        if(retornar[k]==7) {
            cadena_retornar[k]=55;
        }

        if(retornar[k]==8) {
            cadena_retornar[k]=56;
        }

        if(retornar[k]==9) {
            cadena_retornar[k]=57;
        }
    }

    return cadena_retornar;

}

/*
    Retorna el resultado de la conversión utilizando el método de la división
    para la parte fraccionaria.
*/
double division_partFrac(char * cadenaFrac, int origen, int destino){

    double suma=0.0;
    double sumaParcial=0;
    char caracter=0;
    int exponente=1;
    int i=0;

    while(cadenaFrac[i]!='\0'){
        caracter=cadenaFrac[i];

        if(caracter=='a' || caracter=='A'){
            sumaParcial=pow(origen,exponente);
            suma=suma+(10/sumaParcial);
        }

        if(caracter=='b' || caracter=='B'){
            sumaParcial=pow(origen,exponente);
            suma=suma+ (11/sumaParcial);
        }

        if(caracter=='c' || caracter=='C'){
            sumaParcial=pow(origen,exponente);
            suma=suma+(12/sumaParcial);
        }

        if(caracter=='d' || caracter=='D'){
            sumaParcial=pow(origen,exponente);
            suma=suma+(13/sumaParcial);
        }

        if(caracter=='e' || caracter=='E'){
            sumaParcial=pow(origen,exponente);
            suma=suma+ (14/sumaParcial);
        }

        if(caracter=='f' || caracter=='F'){
            sumaParcial=pow(origen,exponente);
            suma=suma+(15/sumaParcial);
        }

        if(caracter>='0' && caracter<='9'){
            sumaParcial=pow(origen,exponente);
            int num = caracter - '0';
            double division=num/sumaParcial;
            suma=suma+(division);
        }

        i++;
        exponente++;
    }
    return suma;
}
