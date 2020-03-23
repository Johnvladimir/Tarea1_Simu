#include <vector>
#include "math.h"
using namespace std;

typedef vector<float> Vector;
typedef vector<Vector> Matrix;

//Inicializa Matrix
void zeroes(Matrix &M, int n){
    for(int i=0; i<n; i++){
        Vector row(n,0.0);
        M.push_back(row);
    }
}

void copyMatrix(Matrix A, Matrix &copy){
    //Se inicializa la copia con ceroes
    //asegurandose de sus dimensiones
    zeroes(copy,A.size());
    //Se recorre la matriz original
    for(int i=0;i<A.size();i++)
        for(int j=0;j<A.at(0).size();j++)
            //Se coloca la celda actual de la matriz original
            //en la misma posicion dentro de la copia
            copy.at(i).at(j) = A.at(i).at(j);
}

void getMinor(Matrix &M,int i, int j){
    //Se elimina la fila i
    M.erase(M.begin()+i); //Uso de begin para obtener un iterator a la posicion de interes
    //Se recorren las filas restantes
    for(int i=0;i<M.size();i++)
        //En cada fila se elimina la columna j
        M.at(i).erase(M.at(i).begin()+j);
}

float determinant(Matrix M){
    //Caso trivial: si la matriz solo tiene una celda, ese valor es el determinante
    if(M.size() == 1) return M.at(0).at(0);
    else{
        //Se inicia un acumulador
        float det=0.0;
        //Se recorre la primera fila
        for(int i=0;i<M.at(0).size();i++){
            //Se obtiene el menor de la posicion actual
            Matrix minor;
            copyMatrix(M,minor);
            getMinor(minor,0,i);

            //Se calculala contribucion de la celda actual al determinante
            //(valor alternante * celda actual * determinante de menor actual)
            det += pow(-1,i)*M.at(0).at(i)*determinant(minor);
        }
        return det;
    }
}

void transpose(Matrix M, Matrix &T){
    //Se prepara la matriz resultante con las mismas dimensiones
    //de la matriz original
    zeroes(T,M.size());
    //Se recorre la matriz original
    for(int i=0;i<M.size();i++)
        for(int j=0;j<M.at(0).size();j++)
            //La posicion actual se almacena en la posicion con indices
            //invertidos de la matriz resultante
            T.at(j).at(i) = M.at(i).at(j);
}

void cofactors(Matrix M, Matrix &Cof){
    //Se prepara la matriz de cofactores para que sea de las mismas
    //dimensiones de la matriz original
    zeroes(Cof,M.size());
    //Se recorre la matriz original
    for(int i=0;i<M.size();i++){
        for(int j=0;j<M.at(0).size();j++){
            //Se obtiene el menor de la posicion actual
            Matrix minor;
            copyMatrix(M,minor);
            getMinor(minor,i,j);
            //Se calcula el cofactor de la posicion actual
            //      alternante * determinante del menor de la posicion actual
            Cof.at(i).at(j) = pow(-1,i+j)*determinant(minor);
        }
    }
}

void dividirDetMatrix(float real,Matrix M,Matrix &R){
    //Se prepara la matriz de respuesta con las mismas dimensiones de la
    //matriz
    zeroes(R,M.size());
    //Se recorre la matriz original
    for(int i=0;i<M.size();i++)
        for(int j=0;j<M.at(0).size();j++)
            //La celda actual se multiplica por el real, y se almacena
            //el resultado en la matriz de respuesta
            R.at(i).at(j) = M.at(i).at(j)/real;
}




