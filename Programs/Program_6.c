#include <stdio.h>
#include <stdlib.h>

struct node
{
  char name[50];
  int roll;
  float percentage;
  struct node *next;
};

struct node *head = NULL;
struct node *temp = NULL;

void append();
void display();

int main()
{
  int choice;
  do
  {
    printf("\n--- Student Linked List Menu ---\n");
    printf("1. Append Student\n");
    printf("2. Display Students\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      append();
      break;
    case 2:
      display();
      break;
    case 3:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice! Please try again.\n");
    }

  } while (choice != 3);

  return 0;
}

void append()
{
  struct node *newnode;

  newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter student name: ");
  scanf("%s", newnode->name);
  printf("Enter student roll: ");
  scanf("%d", &newnode->roll);
  printf("Enter student percentage: ");
  scanf("%f", &newnode->percentage);

  newnode->next = NULL;

  if (head == NULL)
  {
    head = temp = newnode;
  }
  else
  {
    temp->next = newnode;
    temp = newnode;
  }

  printf("Student added successfully!\n");
}

void display()
{
  struct node *temp = head;

  printf("\nStudent List:\n");
  while (temp != NULL)
  {
    printf("Name: %s, Roll: %d, Percentage: %.2f%%\n", temp->name, temp->roll, temp->percentage);
    temp = temp->next;
  }
}