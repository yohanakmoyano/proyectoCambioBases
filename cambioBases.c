#include <math.h>
#include "convert.h"
#include <stdlib.h>
#include <stdio.h>

//--------Métodos de conversión----------

void ayuda(){
     printf("-User commands \n");
        printf("\n");
        //Nombre
        printf("NOMBRE\n");
        printf("Convert aplicacion\n");
        printf("\n");
        //Synopsis
        printf("SYNOPSIS\n");
        printf("Modo de empleo: convert -n<number> [-s <source_base>] [-d <dest_base>] [-v] [-h] \n");
        printf("\n");
        //Descripcion
        printf("DESCRIPCION\n");
        printf("-n  numero que desea convertir\n");
        printf("-s  base origen que esta expresado el numero\n");
        printf("-d  base destino que desea convertir\n");
        printf("-h  muestra esta ayuda y sale del programa\n");
        printf("-v  muestra los computos intermedios que se realizaron en el proceso de conversion\n");
        printf("\n");
}

/*
    Retorna el resultado de la conversión utilizando el método de la división
    para la parte entera.
*/

char * division_partEnt(char * cadenaEnt,int origen, int destino, int pasos){

    if(pasos==1){
        printf("\n");
        printf("----------------------------------------- \n");
        printf("Parte Entera resuelta con el metodo de la division \n");
    }

    char *cadena_retornar =  (char *) malloc(10 * sizeof(char));
    //char *cadena_retornar = malloc(sizeof(4));
    int retornar[10];
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

    if(pasos==1){
        printf("Dividimos el numero por la base destino tantas veces como sea posible, y me quedo con el resto \n");
    }

    for(int z=0; z<10 && resultado!=0; z++){

        resultado=num/destino;

        resto=num%destino;

        retornar[z]=resto;

        if(pasos==1){
            printf("result = %i / %i : %i, con resto: %i \n",num,destino,resultado,resto);
        }

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

char * division_partEntAuxiliar(int decimal,int destino,int pasos){

    if(pasos==1){
        printf("\n");
        printf("----------------------------------------- \n");
        printf("Parte Entera resuelta con el metodo de la division \n");
    }
    char *cadena_retornar =  (char *) malloc(10 * sizeof(char));
    //char *cadena_retornar = malloc(sizeof(4));
    int retornar[10];

    int resultado=1;
    int resto=0;
    int cantArreglo=0;

    if(pasos==1){
        printf("Dividimos el numero por la base destino tantas veces como sea posible, y me quedo con el resto \n");
    }

    for(int z=0; z<10 && resultado!=0; z++){
        resultado=decimal/destino;
        //printf("El resultado es: %i \n",resultado);
        resto=decimal%destino;
        //printf("El resto es: %i \n",resto);
        retornar[z]=resto;

        //num seria decimal?
        if(pasos==1){
            printf("result = %i / %i : %i, con resto: %i \n",decimal,destino,resultado,resto);
        }
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
int multiplicacion_partEnt(char * cadenaEnt,int origen, int pasos){

    if(pasos==1){
        printf("\n");
        printf("----------------------------------------- \n");
        printf("Parte Entera resuelta con el metodo de la multiplicacion \n");
    }
    int suma=0;
    int sumaParcial=0;
    char caracter=0;
    int cant=0;
    int j=0;
    int multExp = 0;

    while(cadenaEnt[j]!='\0'){
        cant++;
        j++;
    }
    if(pasos==1){
        printf("Multiplicamos cada numero por la base origen, elevado a la posicion del numero y sumo todo los resultados \n");
    }
    int exponente=cant-1;
    int i=0;
    //agregado para ayuda
    int sumaAnterior=0;

    while(cadenaEnt[i]!='\0'){
        caracter=cadenaEnt[i];
        sumaAnterior = suma;

        if(caracter=='a' || caracter=='A'){
            sumaParcial=pow(origen,exponente);
            multExp = 10*sumaParcial;
            suma=suma + multExp;
        }

        if(caracter=='b' || caracter=='B'){
            sumaParcial=pow(origen,exponente);
            multExp = 11*sumaParcial;
            suma=suma + multExp;
        }

        if(caracter=='c' || caracter=='C'){
            sumaParcial=pow(origen,exponente);
            multExp = 12*sumaParcial;
            suma=suma + multExp;
        }

        if(caracter=='d' || caracter=='D'){
            sumaParcial=pow(origen,exponente);
            multExp = 13*sumaParcial;
            suma=suma + multExp;;
        }

        if(caracter=='e' || caracter=='E'){
            sumaParcial=pow(origen,exponente);
            multExp = 14*sumaParcial;
            suma=suma + multExp;;
        }

        if(caracter=='f' || caracter=='F'){
            sumaParcial=pow(origen,exponente);
            multExp = 15*sumaParcial;
            suma=suma + multExp;
        }

        if(caracter>='0' && caracter<='9'){
            sumaParcial=pow(origen,exponente);
            int num = caracter - '0';
            multExp = num*sumaParcial;
            suma=suma + multExp;
        }

        if(pasos==1){
            printf("result = %c * %i^(%i) : %i  ---- ",caracter,origen,exponente,multExp);
            printf("suma total: %i + %i: %i \n",sumaAnterior,multExp,suma);
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
char * multiplicacion_partFrac(char * cadenaFrac,int origen, int destino, int pasos){

    if(pasos==1){
        printf("\n");
        printf("----------------------------------------- \n");
        printf("Parte Fraccionaria resuelta con el metodo de la multiplicacion \n");
    }
    char *cadena_retornar = (char *) malloc(5 * sizeof(char));
    //char *cadena_retornar = malloc(sizeof(4));
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
    int retornar[5];

    if(pasos==1){
        printf("Tomo el numero y lo multiplico por la base destino. Me quedo con la parte entera del resultado. \n");
        printf("Al resultado le resto la parte entera y vuelvo a multiplicar por la base\n");
    }

    for(int i=0;i<5;i++){
        resultado=num_convertir*destino;

        pe=(int)resultado;
        pf=resultado-pe;
        retornar[i]=pe;
        num_convertir=pf;

        if(pasos==1){

            printf("result : %f * %i = %f",num_convertir,destino,resultado);
            printf("------>%i \n",pe);
            printf("numero = %f - %i = %f",resultado,pe,pf);
            printf("\n");
        }

    }

    for(int k=0;k<5;k++){
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
char * multiplicacion_partFracAuxiliar(double decimal,int destino, int pasos){

    if(pasos==1){
        printf("\n");
        printf("----------------------------------------- \n");
        printf("Parte Fraccionaria resuelta con el metodo de la multiplicacion \n");
    }
    char *cadena_retornar =  (char *) malloc(5 * sizeof(char));
    //char *cadena_retornar = malloc(sizeof(4));
    int pe=0;
    double pf=0.0;
    double resultado=0;
    int retornar[5];

    if(pasos==1){
        printf("Tomo el numero y lo multiplico por la base destino. Me quedo con la parte entera del resultado. \n");
        printf("Al resultado le resto la parte entera y vuelvo a multiplicar por la base\n");
    }

    for(int i=0;i<5;i++){
        resultado=decimal*destino;

        pe=(int)resultado;
        pf=resultado-pe;
        retornar[i]=pe;
        decimal=pf;

        if(pasos==1){

            printf("result : %f * %i = %f",decimal,destino,resultado);
            printf("------>%i \n",pe);
            printf("numero = %f - %i = %f",resultado,pe,pf);
            printf("\n");
        }
    }

    for(int k=0;k<5;k++){
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
double division_partFrac(char * cadenaFrac, int origen, int destino, int pasos){

    if(pasos==1){
        printf("\n");
        printf("----------------------------------------- \n");
        printf("Parte Fraccionaria resuelta con el método de la división \n");
    }
    double suma=0.0;
    double sumaParcial=0;
    double sumaAnterior = 0;
    char caracter=0;
    int exponente=1;
    int i=0;


    if(pasos==1){
       printf("Dividimos cada numero decimal por la base origen, elevado a la posicion del numero negativo y sumo todo los resultados \n");
    }

    while(cadenaFrac[i]!='\0'){
        caracter=cadenaFrac[i];

        sumaAnterior = suma;

        if(caracter=='a' || caracter=='A'){
            sumaParcial=pow(origen,exponente);
            sumaParcial = 10/sumaParcial;
            suma=suma + sumaParcial;
        }

        if(caracter=='b' || caracter=='B'){
            sumaParcial=pow(origen,exponente);
            sumaParcial = 11/sumaParcial;
            suma=suma + sumaParcial;
        }

        if(caracter=='c' || caracter=='C'){
            sumaParcial=pow(origen,exponente);
            sumaParcial = 12/sumaParcial;
            suma=suma + sumaParcial;
        }

        if(caracter=='d' || caracter=='D'){
            sumaParcial=pow(origen,exponente);
            sumaParcial = 13/sumaParcial;
            suma=suma + sumaParcial;
        }

        if(caracter=='e' || caracter=='E'){
            sumaParcial=pow(origen,exponente);
            sumaParcial = 14/sumaParcial;
            suma=suma + sumaParcial;
        }

        if(caracter=='f' || caracter=='F'){
            sumaParcial=pow(origen,exponente);
            sumaParcial = 15/sumaParcial;
            suma=suma + sumaParcial;
        }

        if(caracter>='0' && caracter<='9'){
            sumaParcial=pow(origen,exponente);
            int num = caracter - '0';
            sumaParcial = num/sumaParcial;
            //este division esta de mas?
            double division= sumaParcial;
            suma= suma + (division);
        }

        if(pasos==1){
            printf("result = %c * %i^(-%i) : %f  ---- ",caracter,origen,exponente,sumaParcial);
            printf("suma total: %f + %f= %f \n",sumaAnterior,sumaParcial,suma);
        }

        i++;
        exponente++;
    }
    return suma;
}
