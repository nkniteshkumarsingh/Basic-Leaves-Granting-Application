#include <stdio.h>
#define NumberOfEmployees 5        //Total number of Employees

float LeavesArray[NumberOfEmployees][10];       //Global Variable


int DisplayLeaves(int DisplayEid) {
    int i=1;
    while(((int)LeavesArray[i][0] != DisplayEid))
        i++;
    {
        printf("\nCasual Leave : %1.1f\nSpecial Casual Leave : %1.1f\nSpecial Leave : %1.1f\nEarned Leave : %1.1f\nVacation : %1.1f\nHalf Pay Leave : %1.1f\nCommuted Leave : %1.1f\nLeave Not Due : %1.1f\nExtra-ordinary Leave : %1.1f",LeavesArray[i][1],LeavesArray[i][2],LeavesArray[i][3],LeavesArray[i][4],LeavesArray[i][5],LeavesArray[i][6],LeavesArray[i][7],LeavesArray[i][8],LeavesArray[i][9]);
    }
    return 0;
}


int CasualLeave (int CasualEid) {
    int i=1;
    float days;
    printf("Enter the number of days you want to take leave : \n");
    scanf("%f",&days);

    while(((int)LeavesArray[i][0] != CasualEid))
        i++;

    if (days > 5) {
        printf("\nSorry! A leave for %1.1f days can not be granted under Casual Leaves.\nPlease try again.",days);
        return 1;
    }
    else if (LeavesArray[i][1] <= days) {
        printf("\nSorry! You Don't have %1.1f leaves left in your Casual leaves section.\nPlease try again.", days);
        return 1;
    }
    else {
        printf("\nCongratulations! A leave for %1.1f days has been granted to you.",days);
        LeavesArray[i][1] -= days;
        printf("\nRemaining Casual Leaves : %1.1f",LeavesArray[i][1]);
        return 0;
    }
}

int SpecialCasualLeave (int SpecialCasualEid) {
    int i=1,days;
    printf("Enter the number of days you want to take leave : \n");
    scanf("%d",&days);

    while(((int)LeavesArray[i][0] != SpecialCasualEid))
        i++;

    if ((int)LeavesArray[i][2] <= days) {
        printf("\nSorry! You Don't have %d leaves left in your Special Casual leaves section.\nPlease try again.", days);
        return 1;
    }
    else {
        printf("\nCongratulations! A leave for %d days has been granted to you.",days);
        LeavesArray[i][2] -= (float)days;
        printf("\nRemaining Special Casual Leaves : %1.1f",LeavesArray[i][2]);
        return 0;
    }
}

int SpecialLeave (int SpecialEid) {
    int i=1,days;
    printf("Enter the number of days you want to take leave : \n");
    scanf("%d",&days);

    while(((int)LeavesArray[i][0] != SpecialEid))
        i++;

    if ((int)LeavesArray[i][3] <= days) {
        printf("\nSorry! You Don't have %d leaves left in your Special leaves section.\nPlease try again.", days);
        return 1;
    }
    else {
        printf("\nCongratulations! A leave for %d days has been granted to you.",days);
        LeavesArray[i][3] -= (float)days;
        printf("\nRemaining Special Leaves : %1.1f",LeavesArray[i][3]);
        return 0;
    }
}

int EarnedLeave (int EarnedEid) {
    int i=1, days;
    printf("Enter the number of days you want to take leave : \n");
    scanf("%d",&days);

    while(((int)LeavesArray[i][0] != EarnedEid))
        i++;

    if ((int)LeavesArray[i][4] <= days) {
        printf("\nSorry! You Don't have %d leaves left in your Earned leaves section.\nPlease try again.", days);
        return 1;
    }
    else {
        printf("\nCongratulations! A leave for %d days has been granted to you.",days);
        LeavesArray[i][4] -= (float)days;
        printf("\nRemaining Earned Leaves : %1.1f",LeavesArray[i][4]);
        return 0;
    }
}

int Vacation (int VacationEid) {
    int i=1,days;
    printf("Enter the number of days you want to take leave : \n");
    scanf("%d",&days);

    while(((int)LeavesArray[i][0] != VacationEid))
        i++;

    if ((int)LeavesArray[i][5] <= days) {
        printf("\nSorry! You Don't have %d leaves left in your Vacation leaves section.\nPlease try again.", days);
        return 1;
    }
    else {
        printf("\nCongratulations! A leave for %d days has been granted to you.",days);
        if ((int)LeavesArray[i][4] <= days/2) {
            LeavesArray[i][5] -= (float)days/2;
            LeavesArray[i][4] -= (float)days/2;
        }
        else {
            days -= (int)LeavesArray[i][4];
            LeavesArray[i][4] = 0;
            LeavesArray[i][5] -= (float)days;
        }
        printf("\nRemaining Vacation Leaves : %1.1f",LeavesArray[i][5]);
        printf("\nRemaining Earned Leaves : %1.1f",LeavesArray[i][4]);
        return 0;
    }
}

