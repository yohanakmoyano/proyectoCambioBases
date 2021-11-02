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
    char *cad =  (char *) malloc(10 * sizeof(char));
    char *cadena_baseOrigen =  (char *) malloc(10 * sizeof(char));
    char *cadena_baseDestino =  (char *) malloc(10 * sizeof(char));
    char *parteEntera =  (char *) malloc(10 * sizeof(char));
    char *parteFrac =  (char *) malloc(5 * sizeof(char));
    char *mult_pf = (char *) malloc(5 * sizeof(char));
    char *div_pe = (char *) malloc(10 * sizeof(char));
    char *retornar_parteEntera =  (char *) malloc(10 * sizeof(char));
    char *retornar_parteFraccionaria =  (char *) malloc(10 * sizeof(char));

    int *x;
    x=(int *)malloc(sizeof(int));
    *x=0;
    int *num_baseOrigen;
    num_baseOrigen=(int *)malloc(sizeof(int));
    *num_baseOrigen=0;
    int *cant_baseOrigen;
    cant_baseOrigen=(int *)malloc(sizeof(int));
    *cant_baseOrigen=0;
    int *num_baseDestino;
    num_baseDestino=(int *)malloc(sizeof(int));
    *num_baseDestino=0;
    int *cant_baseDestino;
    cant_baseDestino=(int *)malloc(sizeof(int));
    *cant_baseDestino=0;
    int *bo;
    bo=(int *)malloc(sizeof(int));
    *bo=0;
    int *bd;
    bd=(int *)malloc(sizeof(int));
    *bd=0;
    int *entero_baseOrigen;
    entero_baseOrigen=(int *)malloc(sizeof(int));
    *entero_baseOrigen=0;
    int *i;
    i=(int *)malloc(sizeof(int));
    *i=0;
    int *j;
    j=(int *)malloc(sizeof(int));
    *j=0;
    int *k;
    k=(int *)malloc(sizeof(int));
    *k=0;
    int *m;
    m=(int *)malloc(sizeof(int));
    *m=0;
    int *corte;
    corte=(int *)malloc(sizeof(int));
    *corte=0;
    int *entero_baseDestino;
    entero_baseDestino=(int *)malloc(sizeof(int));
    *entero_baseDestino=0;
    int *contEnt;
    contEnt=(int *)malloc(sizeof(int));
    *contEnt=0;
    int *contFrac;
    contFrac=(int *)malloc(sizeof(int));
    *contFrac=0;
    double *div_pf;
    div_pf=(double *)malloc(sizeof(double));
    *div_pf=0.0;
    int *mult_pe;
    mult_pe=(int *)malloc(sizeof(int));
    *mult_pe=0;
    double *resultado;
    resultado=(double *)malloc(sizeof(double));
    *resultado=0.0;
    int *enteroDecimal;
    enteroDecimal=(int *)malloc(sizeof(int));
    *enteroDecimal=0;
    double *decimal_pf;
    decimal_pf=(double *)malloc(sizeof(double));
    *decimal_pf=0.0;
    int *z;
    z=(int *)malloc(sizeof(int));
    *z=0;
    int *longitud;
    longitud=(int *)malloc(sizeof(int));
    *longitud=0;
    int *mostrarPasos;
    mostrarPasos=(int *)malloc(sizeof(int));
    *mostrarPasos=0;
    char *auxiliar;
    auxiliar=(char *)malloc(10 * sizeof(char));
    int *h;
    h=(int *)malloc(sizeof(int));
    int *g;
    g=(int *)malloc(sizeof(int));
    int *largo;
    largo=(int *)malloc(sizeof(int));


    while(argv[*x]!=NULL){
       *longitud+=1;
       *x+=1;
    }


    while(argv[*z]!=NULL){

        if(strcmp(argv[*z], "-n")==0){
            if(*z==*longitud-1){
                cad=NULL;
            }
            else{
                if (strcmp(argv[*z+1], "-d") ==0 || strcmp(argv[*z+1], "-s")==0 || strcmp(argv[*z+1], "-v")==0 || strcmp(argv[*z+1], "-h")==0) {
                  cad=NULL;
                }
                else {
                    cad=(argv[*z+1]);
                }
            }

        }

        if(strcmp(argv[*z], "-s")==0){
            if(*z==*longitud-1){
                cadena_baseOrigen=NULL;
            }
            else{
                if( strcmp(argv[*z+1], "-d")==0 || strcmp(argv[*z+1], "-n")==0 || strcmp(argv[*z+1], "-v")==0 || strcmp(argv[*z+1], "-h")==0 ){
                    cadena_baseOrigen=NULL;
                }else{
                    cadena_baseOrigen=(argv[*z+1]);
                }
            }

        }

        if(strcmp(argv[*z], "-d")==0){
            if(*z==*longitud-1){
                cadena_baseDestino=NULL;
            }else{
                    if( strcmp(argv[*z+1], "-s")==0 || strcmp(argv[*z+1], "-n")==0 || strcmp(argv[*z+1], "-v")==0 || strcmp(argv[*z+1], "-h")==0 ){
                        cadena_baseDestino=NULL;
                    }else{
                        cadena_baseDestino=(argv[*z+1]);
                    }
            }

        }

        if(strcmp(argv[*z], "-h")==0){
            ayuda();
        }

        if(strcmp(argv[*z], "-v")==0){
            *mostrarPasos=1;
        }

       *z+=1;
    }

    //Verifico si hay cadena para el parámetro -n

    if(cad==NULL) {
        printf("No se ingreso ningun numero para convertir \n");
        free(x);
        free(num_baseOrigen);
        free(num_baseDestino);
        free(cant_baseOrigen);
        free(cant_baseDestino);
        free(bo);
        free(bd);
        free(entero_baseOrigen);
        free(i);
        free(j);
        free(k);
        free(m);
        free(corte);
        free(entero_baseDestino);
        free(contEnt);
        free(contFrac);
        free(div_pf);
        free(mult_pe);
        free(resultado);
        free(enteroDecimal);
        free(decimal_pf);
        free(z);
        free(longitud);
        free(mostrarPasos);
        free(cad);
        free(cadena_baseOrigen);
        free(cadena_baseDestino);
        free(parteEntera);
        free(parteFrac);
        free(retornar_parteEntera);
        free(retornar_parteFraccionaria);
        free(g);
        free(h);
        free(auxiliar);
        free(largo);

        exit(EXIT_FAILURE);
    }

    /*
       Este método separa la cadena del número ingresado en parte entera y parte fraccionaria.
    */

    //Retorna la parte entera del número.
    while(cad[*i]!='\0' && *corte != 1 ){
        if (cad[*i]=='.'){
            *corte=1;
        }else{
            parteEntera[*i]=cad[*i];
            *i+=1;
            *contEnt+=1;
        }

    }

    //Retorna la parte fraccionaria del número.
    if(cad[*i]=='.'){
        *i+=1;
        while(cad[*i]!='\0'){
            parteFrac[*j]=cad[*i];
            *i+=1;
            *j+=1;
            *contFrac+=1;
        }
    }

    /*
        Controla la correcta cantidad de digitos en la parte entera.
    */
    if(*contEnt>10){
        printf("La cantidad maxima de digitos enteros es 10. Vuelva a introducir su numero. \n");

        free(x);
    free(num_baseOrigen);
    free(num_baseDestino);
    free(cant_baseOrigen);
    free(cant_baseDestino);
    free(bo);
    free(bd);
    free(entero_baseOrigen);
    free(i);
    free(j);
    free(k);
    free(m);
    free(corte);
    free(entero_baseDestino);
    free(contEnt);
    free(contFrac);
    free(div_pf);
    free(mult_pe);
    free(resultado);
    free(enteroDecimal);
    free(decimal_pf);
    free(z);
    free(longitud);
    free(mostrarPasos);
    free(cad);
    free(cadena_baseOrigen);
    free(cadena_baseDestino);
    free(parteEntera);
    free(parteFrac);
    free(retornar_parteEntera);
    free(retornar_parteFraccionaria);
    free(g);
    free(h);
    free(auxiliar);
    free(largo);

    exit(EXIT_FAILURE);
    }

    /*
        Controla la correcta cantidad de digitos en la parte fraccionaria.
    */
    if(*contFrac>5){
        printf("La cantidad maxima de digitos fraccionarios es 5. Vuelva a introducir su numero. \n");

        free(x);
    free(num_baseOrigen);
    free(num_baseDestino);
    free(cant_baseOrigen);
    free(cant_baseDestino);
    free(bo);
    free(bd);
    free(entero_baseOrigen);
    free(i);
    free(j);
    free(k);
    free(m);
    free(corte);
    free(entero_baseDestino);
    free(contEnt);
    free(contFrac);
    free(div_pf);
    free(mult_pe);
    free(resultado);
    free(enteroDecimal);
    free(decimal_pf);
    free(z);
    free(longitud);
    free(mostrarPasos);
    free(cad);
    free(cadena_baseOrigen);
    free(cadena_baseDestino);
    free(parteEntera);
    free(parteFrac);
    free(retornar_parteEntera);
    free(retornar_parteFraccionaria);
    free(g);
    free(h);
    free(auxiliar);
    free(largo);

    exit(EXIT_FAILURE);
    }



    //---------------BaseOrigen-----------------------------

    if(cadena_baseOrigen==NULL){
        *num_baseOrigen=10;
    }else{
        /*
        Cuenta la cantidad de dígitos que tiene la cadena de caracteres base origen ingresada.
        */

        while(cadena_baseOrigen[*bo]!='\0'){
            *cant_baseOrigen+=1;
            *bo+=1;
        }

        /*
        Convierte la cadena de base origen, en entero.
        */

        while(cadena_baseOrigen[*k]!='\0'){
            *entero_baseOrigen = cadena_baseOrigen[*k]-'0';
            *num_baseOrigen = *num_baseOrigen+(*entero_baseOrigen)*pow(10,*cant_baseOrigen-1);
            *cant_baseOrigen=*cant_baseOrigen-1;
            *k+=1;
        }
    }

    printf("La base origen es %i \n", *num_baseOrigen);

    /*
        Controla que la base origen ingresada sea correcta.
    */
      if(*num_baseOrigen < 2 || *num_baseOrigen > 16){
        printf("La base origen esta mal ingreada. Vuelva a introducir su numero. \n");

        free(x);
    free(num_baseOrigen);
    free(num_baseDestino);
    free(cant_baseOrigen);
    free(cant_baseDestino);
    free(bo);
    free(bd);
    free(entero_baseOrigen);
    free(i);
    free(j);
    free(k);
    free(m);
    free(corte);
    free(entero_baseDestino);
    free(contEnt);
    free(contFrac);
    free(div_pf);
    free(mult_pe);
    free(resultado);
    free(enteroDecimal);
    free(decimal_pf);
    free(z);
    free(longitud);
    free(mostrarPasos);
    free(cad);
    free(cadena_baseOrigen);
    free(cadena_baseDestino);
    free(parteEntera);
    free(parteFrac);
    free(retornar_parteEntera);
    free(retornar_parteFraccionaria);
    free(g);
    free(h);
    free(auxiliar);
    free(largo);

    exit(ERROR_EXCEDIDO_BASE_ORIGEN);
    }


    //---------------BaseDestino-----------------------------

    if(cadena_baseDestino==NULL){
        *num_baseDestino=10;
    }else{

        /*
        Cuenta la cantidad de dígitos que tiene la cadena de caracteres base destino ingresada.
        */
        while(cadena_baseDestino[*bd]!='\0'){
            *cant_baseDestino+=1;
            *bd+=1;
        }

        /*
        Convierte la cadena de base destino, en entero.
        */
        while(cadena_baseDestino[*m]!='\0'){
            *entero_baseDestino = cadena_baseDestino[*m]-'0';
            *num_baseDestino = *num_baseDestino+(*entero_baseDestino)*pow(10,*cant_baseDestino-1);
            *cant_baseDestino-=1;
            *m+=1;
        }
    }

    printf("La base destino es %i \n", *num_baseDestino);

    /*
        Controla que la base destino ingresada sea correcta.
    */
    if( *num_baseDestino < 2 || *num_baseDestino > 16){
        printf("La base destino esta mal ingresada. Vuelva a introducir su numero. \n");

        free(x);
    free(num_baseOrigen);
    free(num_baseDestino);
    free(cant_baseOrigen);
    free(cant_baseDestino);
    free(bo);
    free(bd);
    free(entero_baseOrigen);
    free(i);
    free(j);
    free(k);
    free(m);
    free(corte);
    free(entero_baseDestino);
    free(contEnt);
    free(contFrac);
    free(div_pf);
    free(mult_pe);
    free(resultado);
    free(enteroDecimal);
    free(decimal_pf);
    free(z);
    free(longitud);
    free(mostrarPasos);
    free(cad);
    free(cadena_baseOrigen);
    free(cadena_baseDestino);
    free(parteEntera);
    free(parteFrac);
    free(retornar_parteEntera);
    free(retornar_parteFraccionaria);
    free(g);
    free(h);
    free(auxiliar);
    free(largo);

    exit(ERROR_EXCEDIDO_BASE_DESTINO);
    }

    printf("La cadena de parte entera es %s \n", parteEntera);
    printf("La cadena de parte fraccionaria es %s \n", parteFrac);

    //------------Conversión de bases--------------------------

    /*
        Invoca a los métodos de CambioBases y retorna el valor de la conversión del número.
    */
    if(*num_baseOrigen==10){
        //parteEntera
        div_pe=division_partEnt(parteEntera, num_baseDestino,mostrarPasos);
        printf("La parte entera es: %s \n",div_pe);
        //parteFraccionaria
        mult_pf=multiplicacion_partFrac(parteFrac,num_baseDestino,mostrarPasos);
        printf("La parte fraccionaria es: %s \n",mult_pf);
        printf("El resultado es: %s.%s \n",div_pe,mult_pf);
    }

    if(*num_baseDestino==10){
        //parteEntera
        mult_pe=multiplicacion_partEnt(parteEntera,num_baseOrigen,mostrarPasos);
        printf("La parte entera es: %i \n",*mult_pe);
        //parteFraccionaria
        div_pf=division_partFrac(parteFrac,num_baseOrigen,mostrarPasos);
        printf("La parte fraccionaria es: %f \n",*div_pf);
        *resultado=*mult_pe+*div_pf;
        printf("El resultado es: %f \n",*resultado);
    }

    if(*num_baseDestino!=10 && *num_baseOrigen!=10){
        //parteEntera
        enteroDecimal=multiplicacion_partEnt(parteEntera,num_baseOrigen,mostrarPasos);
        printf("El entero decimal de la entera es: %i \n",*enteroDecimal);
        retornar_parteEntera=division_partEntAuxiliar(enteroDecimal,num_baseDestino,mostrarPasos);
        *largo=strlen(retornar_parteEntera);
        *g=*largo-1;
        //invierte la cadena: cadena_parteEntera
        for (*h=0; *h<*largo; *h+=1){
            auxiliar[*h]= retornar_parteEntera[*g];
            *g-=1;
        }

        printf("El resultado de la parte entera es: %s \n",auxiliar);

        //parteFraccionaria
        decimal_pf=division_partFrac(parteFrac,num_baseOrigen,mostrarPasos);
        printf("El entero decimal de la fraccionaria es: %f \n",*decimal_pf);
        retornar_parteFraccionaria=multiplicacion_partFracAuxiliar(decimal_pf,num_baseDestino,mostrarPasos);
        printf("El resultado de la parte fraccionaria es: %s \n",retornar_parteFraccionaria);
        printf("El resultado es: %s.%s \n",retornar_parteEntera,retornar_parteFraccionaria);

    }

    free(x);
    free(num_baseOrigen);
    free(num_baseDestino);
    free(cant_baseOrigen);
    free(cant_baseDestino);
    free(bo);
    free(bd);
    free(entero_baseOrigen);
    free(i);
    free(j);
    free(k);
    free(m);
    free(corte);
    free(entero_baseDestino);
    free(contEnt);
    free(contFrac);
    free(div_pf);
    free(mult_pe);
    free(resultado);
    free(enteroDecimal);
    free(decimal_pf);
    free(z);
    free(longitud);
    free(mostrarPasos);
    free(cad);
    free(cadena_baseOrigen);
    free(cadena_baseDestino);
    free(parteEntera);
    free(parteFrac);
    free(retornar_parteEntera);
    free(retornar_parteFraccionaria);
    free(g);
    free(h);
    free(auxiliar);
    free(largo);

    return EXIT_SUCCESS;
}
