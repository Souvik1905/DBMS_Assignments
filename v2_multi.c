#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[200], sql[300];
    int age, marks, i;
    char *ptr;
    
    printf("V2: Multi-Condition Queries\n");
    printf("===========================\n\n");
    
    printf("Examples:\n");
    printf("- Show students older than 20 and with marks > 85\n");
    printf("- Students with age > 18 or marks < 50\n\n");
    
    while(1) {
        printf("Query: ");
        fgets(input, 200, stdin);
        
        // strip newline
        input[strcspn(input, "\n")] = 0;
        
        if(strcmp(input, "exit") == 0) break;
        
        // make lowercase
        for(i = 0; input[i]; i++) {
            input[i] = tolower(input[i]);
        }
        
        // handle AND queries
        if(strstr(input, "and")) {
            age = 20;
            marks = 85;
            
            ptr = strstr(input, "than");
            if(ptr) {
                sscanf(ptr + 4, "%d", &age);
            }
            
            ptr = strstr(input, "marks");
            if(ptr) {
                ptr = strchr(ptr, '>');
                if(ptr) sscanf(ptr + 1, "%d", &marks);
            }
            
            sprintf(sql, "SELECT * FROM students WHERE age > %d AND marks > %d;", age, marks);
        }
        // handle OR queries
        else if(strstr(input, "or")) {
            age = 18;
            marks = 50;
            
            ptr = strstr(input, "age");
            if(ptr) {
                ptr = strchr(ptr, '>');
                if(ptr) sscanf(ptr + 1, "%d", &age);
            }
            
            ptr = strstr(input, "marks");
            if(ptr) {
                ptr = strchr(ptr, '<');
                if(ptr) sscanf(ptr + 1, "%d", &marks);
            }
            
            sprintf(sql, "SELECT * FROM students WHERE age > %d OR marks < %d;", age, marks);
        }
        else {
            // default
            sprintf(sql, "SELECT * FROM students WHERE age > 20 AND marks > 85;");
        }
        
        printf("SQL: %s\n\n", sql);
    }
    
    return 0;
}