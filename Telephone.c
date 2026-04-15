Telephone system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for contact
struct Contact {
    char name[50];
    char phone[15];
    struct Contact *prev, *next;
};

struct Contact *head = NULL;

// Create new contact
struct Contact* createContact(char name[], char phone[]) {
    struct Contact *newNode = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Add contact
void addContact() {
    char name[50], phone[15];
    printf("Enter Name: ");
    scanf(" %[^\n]", name);
    printf("Enter Phone: ");
    scanf("%s", phone);

    struct Contact *newNode = createContact(name, phone);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Contact *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Contact Added Successfully!\n");
}

// Display all contacts
void displayContacts() {
    struct Contact *temp = head;
    if (temp == NULL) {
        printf("No Contacts Found!\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    while (temp != NULL) {
        printf("Name: %s | Phone: %s\n", temp->name, temp->phone);
        temp = temp->next;
    }
}

// Search contact
struct Contact* searchContact(char name[]) {
    struct Contact *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// Delete contact
void deleteContact() {
    char name[50];
    printf("Enter Name to Delete: ");
    scanf(" %[^\n]", name);

    struct Contact *temp = searchContact(name);

    if (temp == NULL) {
        printf("Contact Not Found!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Contact Deleted Successfully!\n");
}

// Update contact
void updateContact() {
    char name[50];
    printf("Enter Name to Update: ");
    scanf(" %[^\n]", name);

    struct Contact *temp = searchContact(name);

    if (temp == NULL) {
        printf("Contact Not Found!\n");
        return;
    }

    printf("Enter New Phone: ");
    scanf("%s", temp->phone);

    printf("Contact Updated Successfully!\n");
}

// Navigate contacts
void navigateContacts() {
    struct Contact *temp = head;
    int choice;

    if (temp == NULL) {
        printf("No Contacts Available!\n");
        return;
    }

    while (1) {
        printf("\nCurrent Contact:\n");
        printf("Name: %s | Phone: %s\n", temp->name, temp->phone);

        printf("\n1. Next\n2. Previous\n3. Exit Navigation\nEnter Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (temp->next != NULL)
                temp = temp->next;
            else
                printf("End of List!\n");
        } else if (choice == 2) {
            if (temp->prev != NULL)
                temp = temp->prev;
            else
                printf("Start of List!\n");
        } else {
            break;
        }
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- Telephone Contact System ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Update Contact\n");
        printf("6. Navigate Contacts\n");
        printf("7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: {
                char name[50];
                printf("Enter Name to Search: ");
                scanf(" %[^\n]", name);
                struct Contact *res = searchContact(name);
                if (res)
                    printf("Found: %s | %s\n", res->name, res->phone);
                else
                    printf("Not Found!\n");
                break;
            }
            case 4: deleteContact(); break;
            case 5: updateContact(); break;
            case 6: navigateContacts(); break;
            case 7: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }

    return 0;
}
