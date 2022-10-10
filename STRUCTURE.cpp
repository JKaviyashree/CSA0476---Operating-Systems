#include <stdio.h>
int main() 
{
  struct student 
  {
    char firstname[64];
    char id[64];
  };
  struct student std1;
  printf("Enter Name: ");
  scanf("%s", std1.firstname);  
  printf("Enter ID: ");
  scanf("%s", std1.id);
  printf("\nStudent Detail:\n");
  printf("Name: %s\n", std1.firstname);
  printf("ID: %s\n", std1.id);
  return 0;
}