int HalfPayLeave (int HalfPayEid) {
    int i=1,days;
    printf("Enter the number of days you want to take leave : \n");
    scanf("%d",&days);

    while(((int)LeavesArray[i][0] != HalfPayEid))
        i++;

    if ((int)LeavesArray[i][6] <= days) {
        printf("\nSorry! You Don't have %d leaves left in your Half Pay leaves section.\nPlease try again.", days);
        return 1;
    }
    else {
        printf("\nCongratulations! A leave for %d days has been granted to you.",days);
        LeavesArray[i][6] -= (float)days;
        printf("\nRemaining Half Pay Leaves : %1.1f",LeavesArray[i][6]);
        return 0;
    }
}

int CommutedLeave (int CommutedEid) {
    int i=1,days;
    printf("Enter the number of days you want to take leave : \n");
    scanf("%d",&days);

    while(((int)LeavesArray[i][0] != CommutedEid))
        i++;
    if ((LeavesArray[i][4] == 0) || (LeavesArray[i][6] == 0)) {
        printf("\nSorry! You are not eligible for a Commuted Leave. \nPlease try again.");
        return 1;
    }
    else {
        if ((int)LeavesArray[i][7] <= days) {
            printf("\nSorry! You Don't have %d leaves left in your Commuted leaves section.\nPlease try again.", days);
            return 1;
        }
        else {
            printf("\nCongratulations! A leave for %d days has been granted to you.",days);
            LeavesArray[i][7] -= (float)days;
            printf("\nRemaining Commuted Leaves : %1.1f",LeavesArray[i][7]);
            return 0;
        }
    }
}

int LeaveNotDue (int LeaveNotDueEid) {
    int i=1,days;
    printf("Enter the number of days you want to take leave : \n");
    scanf("%d",&days);

    while(((int)LeavesArray[i][0] != LeaveNotDueEid))
        i++;
    if (!LeavesArray[i][6]) {
        printf("\nSorry! You are not eligible for a Leave Not Due. \nPlease try again.");
        return 1;
    }
    else {
        if ((int)LeavesArray[i][8] <= days) {
            printf("\nSorry! You Don't have %d leaves left in your Leave Not Due section.\nPlease try again.", days);
            return 1;
        }
        else {
            printf("\nCongratulations! A leave for %d days has been granted to you.",days);
            LeavesArray[i][8] -= (float)days;
            printf("\nRemaining Leave Not Due : %1.1f",LeavesArray[i][8]);
            return 0;
        }
    }
}

int ExtraOrdinaryLeave (int ExtraOrdinaryEid) {
    int i=1;
    float days;
    printf("Enter the number of days you want to take leave : \n");
    scanf("%f",&days);

    while(((int)LeavesArray[i][0] != ExtraOrdinaryEid))
        i++;

    if (days > 90) {
        printf("\nSorry! A leave for %1.1f days can not be granted under Extra Ordinary Leaves.\nPlease try again.",days);
        return 1;
    }
    else if (LeavesArray[i][9] <= days) {
        printf("\nSorry! You Don't have %1.1f leaves left in your Extra Ordinary leaves section.\nPlease try again.", days);
        return 1;
    }
    else {
        printf("\nCongratulations! A leave for %1.1f days has been granted to you.",days);
        LeavesArray[i][9] -= days;
        printf("\nRemaining Extra Ordinary Leaves : %1.1f",LeavesArray[i][9]);
        return 0;
    }
}

int MaternityLeave () {
    float days;
    printf("Enter the number of days you want to take leave : \n");
    scanf("%f",&days);

    if (days > 135) {
        printf("\nSorry! A leave for %1.1f days can not be granted under Maternity Leaves.\nPlease try again.",days);
        return 1;
    }
    else {
        printf("\nCongratulations! A leave for %1.1f days has been granted to you.",days);
        return 0;
    }
}

int AdoptionLeave () {
    int age;
    float days;
    printf("Enter the number of days you want to take leave : \n");
    scanf("%f",&days);

    printf("\nEnter the age of the child in months : ");
    scanf("%d",&age);
    if (age <= 1) {
        if (days > 365) {
            printf("\nSorry! A leave for %1.1f days can not be granted under Adoption Leaves.\nPlease try again.",
                   days);
            return 1;
        }
        else {
            printf("\nCongratulations! A leave for %1.1f days has been granted to you.",days);
            return 0;
        }
    }
    else if (age <= 6) {
        if (days > 180) {
            printf("\nSorry! A leave for %1.1f days can not be granted under Adoption Leaves.\nPlease try again.",
                   days);
            return 1;
        }
        else {
            printf("\nCongratulations! A leave for %1.1f days has been granted to you.",days);
            return 0;
        }
    }
    else {
        if (days > 90) {
            printf("\nSorry! A leave for %1.1f days can not be granted under Adoption Leaves.\nPlease try again.",days);
            return 1;
        }
        else {
            printf("\nCongratulations! A leave for %1.1f days has been granted to you.",days);
            return 0;
        }
    }
}

