#include <stdio.h>
#include <stdlib.h>

void createFile(char fname[]) {
    FILE *fp = fopen(fname, "w");
    if (fp == NULL) {
        printf("Unable to create file.\n");
        return;
    }
    char data[100];
    printf("Enter data to write in file:\n");
    getchar();
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);
    printf("File created and data written.\n");
}

void readFile(char fname[]) {
    FILE *fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("File not found.\n");
        return;
    }
    char ch;
    printf("\nReading file content:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

void appendFile(char fname[]) {
    FILE *fp = fopen(fname, "a");
    if (fp == NULL) {
        printf("File not found.\n");
        return;
    }
    char data[100];
    printf("Enter data to append:\n");
    getchar();
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);
    printf("Data appended successfully.\n");
}

int main() {
    char fname[50];
    int choice;
    printf("Enter file name (with .txt): ");
    scanf("%s", fname);

    while (1) {
        printf("\n1. Create & Write\n2. Read\n3. Append\n4. Exit\nChoose option: ");
        scanf("%d", &choice);
        if (choice == 1)
            createFile(fname);
        else if (choice == 2)
            readFile(fname);
        else if (choice == 3)
            appendFile(fname);
        else if (choice == 4)
            break;
        else
            printf("Invalid option.\n");
    }

    return 0;
}
