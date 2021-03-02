#include <iostream>
#include <fstream>

//#include "Plot_Graphs/matplotlibcpp.h"
#include "Other_Headers/BinarySearchTree.hpp"
#include "Insertion_Sort/insertionSort.hpp"
//#include "Merge_Sort/mergeSort.hpp"
//#include "Heap_Sort/heapSort.hpp"
#include "Quick_Sort/quickSort.hpp"
#include "Randomised_Quick_Sort/randomisedQuickSort.hpp"

#define MAX 1000        //Array indexing starts from 1, 2, 3...

using namespace std;

class Sortings
{
    private:
        int size;
        int array[MAX];
        
    public:
        int ch;
        void options();
        int choice();
        void choiceCalling(int);

        void best_case(int);
        void average_case(int);
        void worst_case(int);

        void insertion_sort(int *);
        void merge_sort();
        void heap_sort();
        void quick_sort(int *);
        void randomised_quick_sort(int *);

        void file_writer(string, string, int);
};

void Sortings::options()
{
    cout << "\n------- MENU -------";
    cout << "\n1. INSERTION SORT"
        << "\n2. MERGE SORT"
        << "\n3. HEAP SORT"
        << "\n4. QUICK SORT"
        << "\n5. RANDOMISED QUICK SORT"
        << "\n0. EXIT";
}

int Sortings::choice()
{
    cout << "\n\nEnter the number of your choice: ";
    cin >> ch;
    return ch;
}

void Sortings::choiceCalling(int ch)
{
    int key;
    switch(ch)
    {
        case 1:
            insertion_sort(array);
            break;
        case 2:
            
            break;
        case 3:
            break;
        case 4:
            quick_sort(array);
            break;
        case 5:
            randomised_quick_sort(array);
            break;
        case 0:
            break;
        default:
            cout << "\n########### WRONG CHOICE... ###########\n";
    }
}

void Sortings::best_case(int size)
{
    for(int i=1; i<=size; i++)
        array[i] = i;
}

void Sortings::average_case(int size)
{
    // Generating randomm numbers in the array
    for(int i=1; i<=size; i++)
        array[i] = rand() % 1000;
}

void Sortings::worst_case(int size)
{
    for(int i=1; i<=size; i++)
        array[i] = size - i;
}

void Sortings::file_writer(string fileName, string Case, int comparisons)
{
    ofstream fout;
    
    fout.open(fileName, ios::app);

    if(Case != "worst")
        fout << comparisons << ", ";
    else
        fout << comparisons << endl;

    fout.close();
}

void Sortings::insertion_sort(int *array)
{
    Insertion_Sort insert;
    ofstream fout;

    cout << "\n=========== INSERTION SORT ===========";

    fout.open("Insertion_Sort/comp.csv", ios::trunc);
    fout << "Best, " << "Average, " << "Worst\n";
    fout.close();

    for(size=10; size<=1000; size=size+10)
    {
        int comparisons = 0;
        for(int i=0; i<=size; i++)
            array[i] = 0;

        //Best Case
        best_case(size);

        comparisons = insert.insertion_sort(array, size);
        file_writer("Insertion_Sort/comp.csv", "best", comparisons);
        
        //Average Case
        average_case(size);

        comparisons = insert.insertion_sort(array, size);
        file_writer("Insertion_Sort/comp.csv", "average", comparisons);
            
        //Worst Case
        worst_case(size);

        comparisons = insert.insertion_sort(array, size);
        file_writer("Insertion_Sort/comp.csv", "worst", comparisons);
    }
    
    cout << "\nCompleted INSERTION SORT!\n";
}

void Sortings::quick_sort(int *array)
{
    Quick_Sort quick;
    ofstream fout;

    cout << "\n=========== QUICK SORT ===========";
    
    fout.open("Quick_Sort/comp.csv", ios::trunc);
    fout << "Best, " << "Average, " << "Worst\n";
    fout.close();
    
    for(size=10; size<=1000; size=size+10)
    {
        int comparisons = 0;
        for(int i=0; i<=size; i++)
            array[i] = 0;

        //Best Case
        /**
         * @brief We use Binary Search Tree to construct post-order of sorted array in ascending
         *        order. Since post-order partitions' the array in exactly two halves, i.e.,
         *        from the median.
         * 
         *        Time Complexity: O(nlog(n))
         * 
         */
        binarySearchTree binary;
        best_case(size);
        array = binary.itr_post_order(array, size);
        
        comparisons = quick.quick_sort(array, 1, size);
        file_writer("Quick_Sort/comp.csv", "best", comparisons);
        
        // Average Case:    Time Complexity: O(nlog(n))
        average_case(size);
        
        comparisons = quick.quick_sort(array, 1, size);
        file_writer("Quick_Sort/comp.csv", "average", comparisons);
        
        // Worst Case
        /**
         * @brief The worst case occurs when the partition process always picks greatest or
         *        smallest element as pivot. If we consider above partition strategy where
         *        last element is always picked as pivot, the worst case would occur when the
         *        array is already sorted in increasing or decreasing order.
         * 
         *        Time Complexity: O(n^2)
         * 
         */
        worst_case(size);
        
        comparisons = quick.quick_sort(array, 1, size);
        file_writer("Quick_Sort/comp.csv", "worst", comparisons);
    }

    cout << "\nCompleted QUICK SORT!\n";
}

void Sortings::randomised_quick_sort(int *array)
{
    Randomised_Quick_Sort random_quick;
    ofstream fout;

    cout << "\n=========== QUICK SORT ===========";
    
    fout.open("Randomised_Quick_Sort/comp.csv", ios::trunc);
    fout << "Best, " << "Average, " << "Worst\n";
    fout.close();
    
    for(size=10; size<=1000; size=size+10)
    {
        int comparisons = 0;
        for(int i=0; i<=size; i++)
            array[i] = 0;

        //Best Case
        binarySearchTree binary;
        best_case(size);
        array = binary.itr_post_order(array, size);
        
        comparisons = random_quick.randomised_quick_sort(array, 1, size);
        file_writer("Randomised_Quick_Sort/comp.csv", "best", comparisons);
        
        // Average Case
        average_case(size);
        
        comparisons = random_quick.randomised_quick_sort(array, 1, size);
        file_writer("Randomised_Quick_Sort/comp.csv", "average", comparisons);
        
        // Worst Case
        worst_case(size);
        
        comparisons = random_quick.randomised_quick_sort(array, 1, size);
        file_writer("Randomised_Quick_Sort/comp.csv", "worst", comparisons);
    }

    cout << "\nCompleted RANDOMISED QUICK SORT!\n";
}

int main()
{
    int choice;
    Sortings sort;
    do
    {
        cout << "\n=========== SORTING TECHNIQUES ===========\n";
        sort.options();
        choice = sort.choice();
        if(sort.ch == 0)
            break;
        system("clear");
        cout << "\n=========== SORTING TECHNIQUES ===========\n";
        sort.choiceCalling(choice);
        cout << "\nPress Enter to continue...";
        cin.ignore();
        getchar();
        system("clear");
    }while(1);
    
    return 0;
}