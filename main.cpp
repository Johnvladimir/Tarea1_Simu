#include <iostream>
#include <stdio.h>
#include "stdlib.h"
#include "math_tools.h"
#include "display_tools.h"

int main()
{
    Matrix exc_matrix, answer_matrix, result_matrix, transp_matrix;
    zeroes(exc_matrix,3);
    exc_matrix.at(0).at(0) = 2; exc_matrix.at(0).at(1) = 2; exc_matrix.at(0).at(2) = 3;
    exc_matrix.at(1).at(0) = 4; exc_matrix.at(1).at(1) = 5; exc_matrix.at(1).at(2) = 6;
    exc_matrix.at(2).at(0) = 7; exc_matrix.at(2).at(1) = 8; exc_matrix.at(2).at(2) = 9;
    
    //Primero el determinante
    if(determinant(exc_matrix) == 0){
        exit(EXIT_FAILURE);
    }else{
     cout << "El determinante de la matrix es:" << endl;
     cout << determinant(exc_matrix) << endl;
     cout << endl;   
    }
    
    //Segundo la matris transpuesta
    cout << "La matrix transpuesta es:" << endl;
    transpose(exc_matrix, answer_matrix);
    show_matrix(answer_matrix);
    cout << endl;
    
    //Tercero la matrix adjunta
    cout << "La matrix adjunta de la transpuesta es:" << endl;
    cofactors(answer_matrix, result_matrix);
    show_matrix(result_matrix);
    cout << endl;
    
    //Cuarto se divide la matrix adjunta por el determinante
    cout << "La matrix inversa es:" << endl;
    dividirDetMatrix(determinant(exc_matrix),result_matrix,transp_matrix);
    show_matrix(transp_matrix);
    
    
    return 0;
}
