//PARA MATRIX
void show_matrix(Matrix k){
    for(int i=0; i<k.at(0).size(); i++){
        cout << "[\t";
        for(int j=0; j<k.size(); j++){
            cout << k.at(i).at(j) << "\t";
        }
        cout << "]\n";
    }
}