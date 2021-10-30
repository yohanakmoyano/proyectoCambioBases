#ifndef CONVERT_H_INCLUDED
#define CONVERT_H_INCLUDED

int multiplicacion_partEnt(char * cadenaEnt,int origen);
char * multiplicacion_partFrac(char * cadenaFrac,int origen, int destino);
char * division_partEnt(char * cadenaEnt,int origen, int destino);
double division_partFrac(char * cadenaFrac,int origen, int destino);
char * division_partEntAuxiliar(int decimal,int destino);
char * multiplicacion_partFracAuxiliar(double decimal,int destino);

#endif // CONVERT_H_INCLUDED
