#include <stdio.h>
#include <string.h>

void recursive_permutations(char *str, int start, int end) {
    // Swap function to swap characters
    void swap(char *x, char *y) {
        char temp = *x;
        *x = *y;
        *y = temp;
    }

    // Base case: When start index reaches the end index
    if (start == end) {
        printf("%s\n", str);  // Print the permutation
        return;
    }

    // Recursive case: Generate permutations by swapping characters
    for (int i = start; i <= end; i++) {
        swap((str + start), (str + i));  // Swap characters
        recursive_permutations(str, start + 1, end);  // Recursive call
        swap((str + start), (str + i));  // Backtrack by swapping characters back
    }
}

int main() {
    // Input your string here
    char str[] = "Luckner";
    int n = strlen(str);

    recursive_permutations(str, 0, n - 1);

    return 0;
}
