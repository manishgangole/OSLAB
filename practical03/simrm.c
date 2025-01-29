#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];

    // Get file name from user
    printf("Enter filename to delete: ");
    scanf("%s", filename);

    // Attempt to remove the file
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("Error deleting file");
    }

    return 0;
}
