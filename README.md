# Heap Sort Visualizer in C++

## 1. Introduction
This report outlines the development and implementation of an interactive heap sort visualizer in C++. The program demonstrates the heap sort algorithm while visually displaying each stage of the process, from heap construction to sorting. The visualization is intended to help learners understand the mechanics of heap sort and the process of heapifying a tree, providing a step-by-step breakdown of the algorithm’s execution.

## 2. Problem Description
Heap sort is a comparison-based sorting algorithm that works by first building a max heap from the input data, followed by extracting the root (the maximum element) and placing it at the end of the array. This process is repeated for the remaining elements in the heap. The visualization allows users to observe how the heap is built and how elements are moved and swapped during the sorting phase. The primary goal is to aid in understanding the structure and behavior of the heap and sorting algorithm.

## 3. Solution Approach
The solution uses the heap sort algorithm with detailed visualizations:
- **Heap Construction**: The algorithm first builds a max heap, ensuring that the root of the tree holds the largest value. The heap is built in-place by calling the heapify function for each internal node.
- **Heapify Function**: The heapify function is responsible for maintaining the heap property. When an element is out of order, the function swaps it with the largest of its children to ensure the largest value is always at the root.
- **Swap and Visualization**: After each swap, the heap structure is printed to the screen as a tree. This visualization allows the user to observe the algorithm’s progress step-by-step, showing how the tree is rearranged after each swap.
- **Sorting**: Once the heap is built, the root is swapped with the last element, and the heap size is reduced. The heapify process is repeated for the root of the heap, ensuring the largest element is placed in its correct position.

## 4. Code Structure and Design
The program is structured as follows:

### 4.1 Input Handling
- The user is prompted to input the size of the array and the elements to be sorted.

### 4.2 Heap Construction and Heapify Process
- The heap is built from the array using the heapify function, which is called recursively to ensure the max-heap property.
- The program prints the heap structure at each stage, allowing the user to observe how elements are swapped and the heap is restructured.

### 4.3 Display Functions
- **clearScreen()**: Clears the console screen for better visualization of the current state of the heap.
- **printHeapTree()**: This function prints the heap as a tree, showing the structure clearly in a hierarchical format.

### 4.4 Pause and Delay
- **pause()**: Introduces a delay of 1.5 seconds between steps, allowing the user to follow the process at a comfortable pace.

### 4.5 Heap Sort Execution
- The main sorting logic is executed in `heapSort()`, which begins by building the heap, then performs the sorting by repeatedly swapping the root of the heap with the last element and heapifying the root.

## 5. Time Complexity
The time complexity of the heap sort algorithm is O(n log n) for both the best and worst cases due to the logarithmic depth of the heap and the linear scans involved in the heapify process. Specifically:
- **Building the Heap**: O(n)
- **Sorting the Heap**: O(n log n)

Thus, the overall time complexity is O(n log n), making it efficient for large datasets.

## 6. Space Complexity
The space complexity is O(n) due to the storage required for the input array and the auxiliary variables used in the heapify process. Since the heap is built in-place, no additional storage is needed for the heap itself.

## 7. Additional Considerations
- **Platform Compatibility**: The program uses preprocessor directives to ensure that it works on both Windows and Unix-based systems for clearing the console screen.
- **Educational Value**: The visualizer is designed to provide a step-by-step understanding of the heap sort algorithm. The combination of printed tree structures and decision messages helps users grasp the changes in the heap after each operation.
- **Future Enhancements**:
  - **Color Coding**: Future versions could include color coding for different operations, such as highlighting swapped elements in a different color.
  - **Interactivity**: Adding interactive controls to adjust the delay or allow for user-driven steps could enhance the user experience.
  - **Supporting More Algorithms**: The visualizer could be extended to support other sorting algorithms or more complex data structures.

## 8. Conclusion
This interactive C++ program provides an educational tool for visualizing the heap sort algorithm. By showcasing each step of the process, the program helps users understand how heap sort works, from building the heap to sorting the array. This visual approach makes the algorithm more accessible, especially for learners who may find it difficult to understand the underlying mechanics of heap-based sorting.

The program successfully demonstrates the dynamic aspects of heap sort, and the future scope includes adding more interactive features to enhance learning.
