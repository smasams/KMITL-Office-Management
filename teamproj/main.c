#include <stdio.h>
#include <stdlib.h>

char un[80];
char pass[80];
int userno;

void login(){
    int c=0;
    while(c==0){

        printf("Username or enter (q) to exit: ");
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
        fprintf(ftask,"");
        fclose(ftask);
    }
    else{
        printf("then do so");
        exit(0);
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
    scanf("%d",&emno);
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
    scanf("%d",&emno);
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

int main()
{
    login();
    int com;
    if(strcmp (un, "admin")==0){
        printf("command: (1)give task (2)see data: ");
        scanf("%d",&com);
    }
    else{
        printf("command: (0)view task: ");
        scanf("%d",&com);
    }
    if(com==0){
        viewtask();
    }
    else if(com==1){
        givetask();
    }
    else if(com==2){
        seedata();
    }
    return 0;
}
