#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <cstdio>
#include <windows.h>

using namespace std;

void klawisz2();
void fillTab(int tab[], int n)
{
	for(int i=0; i<=n; i++)
	{
		tab[i] = rand() % 100;
	}
}

void displayTab(int tab[], int n)
{
	cout<<"| ";
	for(int i=0; i<=n; i++)
	{
		cout<<tab[i]<<" | ";
	}
}

void bubbleSort(int tab[], int n)
{
	int h;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i; j++)
		{
			if(tab[j]>tab[j+1])
			{
				h = tab[j+1];
				tab[j+1] = tab[j];
				tab[j] = h;
			}
		}
	}
}

void insertSort(int tab[], int n)
{
	for(int nr=2, i; nr<=n; nr++)
	{
		tab[0]=tab[nr];
		i=nr-1;
		while(tab[i]>tab[0])
		{
			tab[i+1]=tab[i];
			i--;
		}
		tab[i+1]=tab[0];
	}
}

void selectionSort(int t[], int n)
{
	int min, imin;
	for(int nr=1; nr<n; nr++)	//opt(n^2) ocz(n^2) pes(n^2)
	{
		min=t[nr];
		imin=nr;
		for(int i=nr+1; i<=n; i++)
		{
			if(t[i]<min)
			{
				min=t[i];
				imin=i;
			}
		}
		t[imin]=t[nr];
		t[nr]=min;
	}
	
}

void swap(int &a, int &b) 
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build heap (rearrange the array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move the current root to the end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() 
{
	int n, *tab, num;
	srand(time(NULL));
	
	cout<<"Size: ";
	cin>>n;
	cout<<"What sorting algorythm? \n";
	cout<<"1.Bubble\n2.Insert\n3.Selection\n4.Quick\n5.Heap\n";
	cin>>num;
	tab = new int[n-1];
	fillTab(tab, n);
	displayTab(tab, n);
	cout<<"\n\n";
	switch(num)
	{
		case 1:		bubbleSort(tab, n);
					break;
		case 2:		insertSort(tab, n);
					break;
		case 3:		selectionSort(tab, n);
					break;
		case 4:		quickSort(tab, 0, n);
					break;
		case 5:		heapSort(tab, n+1);
					break;
					
		default:	cout<<"wrong choice\n";
					break;
	}
	cout<<"After:\n";
	klawisz2();
	displayTab(tab, n);
	klawisz2();
	delete [] tab;
	return 0;
}

void klawisz2()
{
	char tekst[30];
	int i;
	fflush(stdin);
	strcpy(tekst, "Nacisnij ENTER by kontnuowac");
	cout<<endl;
	for(int i=0; i<strlen(tekst); i++)
	{
		cout<<tekst[i]<<" ";
		Sleep(50);
	}
	getchar();
	cout<<endl;
}