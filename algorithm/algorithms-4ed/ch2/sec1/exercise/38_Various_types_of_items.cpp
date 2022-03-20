/* 2.1.38  Various types of items. Write a client that generates arrays of items
 * of various */
/* types with random key values, including the following: */

/* * String key (at least ten characters), one double value */
/* * double key, ten String values (all at least ten characters) */
/* * int key, one int[20] value */

/* Develop and test hypotheses about the effect of such input on the performance
 * of the */

#include <array>
#include <ctime>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename _Tp1, typename _Tp2> class Expreiments {
  enum SortType { SELECTION, INSERTION, SHELL };

public:
  void runAllExperiments(int, int);

private:
  void runExperiments(vector<unordered_map<_Tp1, _Tp2>> &);
  double timer(vector<unordered_map<_Tp1, _Tp2>> &, SortType);
  void printExperiment(SortType, int, double);

private:
  void selectionSort(unordered_map<_Tp1, _Tp2>)

private:
  vector<unordered_map<string, double>> generateStringKeyDoubleValuesArray(int);
  vector<unordered_map<double, array<string, 10>>> generateDoubleKeyStringValuesArray(int);
  vector<unordered_map<int, array<int, 20>>> generateIntKeyIntArrayValuesArray(int);

private:
  array<string, 10> generate10CharRandomString();
  double generateRandomDouble(double min = 0.0, double max = 1.0);
  int generateRandomInt(int min = 0, int max = 100);
  array<int, 20> generaterandomIntArray();
};

/////////////////////////////////////////////////////////////
//
//                      Random Generator
//
/////////////////////////////////////////////////////////////

template <typename _Tp1, typename _Tp2>
inline double Expreiments<_Tp1, _Tp2>::generateRandomDouble(double min,
                                                            double max) {
  srand(time(0));
  return static_cast<double>(rand()) / RAND_MAX * (max - min) + min;
};


template <typename _Tp1, typename _Tp2>
inline int Expreiments<_Tp1, _Tp2>::generateRandomInt(int min, int max) {
  srand(time(0));
  return rand() % (max - min) + min;
};


template <typename _Tp1, typename _Tp2>
inline array<int, 20> Expreiments<_Tp1, _Tp2>::generaterandomIntArray() {
  array<int, 20> ret;

  for (int i = 0; i < ret.size(); ++i) {
    ret[i] = generateRandomInt();
  }

  return ret;
};


template <typename _Tp1, typename _Tp2>
inline array<string, 10> Expreiments<_Tp1, _Tp2>::generate10CharRandomString() {
  array<string, 10> ret;
  
  for (int i = 0; i < 10; ++i) {
    string str(10, ' ');

    for (auto &ch : str) {
      ch = rand() % 26 + 97;
    }

    ret[i] = str;
  }

  return ret;
};


/////////////////////////////////////////////////////////////
//
//                      Array Generator
//
/////////////////////////////////////////////////////////////


template <typename _Tp1, typename _Tp2>
inline vector<unordered_map<string, double>>
Expreiments<_Tp1, _Tp2>::generateStringKeyDoubleValuesArray(int arraySize) {
  vector<unordered_map<string, double>> ret;

  for (int i = 0; i < arraySize; ++i) {
    unordered_map<string, double> keyValues;

    string randomKey = generate10CharRandomString();
    auto randomValue = generateRandomDouble();
    keyValues[randomKey] = randomValue;

    ret.push_back(keyValues);
  }

  return ret;
};


template <typename _Tp1, typename _Tp2>
inline vector<unordered_map<double, array<string, 10>>>
Expreiments<_Tp1, _Tp2>::generateDoubleKeyStringValuesArray(int arraySize) {
  vector<unordered_map<double, array<string, 10>>> ret;

  for (int i = 0; i < arraySize; ++i) {
    unordered_map<double, array<string, 10>> keyValues;

    auto randomKey = generateRandomDouble();
    auto randomValue = generate10CharRandomString();
    keyValues[randomKey] = randomValue;

    ret.push_back(keyValues);
  }

  return ret;
}


template <typename _Tp1, typename _Tp2>
inline vector<unordered_map<int, array<int, 20>>>
Expreiments<_Tp1, _Tp2>::generateIntKeyIntArrayValuesArray(int arraySize) {
  vector<unordered_map<int, array<int, 20>>> ret;

  for (int i = 0; i < arraySize; ++i) {
    unordered_map<int, array<int, 20>> keyValues;

    auto randomKey = generateRandomInt();
    auto randomValue = generaterandomIntArray();
    keyValues[randomKey] = randomValue;

    ret.push_back(keyValues);
  }

  return ret;
}

/////////////////////////////////////////////////////////////
//
//                      Sorter
//
/////////////////////////////////////////////////////////////


void selectionSort()


/////////////////////////////////////////////////////////////
//
//                      Handler
//
/////////////////////////////////////////////////////////////

template <typename _Tp1, typename _Tp2>
double Expreiments<_Tp1, _Tp2>::timer(vector<unordered_map<_Tp1, _Tp2>> &array,
                                      SortType sortType) {
  auto t1 = clock();

  switch (sortType) {
  case SELECTION:
    selectionSort(array);
    break;
  case INSERTION:
    insertionSort(array);
    break;
  case SHELL:
    shellSort(array);
    break;
  }

  auto t2 = clock();

  return static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;
}

template <typename _Tp1, typename _Tp2>
void Expreiments<_Tp1, _Tp2>::runExperiments(
    vector<unordered_map<_Tp1, _Tp2>> &array) {
  auto arrayCopy1 = array;
  auto arrayCopy2 = array;

  double timeSelection = timer(array, SELECTION);
  double timeInsertion = timer(array, INSERTION);
  double timeShell = timer(array, SHELL);
}

template <typename _Tp1, typename _Tp2>
inline void Expreiments<_Tp1, _Tp2>::runAllExperiments(int initialArraySize,
                                                       int experiments) {
  int arraySize = initialArraySize;
  printf("%15s %17s %8s\n", "Sort Type", "Array Length", "Time");

  printf("String key, one double value");
  for (int experiment = 0; experiment < experiments; ++experiment) {
    auto stringKeyDoubleValueArray =
        generateStringKeyDoubleValuesArray(arraySize);
    runExperiments(stringKeyDoubleValueArray);
    arraySize *= 2;
  }

  printf("\n\n");
  arraySize = initialArraySize;

  printf("Double key, ten String values");
  for (int experiment = 0; experiment < experiments; ++experiment) {
    auto doubleKeyStringValuesArray =
        generateDoubleKeyStringValuesArray(arraySize);
    runExperiments(doubleKeyStringValuesArray, STRING);
    arraySize *= 2;
  }

  printf("\n\n");
  arraySize = initialArraySize;

  printf("Int key, int array value");
  for (int experiment = 0; experiment < experiments; ++experiment) {
    auto intKeyIntArrayValuesArray =
        generateIntKeyIntArrayValuesArray(arraySize);
    runExperiments(intKeyIntArrayValuesArray, STRING);
    arraySize *= 2;
  }
};

int main(int argc, char **argv) {
  int arraySize = std::stoi(argv[1]);
  int experiments = std::stoi(argv[2]);
  Expreiments<string, double> exp;

  exp.runAllExperiments(arraySize, experiments);

  return 0;
}
