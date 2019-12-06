#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <array>
using namespace std;
#include "Data.h"

//template code from ppt
template<typename T>
void bubbleSort(vector <T>& a, int size) {
    int i, j;
    bool swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = false;
        for (j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                T temp=a.at(j);//swaps values
                a.at(j)=a.at(j+1);
                a.at(j+1)=temp;
                swapped = true;
            }
        }
    }
}
//changed array to vector and template format
//quick sort
template <typename T>
int Partition(vector<T>& numbers, int i, int k) {
    int l;//low
    int h;//high
    int midpoint;//middle
    T temp;
    bool done;
    //middle is pivot
    midpoint = i + (k - i) / 2;
    T pivot = numbers.at(midpoint);
    done = false;
    l = i;
    h = k;
    while (!done) {
        while (numbers.at(l) < pivot) {//increment
            ++l;
        }
        while (pivot < numbers.at(h)) {//decrement
            --h;
        }
        if (l >= h) {
            done = true;
        }
        else {
            temp = numbers.at(l);
            numbers.at(l) = numbers.at(h);
            numbers.at(h) = temp;
            ++l;
            --h;
        }
    }
    return h;
}
//quick sort
//changed array to vector/template format
template <typename T>
void Quicksort(vector<T>& numbers, int i, int k) {
    int j;
    if (i >= k) {//base case
        return;
    }
    j = Partition(numbers, i, k);
    //recursive
    Quicksort(numbers, i, j);
    Quicksort(numbers, j + 1, k);
}
//selection sort
template <typename T>
void SelectionSort(vector<T>& numbers, int numbersSize) {
    int i;
    int j;
    int indexSmallest;
    //temp var for swap
    T temp;
    for (i = 0; i < numbersSize - 1; ++i) {
        indexSmallest = i;//smallest remaining element
        for (j = i + 1; j < numbersSize; ++j) {
            if (numbers.at(j) < numbers.at(indexSmallest)) {
                indexSmallest = j;
            }
        }
        //swap below
        temp = numbers[i];
        numbers[i] = numbers[indexSmallest];
        numbers[indexSmallest] = temp;
    }
}

//merge sorted lists below
template <typename T>
void mergeSortedLists(vector<T>& a, vector<T>& tmp, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;
    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmp[tempPos++] = a[leftPos++];
        } else {
            tmp[tempPos++] = a[rightPos++];
        }
    }
    while (leftPos <= leftEnd) {
        tmp[tempPos++] = a[leftPos++];
    }
    while (rightPos <= rightEnd) {
        tmp[tempPos++] = a[rightPos++];
    }
    for (int i = 0; i < numElements; i++, --rightEnd) {
        a[rightEnd] = tmp[rightEnd];
    }
}
//merge sort below
template <typename T>
void mergeSort(vector<T>& a, vector<T>& tmp, int left, int right) {
    if (left < right) {
        int center = ( left + right ) / 2;
        mergeSort(a, tmp, left, center);
        mergeSort(a, tmp, center + 1, right);
        mergeSortedLists(a, tmp, left, center + 1, right);
    }
}

