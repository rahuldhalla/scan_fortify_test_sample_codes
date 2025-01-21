#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int flist_size = 2147483547; // Example value close to INT_MAX
    int fudge_factor = 100;
    int len;

    printf("Initial flist_size: %d\n", flist_size);
    printf("Fudge factor: %d\n", fudge_factor);

    // Overflow check before addition
    if (flist_size > INT_MAX - fudge_factor) {
        printf("Error: Addition of fudge factor causes integer overflow.\n");
        return EXIT_FAILURE;
    }

    // Safe addition
    len = flist_size + fudge_factor;
    printf("Safe addition result: %d\n", len);

    // Allocate memory safely
    char *buffer = (char *)malloc((size_t)len);
    if (buffer == NULL) {
        printf("Error: Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    printf("Memory allocated successfully with size: %d\n", len);

    // Clean up
    free(buffer);
    printf("Memory deallocated successfully.\n");

    return EXIT_SUCCESS;
}
