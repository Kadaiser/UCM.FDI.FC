#include <stdio.h>
#include "trafo.h"
#include "types.h"

//#define N 8
//#define M 4


#define FACTOR ( (unsigned char) ( 255/(N+M-2) ) )

// Defincion de funciones y variables declaradas en ensamblador


//---------------------------------------------------------------


pixelRGB imagenRGB[N][M];
int imagenGris[N][M];
int imagenBinaria[N][M];
int unosPorFila[N];

void initRGB(pixelRGB m[N][M], int nfilas, int ncols) {

    int i,j;
    
    for (i=0;i<nfilas;i++)
        for (j=0; j<ncols; j++) {
            m[i][j].R = (i+j)*FACTOR;
            m[i][j].G = (i+j)*FACTOR;
            m[i][j].B = (i+j)*FACTOR;
            //(i+j)*FACTOR
        }
}



int main() {
    
    // 1. Crear una matriz NxM de diferentes colores

	initRGB(imagenRGB,N,M);

	// 2. Traducir la matriz RGB a una matriz de grises

    RGB2GrayMatrix(imagenRGB,imagenGris,N,M);

    // 3. Traducir la matriz de grises a una matriz en blanco y negro

    Gray2BinaryMatrix(imagenGris,imagenBinaria,N,M);

    // Contar los unos que aparecen por filas en la matriz de blanco y negro

    contarUnos(imagenBinaria,unosPorFila,N,M);

    return 0;
}
