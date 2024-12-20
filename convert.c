#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "convert.h"
#include "constantes.h"
#include <string.h>

/*
    Programa convert. Convierte el n�mero recibido por par�metro -n <number> desde la base origen
     -s <source_base> a la base destino -d <dest_base>. El par�metro -v muestra c�mputos intermedios.
     El par�metro -h muestra una ayuda.
*/
int main(int argc,char * argv[])
{
    char *cad =  (char *) malloc(16 * sizeof(char));
    char *cadena_baseOrigen =  (char *) malloc(2 * sizeof(char));
    char *cadena_baseDestino =  (char *) malloc(2 * sizeof(char));
    char *parteEntera =  (char *) malloc(10 * sizeof(char));
    char *parteFrac =  (char *) malloc(5 * sizeof(char));
    char *mult_pf;
    char *div_pe;
    char *retornar_parteEntera =  (char *) malloc(10 * sizeof(char));
    char *retornar_parteFraccionaria =  (char *) malloc(5 * sizeof(char));
    char *auxiliar;
    auxiliar=(char *)malloc(10 * sizeof(char));
    int *long_cadParteEntera;
    long_cadParteEntera=(int *)malloc(sizeof(int));
    *long_cadParteEntera=strlen(parteEntera);
    int *a;
    a=(int *)malloc(sizeof(int));
    int *long_cadParteFraccionaria;
    long_cadParteFraccionaria=(int *)malloc(sizeof(int));
    *long_cadParteFraccionaria=strlen(parteFrac);
    int *b;
    b=(int *)malloc(sizeof(int));
    int *long_cad;
    long_cad=(int *)malloc(sizeof(int));
    *long_cad=strlen(cad);
    int *c;
    c=(int *)malloc(sizeof(int));
    int *long_bases;
    long_bases=(int *)malloc(sizeof(int));
    *long_bases=strlen(cadena_baseOrigen);
    int *d;
    d=(int *)malloc(sizeof(int));
    char *auxiliar_div =(char *) malloc (10 *sizeof(char));
    int *largo_div=(int *) malloc (sizeof(int));

    //Inicializo Parte Entera  y retornar_parteEntera con nulos
    for(*a=0;*a<*long_cadParteEntera;*a+=1){
        parteEntera[*a]='\0';
        retornar_parteEntera[*a]='\0';
        auxiliar[*a]='\0';
    }

    //Inicializo ParteFrac y retornar_parteFraccionaria con nulos
    for(*b=0;*b<*long_cadParteFraccionaria;*b+=1){
        parteFrac[*b]='\0';
        retornar_parteFraccionaria[*b]='\0';

    }

    //Inicializo cad con nulos
    for(*c=0;*c<*long_cad;*c+=1){
        cad[*c]='\0';
    }


    //Inicializo cadena_baseOrigen y cadena_baseDestino con nulos
    for(*d=0;*d<*long_bases;*d+=1){
        cadena_baseOrigen[*d]='\0';
        cadena_baseDestino[*d]='\0';
    }


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
    int *h;
    h=(int *)malloc(sizeof(int));
    int *g;
    g=(int *)malloc(sizeof(int));
    int *largo;
    largo=(int *)malloc(sizeof(int));
    int *e;
    e=(int *) malloc (sizeof(int));
    int *f;
    f=(int *) malloc (sizeof(int));

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

    //Verifico si hay cadena para el par�metro -n

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
        free(auxiliar_div);
        free(largo_div);
        free(e);
        free(f);

        exit(EXIT_FAILURE);
    }

    /*
       Este m�todo separa la cadena del n�mero ingresado en parte entera y parte fraccionaria.
    */

    //Retorna la parte entera del n�mero.
    while(cad[*i]!='\0' && *corte != 1 ){
        if (cad[*i]=='.'){
            *corte=1;
        }else{
            parteEntera[*i]=cad[*i];
            *i+=1;
            *contEnt+=1;
        }
    }

    //Retorna la parte fraccionaria del n�mero.
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
        free(auxiliar_div);
        free(largo_div);
        free(e);
        free(f);

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
        free(auxiliar_div);
        free(largo_div);
        free(e);
        free(f);

        exit(EXIT_FAILURE);
    }

    //---------------BaseOrigen-----------------------------

    if(*cadena_baseOrigen=='\0'){
        *num_baseOrigen=10;
    }else{
        /*
        Cuenta la cantidad de d�gitos que tiene la cadena de caracteres base origen ingresada.
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
        printf("La base origen esta mal ingresada. Vuelva a introducir su numero. \n");

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
        free(auxiliar_div);
        free(largo_div);
        free(e);
        free(f);

        exit(ERROR_EXCEDIDO_BASE_ORIGEN);
    }


    //---------------BaseDestino-----------------------------

    if(*cadena_baseDestino=='\0'){
        *num_baseDestino=10;
    }else{

        /*
        Cuenta la cantidad de d�gitos que tiene la cadena de caracteres base destino ingresada.
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
        free(auxiliar_div);
        free(largo_div);
        free(e);
        free(f);

        exit(ERROR_EXCEDIDO_BASE_DESTINO);
    }

    printf("La cadena de parte entera es %s \n", parteEntera);
    printf("La cadena de parte fraccionaria es %s \n", parteFrac);

    //------------Conversi�n de bases--------------------------

    /*
        Invoca a los m�todos de CambioBases y retorna el valor de la conversi�n del n�mero.
    */
    if(*num_baseOrigen==10){
        //parteEntera
        div_pe=division_partEnt(parteEntera, num_baseDestino,mostrarPasos);
        *largo_div=strlen(div_pe);
        *e=*largo_div - 1;
        //invierte la cadena: cadena_parteEntera
        for (*f=0; *f<*largo_div; *f+=1){
            auxiliar_div[*f]= div_pe[*e];
            *e-=1;
        }
        printf("La parte entera es: %s \n",auxiliar_div);
        //parteFraccionaria
        mult_pf=multiplicacion_partFrac(parteFrac,num_baseDestino,mostrarPasos);
        printf("La parte fraccionaria es: %s \n",mult_pf);
        printf("El resultado es: %s.%s \n",auxiliar_div,mult_pf);
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
        retornar_parteFraccionaria=multiplicacion_partFracAuxiliar(decimal_pf,num_baseDestino,mostrarPasos);
        printf("El resultado de la parte fraccionaria es: %s \n",retornar_parteFraccionaria);
        printf("El resultado es: %s.%s \n",auxiliar,retornar_parteFraccionaria);

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
    free(auxiliar_div);
    free(largo_div);
    free(e);
    free(f);

    return EXIT_SUCCESS;
}
