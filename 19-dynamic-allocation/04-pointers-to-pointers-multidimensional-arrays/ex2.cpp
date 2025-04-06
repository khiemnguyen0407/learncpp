/* DYNAMIC MULTIDIMENSIONAL ARRAYS */

#include <iostream>

int main () 
{
    
    int array2d[2][6] {{0, 1, 2, 3, 4, 5}, {5, 4, 3, 2, 1, 0}};

    std::cout << "Two-dimensional array:\n";
    for (int i {0}; i < 2; ++i) {
        for (int j {0}; j < 6; ++j) {
            std::cout << array2d[i][j] << '\t';
        }
        std::cout << '\n';
    }

    /* Dynamically allocating a two-dimensional array 
    ================================================= */
    int x { 3 };                              // non-constant
    int (*array1)[5] { new int[x][5] };      // rightmost dimension must be constexpr
    // The parenthesis are required so that the compiler knows we want 
    // array to be a pointer to an array of 5 int (which in this case 
    // is the first row of a 3-row multidimensional array). Without 
    // the parenthesis, the compiler would interpret this as int* array[5], 
    // which is an array of 5 int*.

    // This is a good place to use automatic type deduction:
    auto array2 {new int[x][5]};

    /* Unfortunately, this relatively simple solution doesn’t work if the rightmost array dimension 
    isn’t a compile-time constant. In that case, we have to get a little more complicated. First, 
    we allocate an array of pointers (as per above). Then we iterate through the array of pointers 
    and allocate a dynamic array for each array element. Our dynamic two-dimensional array is a 
    dynamic one-dimensional array of dynamic one-dimensional arrays! */

    int nrows { 3 };
    int ncols { 5 };
    int **array3 {new int*[nrows]};
    for (int i {0}; i < nrows; ++i) {
        array3[i] = new int[ncols];     // these are our columns
    }

    /* With this method, because each array column is dynamically allocated 
    independently, it’s possible to make dynamically allocated two dimensional 
    arrays that are not rectangular. For example, we can make a 
    triangle-shaped array: */
    int m {6};
    int** tri_array {new int*[m]};
    for (int i {0}; i < m; ++i) 
        tri_array[i] = new int[i + 1];      // these are our columns
    // In this example, the tri_array[0] is an array of length 1, tri_array[1] 
    // is array of length 2, tri_array[2] is an array of length 3, and so on.

    // Let us pop the number into tri_array
    int count {0};
    for (int i {0}; i < m; ++i) {
        for (int j {0}; j <= i; ++j) {
            count++;
            tri_array[i][j] = count;
        }
    }

    // Let us print the values of tri_array to console
    std::cout << "Triangular Array: \n";
    for (int i {0}; i < m; ++i) {
        for (int j {0}; j <= i; ++j) {
            std::cout << tri_array[i][j] << '\t';
        }
        std::cout << '\n';
    }

    /* Deallocating a dynamically allocated two-dimensional array using this method
    requires a loop as well. */
    for (int i {0}; i < m; ++i)
        delete[] tri_array[i];
    delete[] tri_array;

    // Note that we delete the array in the opposite order that we created it 
    // (elements first, then the array itself). If we delete array before the array 
    // columns, then we’d have to access deallocated memory to delete the array 
    // columns. And that would result in undefined behavior.
}