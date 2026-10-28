#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void BST(int arr[], int &index, int lower, int upper, int N)
{
    // Base Case: Agar range se bahar hai ya array khatam
    if (index == N || arr[index] < lower || arr[index] > upper)
        return;

    // Current element range mein hai, toh ise root maan kar aage badho
    int value = arr[index];
    index++;

    // Left child ki range: (lower, value)
    BST(arr, index, lower, value, N);

    // Right child ki range: (value, upper)
    BST(arr, index, value, upper, N);
}

int canRepresentBST(int arr[], int N)
{
    int index = 0;
    // Sirf function call karo, ye 'index' ko reference se update karega
    BST(arr, index, INT_MIN, INT_MAX, N);

    // Agar index N tak pahunch gaya, matlab har element sahi 'range' mein fit ho gaya
    return index == N;
}

int main()
{
    // Case 1: Valid Preorder
    int arr1[] = {40, 30, 35, 80, 100};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    if (canRepresentBST(arr1, n1))
        cout << "Array 1: Valid BST representation" << endl;
    else
        cout << "Array 1: Not a BST" << endl;

    // Case 2: Invalid Preorder (45, 80 ke baad nahi aa sakta agar root 40 hai)
    int arr2[] = {40, 30, 35, 20, 80, 100};
    // Isme 20, 35 ke baad aa raha hai (Right child ke subtree mein), jo galat hai
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    if (canRepresentBST(arr2, n2))
        cout << "Array 2: Valid BST representation" << endl;
    else
        cout << "Array 2: Not a BST" << endl;

    return 0;
}

// This code give the segmentation fault, want to access the memory jisko access karne ki permission nahi hai.