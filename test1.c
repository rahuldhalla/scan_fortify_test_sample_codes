#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>

// Constants
#define RSIZE_MAX 4096

// Function prototype
int testprintf(char *buffer, size_t bufsz, const char *format, ...);

/*
 * Custom testprintf implementation
 */
int testprintf(char *buffer, size_t bufsz, const char *format, ...)
__attribute__((format(printf, 3, 4)))
{
    va_list vlist;
    int formatted_length = 0;

    // Validate input pointers
    if (buffer == NULL || format == NULL) {
        return -1;
    }

    // Validate buffer size
    if (bufsz == 0 || bufsz > RSIZE_MAX) {
        return -1;
    }

    // Initialize buffer to ensure null-termination
    buffer[0] = '\0';

    va_start(vlist, format);
    formatted_length = vsnprintf(buffer, bufsz, format, vlist);
    va_end(vlist);

    // Handle encoding errors
    if (formatted_length < 0) {
        buffer[0] = '\0';
        return -1;
    }

    // Check for truncation
    if (formatted_length >= bufsz) {
        buffer[bufsz - 1] = '\0'; // Ensure null-termination
    }

    return formatted_length;
}

int main()
{
    char buffer[50];
    int result;

    // Test 1: Normal case
    result = testprintf(buffer, sizeof(buffer), "Hello, %s!", "World");
    printf("Test 1: result=%d, buffer='%s'\n", result, buffer);

    // Test 2: Null buffer
    result = testprintf(NULL, sizeof(buffer), "This should fail.");
    printf("Test 2: result=%d\n", result);

    // Test 3: Null format
    result = testprintf(buffer, sizeof(buffer), NULL);
    printf("Test 3: result=%d\n", result);

    // Test 4: Buffer size zero
    result = testprintf(buffer, 0, "This should also fail.");
    printf("Test 4: result=%d\n", result);

    // Test 5: Truncated output
    result = testprintf(buffer, 10, "This string is too long for the buffer.");
    printf("Test 5: result=%d, buffer='%s'\n", result, buffer);

    // Test 6: Buffer size exceeds RSIZE_MAX
    result = testprintf(buffer, RSIZE_MAX + 1, "Exceeds max size.");
    printf("Test 6: result=%d\n", result);

    // Test 7: Empty format string
    result = testprintf(buffer, sizeof(buffer), "");
    printf("Test 7: result=%d, buffer='%s'\n", result, buffer);

    return 0;
}
