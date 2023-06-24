int sumEven(int vals[], int low, int high) {
    // Base case: If low index exceeds high index, return 0
    if (low > high)
        return 0;

    int num_even = 0; // Declare and initialize the variable to store the sum of even numbers

    // Check if the element at the low index is even
    if (vals[low] % 2 == 0)
        num_even = vals[low]; // If even, add it to the result

    // Recursive step: Add the sum of even numbers from the remaining elements
    return num_even + sumEven(vals, low + 1, high);
}
