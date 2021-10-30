#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "convert.h"
#include "constantes.h"
#include <string.h>

/*
    Programa convert. Convierte el número recibido por parámetro -n <number> desde la base origen
     -s <source_base> a la base destino -d <dest_base>. El parámetro -v muestra cómputos intermedios.
     El parámetro -h muestra una ayuda.
*/
int main(int argc,char * argv[])
{
    char cd[10];
    char *cad = cd;
    char cbo[3];
    char *cadena_baseOrigen=cbo;
    char cbd[3];
    char *cadena_baseDestino=cbd;
    char pe[3];
    char *parteEntera = pe;
    char pf[5];
    char *parteFrac = pf;
    int num_baseOrigen=0;
    int cant_baseOrigen=0;
    int num_baseDestino=0;
    int cant_baseDestino=0;
    int bo = 0;
    int bd = 0;
    int entero_baseOrigen=0;
    int i=0;
    int j=0;
    int k=0;
    int m=0;
    int corte = 0;
    int entero_baseDestino=0;
    int contEnt = 0;
    int contFrac = 0;
    double div_pf=0.0;
    int mult_pe=0;
    double resultado=0.0;
    char *mult_pf;
    char *div_pe;
    int enteroDecimal=0;
    char rpe[10];
    char *retornar_parteEntera=rpe;
    double decimal_pf=0.0;
    char rpf[10];
    char *retornar_parteFraccionaria=rpf;
    int z=0;

    int longitud = 0;
    int x=0;

    while(argv[x]!=NULL){
       longitud++;
       x++;
    }

    printf("la longitud del arreglo es: %i \n",longitud);

    while(argv[z]!=NULL){

        if(strcmp(argv[z], "-n")==0){ //Si encuentro -n
            if(z==longitud-1){
                cad=NULL;
            }
            else{
                if (strcmp(argv[z+1], "-d") ==0 || strcmp(argv[z+1], "-s")==0 || strcmp(argv[z+1], "-v")==0 || strcmp(argv[z+1], "-h")==0) {
                  cad=NULL;
                }
                else {
                    cad=(argv[z+1]);
                }
            }

            printf("Lo que hay en cad es: %s \n",cad);
        }

        if(strcmp(argv[z], "-s")==0){
            if(z==longitud-1){
                cadena_baseOrigen=NULL;
            }
            else{
                if( strcmp(argv[z+1], "-d")==0 || strcmp(argv[z+1], "-n")==0 || strcmp(argv[z+1], "-v")==0 || strcmp(argv[z+1], "-h")==0 ){
                    cadena_baseOrigen=NULL;
                }else{
                    cadena_baseOrigen=(argv[z+1]);
                }
            }

            printf("Lo que hay en cadena_baseOrigen es: %s \n",cadena_baseOrigen);
        }

        if(strcmp(argv[z], "-d")==0){
            if(z==longitud-1){
                cadena_baseDestino=NULL;
            }else{
                    if( strcmp(argv[z+1], "-s")==0 || strcmp(argv[z+1], "-n")==0 || strcmp(argv[z+1], "-v")==0 || strcmp(argv[z+1], "-h")==0 ){
                        cadena_baseDestino=NULL;
                    }else{
                        cadena_baseDestino=(argv[z+1]);
                    }
            }


            printf("Lo que hay en cadena_BaseDestino es: %s \n",cadena_baseDestino);
        }

        //el if para el -v

        //el if para el -h
       //longitud++;
       z++;
    }

    printf("Holi \n");



    //Verifico si hay cadena para el parámetro -n

    if(cad==NULL) {
        printf("No se ingreso ningun numero para convertir \n");
        exit(EXIT_FAILURE);
    }


    /*
       Este método separa la cadena del número ingresado en parte entera y parte fraccionaria.
    */

    //Retorna la parte entera del número.
    while(cad[i]!='\0' && corte != 1 ){
        if (cad[i]=='.'){
            corte=1;
        }else{
            parteEntera[i]=cad[i];
            i++;
            contEnt++;
        }

    }

    //Retorna la parte fraccionaria del número.
    if(cad[i]=='.'){
        i++;
        while(cad[i]!='\0'){
            parteFrac[j]=cad[i];
            i++;
            j++;
            contFrac++;
        }
    }

    /*
        Controla la correcta cantidad de digitos en la parte entera.
    */
    if(contEnt>10){
        printf("La cantidad maxima de digitos enteros es 10. Vuelva a introducir su numero. \n");
        exit(EXIT_FAILURE);
    }

    /*
        Controla la correcta cantidad de digitos en la parte fraccionaria.
    */
    if(contFrac>5){
        printf("La cantidad maxima de digitos fraccionarios es 5. Vuelva a introducir su numero. \n");
        exit(EXIT_FAILURE);
    }



    //---------------BaseOrigen-----------------------------

    if(cadena_baseOrigen==NULL){
        num_baseOrigen=10;
    }else{
        /*
        Cuenta la cantidad de dígitos que tiene la cadena de caracteres base origen ingresada.
        */

        while(cadena_baseOrigen[bo]!='\0'){
            cant_baseOrigen++;
            bo++;
        }

        /*
        Convierte la cadena de base origen, en entero.
        */

        while(cadena_baseOrigen[k]!='\0'){
            entero_baseOrigen = cadena_baseOrigen[k]-'0';
            num_baseOrigen = num_baseOrigen+entero_baseOrigen*pow(10,cant_baseOrigen-1);
            cant_baseOrigen--;
            k++;
        }
    }

    printf("La base origen es %i \n", num_baseOrigen);

    /*
        Controla que la base origen ingresada sea correcta.
    */
      if(num_baseOrigen < 2 || num_baseOrigen > 16){
        printf("La base origen esta mal ingreada. Vuelva a introducir su numero. \n");
        exit(ERROR_EXCEDIDO_BASE_ORIGEN);
    }


    //---------------BaseDestino-----------------------------

    if(cadena_baseDestino==NULL){
        num_baseDestino=10;
    }else{

        /*
        Cuenta la cantidad de dígitos que tiene la cadena de caracteres base destino ingresada.
        */
        while(cadena_baseDestino[bd]!='\0'){
            cant_baseDestino++;
            bd++;
        }

        /*
        Convierte la cadena de base destino, en entero.
        */
        while(cadena_baseDestino[m]!='\0'){
            entero_baseDestino = cadena_baseDestino[m]-'0';
            num_baseDestino = num_baseDestino+entero_baseDestino*pow(10,cant_baseDestino-1);
            cant_baseDestino--;
            m++;
        }
    }

    printf("La base destino es %i \n", num_baseDestino);

    /*
        Controla que la base destino ingresada sea correcta.
    */
    if( num_baseDestino < 2 || num_baseDestino > 16){
        printf("La base destino esta mal ingresada. Vuelva a introducir su numero. \n");
        exit(ERROR_EXCEDIDO_BASE_DESTINO);
    }

    printf("La cadena de parte entera es %s \n", parteEntera);
    printf("La cadena de parte fraccionaria es %s \n", parteFrac);

    //------------Conversión de bases--------------------------

    /*
        Invoca a los métodos de CambioBases y retorna el valor de la conversión del número.
    */
    if(num_baseOrigen==10){
        mult_pf=multiplicacion_partFrac(parteFrac,num_baseOrigen,num_baseDestino);
        printf("La parte fraccionaria es: %s \n",mult_pf);
        div_pe=division_partEnt(parteEntera, num_baseOrigen, num_baseDestino);
        printf("La parte entera es: %s \n",div_pe);
        printf("El resultado es: %s \n",strcat(div_pe,mult_pf));
    }

    if(num_baseDestino==10){
        mult_pe=multiplicacion_partEnt(parteEntera,num_baseOrigen);
        printf("La parte entera es: %i \n",mult_pe);
        div_pf=division_partFrac(parteFrac,num_baseOrigen,num_baseDestino);
        printf("La parte fraccionaria es: %f \n",div_pf);
        resultado=mult_pe+div_pf;
        printf("El resultado es: %f \n",resultado);
    }

    if(num_baseDestino!=10 && num_baseOrigen!=10){
        //parteEntera
        printf("Entra al if \n");
        enteroDecimal=multiplicacion_partEnt(parteEntera,num_baseOrigen);
        printf("El entero decimal de la entera es: %i \n",enteroDecimal);
        retornar_parteEntera=division_partEntAuxiliar(enteroDecimal,num_baseDestino);
        printf("El resultado de la parte entera es: %s \n",retornar_parteEntera);

        //parteFraccionaria
        decimal_pf=division_partFrac(parteFrac,num_baseOrigen,10);
        printf("El entero decimal de la fraccionaria es: %f \n",decimal_pf);
        retornar_parteFraccionaria=multiplicacion_partFracAuxiliar(decimal_pf,num_baseDestino);
        printf("El resultado de la parte fraccionaria es: %s \n",retornar_parteFraccionaria);
        printf("El resultado es: %s \n",strcat(retornar_parteEntera,retornar_parteFraccionaria));

    }

    return EXIT_SUCCESS;
}
