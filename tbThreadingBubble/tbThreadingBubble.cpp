#include <iostream>
#include <thread>

// antal element i arrayen som ska sorteras
#define MAX 20

// antal maximala trådar
#define THREAD_MAX 4

using namespace std;

// array med storleken MAX
int array_to_sort[MAX];
int part = 0;

//Metod som byter två tal
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Funktion som implementerar bubblesort
void bubbleSort(int arr[], int start, int end)
{
    int i, j;
    for (i = start; i < end; i++)
        // Last i elements are already in place 
        for (j = start; j < end - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

//Metod som skriver ut arrayen
void printArray(int arr[], int start, int end)
{
    int i;
    for (i = start; i < end; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main()
{

    //Fyll arrayen med slumpade tal mellan 0 - 99
    for (int i = 0; i < MAX; i++)
        array_to_sort[i] = rand() % 100;

    //Få total storlek av arrayen
    //int n = sizeof(array_to_sort) / sizeof(array_to_sort[0]);

    cout << "Osorted array: " << endl;
    printArray(array_to_sort, 0, MAX);

    //Utför bubbelsortering med en tråd (som inte är huvudtråden)
    thread t = thread(bubbleSort, array_to_sort, 0, MAX);
    t.join();

    cout << "Sorterad array: " << endl;
    printArray(array_to_sort, 0, MAX);

    return 0;
}


