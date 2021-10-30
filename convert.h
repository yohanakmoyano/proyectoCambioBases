#ifndef CONVERT_H_INCLUDED
#define CONVERT_H_INCLUDED

int multiplicacion_partEnt(char * cadenaEnt,int origen, int pasos);
char * multiplicacion_partFrac(char * cadenaFrac,int origen, int destino, int pasos);
char * division_partEnt(char * cadenaEnt,int origen, int destino, int pasos);
double division_partFrac(char * cadenaFrac,int origen, int destino, int pasos);
char * division_partEntAuxiliar(int decimal,int destino, int pasos);
char * multiplicacion_partFracAuxiliar(double decimal,int destino, int pasos);
void ayuda();

#endif // CONVERT_H_INCLUDED
