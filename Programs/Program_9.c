#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
  char name[30];
  int roll, percent;
  struct student *next;
};

struct student *head = NULL, *last = NULL;

void append()
{
  struct student *temp;
  temp = (struct student *)malloc(sizeof(struct student));
  printf("\nEnter the student name: ");
  scanf("%s", temp->name);
  printf("\nEnter the student roll: ");
  scanf("%d", &temp->roll);
  printf("\nEnter the student percentage: ");
  scanf("%d", &temp->percent);
  temp->next = NULL;
  if (head == NULL)
  {
    head = temp;
    last = temp;
  }
  else
  {
    last->next = temp;
    last = temp;
  }
}

void display()
{
  struct student *temp = head;
  while (temp != NULL)
  {
    printf("\nName: %s", temp->name);
    printf("\nRoll: %d", temp->roll);
    printf("\nPercentage: %d\n", temp->percent);
    temp = temp->next;
  }
}

void insert()
{
  int pos, c = 1;
  struct student *temp, *p;
  temp = (struct student *)malloc(sizeof(struct student));
  printf("\nEnter new student name: ");
  scanf("%s", temp->name);
  printf("\nEnter new student roll: ");
  scanf("%d", &temp->roll);
  printf("\nEnter new student percentage: ");
  scanf("%d", &temp->percent);
  printf("Enter position to insert: ");
  scanf("%d", &pos);

  if (pos == 1)
  {
    temp->next = head;
    head = temp;
    if (last == NULL)
      last = temp;
  }
  else
  {
    p = head;
    while (c < pos - 1 && p != NULL)
    {
      p = p->next;
      c++;
    }
    if (p == NULL)
    {
      printf("Position out of range!\n");
      free(temp);
    }
    else
    {
      temp->next = p->next;
      p->next = temp;
      if (temp->next == NULL)
        last = temp;
    }
  }
}

void del()
{
    int roll;
    struct student *temp = head, *prev = NULL;

    if (head == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    while (temp != NULL && temp->roll != roll)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Student with roll %d not found!\n", roll);
        return;
    }

    if (temp == head)
    {
        head = head->next;
        if (head == NULL)
            last = NULL;
    }
    else
    {
        prev->next = temp->next;
        if (prev->next == NULL)
            last = prev;
    }
    free(temp);
    printf("Student deleted successfully!\n");
}

void rev()
{
    struct student *prev = NULL, *present = head, *next = NULL;
    last = head; // last will become old head

    while (present != NULL)
    {
        next = present->next;
        present->next = prev;
        prev = present;
        present = next;
    }
    head = prev;
    printf("\nList reversed successfully!\n");
}

int main()
{
  int n, choice, i;

  printf("Enter total number of students: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    append();

  while (1)
  {
    printf("\nEnter 1 to append\nEnter 2 to display\nEnter 3 to insert\nEnter 4 to delete\nEnter 5 to reverse\nEnter 6 to exit\nEnter your choice: ");
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
      insert();
      break;
    case 4:
      del();
      break;
    case 5:
      rev();
      break;
    case 6:
      exit(0);
    default:
      printf("Invalid input!!!\n");
    }
  }
  return 0;
}