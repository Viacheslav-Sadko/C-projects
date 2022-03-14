#include <stdio.h>

struct{
    char name[255];
    int age;
}add;

void registration(){
    FILE * ptr;
    ptr = fopen("record.dat", "a+");
    scanf("%i",&add.age);
    scanf("%s", add.name);
    fprintf(ptr, "%s %i \n", add.name, add.age);
    fclose(ptr);
}

int main(){
    int n=0;
    printf("Hello, welcome to the Bank management system\nSelect your menu\n");
    printf("Menu:\n1) New client registration\n2) Exit\n");
  
        scanf("%d", &n);
        switch(n){
            case 1:
            registration();
            break;
            case 2:
            break;
        }
    
}