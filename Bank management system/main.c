#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
char login[]="Viacheslav";
char password[]="Ghtyvb1092";
struct{
    char first_name[255];
    char last_name[255];
    int age;
    int cart_number;
}add;

void registration(){
    FILE * ptr;
    ptr = fopen("record.dat", "a+");
    printf("Age:");
    scanf("%i",&add.age);
    printf("First name:");
    scanf("%s", add.first_name);
    printf("Last name:");
    scanf("%s", add.last_name);
    printf("Cart number:");
    scanf("%i",&add.cart_number);
    printf("First name:");
    fprintf(ptr, "%s %s %i %i\n", add.first_name, add.last_name, add.age, add.cart_number);
    fclose(ptr);
    system("clear");
}

void see(){
    FILE * ptr;
    char buffer[255];
    ptr=fopen("/home/viacheslav/C-Projects/Bank management system/record.dat", "r");
    while(fgets(buffer, 255, ptr)!=NULL){
        printf("%s", buffer);
    }
    sleep(3);
    system("clear");
    fclose(ptr);
 
}

int menu(){
    int n=0;
    printf("Hello, welcome to the Bank management system\nSelect your menu\n");
    printf("Menu:\n1) New client registration\n2) See all members\n3) Exit\n");
    while(n!=3){
        scanf("%d", &n);
        switch(n){
            case 1:
            registration();
            break;
            case 2:
            see();
            break;
        }
        if(n!=3)
        printf("Menu:\n1) New client registration\n2) See all members\n3) Exit\n");
    }   
}

int main(){
    char log[255], pass[255];
    login_try:
    printf("Login:");
    scanf("%s", log);
    if(strcmp(log,login)!=0){
        printf("Error: wrong login\n");
        system("clear");
        sleep(2);
        goto login_try;
    }
    password_try:
    printf("Password:");
    scanf("%s", pass);
    if(strcmp(pass,password)==0){
        sleep(2);
        system("clear");
        menu();
    }
    else{
        printf("Error: wrong password\n");
        sleep(2);
        system("clear");
        goto password_try;
    }
}