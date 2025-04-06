/* TWO-DIMENSIONAL DYNAMICALLY ALLOCATED ARRAYS */

/* Simple math can then be used to convert a row and column index for a rectangular two-dimensional 
array into a single index for a one-dimensional array: */

#include <iostream>


int get_single_index(int row, int col, int number_of_columns_in_array)
{
    return (row * number_of_columns_in_array) + col;
}

int main ()
{
    /* Because allocating and deallocating two-dimensional arrays 
    is complex and easy to mess up, it’s often easier to "flatten"
    a two-dimensional array (of size x by y) into a one-dimensional 
    array of size x * y: */

    // Instead of this:
    int nrows { 4 };
    int ncols { 5 };

    // Allocate an array of 10 int pointers — these are our rows
    int** array2d { new int*[nrows] };
    for (int count { 0 }; count < nrows; ++count)
        array2d[count] = new int[ncols]; // these are our columns

    // Do this
    int *array1d { new int[nrows * ncols] {} }; // a 4x5 array flattened into a single array
    
    array1d[get_single_index(9, 4, ncols)] = 3;
    
    // Populate numbers into 2D array and 1D array
    for (int i { 0 }; i < nrows; ++i) {
        for (int j { 0 }; j < ncols; ++j) {
            array2d[i][j] = i * ncols + j;
            array1d[get_single_index(i, j, ncols)] = i * ncols + j;
        }
    }

    // Print the 2D array to console:
    std::cout << "2D array:\n";
    for (int i { 0 }; i < nrows; ++i) {
        for (int j { 0 }; j < ncols; ++j) {
            std::cout << array2d[i][j] << '\t';
        }
        std::cout << '\n';
    }

    // Print the 1D array to console:
    std::cout << "1D array but indexed as 2D array:\n";
    for (int i { 0 }; i < nrows; ++i) {
        for (int j { 0 }; j < ncols; ++j) {
            std::cout << array1d[get_single_index(i, j, ncols)] << '\t';
        }
        std::cout << '\n';
    }
}