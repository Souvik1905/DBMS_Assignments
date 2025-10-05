#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Helper function: Convert string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Helper function: Check if text contains a word
int containsWord(const char *text, const char *word) {
    return strstr(text, word) != NULL;
}

// V1: Basic Rule-Based Query
// Difficulty: ⭐ Easy
void v1_basic_rule_based() {
    char input[200];
    char sql[300];
    
    printf("=== V1: Basic Rule-Based Query ===\n");
    printf("Difficulty: ⭐ Easy\n");
    printf("Example: 'Show students with marks above 80'\n\n");
    
    printf("Enter your query: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // remove newline
    
    toLowerCase(input);
    
    // Parse the input
    if (containsWord(input, "marks") && containsWord(input, "above")) {
        // Extract number after "above"
        char *ptr = strstr(input, "above");
        int marks = 0;
        if (ptr) {
            sscanf(ptr + 5, "%d", &marks);
        }
        sprintf(sql, "SELECT * FROM students WHERE marks > %d;", marks);
    }
    else if (containsWord(input, "marks") && containsWord(input, "greater")) {
        char *ptr = strstr(input, "than");
        int marks = 0;
        if (ptr) {
            sscanf(ptr + 4, "%d", &marks);
        }
        sprintf(sql, "SELECT * FROM students WHERE marks > %d;", marks);
    }
    else if (containsWord(input, "show") || containsWord(input, "list")) {
        sprintf(sql, "SELECT * FROM students;");
    }
    else {
        sprintf(sql, "SELECT * FROM students WHERE marks > 80;");
    }
    
    printf("\n✓ Generated SQL:\n");
    printf("  %s\n", sql);
    printf("\n✓ Explanation:\n");
    printf("  - SELECT * retrieves all columns\n");
    printf("  - FROM students specifies the table\n");
    printf("  - WHERE marks > 80 filters the results\n");
}

int main() {
    v1_basic_rule_based();
    return 0;
}
