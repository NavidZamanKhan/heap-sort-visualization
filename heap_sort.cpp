#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <iomanip>

using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

// Function to clear the console
void clearScreen()
{
    system(CLEAR);
}

// Delay for 1.5 seconds between steps
void pause()
{
    this_thread::sleep_for(chrono::milliseconds(1500));
}

// Function to print the heap as a tree
void printHeapTree(const vector<int> &heap, int size)
{
    int levels = log2(size) + 1;
    int maxWidth = pow(2, levels) * 2;

    cout << "\nHeap Tree Structure:\n\n";
    int index = 0;
    for (int level = 0; level < levels; ++level)
    {
        int elements = pow(2, level);
        int spacing = maxWidth / (elements + 1);

        cout << string(spacing / 2, ' ');
        for (int i = 0; i < elements && index < size; ++i)
        {
            cout << setw(2) << heap[index++] << string(spacing, ' ');
        }
        cout << "\n\n";
    }
}

// Function to heapify a subtree rooted at index i
void heapify(vector<int> &arr, int n, int i, int &swapCount)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    cout << "Heapifying at index " << i << " (value = " << arr[i] << ")\n";

    if (left < n && arr[left] > arr[largest])
    {
        cout << "Left child " << arr[left] << " > current largest " << arr[largest] << "\n";
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        cout << "Right child " << arr[right] << " > current largest " << arr[largest] << "\n";
        largest = right;
    }

    if (largest != i)
    {
        cout << "Swapping " << arr[i] << " and " << arr[largest] << "\n";
        swap(arr[i], arr[largest]);
        swapCount++;
        pause();
        clearScreen();
        printHeapTree(arr, n);
        heapify(arr, n, largest, swapCount); // Recursively heapify the affected subtree
    }
    else
    {
        cout << "No swap needed.\n";
    }

    pause();
    clearScreen();
}

// Heap sort algorithm with visualization
void heapSort(vector<int> &arr)
{
    int n = arr.size();
    int swapCount = 0;

    cout << "Building max heap...\n";
    pause();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, swapCount);
    }

    clearScreen();
    cout << "Max Heap built:\n";
    printHeapTree(arr, n);
    pause();

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--)
    {
        cout << "Swapping root " << arr[0] << " with end " << arr[i] << "\n";
        swap(arr[0], arr[i]);
        swapCount++;
        pause();
        clearScreen();

        printHeapTree(arr, n);
        cout << "Heapifying root...\n";
        heapify(arr, i, 0, swapCount);
    }

    cout << "\n✅ Heap sort completed.\n";
    cout << "Total swaps: " << swapCount << "\n\n";
    cout << "Sorted array:\n";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << "\n";
}

int main()
{
    clearScreen();

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Please enter a positive number of elements.\n";
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " elements separated by space:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    clearScreen();
    cout << "Initial array:\n";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << "\n\nStarting heap sort visualization...\n";
    pause();

    heapSort(arr);

    return 0;
}
