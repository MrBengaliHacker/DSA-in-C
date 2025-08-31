## 📋Program 7: Linked List of Students with Insertion

**Question**: Write a program to create a single linked list of students (Name, Roll, Percentage) and perform insertion of a new student at the i-th position along with displaying the list. 

**Solution**: [View Code](Program_7.c)

```c
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
int main()
{
  getch();
  int n, choice, i;

  printf("Enter total number of students: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    append();

  while (1)
  {
    printf("\nEnter 1 to append\nEnter 2 to display\nEnter 3 to insert\nEnter 4 to exit\nEnter your choice: ");
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
      exit(0);
    default:
      printf("Invalid input!!!\n");
    }
  }
  getch();
  return 0;
}
```
### OUTPUT

```
Enter total number of students: 2

Enter the student name: Ram

Enter the student roll: 1

Enter the student percentage: 90

Enter the student name: Jodu

Enter the student roll: 3

Enter the student percentage: 80

Enter 1 to append
Enter 2 to display
Enter 3 to insert
Enter 4 to exit
Enter your choice: 2

Name: Ram
Roll: 1
Percentage: 90

Name: Jodu
Roll: 3
Percentage: 80

Enter 1 to append
Enter 2 to display
Enter 3 to insert
Enter 4 to exit
Enter your choice: 1

Enter the student name: Modhu

Enter the student roll: 4

Enter the student percentage: 75

Enter 1 to append
Enter 2 to display
Enter 3 to insert
Enter 4 to exit
Enter your choice: 2

Name: Ram
Roll: 1
Percentage: 90

Name: Jodu
Roll: 3
Percentage: 80

Name: Modhu
Roll: 4
Percentage: 75

Enter 1 to append
Enter 2 to display
Enter 3 to insert
Enter 4 to exit
Enter your choice: 3

Enter new student name: Shyam

Enter new student roll: 2

Enter new student percentage: 85
Enter position to insert: 2

Enter 1 to append
Enter 2 to display
Enter 3 to insert
Enter 4 to exit
Enter your choice: 2

Name: Ram
Roll: 1
Percentage: 90

Name: Shyam
Roll: 2
Percentage: 85

Name: Jodu
Roll: 3
Percentage: 80

Name: Modhu
Roll: 4
Percentage: 75

Enter 1 to append
Enter 2 to display
Enter 3 to insert
Enter 4 to exit
Enter your choice: 4 
```
## 📋Program 8: Selection Sort

**Question**: Write a program in c to implement selection sort.

**Solution**: [View Code](Program_8.c)

```c
#include <stdio.h>
#include <conio.h>

void selectionSort(int arr[], int n)
{
    int i, j, temp, min;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        // Swap after inner loop
        if (min != i)
        {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    clrscr();
    int arr[50], n, i;

    printf("Enter The Number Of Elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nEntered Array:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("\nSorted Array:\n");
    printArray(arr, n);

    getch();
    return 0;
}
```
### OUTPUT

```
Enter The Number Of Elements: 5
Enter Element 1: 44
Enter Element 2: 12
Enter Element 3: 69
Enter Element 4: 16
Enter Element 5: 20

Entered Array: 
44 12 69 16 20 

Sorted Array:
12 16 20 44 69
```