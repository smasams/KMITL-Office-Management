#include <stdio.h>
#include <stdlib.h>

char un[80];
char pass[80];
int userno;
int z=0;
void login(){
    int c=0;
    while(c==0){

        printf("Username or enter (q) to exit: ");
        if(z==1){
            fgets(un, 20, stdin);
        }
        fgets(un, 20, stdin);
        un[strcspn(un, "\r\n")] = 0;
        if(strcmp (un, "q")==0){
            exit(0);
        }
        printf("Password: ");
        fgets(pass, 20, stdin);
        pass[strcspn(pass, "\r\n")] = 0;

        int i=0;
        char fu[80];
        char fp[80];

        while(i<=99){

            sprintf(fu,"%d-un.txt",i);
            sprintf(fp,"%d-pass.txt",i);
            FILE *fun;
            fun = fopen(fu, "r");
            FILE *fpass;
            fpass= fopen(fp,"r");

            char chun[80];
            char chpa[80];
            const size_t line_size = 300;
            char* line = malloc(line_size);
            while (fgets(line, line_size, fun) != NULL)  {
                strcpy(chun, line);
            }
            while (fgets(line, line_size, fpass) != NULL)  {
                strcpy(chpa, line);
                }
            if(strcmp (un, chun)==0 && strcmp (pass, chpa)==0){
                c=1;
                userno=i;
                break;
            }
            i++;
        }

        if(c==1){
            printf("success");
        }
        else{
            printf("fail");
            z=0;
        }
        Sleep(1000);
        system("cls");
    }
}

void viewtask(){
    char ut[80];
    sprintf(ut,"%d-task.txt",userno);
    FILE *ftask;
    ftask = fopen(ut, "r");
    char ch,*ptr;
    char s[100];
    int count=0;
    ch=fgetc(ftask);
    while(ch != EOF){
        s[count]=ch;
        ch=fgetc(ftask);
        count++;
    }
    printf("%s",s);
    fclose(ftask);
    int comp;
    printf("\nis it complete? Yes(1) No(0): ");
    scanf("%d",&comp);
    if(comp==1){
        ftask = fopen(ut, "w");
        fprintf(ftask," ");
        fclose(ftask);
        FILE *fcn= fopen("notif.txt","a");
        fprintf(fcn,"%s has complete his/her task.\n",un);
        fclose(fcn);
    }
    else{
        printf("then do so");
    }
}
void givetask(){
    printf("give task to who(if task already exist, it will be replace)?(enter number infront of name) \n");
    FILE *fen;
    fen = fopen("emna.txt", "r");
    char ch;
    char s[100];
    int count=0;
    ch=fgetc(fen);
    while(ch != EOF){
        s[count]=ch;
        ch=fgetc(fen);
        count++;
    }
    printf("%s\n",s);
    fclose(fen);
    int emno;
    printf("Input: ");
    scanf("%d",&emno);
    printf("\n");
    char at[80];
    sprintf(at,"%d-task.txt",emno);
    FILE *ftask;
    ftask = fopen(at, "w");
    char tas[100];
    printf("what is the task?: ");
    fgets(tas, 20, stdin);
    fgets(tas, 100, stdin);
    un[strcspn(tas, "\r\n")] = 0;
    fprintf(ftask,"%s",tas);
    fclose(ftask);

}

void seedata(){
    printf("view which employee data?(enter number infront of name)\n");
    FILE *fen;
    fen = fopen("emna.txt", "r");
    char ch;
    char s[100];
    int count=0;
    ch=fgetc(fen);
    while(ch != EOF){
        s[count]=ch;
        ch=fgetc(fen);
        count++;
    }
    printf("%s\n",s);
    fclose(fen);
    int emno;
    printf("Input: ");
    scanf("%d",&emno);
    printf("\n");
    char ud[80];
    sprintf(ud,"%d-data.txt",emno);
    FILE *fdat;
    fdat = fopen(ud, "r");
    char ch2;
    char s2[100];
    count=0;
    ch2=fgetc(fdat);
    while(ch2 != EOF){
        s2[count]=ch2;
        ch2=fgetc(fdat);
        count++;
    }
    printf("%s",s2);
    fclose(fdat);

}
void seenotif(){
    FILE *fcn;
    fcn = fopen("notif.txt", "r");
    char ch;
    char s[100];
    int count=0;
    ch=fgetc(fcn);
    while(ch != EOF){
        s[count]=ch;
        ch=fgetc(fcn);
        count++;
    }
    printf("%s\n",s);
    fclose(fcn);
    int del;
    printf("\ndelete all notification?: yes(1) no(0)");
    scanf("%d",&del);
    if(del==1){
        fcn = fopen("notif.txt", "w");
        fprintf(fcn," ");
        fclose(fcn);
    }
}
void leaves(){
    FILE *fcn= fopen("notif.txt","a");
        fprintf(fcn,"%s request for leave of absence.\n",un);
        fclose(fcn);
}
int main()
{
    int l=0;
    while(l==0){
        l=1;
        login();
        int com;
        int c=0;
        while(c==0){
            if(strcmp (un, "admin")==0){
            printf("command: (0)see notification (1)give task (2)see data: ");
            scanf("%d",&com);
                if(com==0){
                    seenotif();
                    c=1;
                }
                else if(com==1){
                    givetask();
                    c=1;
                }
                else if(com==2){
                    seedata();
                    c=1;
                }
                else{
                    printf("command doesn't exist\n");
                    Sleep(1000);
                    system("cls");
                }
                }
            else{
                printf("command: (0)view task (1)apply for leaves: ");
                scanf("%d",&com);
                if(com==0){
                    viewtask();
                    c=1;
                }
                else if(com==1){
                    leaves();
                    c=1;
                }
                else{
                    printf("command doesn't exist\n");
                    Sleep(1000);
                    system("cls");
                }
            }
            if(c==1){
                int r;
                printf("\n\nAnything Else?: yes(1) No(0)");
                scanf("%d",&r);
                if(r==1){
                    c=0;
                }
                if(c==0){
                    printf("\ndo you want to login with another account?: yes(1) No(0)");
                    scanf("%d",&r);
                    if(r==1){
                        l=0;
                        c=1;
                        z=1;
                    }
                }
            }
        }
    }
    return 0;
}
