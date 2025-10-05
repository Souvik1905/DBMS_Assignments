#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[200], sql[300];
    int i;
    
    printf("V4: Sorting Queries\n");
    printf("===================\n\n");
    
    printf("Examples: order by marks desc, sort by age, etc.\n\n");
    
    while(1) {
        printf("Query: ");
        fgets(input, 200, stdin);
        input[strcspn(input, "\n")] = 0;
        
        if(strcmp(input, "exit") == 0) break;
        
        // make everything lowercase
        for(i = 0; input[i]; i++) {
            input[i] = tolower(input[i]);
        }
        
        // check for descending order
        if(strstr(input, "desc") || strstr(input, "highest")) {
            if(strstr(input, "marks"))
                sprintf(sql, "SELECT * FROM students ORDER BY marks DESC;");
            else if(strstr(input, "age"))
                sprintf(sql, "SELECT * FROM students ORDER BY age DESC;");
            else if(strstr(input, "name"))
                sprintf(sql, "SELECT * FROM students ORDER BY name DESC;");
            else
                sprintf(sql, "SELECT * FROM students ORDER BY marks DESC;");
        }
        // check for ascending order
        else if(strstr(input, "asc") || strstr(input, "lowest")) {
            if(strstr(input, "marks"))
                sprintf(sql, "SELECT * FROM students ORDER BY marks ASC;");
            else if(strstr(input, "age"))
                sprintf(sql, "SELECT * FROM students ORDER BY age ASC;");
            else
                sprintf(sql, "SELECT * FROM students ORDER BY marks ASC;");
        }
        // just general ordering
        else if(strstr(input, "order") || strstr(input, "sort")) {
            if(strstr(input, "marks"))
                sprintf(sql, "SELECT * FROM students ORDER BY marks DESC;");
            else if(strstr(input, "age"))
                sprintf(sql, "SELECT * FROM students ORDER BY age DESC;");
            else if(strstr(input, "name"))
                sprintf(sql, "SELECT * FROM students ORDER BY name ASC;");
            else
                sprintf(sql, "SELECT * FROM students ORDER BY marks DESC;");
        }
        else {
            sprintf(sql, "SELECT * FROM students ORDER BY marks DESC;");
        }
        
        printf("SQL: %s\n\n", sql);
    }
    
    return 0;
}