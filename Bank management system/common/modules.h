#include "../info/users.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

void registration(){
    int c=1;
    FILE * ptr;
    char buffer[255];
    ptr = fopen("./info/record.dat", "a+");
    while(fgets(buffer, 255, ptr)!=NULL){
        c++;
    }
    add.ac_number=c;
    printf("Age:");
    scanf("%i",&add.age);
    printf("First name:");
    scanf("%s", add.first_name);
    printf("Last name:");
    scanf("%s", add.last_name);
    printf("Cart number:");
    scanf("%i",&add.cart_number);
    printf("First name:");
    fprintf(ptr, "%i) %s %s %i %i\n",add.ac_number, add.first_name, add.last_name, add.age, add.cart_number);
    fclose(ptr);
    system("clear");
}

int see(){
    FILE * ptr;
    char buffer[255];
    if(fopen("./info/record.dat", "r")!=NULL){
        ptr=fopen("./info/record.dat", "r");
        system("clear");
        while(fgets(buffer, 255, ptr)!=NULL){
            printf("%s", buffer);
        }
        sleep(3);
        system("clear");
        fclose(ptr);
    }
    else{
        char choose;
        printf("File doesn't exist\nDid you wanna create new file?\n[Y/n]\n");
        scanf("%s", &choose);
            if(choose=='Y'){
                printf("Creating file\n");
                sleep(2);
                fopen("./info/record.dat", "a+");
                printf("File was successfuly created\n");
                sleep(1);
                system("clear");
            }
            else{
                return 0;
            }
    }
}

void delete_ac()
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("./info/record.dat", "r");
    newrec=fopen("./info/new.dat","a+");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&new_ac.ac_number);
    while (fscanf(old,"%d) %s %s %d %d",&add.ac_number, add.first_name, add.last_name, &add.age, &add.cart_number)!=EOF)
   {
        if(add.ac_number!=new_ac.ac_number)
            fprintf(newrec,"%d) %s %s %d %d\n",add.ac_number, add.first_name, add.last_name, add.age, add.cart_number);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("./info/record.dat");
   rename("./info/new.dat","./info/record.dat");
}

int menu(){
    int n=0;
    printf("Hello, welcome to the Bank management system\nSelect your menu\n");
    printf("Menu:\n1) New client registration\n2) See all members\n3) Delete account\n4) Exit\n");
    while(n!=4){
        scanf("%d", &n);
        switch(n){
            case 1:
            registration();
            break;
            case 2:
            see();
            case 3:
            delete_ac();
            break;
            case 4:
            break;
            default:
            printf("Choose promote number\n");
            break;
        }
        if(n!=4)
        printf("Menu:\n1) New client registration\n2) See all members\n3) Delete account\n4) Exit\n");
    }   
    return 0;
}

