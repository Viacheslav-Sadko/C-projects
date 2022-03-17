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

void replace(){
    FILE *ptr, *new_ptr;
    char buffer[255];
    int c=0, t=1;
    ptr=fopen("./info/record.dat", "r");
    new_ptr=fopen("./info/new_record.dat", "a+");
    while(fgets(buffer, 255, ptr)!=NULL){
        c++;
            if(c==t){
                continue;
            }
            //fprintf(ptr, "%i) %s %s %i %i\n",add.ac_number, add.first_name, add.last_name, add.age, add.cart_number);
            new_ac.ac_number=c;
            rewind(ptr);
            fscanf(buffer,"%i %s %s %i %i",&new_ac.ac_number, new_ac.first_name, new_ac.last_name, &new_ac.age, &new_ac.cart_number);

            fprintf(new_ptr, "%i) %s %s %i %i\n",c, new_ac.first_name, new_ac.last_name, new_ac.age, new_ac.cart_number);
            
        }
    
    // for(int i=0;i<=c;i++){
    //     if(t!=c){
    //         fgets(buffer, 255, ptr);
    //         printf("%s", buffer);
    //     }
    // }
    fclose(ptr);
    fclose(new_ptr);
}

int menu(){
    int n=0;
    printf("Hello, welcome to the Bank management system\nSelect your menu\n");
    printf("Menu:\n1) New client registration\n2) See all members\n4) Exit\n");
    while(n!=4){
        scanf("%d", &n);
        switch(n){
            case 1:
            registration();
            break;
            case 2:
            see();
            case 3:
            replace();
            break;
            case 4:
            break;
            default:
            printf("Choose promote number\n");
            break;
        }
        if(n!=4)
        printf("Menu:\n1) New client registration\n2) See all members\n4) Exit\n");
    }   
}

