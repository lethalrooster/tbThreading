#include <iostream>
#include <thread>

#include <ctime>
#include <ratio>
#include <chrono>

// antal element i arrayen som ska sorteras
#define MAX 100000

// antal maximala trådar
#define THREAD_MAX 4

using namespace std;
using namespace std::chrono;

// array med storleken MAX
int array_to_sort[MAX];
int array_to_sort1[MAX];
int array_to_sort2[MAX];
int array_to_sort3[MAX];
int array_to_sort4[MAX];
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
        for (j = start; j < end - start - i - 1; j++)
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
    {
        array_to_sort[i] = rand() % 100;
        array_to_sort1[i] = rand() % 100;
        array_to_sort2[i] = rand() % 100;
        array_to_sort3[i] = rand() % 100;
        array_to_sort4[i] = rand() % 100;
    }

    //Få total storlek av arrayen
    //int n = sizeof(array_to_sort) / sizeof(array_to_sort[0]);

    //cout << "Osorted array: " << endl;
    //printArray(array_to_sort, 0, MAX);a
    
    high_resolution_clock::time_point time1 = high_resolution_clock::now();
    int part = MAX / 4;
    
    
    //Utför bubbelsortering med en tråd (som inte är huvudtråden)
    /*
    thread t1 = thread(bubbleSort, array_to_sort, 0, part - 1);
    thread t2 = thread(bubbleSort, array_to_sort, part, part * 2 - 1);
    thread t3 = thread(bubbleSort, array_to_sort, part * 2, part * 3 - 1);
    thread t4 = thread(bubbleSort, array_to_sort, part * 3, MAX);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    */

    bubbleSort(array_to_sort, 0, MAX);
    

    

    /*
    thread t1 = thread(bubbleSort, array_to_sort1, 0, MAX);
    thread t2 = thread(bubbleSort, array_to_sort2, 0, MAX);
    thread t3 = thread(bubbleSort, array_to_sort3, 0, MAX);
    thread t4 = thread(bubbleSort, array_to_sort4, 0, MAX);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    */

    /*bubbleSort(array_to_sort1, 0, MAX);
    bubbleSort(array_to_sort2, 0, MAX);
    bubbleSort(array_to_sort3, 0, MAX);
    bubbleSort(array_to_sort4, 0, MAX);*/

    high_resolution_clock::time_point time2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(time2 - time1);

    //cout << "Sorterad array: " << endl;
    //printArray(array_to_sort, 0, MAX);


    cout << "Det tog: " << time_span.count() << " sekunder.";

    return 0;
}


