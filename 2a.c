#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<sys/wait.h>
int compare(const void *a, const void *b) 
{
return (*(int *)a - *(int *)b);
}
int main(int argc, char *argv[]) 
{
int integer_array[10], search;
char *char_array[11]; 
char *newenviron[]={NULL};
int no_of_elements;
int id = fork();
if (id >0) 
{ 
printf("Enter how many elements you want to add in array : ");
scanf("%d", &no_of_elements);
printf("\nEnter Array elements:\n");
for (int i = 0; i < no_of_elements; i++) 
{
printf("Enter %d element : ", i + 1);
scanf("%d", &integer_array[i]);
}
printf("Array elements are: ");
for (int i = 0; i < no_of_elements; i++) 
{
printf("%d\t", integer_array[i]);
}
qsort(integer_array, no_of_elements, sizeof(int), compare);
printf("\nAfter sorting array elements are : ");
for (int i = 0; i < no_of_elements; i++) 
{
printf("%d\t", integer_array[i]);
}
for (int i = 0; i < no_of_elements; i++) 
{
char a[sizeof(int)];
snprintf(a, sizeof(int), "%d", integer_array[i]);
char_array[i] = malloc(sizeof(a));
strcpy(char_array[i], a);
}
char_array[no_of_elements] = NULL; 
wait(NULL);
for (int i = 0; i < no_of_elements; i++) 
{
free(char_array[i]);
}
}
return 0;
}
