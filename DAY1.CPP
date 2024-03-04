#include<iostream>
#include<vector>
using namespace std;

const int N = 2;
const int M = 2;
const int P = 2;

void print(int matrix[3][2]) { // the function is only allowed to receive only 3 x 2 matrix
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrix[i][j] << " ";
        }
    }
}

void print_1(int matrix[][2], int row) { // Adv - we can pass a matrix of any rows but fixed no of columns
    
    for(int i = 0; i < row; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrix[i][j] << " ";
        }
    }

}

void c_style_print(int* matrix[], int row, int column) { // passing a multidimensional array via double pointer 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << matrix[i][j] << " ";
        }
    }
}

void print_via_array_of_vectors(vector<int> matrix[], int rows) { // passing a multidimensional array via vectors
    
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
    }

}

void print_via_vector_of_vectors(vector<vector<int> >matrix) { // we can create a jagged array with the help of this but the indivisual rows arent stored at contaigous location 

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
    }
}

void printSnake(vector<vector<int> >& matrix) { //0(ROWS * COLUMN)
    int row = matrix.size();
    int column = matrix[0].size();

    for (int i = 0; i < row; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < column; j++) {
                cout << matrix[i][j] << " ";
            }
        } else {
            for (int j = column - 1; j >= 0; j--) {
                cout << matrix[i][j] << " ";
            }
        }
    }
}

void matrix_boundary_traversal(vector<vector<int> >matrix){
    
}
int main() {
    int matrix[4]  = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    printSnake(matrix);
    return 0;
}
