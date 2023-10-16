#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <chrono>

using namespace std;
/** Main function */
int main(int argc, char *argv[])
{

    auto start = chrono::high_resolution_clock::now();

    int mat_size, i, j, step;
    if (argc == 1)
    {
        cout << "Introduce un valor para la matriz " << std::endl;
        // return 0;
        exit(-1);
    }
    else
    {
        if (argv[1] == string("0"))
        {
            cout << "Introduce un valor para la matriz diferente a 0" << endl;
            exit(-1);
        }
        mat_size = atoi(argv[1]);
    }

    // crear una matriz 2D mediante asignación de memoria dinámica
    double **mat = new double *[mat_size + 1], **x = new double *[mat_size];
    for (i = 0; i <= mat_size; i++)
    {
        mat[i] = new double[mat_size + 1];
        if (i < mat_size)
            x[i] = new double[mat_size + 1];
    }

    // obtener los elementos de la matriz del usuario
    for (i = 0; i < mat_size; i++)
    {
        for (j = 0; j <= mat_size; j++)
        {
            mat[i][j] = rand() % 2001; // Ingrese el valor (mat_size*mat_size) de la matriz.
        }
    }

    // realizar eliminación gaussiana
    for (step = 0; step < mat_size - 1; step++)
    {
#pragma omp parallel for shared(mat) private(i, j)
        for (i = step; i < mat_size - 1; i++)
        {
            double a = (mat[i + 1][step] / mat[step][step]);

            for (j = step; j <= mat_size; j++)
                mat[i + 1][j] = mat[i + 1][j] - (a * mat[step][j]);
        }
    }

    cout << endl
         << "Matriz utilizando el método de eliminación gaussiana: " << endl;
    for (i = 0; i < mat_size; i++)
    {
        for (j = 0; j <= mat_size; j++)
        {
            x[i][j] = mat[i][j];
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << "Valores de los números del método de eliminación gaussiano: " << endl;
    for (i = mat_size - 1; i >= 0; i--)
    {
        double sum = 0;
        for (j = mat_size - 1; j > i; j--)
        {
            x[i][j] = x[j][j] * x[i][j];
            sum = x[i][j] + sum;
        }
        if (x[i][i] == 0)
            x[i][i] = 0;
        else
            x[i][i] = (x[i][mat_size] - sum) / (x[i][i]);

        cout << "x" << i << "= " << x[i][i] << endl;
    }

    for (i = 0; i <= mat_size; i++)
    {
        delete[] mat[i];
        if (i < mat_size)
            delete[] x[i];
    }
    delete[] mat;
    delete[] x;

    auto end = chrono::high_resolution_clock::now();

    // Calcula la duración en microsegundos (puedes cambiar la unidad si lo deseas)
    chrono::duration<double> duration = end - start;

    // Imprime el tiempo transcurrido
    cout << "Tiempo de ejecución: " << duration.count() << " segundos" << std::endl;

    return 0;
}
