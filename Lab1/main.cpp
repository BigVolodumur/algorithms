#include  <ctime>
#include<iostream>
#include <string>

using namespace std;

class Bicycle {
private:
    int gearNumber;
    double mass;
    double maxMas;
    string makerName;
public:
    Bicycle() {}

    Bicycle(int gearNumber, int mass, double maxMas, const string &makerName) : gearNumber(gearNumber),
                                                                                   mass(mass), maxMas(maxMas),
                                                                                   makerName(makerName) {}

    int getGearNumber() const {
        return gearNumber;
    }

    void setGearNumber(int gearNumber) {
        Bicycle::gearNumber = gearNumber;
    }

    int getMass() const {
        return mass;
    }

    void setMass(int mass) {
        Bicycle::mass = mass;
    }

    double getMaxMas() const {
        return maxMas;
    }

    void setMaxMas(double maxMas) {
        Bicycle::maxMas = maxMas;
    }

    const std::string &getMakerName() const {
        return makerName;
    }

    void setMakerName(const std::string &makerName) {
        Bicycle::makerName = makerName;
    }
};

void quickSort(Bicycle a[], int first, int last);
int pivot(Bicycle a[], int first, int last);
void swap(int &a, int &b);

int comparisonsQuick;
int exchangesQuick;

int main() {
    const int NUMBER_OF_BICYCLES = 10;
    //InsertionSort
    Bicycle list[NUMBER_OF_BICYCLES];
    for (int index = 0; index < NUMBER_OF_BICYCLES; index++) {
        list[index] = Bicycle(rand() % 9 + 3, rand() % 50 + 50, 100 + rand() % 100, "EE");
    }

    Bicycle key;
    int i;

    int comparisonsInsertion = 0;
    int exchangesInsertion = 0;

    cout << "Gear numbers:" << endl;
    for (int index = 0; index < NUMBER_OF_BICYCLES; index++) {
        cout << list[index].getGearNumber() << " ";
    }
    cout << endl;

    // insertion sort
    for (int j = 0; j < NUMBER_OF_BICYCLES; j++) {
        key = list[j];
        i = j - 1;
        while ((comparisonsInsertion++) && (i >= 0) && list[i].getGearNumber() < key.getGearNumber()) {
            list[i + 1] = list[i];
            i--;
            exchangesInsertion++;
        }
        list[i + 1] = key;
    }

    cout << "\nInsertion" << "\n\n";
    //Вивід часу роботи алготимму Insertion
    int timeInsertionSort = clock();
    cout << "Time\t" << ((float) timeInsertionSort / CLOCKS_PER_SEC) << endl;

    //Вивід кількості порівняня алготимму Insertion
    cout << "Number of exchanges " << exchangesInsertion << endl;
    cout << "Number of comparisons " << comparisonsInsertion << endl;

    //Вивід відсортованого алготимму Insertion
    cout << "Sorted gear numbers:" << endl;
    for (int index = 0; index < NUMBER_OF_BICYCLES; index++) {
        cout << list[index].getGearNumber() << " ";
    }
    cout << endl;
    //__________________________________________________________________________________________________________________//

    //QuickSort

    //Заповненя масиву рандомними числами
    exchangesQuick = 0;
    comparisonsQuick = 0;

    cout << "\n\nMasses:" << endl;
    for (int index = 0; index < NUMBER_OF_BICYCLES; index++) {
        cout << list[index].getMass() << " ";
    }
    cout << endl;

    int timeQuickSort = clock();

    clock_t start = clock();
    quickSort(list, 0, NUMBER_OF_BICYCLES - 1);

    //for (int i = 0; i < 10; i++)
    //{
    //	cout << i << endl;
    //}
    clock_t end = clock();

    double timeCheckpoint2 = ((double) timeQuickSort / CLOCKS_PER_SEC);

    cout << "\n\nQuickSort\n\n" << endl;

    cout << "Sorted masses:" << endl;
    for (int index = 0; index < NUMBER_OF_BICYCLES; index++) {
        cout << list[index].getMass() << " ";
    }
    cout << endl;

    double seconds = (double) (end - start) / CLOCKS_PER_SEC;
    cout << fixed << "Quick sort time is " << seconds << " s" << endl;
    cout << "Number of exchanges " << exchangesQuick << endl;
    cout << "Number of comparisons " << comparisonsQuick << endl;

    return 0;
}

//Функцфя сортуваня QuickSort
void quickSort(Bicycle a[], int first, int last) {
    int pivotElement;

    if (first < last) {
        pivotElement = pivot(a, first, last);
        quickSort(a, first, pivotElement - 1);
        quickSort(a, pivotElement + 1, last);
    }
}


int pivot(Bicycle a[], int first, int last) {
    extern int comparisonsQuick, exchangesQuick;
    int p = first;
    Bicycle pivotElement = a[first];

    for (int i = first + 1; i <= last; i++) {
        // По зростаню "<="  По спаданю ">"
        if ((comparisonsQuick++) && (a[i].getMass() > pivotElement.getMass())) {
            p++;
            swap(a[i], a[p]);
            exchangesQuick++;
        }
    }

    swap(a[p], a[first]);

    return p;
}

void swap(Bicycle &a, Bicycle &b) {
    Bicycle temp = a;
    a = b;
    b = temp;
}
