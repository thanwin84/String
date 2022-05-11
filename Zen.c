#include<stdio.h>
void add();
void deposit();
void withdraw();
void check_balance();
void check_details();
void deleteAcc();
int main()
{
    int choice;
    do
    {
        printf("Enter 1 for create new Account: \n");
        printf("Enter 2 for deposit: \n");
        printf("Enter 3 for withdraw: \n");
        printf("Enter 4 for check_balance: \n");
        printf("Enter 5 for check details: \n");
        printf("Enter 6 for delete Account: \n");
        printf("Enter 7 for Exit: \n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            add();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            check_balance();
            break;
        case 5:
            check_details();
            break;
        case 6:
            deleteAcc();
            break;
        }
    }
    while(choice != 7);
    return 0;
}
void add()
{
    char name[100], gender[10], address[1000], gmail[1000], phone[20], DOB[50];
    int deposit = 500;
    // Taking information
    printf("Enter Your name: ");
    fflush(stdin);
    gets(name);// input name
    printf("Enter Your date of birth(d/m/y): ");
    fflush(stdin);
    gets(DOB);
    printf("Enter Your gender: ");
    fflush(stdin);
    gets(gender); // input gender
    printf("Enter your address: ");
    fflush(stdin);
    gets(address); // input address
    printf("Enter Your Gmail address: ");
    fflush(stdin);
    gets(gmail); // input gmail
    printf("Enter your Phone number: ");
    fflush(stdin);
    gets(phone); //input phone
    //Create file and put information of Account holder
    char fName[16];
    strcpy(fName, phone);
    strcat(fName, ".txt");
    FILE *file;
    file = fopen(fName, "w");
    fprintf(file, "%s", name);
    fprintf(file, "\n");
    fprintf(file, "%s", DOB);
    fprintf(file, "\n");
    fprintf(file, "%s", gender);
    fprintf(file, "\n");
    fprintf(file, "%s", address);
    fprintf(file, "\n");
    fprintf(file, "%s", gmail);
    fprintf(file, "\n");
    fprintf(file, "%s", phone);
    fprintf(file, "\n");

    fclose(file);
    char bfn[100];
    strcpy(bfn, phone);
    strcat(bfn, "balance.txt");
    file = fopen(bfn, "w");
    fprintf(file, "%d", deposit);
    fclose(file);
    printf("\n\nYour account is created successfully\nYour Account number is: %s\n\n", phone);
}
void check_details()
{
    char accNumber[11];
    printf("Enter account Number: ");
    fflush(stdin);
    gets(accNumber);//input account number
    strcat(accNumber, ".txt");
    FILE *file;
    file = fopen(accNumber, "r");
    if(file == NULL)
        printf("\n\nAccount does not exist\n\n");
    else
    {
        printf("Account details: \n");
        while(!feof(file))
        {
            char ch;
            ch = fgetc(file);
            printf("%c", ch);
        }
        fclose(file);
        return 0;
    }
}
void deposit()
{
    int amount, balance;
    char str[1000000], acc_no[1000];
    printf("Enter Account No: ");
    fflush(stdin);
    gets(acc_no);
    strcat(acc_no, "balance.txt");
    FILE *file;
    file = fopen(acc_no, "r");
    if(file == NULL)
    {
        printf("Something is wrong, please try again or contact in office\n");
        return 0;
    }
    else
    {
        printf("Enter amount: ");
        scanf("%d", &amount);
        while(!feof(file))
        {
            fgets(str, 100000000, file);
        }
        balance = atoi(str);
        balance += amount;
    }
    fclose(file);
    file = fopen(acc_no, "w");
    fprintf(file, "%d", balance);
    fclose(file);
    printf("Deposit successful\n");
    printf("New balance is: %d\n", balance);
}
void withdraw()
{
    int amount, balance;
    char str[1000000], acc_no[1000];
    printf("Enter Account No: ");
    fflush(stdin);
    gets(acc_no);
    strcat(acc_no, "balance.txt");
    FILE *file;
    file = fopen(acc_no, "r");
    if(file == NULL)
    {
        printf("File does not found\n");
        return 0;
    }
    else
    {
        printf("Enter amount: ");
        scanf("%d", &amount);
        while(!feof(file))
        {
            fgets(str, 100000000, file);
        }
        balance = atoi(str);
        if(balance < amount)
        {
            printf("Insufficient balance\n");
            return;
        }
        else
            balance -= amount;
    }
    fclose(file);
    file = fopen(acc_no, "w");
    fprintf(file, "%d", balance);
    fclose(file);
    printf("Withdraw successful\n");
    printf("New balance is: %d\n", balance);
}
void check_balance()
{
    char acc_no[100];
    printf("Enter Account number: ");
    fflush(stdin);
    gets(acc_no);
    strcat(acc_no, "balance.txt");
    FILE *file;
    file = fopen(acc_no, "r");
    if(file == NULL)
        printf("Wrong Account number\n");
    else
    {
        while(!feof(file))
        {
            printf("%c", fgetc(file));
        }
    }
    fclose(file);
    printf("\n");
}
void deleteAcc()
{
    char acc_no[100], bf[100];
    printf("Enter Account number: ");
    fflush(stdin);
    gets(acc_no);
    strcpy(bf, acc_no);
    strcat(acc_no, ".txt");
    strcat(bf, "balance.txt");
    int l = remove(acc_no);
    int m = remove(bf);
    if(l == 0 && m == 0)
        printf("Account delete successfully\n");
    else
        printf("Something wrong, try again\n");
}
