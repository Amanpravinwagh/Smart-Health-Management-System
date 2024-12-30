#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char disease[50];
} Patient;

void addPatient();
void viewPatients();

int main() {
    int choice;
    while (1) {
        printf("\n--- Patient Record Management ---\n");
        printf("1. Add Patient\n2. View Patients\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                viewPatients();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void addPatient() {
    FILE *fp = fopen("patients.dat", "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }
    Patient p;
    printf("Enter name: ");
    scanf("%s", p.name);
    printf("Enter age: ");
    scanf("%d", &p.age);
    printf("Enter disease: ");
    scanf("%s", p.disease);
    fwrite(&p, sizeof(Patient), 1, fp);
    fclose(fp);
    printf("Patient added successfully!\n");
}

void viewPatients() {
    FILE *fp = fopen("patients.dat", "rb");
    if (!fp) {
        printf("No patients found!\n");
        return;
    }
    Patient p;
    printf("\n--- Patient List ---\n");
    while (fread(&p, sizeof(Patient), 1, fp)) {
        printf("Name: %s, Age: %d, Disease: %s\n", p.name, p.age, p.disease);
    }
    fclose(fp);
}
