#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[200], sql[300];
    int i;
    
    printf("V3: Aggregation Functions\n");
    printf("=========================\n\n");
    
    printf("Try: average marks, count students, max marks, etc.\n\n");
    
    while(1) {
        printf("Query: ");
        fgets(input, 200, stdin);
        input[strcspn(input, "\n")] = 0;
        
        if(strcmp(input, "exit") == 0) break;
        
        // lowercase conversion
        for(i = 0; input[i]; i++) {
            input[i] = tolower(input[i]);
        }
        
        // check what kind of aggregation
        if(strstr(input, "average") || strstr(input, "avg")) {
            if(strstr(input, "marks"))
                sprintf(sql, "SELECT AVG(marks) FROM students;");
            else if(strstr(input, "age"))
                sprintf(sql, "SELECT AVG(age) FROM students;");
            else
                sprintf(sql, "SELECT AVG(marks) FROM students;");
        }
        else if(strstr(input, "count") || strstr(input, "total")) {
            sprintf(sql, "SELECT COUNT(*) FROM students;");
        }
        else if(strstr(input, "max") || strstr(input, "highest")) {
            if(strstr(input, "marks"))
                sprintf(sql, "SELECT MAX(marks) FROM students;");
            else
                sprintf(sql, "SELECT MAX(marks) FROM students;");
        }
        else if(strstr(input, "min") || strstr(input, "lowest")) {
            if(strstr(input, "marks"))
                sprintf(sql, "SELECT MIN(marks) FROM students;");
            else
                sprintf(sql, "SELECT MIN(marks) FROM students;");
        }
        else if(strstr(input, "sum")) {
            sprintf(sql, "SELECT SUM(marks) FROM students;");
        }
        else {
            sprintf(sql, "SELECT AVG(marks) FROM students;");
        }
        
        printf("SQL: %s\n\n", sql);
    }
    
    return 0;
}