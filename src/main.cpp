//============================================================================
// Name        : main.cpp
// Author      : Matej Kupciha
//============================================================================

//#ifndef TEST

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

#include "simplevector.h"
#include "simplematrix.h"
#include "compressedmatrix.h"
#include "algorithm.h"
#include "gradientdescent.h"
#include "conjugategradients.h"

Vector* solve(Algorithm* algorithm, Matrix* m, Vector* v, double epsilon) {
    time_t start = time(NULL);
    Vector* result = algorithm->solve(*m, *v, epsilon);
    time_t duration = time(NULL) - start;

    // Print time results
    cout << duration << "s" << endl;

    return result;
}

int main(int argc, char* argv[]) {

    // Check arguments
    if (argc < 5) {
        cout << "Usage: " << argv[0] << " <-gd|-cg> <-s|-cr> <matrix-file> <vector-file>" << endl;
        return 1;
    }

    try {
        // Input files and configuration
        string algorithmType(argv[1]);
        string matrixType(argv[2]);
        ifstream matrixFile(argv[3]);
        ifstream vectorFile(argv[4]);
        double epsilon = 1e-8;

        // Read vector and matrix from files
        Vector* vector = new SimpleVector(vectorFile);
        Matrix* matrix;
        if (matrixType == "-s") {
            matrix = new SimpleMatrix(matrixFile);
        } else {
            matrix = new CompressedMatrix(matrixFile);
        }

        // Choose algorithm
        Algorithm* algorithm;
        string algorithmName;
        if (algorithmType == "-gd") {
            algorithm = new GradientDescent();
            algorithmName = "Gradient descent";
        } else {
            algorithm = new ConjugateGradients();
            algorithmName = "Conjugate gradients";
        }

        // Print results
        cout << algorithmName << ":" << endl;
        cout << "Matrix (" << matrix->rowSize() << "x" << matrix->columnSize() << ")" << endl;
        cout << "Vector (" << vector->size() << ")" << endl;

        // Solve equations
        Vector* result = solve(algorithm, matrix, vector, epsilon);
        result->print(cerr);

        // Free resources
        vectorFile.close();
        matrixFile.close();
        delete vector;
        delete matrix;
        delete algorithm;
        delete result;
    } catch (const char* e) {
        cout << "Exception thrown: " << e << endl;
    }

    return 0;
}

//#endif /* TEST */
