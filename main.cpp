#include <iostream>
template <typename T>
void make2dArray(T ** &, int, int);
template <typename T>
void show2dArray(T ** &, int, int);
template <typename T>
void delete2dArray(T ** &, int, int);

int main()
{
    double ** pd;
    make2dArray(pd, 2, 2);
    pd[0][0] = 3.14;
    pd[0][1] = 1.14;
    pd[1][0] = 5.174;
    pd[1][1] = 1.902;
    show2dArray(pd, 2, 2);
    delete2dArray(pd, 2, 2);
    return 0;
}

template <typename T>
void make2dArray(T ** & px, int num_row, int num_column)
{
    px = new T * [num_row];
    for (int i = 0; i < num_row; ++i)
        *(px + i) = new T [num_column];
}

template <typename T>
void show2dArray(T ** & px, int num_row, int num_column)
{
    for (int i = 0; i < num_row; ++i)
    {
        for (int j = 0; j < num_column; ++j)
            std::cout << px[i][j] << '\t';
        std::cout << std::endl;
    }
}

template <typename T>
void delete2dArray(T ** & px, int num_row, int num_column)
{
    for (int i = 0; i < num_row; ++i)
        delete [] *(px + i);
    delete [] px;
    px = nullptr;
}
