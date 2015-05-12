#ifndef _TRAFO_H
#define _TRAFO_H

#define N 8
#define M 4

#include "types.h"

//-----------------------------------------------------------------------------------
//Las funciones que se definan en ensamblador deberán borrarse de este fichero
//de otra manera habría dos definciones de la misma función
//-----------------------------------------------------------------------------------



void RGB2GrayMatrix(pixelRGB orig[N][M], int dest[N][M], int nfilas, int ncols);

void Gray2BinaryMatrix(int orig[N][M], int dest[N][M], int nfilas, int ncols);

int rgb2gray(pixelRGB pixel);

//void contarUnos(int mat[N][M], int vector[], int nfilas, int ncols);

#endif