int PaternityLeave () {
    int age, num;
    float days;
    printf("Enter the number of days you want to take leave : \n");
    scanf("%f",&days);

    printf("\nEnter the number of children you have :");
    scanf("%d",&num);
    if (num > 2) {
        printf("\nSorry! A leave for %1.1f days can not be granted under Paternity Leaves.\nPlease try again.",days);
        return 1;
    }
    else {
        printf("\nEnter the age of the child in months :");
        scanf("%d",&age);
        if (age > 6) {
            printf("\nSorry! A leave for %1.1f days can not be granted under Paternity Leaves.\nPlease try again.",days);
            return 1;
        }
        else {
            if (days > 15) {
                printf("\nSorry! A leave for %1.1f days can not be granted under Paternity Leaves.\nPlease try again.",days);
                return 1;
            }
            else {
                printf("\nCongratulations! A leave for %1.1f days has been granted to you.",days);
                return 0;
            }
        }
    }
}

int StudyLeave () {
    float days;
    printf("Enter the number of days you want to take leave : \n");
    scanf("%f",&days);

    if (days > 730) {
        printf("\nSorry! A leave for %1.1f days can not be granted under Study Leaves.\nPlease try again.",days);
        return 1;
    }
    else {
        printf("\nCongratulations! A leave for %1.1f days has been granted to you.",days);
        return 0;
    }
}


int TakeLeave(int TakeEid) {
    int LeaveChoice;
    printf("\nEnter the kind of leave you want to take : ");
    printf("\n1. Casual Leave");
    printf("\n2. Special Casual Leave");
    printf("\n3. Special Leave");
    printf("\n4. Earned Leave");
    printf("\n5. Vacation");
    printf("\n6. Half Pay Leave");
    printf("\n7. Commuted Leave");
    printf("\n8. Leave Not Due");
    printf("\n9. Extra-ordinary Leave");
    printf("\n10. Maternity Leave");
    printf("\n11. Adoption Leave");
    printf("\n12. Paternity Leave");
    printf("\n13. Study Leave\n");

    scanf("%d",&LeaveChoice);
    switch (LeaveChoice) {
        case 1: CasualLeave(TakeEid);
            break;
        case 2: SpecialCasualLeave(TakeEid);
            break;
        case 3: SpecialLeave(TakeEid);
            break;
        case 4: EarnedLeave(TakeEid);
            break;
        case 5: Vacation(TakeEid);
            break;
        case 6: HalfPayLeave(TakeEid);
            break;
        case 7: CommutedLeave(TakeEid);
            break;
        case 8: LeaveNotDue(TakeEid);
            break;
        case 9: ExtraOrdinaryLeave(TakeEid);
            break;
        case 10: MaternityLeave();
            break;
        case 11: AdoptionLeave();
            break;
        case 12: PaternityLeave();
            break;
        case 13: StudyLeave();
            break;
        default: printf("\nPlease enter a valid choice.");
            return 1;
    }
    return 0;
}


int main() {
    int Eid, Choice, i;

    for (i=1; i<=NumberOfEmployees; i++) {
        LeavesArray[i][0] = (float)i;
    }

    for (i=1; i<=5; i++) {
        LeavesArray[i][1] = 8;     //Casual Leave
        LeavesArray[i][2] = 15;     //Special Casual Leave
        LeavesArray[i][3] = 15;     //Special Leave
        LeavesArray[i][4] = 30;     //Earned Leave
        LeavesArray[i][5] = 60;     //Vacation
        LeavesArray[i][6] = 20;     //Half Pay Leave
        LeavesArray[i][7] = 180;       //Commuted Leave
        LeavesArray[i][8] = 360;       //Leave Not Due
        LeavesArray[i][9] = 1825;      //Extra Ordinary Leave
    }

    printf("\n~~~~~ LEAVES ~~~~~");
    printf("\nEnter your Employee ID :");
    scanf("%d",&Eid);
    if (Eid <= NumberOfEmployees) {
        printf("Enter your choice : \n");
        printf("1. Display all remaining leaves.\n");
        printf("2. Take Leave.\n");
        scanf("%d",&Choice);

        switch (Choice)
        {
            case 1 : DisplayLeaves(Eid);
                break;
            case 2 : TakeLeave(Eid);
                break;
            default: printf("\nInvalid Option Entered! Please try again.");
                break;
        }
        return 0;
    }
    else {
        printf("\nInvalid Employee ID entered! Please try again.");
        return 1;
    }
}
