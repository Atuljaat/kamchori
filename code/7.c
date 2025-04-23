#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

int main() {
    int numPeople;
    printf("Enter the number of people: ");
    scanf("%d", &numPeople);
    getchar();

    Person *people = (Person *)malloc(numPeople * sizeof(Person));

    for (int i = 0; i < numPeople; i++) {
        printf("Enter the name for person %d: ", i + 1);
        fgets(people[i].name, sizeof(people[i].name), stdin);
        people[i].name[strcspn(people[i].name, "\n")] = 0;

        printf("Enter the age for person %d: ", i + 1);
        scanf("%d", &people[i].age);
        getchar();
    }

    printf("\nPeople:\n");
    for (int i = 0; i < numPeople; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }

    free(people);
    return 0;
}