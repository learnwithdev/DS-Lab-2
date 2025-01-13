#include <stdio.h>
#include <stdlib.h>

struct BankMgmt{
    int acc_no;
    char name[30];
    float balance;
    char acc_type[5];
};

int withdrawl(struct BankMgmt* b1, int draw){
    if (b1->balance<draw){
        printf("Invalid Input\n");
        return 0;
    }
    else{
        b1->balance -= draw;
    }
}

void Deposit(struct BankMgmt* b1, int dep){
    b1->balance += dep;
}

void display(struct BankMgmt* b1){
    printf("\n%s    %d    %s    %f\n", b1->acc_type, b1->acc_no, b1->name, b1->balance);
}
void main(){
    int user;
    struct BankMgmt bank1;
    struct BankMgmt* b1 = &bank1;
    // b1.acc_no = 100155;
    // b1.name = "Malya";
    // b1.acc_type = "SB";

    printf("Enter Acc. Type: \n");
    scanf("%s", b1->acc_type);
    printf("Enter Acc. Number: \n");
    scanf("%d", &b1->acc_no);
    printf("Enter Name: \n");
    scanf("%s", b1->name);
    // printf("Enter Current Balance: \n");
    // scanf("%f", &b1.balance);


    do {
        printf("\nEnter the corresponding number for desired operation:\n");
        printf("1. Withdrawl\n");
        printf("2. Deposit\n");
        printf("3. Display Balance: \n");
        printf("4. Exit: \n");

        scanf("%d", &user);

        switch (user){
            case 1:
                int draw;
                printf("\nEnter the amount to withdraw: \n");
                scanf("%d", &draw);
                withdrawl(b1, draw);
                break;

            case 2:
                int dep;
                printf("\nEnter the amount to deposit: \n");
                scanf("%d", &dep);
                Deposit(b1, dep);
                break;

            case 3:
                printf("\nBalance: \n");
                display(b1);
                break;

            case 4:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
    while(user!=4);
}