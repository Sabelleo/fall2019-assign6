#include <iostream>
#include <fstream>
#include <string>
#include <ctime> // gives me CLOCKS_PER_SEC

using namespace std;

class Sort{
  public:
    Sort(); // constructor
    ~Sort(); // destructor
    void bubbleSort(int size, double * arr);
    void selectionSort(int size, double * arr);
    void insertionSort(int size, double * arr);
    void quickSort(double * arr, int low, int high);
    int partition(double * arr, int low, int high);

    void read(string fileName); // reads the deets
    void output(); // prints the deets
    void run(string fileName); // runs the deets

  private:
    ifstream input;
    int size; // array size

    double* aBubble;
    double* aInsert;
    double* aSelect;
    double* aQuick;
    double newVal;

    clock_t sBubble;
    clock_t eBubble;
    double timeBubble;

    clock_t sInsert;
    clock_t eInsert;
    double timeInsert;

    clock_t sSelect;
    clock_t eSelect;
    double timeSelect;

    clock_t sQuick;
    clock_t eQuick;
    double timeQuick;
};
