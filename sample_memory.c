#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void memory_leak_example() {
    // Memory leak - allocated but never freed
    int* numbers = (int*)malloc(sizeof(int) * 10);
    for(int i = 0; i < 10; i++) {
        numbers[i] = i;
    }
    // Function returns without freeing numbers
}

void null_pointer_example(int* ptr) {
    // Potential null pointer dereference
    *ptr = 42;  // No null check before dereferencing
}

void double_free_example() {
    char* str = (char*)malloc(50);
    if(str != NULL) {
        free(str);
        // Double free
        free(str);
    }
}

void use_after_free_example() {
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 10;
    free(ptr);
    // Use after free
    *ptr = 20;
}

int main() {
    // Example 1: Memory leak
    memory_leak_example();
    
    // Example 2: Null pointer dereference
    int* null_ptr = NULL;
    null_pointer_example(null_ptr);
    
    // Example 3: Double free
    double_free_example();
    
    // Example 4: Use after free
    use_after_free_example();
    
    return 0;
}