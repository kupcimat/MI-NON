//============================================================================
// Name        : main.cpp
// Author      : Matej Kupciha
//============================================================================

//#ifndef TEST

#include <iostream>
#include <fstream>
using namespace std;

#include "simplevector.h"
#include "simplematrix.h"
#include "compressedmatrix.h"
#include "algorithm.h"
#include "gradientdescent.h"
#include "conjugategradients.h"

int main(int argc, char* argv[]) {

    // Check arguments
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <vector-file> <matrix-file>" << endl;
        return 1;
    }

    try {
        // Input files and configuration
        ifstream vectorFile(argv[1]);
        ifstream matrixFile(argv[2]);
        double epsilon = 0.000001;

        // Read vector and matrix from file
        Vector* v = new SimpleVector(vectorFile);
        // Matrix* m = new SimpleMatrix(matrixFile);
        Matrix* m = new CompressedMatrix(matrixFile);

        // Solve equations
        Algorithm* descent = new GradientDescent();
        Algorithm* gradients = new ConjugateGradients();
        // Save results
        Vector* descentResult = descent->solve(*m, *v, epsilon);
        Vector* gradientsResult = gradients->solve(*m, *v, epsilon);

        // Print results
        cout << "Matrix (" << m->rowSize() << "x" << m->columnSize() << ")" << endl;
        // m->print(cout);
        cout << "Vector (" << v->size() << ")" << endl;
        // v->print(cout);
        cout << endl << "Gradient descent   : ";
        descentResult->print(cout);
        cout << endl << "Conjugate gradients: ";
        gradientsResult->print(cout);
        cout << endl;

        // Free resources
        vectorFile.close();
        matrixFile.close();
        delete v;
        delete m;
        delete descent;
        delete gradients;
        delete descentResult;
        delete gradientsResult;
    } catch (const char* e) {
        cout << "Exception thrown: " << e << endl;
    }

    return 0;
}

//#endif /* TEST */
