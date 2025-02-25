// ReverseArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//This program contains two functions 
// the first takes a constant Array and the size of that array and returns a new array in reversed order,
// the second takes a constant array and its size and displays it

#include <iostream>


using namespace std;

int* ReverseArray(int const arr[], int size);
void print(int const arr[], int size);

int main()
{
    const int array[] = { 1,2,3,4,5 };
    const int size = 5;
    print(array, size);
    int* rev = ReverseArray(array, size);
    print(rev, size);
    delete[] rev;
    return 0;
}
/// <summary>
/// takes a constant Array and the size of that array and returns a new array in reversed order,
/// Dont forget to delete that new array!
/// </summary>
/// <param name="arr">constant array to be reversed</param>
/// <param name="size">size of array to be reversed</param>
/// <returns>reversed array of specified size</returns>
int* ReverseArray(int const arr[], int size) {
    int* rev = new int[size];
    for (int i = 0; i < size; i++) {
        rev[size - (1 + i)] = arr[i];
    }
    cout << endl;
    return rev;
}
/// <summary>
/// takes a constant array and its size and displays it
/// </summary>
/// <param name="arr">the array to be displayed</param>
/// <param name="size">the size of the array to be displayed</param>
void print(int const arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
