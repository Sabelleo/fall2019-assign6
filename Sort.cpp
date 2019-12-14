#include "Sort.h"

using namespace std;

//Assignment 6

Sort::Sort() // Constructor
{
  size = 0;
  newVal = 0.0;

  sBubble = 0.0;
  eBubble = 0.0;
  timeBubble = 0.0;
  sInsert = 0.0;
  eInsert = 0.0;
  timeInsert = 0.0;
  sSelect = 0.0;
  eSelect = 0.0;
  timeSelect = 0.0;
  sQuick = 0.0;
  eQuick = 0.0;
  timeQuick = 0.0;
}

Sort::~Sort() // Destructor
{
  delete[] aBubble;
  delete[] aInsert;
  delete[] aSelect;
  delete[] aQuick;
}

void Sort::bubbleSort(int s, double * arr){ // Bubble Sort
  for (int i = 0; i < s; ++i){
    int temp = 0;
    for (int j = 0; j < s; ++j){
      if (arr[j] > arr[j+1]){
        temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void Sort::selectionSort(int s, double * arr){ // Selection Sort
  int minIndex, temp;
  for (int i = 0; i < s; i++){
    minIndex = i;
    for (int j = i + 1; j < s; ++j){
      if (arr[j] < arr[minIndex])
        minIndex = j;
    }
    if (minIndex != i){
      temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
}

void Sort::insertionSort(int s, double * arr){ // Insertion Sort
  for (int i = 1; i < s; i++){ //marker
    int temp = arr[i]; //store marked item
    int j = i - 1; //where to start shifting
    while (j >= 0 && arr[j] > temp){ //while left thing is larger, shift
      arr[j + 1] = arr[j]; //fill in
      j -= 1;
    }
    arr[j + 1] = temp; //put marked item in right spot
  }
}

void Sort::quickSort(double * arr, int low, int high){ // quick sort, recursive
  if (low > high){
    int part = partition(arr, low, high);
    quickSort(arr, low, part); //left side, recursive
    quickSort(arr, part + 1, high); // right side, recursive
  }
}

int Sort::partition(double * arr, int low, int high){ // quick sort partition
  double pivot = arr[high];
  int i = low - 1;
  int temp;
  for (int j = low; j < high; ++j){
    if (arr[j] <= pivot){
      i++;
      temp = arr[i]; //add & to array stuff? // switch
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[i + 1]; // switch
  arr[i + 1] = arr[high];
  arr[high] = temp;
  return (i + 1);
}

void Sort::read(string fileName){
  input.open(fileName);
  if(input.fail()){
    cout << "File does not exist! Try again." << endl;
  }
  else{
    input >> size; // get array ize

    aBubble = new double[size]; //make fout of em!
    aInsert = new double[size];
    aSelect = new double[size];
    aQuick = new double[size];

    for (int i = 0; i < size; ++i){
      input >> newVal;
      aBubble[i] = newVal;
      aInsert[i] = newVal;
      aSelect[i] = newVal;
      aQuick[i] = newVal;
    }
  }
  input.close();
}

void Sort::output(){
  // Bubble
  cout << "Bubble Sort: " << endl;
  timeBubble = double(eBubble - sBubble)/CLOCKS_PER_SEC;
  cout << "Start time: " << sBubble << endl;
  cout << "End time: " << eBubble << endl; // compare lengths of time easily
  cout << "Length of time: " << timeBubble << endl;

  // Insertion
  cout << "Insertion Sort: " << endl;
  timeInsert = double(eInsert - sInsert)/CLOCKS_PER_SEC;
  cout << "Start time: " << sInsert << endl;
  cout << "End time: " << eInsert << endl;
  cout << "Length of time: " << timeInsert << endl;

  // Selection
  cout << "Selection Sort: " << endl;
  timeSelect = double(eSelect - sSelect)/CLOCKS_PER_SEC;
  cout << "Start time: " << sSelect << endl;
  cout << "End time: " << eSelect << endl;
  cout << "Length of time: " << timeSelect << endl;

  // Quick
  cout << "Quick Sort: " << endl;
  timeQuick = double(eQuick - sQuick)/CLOCKS_PER_SEC;
  cout << "Start time: " << sQuick << endl;
  cout << "End time: " << eQuick << endl;
  cout << "Length of time: " << timeQuick << endl;
}

void Sort::run(string fileName){
  read(fileName);

  // c time it
  sBubble = clock();
  bubbleSort(size, aBubble);
  eBubble = clock();

  sInsert = clock();
  insertionSort(size, aInsert);
  eInsert = clock();

  sSelect = clock();
  selectionSort(size, aSelect);
  eSelect = clock();

  sQuick = clock();
  quickSort(aQuick, 0, size - 1);
  eQuick = clock();
  output();
}