//main function
int main() {
    //input and output files
    ifstream inFile;
    ofstream outFile;
    int length;
    cout << "Vector length: " << endl;
    cin >> length;
    //open files
    inFile.open("../NYPDShootings.csv");
    //creating vectors
    vector<Data> dataV;
    vector<Data> dataV_B;//bubble sort
    vector<Data> dataV_S;//selection sort
    vector<Data> dataV_Q;//quick sort
    vector<Data> dataV_M;//merge sort
    vector<Data> dataV_tempM;//merge sort
    vector<int> intV;
    vector<int> intV_B;//bubble sort
    vector<int> intV_S;//selection sort
    vector<int> intV_Q;//quick sort
    vector<int> intV_M;//merge sort
    vector<int> intV_tempM;//merge sort

    if(!inFile.is_open()){//enters if file is not found or cannot be opened
        cout << "Input file did not open." << endl;
    } else{
        cout << "Input file opened." << endl;
    }
    int i=0;
    while(i<length){
        string PRECINCT,JURISDICTIONCODE,XCOORD,YCOORD;
        getline(inFile,PRECINCT, ',');
        getline(inFile,JURISDICTIONCODE,',');
        getline(inFile,XCOORD, ',');
        getline(inFile,YCOORD, '\n');

        int PREC,JURIS, XCOO,YCOO;
        PREC = stoi(PRECINCT);
        JURIS=stoi(JURISDICTIONCODE);
        XCOO = stoi(XCOORD);
        YCOO = stoi(YCOORD);

        Data computerUsageData = Data(PREC, JURIS, XCOO, YCOO);
        dataV.push_back(computerUsageData);//push to stack and queue
        i++;
    }

    //making copies
    dataV_B = dataV;//bubble sort
    dataV_S = dataV;//selection sort
    dataV_Q = dataV;//quick sort
    dataV_M = dataV;//merge sort
    dataV_tempM = dataV;

    srand(time(NULL));//resets to current time
    for(int i=0; i<length;i++){
        int randNum = rand()% 100;
        intV.push_back(randNum);
    }

    //copy the vector to be sorted
    intV_B = intV;//bubble sort
    intV_S = intV;//selection sort
    intV_Q = intV;//quick sort
    intV_M = intV;//merge sort
    intV_tempM = intV;

    cout << "SORTING DATA" << endl;

    //bubble sort
    clock_t start_BubbleSort = clock();//start clock to track time
    bubbleSort(dataV_B, dataV_B.size()-1);
    clock_t end_BubbleSort = clock();
    double elapsed_BubbleSort = double(end_BubbleSort - start_BubbleSort) / CLOCKS_PER_SEC;//calculate seconds
    cout << "Elapsed Time Data Bubble sort : "<< elapsed_BubbleSort <<endl;

    clock_t start_BubbleSort2 = clock();//start clock to track time
    //bubble sort on data again
    bubbleSort(dataV_B, dataV_B.size()-1);
    clock_t end_BubbleSort2 = clock();
    double elapsed_BubbleSort2 = double(end_BubbleSort2 - start_BubbleSort2) / CLOCKS_PER_SEC;//calculate seconds
    cout <<"Elapsed Time Data Bubble sort again : "<< elapsed_BubbleSort2 <<endl;

    //selection sort
    clock_t start_SelectionSort = clock();//start clock to track time
    //selection sort on data
    SelectionSort(dataV_S,dataV_S.size()-1);
    clock_t end_SelectionSort = clock();
    double elapsed_SelectionSort = double(end_SelectionSort - start_SelectionSort) / CLOCKS_PER_SEC;//calculate seconds
    cout <<"Elapsed Time Data Selection sort : "<< elapsed_SelectionSort <<endl;

    clock_t start_SelectionSort2 = clock();//start clock to track time
    //selection sort on data again
    SelectionSort(dataV_S,dataV_S.size()-1);
    clock_t end_SelectionSort2 = clock();
    double elapsed_SelectionSort2 = double(end_SelectionSort2 - start_SelectionSort2) / CLOCKS_PER_SEC;//calculate seconds
    cout <<"Elapsed Time Data Selection sort again : "<< elapsed_SelectionSort2 <<endl;

    //quick sort
    clock_t start_QuickSort = clock();//start clock to track time
    //quick sort on data
    Quicksort(dataV_Q, 0, dataV_Q.size()-1);
    clock_t end_QuickSort = clock();
    double elapsed_QuickSort = double(end_QuickSort - start_QuickSort) / CLOCKS_PER_SEC;//calculate seconds
    cout <<"Elapsed Time Data Quick sort : "<< elapsed_QuickSort <<endl;

    clock_t start_QuickSort2 = clock();//start clock to track time
    //quick sort on data again
    Quicksort(dataV_Q, 0, dataV_Q.size()-1);
    clock_t end_QuickSort2 = clock();//end clock to track time
    double elapsed_QuickSort2 = double(end_QuickSort2 - start_QuickSort2) / CLOCKS_PER_SEC;//calculate seconds
    cout <<"Elapsed Time Data Quick sort again : "<< elapsed_QuickSort2 << endl;

    //merge sort
    clock_t start_MergeSort = clock();//start clock to track time
    //merge on data
    mergeSort(dataV_M, dataV_tempM, 0, dataV_M.size()-1);
    clock_t end_MergeSort = clock();//end clock to track time
    double elapsed_MergeSort = double(end_MergeSort - start_MergeSort) / CLOCKS_PER_SEC;//calculate seconds
    cout << "Elapsed Time Data Merge sort : "<< elapsed_MergeSort << endl;

    clock_t start_MergeSort2 = clock();//start clock to track time
    //merge on data again
    mergeSort(dataV_M, dataV_tempM, 0, dataV_M.size()-1);
    clock_t end_MergeSort2 = clock();//end clock to track time
    double elapsed_MergeSort2 = double(end_MergeSort2 - start_MergeSort2) / CLOCKS_PER_SEC;//calculate seconds
    cout << "Elapsed Time Data Merge sort again : " << elapsed_MergeSort2 << endl;

    cout<<"SORTING INT"<<endl;

    //bubble sort int
    clock_t start_intBubbleSort = clock();//start clock to track time
    //bubble sort on data
    bubbleSort(intV_B, intV_B.size()-1);
    clock_t end_intBubbleSort = clock();//end clock to track time
    double elapsed_intBubbleSort = double(end_intBubbleSort - start_intBubbleSort) / CLOCKS_PER_SEC;//calculate seconds
    cout <<"Elapsed Time int Bubble sort : " << elapsed_intBubbleSort << endl;

    clock_t start_intBubbleSort2 = clock();//start clock to track time
    //bubble sort on data again
    bubbleSort(intV_B, intV_B.size()-1);
    clock_t end_intBubbleSort2 = clock();//end clock to track time
    double elapsed_intBubbleSort2 = double(end_intBubbleSort2 - start_intBubbleSort2) / CLOCKS_PER_SEC;//calculate seconds
    cout << "Elapsed Time int Bubble sort again : " << elapsed_intBubbleSort2 <<endl;

    //selection sort int
    clock_t start_intSelectionSort = clock();//start clock to track time
    //selection sort on data
    SelectionSort(intV_S,intV_S.size()-1);
    clock_t end_intSelectionSort = clock();//end clock to track time
    double elapsed_intSelectionSort = double(end_intSelectionSort - start_intSelectionSort) / CLOCKS_PER_SEC;//calculate seconds
    cout << "Elapsed Time int Selection sort : " << elapsed_intSelectionSort << endl;

    clock_t start_intSelectionSort2 = clock();//start clock to track time
    //selection sort on data again
    SelectionSort(intV_S,intV_S.size()-1);
    clock_t end_intSelectionSort2 = clock();//end clock to track time
    double elapsed_intSelectionSort2 = double(end_intSelectionSort2 - start_intSelectionSort2) / CLOCKS_PER_SEC;//calculate seconds
    cout <<"Elapsed Time intSelection sort again : "<< elapsed_intSelectionSort2 <<endl;

    //quick sort int
    clock_t start_intQuickSort = clock();//start clock to track time
    //quick sort on data
    Quicksort(intV_Q, 0, intV_Q.size()-1);
    clock_t end_intQuickSort = clock();//end clock to track time
    double elapsed_intQuickSort = double(end_intQuickSort - start_intQuickSort) / CLOCKS_PER_SEC;//calculate seconds
    cout <<"Elapsed Time int Quick sort : "<< elapsed_intQuickSort <<endl;

    clock_t start_intQuickSort2 = clock();//start clock to track time
    //quick sort on data again
    Quicksort(intV_Q, 0, intV_Q.size()-1);
    clock_t end_intQuickSort2 = clock();//end clock to track time
    double elapsed_intQuickSort2 = double(end_intQuickSort2 - start_intQuickSort2) / CLOCKS_PER_SEC;//calculate seconds
    cout <<"Elapsed Time int Quick sort again : "<< elapsed_intQuickSort2 <<endl;

    //merge sort
    clock_t start_intMergeSort = clock();//start clock to track time
    //merge on data
    mergeSort(intV_M, intV_tempM,0, intV_M.size()-1);
    clock_t end_intMergeSort = clock();//end clock to track time
    double elapsed_intMergeSort = double(end_intMergeSort - start_intMergeSort) / CLOCKS_PER_SEC;//calculate seconds
    cout <<"Elapsed Time int Merge sort : "<< elapsed_intMergeSort <<endl;

    clock_t start_intMergeSort2 = clock();//start clock to track time
    //merge on data again
    mergeSort(intV_M, intV_tempM, 0, intV_M.size()-1);
    clock_t end_intMergeSort2 = clock();//end clock to track time
    double elapsed_intMergeSort2 = double(end_intMergeSort2 - start_intMergeSort2) / CLOCKS_PER_SEC;//calculate seconds
    cout <<"Elapsed Time int Merge sort again : "<< elapsed_intMergeSort2 <<endl;

    //close file
    inFile.close();
    return 0;
}