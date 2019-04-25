#include  <ctime>
#include<iostream>
#include <string>
using namespace std;

void quickSort(int a[], int first, int last);
int pivot(int a[], int first, int last);
void swap(int& a, int& b);
void print(int array[], const int& N);

int comparisonsQuick;
int exchangesQuick;

class Bicycle
{
public:
	int gearNumber;
	double mass;
	double maxMas;
	string makerName;
};


void main()
{
	//InsertionSort
	Bicycle gearNumber;
	bool upDn = false;
	const int num = 100;
	int list[num] = {};
	//Заповненя масиву рандомними числами
	for (int i = 0; i <num; i++)
	{
		list[i] = gearNumber.gearNumber = rand() % (100 - 1);
	}
	int key, i;

    int comparisonsInsertion = 0;
    int exchangesInsertion = 0;

    // insertion sort
    for (int j = 1; j < num; j++) {
        key = list[j];
        i = j - 1;
        while (comparisonsInsertion++ && (i >= 0) && list[i] < key) {
            list[i + 1] = list[i];    
            i--;
            exchangesInsertion++;
        }
        list[i + 1] = key; 
    }

	cout << "\nInsertion" << "\n\n";
	//Вивід часу роботи алготимму Insertion
	int timeInsertionSort = clock();
	cout << "Time\t" << ((float)timeInsertionSort / CLOCKS_PER_SEC) << endl;

	//Вивід кількості порівняня алготимму Insertion
	cout << "Number of exchanges " << exchangesInsertion << endl;
	cout << "Number of comparisons " << comparisonsInsertion << endl;

	//Вивід відсортованого алготимму Insertion
	for (int i = 0; i < num; i++)
	{
		cout << list[i] <<"\t";
	}
	//__________________________________________________________________________________________________________________//

									//QuickSort

										//Заповненя масиву рандомними числами
	exchangesQuick = 0;
	comparisonsQuick = 0;
	const int numQ = 100;
	int listQ[numQ] = {};
	for (int i = 0; i < numQ; i++)
	{
		listQ[i] = rand() % (100 - 1);
	}

	int timeQuickSort = clock();

	clock_t start = clock();
	quickSort(listQ, 0, numQ - 1);

	//for (int i = 0; i < 10; i++)
	//{
	//	cout << i << endl;
	//}
	clock_t end = clock();

	double timeCheckpoint2 = ((double)timeQuickSort / CLOCKS_PER_SEC);

	cout << "\n\nQuickSort\n\n" << endl;
	print(listQ, numQ);
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Quick sort time is " << seconds << " s" << endl;
	cout << "Number of exchanges " << exchangesQuick << endl;
	cout << "Number of comparisons " << comparisonsQuick << endl;
}

										//Функцфя сортуваня QuickSort
void quickSort(int a[], int first, int last)
{
	int pivotElement;

	if (first < last)
	{
		pivotElement = pivot(a, first, last);
		quickSort(a, first, pivotElement - 1);
		quickSort(a, pivotElement + 1, last);
	}
}


int pivot(int a[], int first, int last)
{
	extern int comparisonsQuick, exchangesQuick;
	int  p = first;
	int pivotElement = a[first];

	for (int i = first + 1; i <= last; i++)
	{
									// По зростаню "<="  По спаданю ">" 
		if ((comparisonsQuick++) && (a[i]  > pivotElement))
		{
			p++;
			swap(a[i], a[p]);
			exchangesQuick++;
		}
	}

	swap(a[p], a[first]);

	return p;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


void print(int a[], const int& N)
{
	for (int i = 0; i < N; i++)
		cout << a[i] << "\t";
		
		cout << "\n\n"<<endl;
}
