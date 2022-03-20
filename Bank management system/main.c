#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "./info/log_info.h"
#include "./common/modules.h"

int main(){
    system("clear");
    char log[255], pass[255];
    login_try:
    printf("Login:");
    scanf("%s", log);
    if(strcmp(log,login)!=0){
        printf("Error: wrong login\n");
        sleep(2);
        system("clear");
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
    menu();
}