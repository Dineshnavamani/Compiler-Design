
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
bool isValidIdentifier(char *identifier) {
    if (!isalpha(identifier[0]) && identifier[0] != '_') {
        return false; 
    }
    
    for (int i = 1; identifier[i] != '\0'; i++) {
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            return false; 
        }
    }
    
    return true; 
}
int main() {
    char identifier[] = "valid_identifier123";
    
    if (isValidIdentifier(identifier)) {
        printf("%s is a valid identifier.\n", identifier);
    } else {
        printf("%s is not a valid identifier.\n", identifier);
    }
    
    return 0;
}

