#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

int check_class_exist = 0;
sqlite3 * pDB = NULL;

//¼W¥[½Òµ{
void AddClass(const string& sName, const string& sDescription, const string& sTarget, const string& sPrice, const string& sAttention, const string& sNote);
//§R°£½Òµ{ˆ·
void DeleteClass(const string& sName);
//½s¿è½Òµ{ˆ·
void ModifyClassName(const string& sName, const string& sNewName);
void ModifyClassDescription(const string& sName, const string& sNewDescription);
void ModifyClassTarget(const string& sName, const string& sNewTarget);
void ModifyClassPrice(const string& sName, const string& sNewPrice);
void ModifyClassAttention(const string& sName, const string& sNewAttention);
void ModifyClassNote(const string& sName, const string& sNewNote);
//´M§ä½Òµ{
void SelectClass();
void SelectClassOne(const string& sName);
void SelectClassName();
void SelectCheckClassName(const string& sName);

int main(){
    system("color F0");
    int input, modify;
    char aa[50], name[100], description[100], target[100], price[100], attention[100], note[100], newname[100], minus_one[5]="-1", empty_class[5]="";
    int nRes = sqlite3_open("./test.db", &pDB);
    if (nRes != SQLITE_OK){
        cout<<"Open database fail: "<<sqlite3_errmsg(pDB);
        return 0;
    }
    //system("color f0");
    while (1){
        printf("1. ¦C¥X©Ò¦³½Òµ{\n");
        printf("2. ·s¼W½Òµ{\n");
        printf("3. §R°£½Òµ{\n");
        printf("4. ½s¿è½Òµ{\n");
        printf("5. Â÷¶}\n");
        //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), );
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
        printf("½Ð¿é¤J¤W­±©Ò¹ïÀ³ªº¼Æ¦r: ");
        scanf("%d", &input);
        gets(aa);
        system("cls");
        printf("½Ð¿é¤J¤W­±©Ò¹ïÀ³ªº¼Æ¦r: %d\n\n", input);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        switch (input){
            case 1:
                printf("©Ò¦³½Òµ{¦p¤U:\n\n");
                SelectClass();
                break;
            case 2:
                printf("-----·s¼W½Òµ{-----\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                printf("¿é¤J½Òµ{¦WºÙ: ");
                gets(name);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                SelectCheckClassName(name);
                if (check_class_exist == 1){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
                    printf("¤w¦s¦b¬Û¦P¦WºÙ¤§½Òµ{¡I\n\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                }
                else if (check_class_exist == 0 && strcmp (name, empty_class) == 0){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
                    printf("½Òµ{¤£±o¯dªÅ¡I\n\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                    printf("¿é¤J½Òµ{»¡©ú: ");
                    gets(description);
                    printf("¿é¤J½Òµ{¾A¦Xªº¹ï¶H: ");
                    gets(target);
                    printf("¿é¤J½Òµ{©w»ù: ");
                    gets(price);
                    printf("¿é¤J½Òµ{ª`·N¨Æ¶µ: ");
                    gets(attention);
                    printf("¿é¤J½Òµ{³Æµù: ");
                    gets(note);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    printf("\n[        ½Òµ{¦WºÙ        ][        ½Òµ{»¡©ú        ][        ½Òµ{¹ï¶H        ][        ½Òµ{©w»ù        ][        ª`·N¨Æ¶µ        ][        ½Òµ{³Æµù        ]\n");
                    printf(" ------------------------  ------------------------  ------------------------  ------------------------  ------------------------  ------------------------ \n");
                    printf("%26s%26s%26s%26s%26s%26s\n", name, description, target, price, attention, note);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                    printf("\n­Y½T©w­n·s¼W¡A½Ð¦A¿é¤J¤@¦¸½Ò¦W¡A§_«h¿é¤J-1¸õ¥X: ");
                    while(1){
                        gets(newname);
                        if (strcmp (name, newname) == 0){
                            system("cls");
                            AddClass(name, description, target, price, attention, note);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                            break;
                        }
                        else if (strcmp (minus_one, newname) == 0){
                            system("cls");
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                            break;
                        }
                        else{
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
                            printf("¿é¤J¿ù»~¡I\n");
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                            printf("­Y½T©w­n·s¼W¡A½Ð¦A¿é¤J¤@¦¸½Ò¦W¡A§_«h¿é¤J-1¸õ¥X: ");
                        }
                    }
                }
                break;
            case 3:
                printf("-----§R°£½Òµ{-----\n\n");
                SelectClassName();
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                printf("½Ð¿é¤J­n§R°£ªº½Òµ{: ");
                gets(name);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                SelectCheckClassName(name);
                if (check_class_exist == 0){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
                    printf("½Òµ{¤£¦s¦b¡I\n\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                }
                else if (check_class_exist == 1){
                    SelectClassOne(name);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                    printf("­Y½T©w­n§R°£¡A½Ð¦A¿é¤J¤@¦¸½Ò¦W¡A§_«h¿é¤J-1¸õ¥X: ");
                    while (1){
                        gets(newname);
                        if (strcmp (name, newname) == 0){
                            system("cls");
                            DeleteClass(name);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                            break;
                        }
                        else if (strcmp (minus_one, newname) == 0){
                            system("cls");
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                            break;
                        }
                        else{
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
                            printf("¿é¤J¿ù»~¡I\n");
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                            printf("­Y½T©w­n§R°£¡A½Ð¦A¿é¤J¤@¦¸½Ò¦W¡A§_«h¿é¤J-1¸õ¥X: ");
                        }
                    }
                }

                break;
            case 4:
                printf("-----½Òµ{½s¿è-----\n\n");
                SelectClassName();
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                printf("½Ð¿é¤J±ý­×§ï¤§½Òµ{: ");
                gets(name);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                SelectCheckClassName(name);
                if (check_class_exist == 0){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
                    printf("½Òµ{¤£¦s¦b¡I\n\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                }
                else {
                    modify = 0;
                    while(modify!=7){
                        SelectClassOne(name);
                        printf("1. ­×§ï¡m%s¡n½Òµ{¦WºÙ\n", name);
                        printf("2. ­×§ï¡m%s¡n½Òµ{»¡©ú\n", name);
                        printf("3. ­×§ï¡m%s¡n½Òµ{¾A¦Xªº¹ï¶H\n", name);
                        printf("4. ­×§ï¡m%s¡n½Òµ{©w»ù\n", name);
                        printf("5. ­×§ï¡m%s¡n½Òµ{ª`·N¨Æ¶µ\n", name);
                        printf("6. ­×§ï¡m%s¡n½Òµ{³Æµù\n", name);
                        printf("7. Â÷¶}½s¿è¼Ò¦¡\n");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                        printf("½Ð¿é¤J¤W­±©Ò¹ïÀ³ªº¼Æ¦r: ");
                        scanf("%d", &modify);
                        gets(aa);
                        switch (modify){
                            case 1:
                                printf("½Ð¿é¤J±ý­×§ï¤§½Òµ{·s¦WºÙ: ");
                                gets(newname);
                                if(strcmp (newname, empty_class) == 0){
                                    system("cls");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
                                    printf("¿ù»~¡A½Òµ{¤£±o¯dªÅ¡I\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                                    break;
                                }
                                system("cls");
                                ModifyClassName(name, newname);
                                strcpy(name, newname);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                                break;
                            case 2:
                                printf("½Ð¿é¤J±ý­×§ï¤§½Òµ{·s»¡©ú: ");
                                gets(description);
                                system("cls");
                                ModifyClassDescription(name, description);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                                break;
                            case 3:
                                printf("½Ð¿é¤J±ý­×§ï¤§½Òµ{·s¾A¦Xªº¹ï¶H: ");
                                gets(target);
                                system("cls");
                                ModifyClassTarget(name, target);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                                break;
                            case 4:
                                printf("½Ð¿é¤J±ý­×§ï¤§½Òµ{·s©w»ù: ");
                                gets(price);
                                system("cls");
                                ModifyClassPrice(name, price);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                                break;
                            case 5:
                                printf("½Ð¿é¤J±ý­×§ï¤§½Òµ{·sª`·N¨Æ¶µ: ");
                                gets(attention);
                                system("cls");
                                ModifyClassAttention(name, attention);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                                break;
                            case 6:
                                printf("½Ð¿é¤J±ý­×§ï¤§½Òµ{·s³Æµù: ");
                                gets(note);
                                system("cls");
                                ModifyClassNote(name, note);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                                break;
                            case 7:
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                                break;
                            default:
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
                                printf("¿é¤J¿ù»~¡A½Ð­«·s¿é¤J¡I\n");
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                        }
                    }
                    //printf("-----¤wÂ÷¶}½Òµ{½s¿è¼Ò¦¡-----\n\n");
                    system("cls");
                }
                break;
            case 5:
                return 0;
            default:
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
                printf("¿é¤J¿ù»~¡A½Ð­«·s¿é¤J\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        }

    }

//QUIT:
    //sqlite3_close(pDB);

    return 0;
}

void AddClass(const string& sName, const string& sDescription, const string& sTarget, const string& sPrice, const string& sAttention, const string& sNote){
    string strSql = "";

    strSql += "insert into class(name, description, target, price, attention, note)";
    strSql += "values('";
    strSql += sName;
    strSql += "','";
    strSql += sDescription;
    strSql += "','";
    strSql += sTarget;
    strSql += "',";
    strSql += sPrice;
    strSql += ",'";
    strSql += sAttention;
    strSql += "','";
    strSql += sNote;
    strSql += "');";

    char* cErrMsg;
    int nRes = sqlite3_exec(pDB , strSql.c_str() ,0 ,0, &cErrMsg);
    if (nRes != SQLITE_OK){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
        printf("·s¼W½Òµ{¥¢±Ñ\: %s\n", cErrMsg);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        //return false;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("·s¼W¡m%s¡n½Òµ{¦¨¥\\\n\n", sName.c_str());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    }

    //return true;
}

void DeleteClass(const string& sName){
    string strSql = "";
    strSql += "delete from class where name='";
    strSql += sName;
    strSql += "';";

    char* cErrMsg;
    int nRes = sqlite3_exec(pDB , strSql.c_str() ,0 ,0, &cErrMsg);
    if (nRes != SQLITE_OK){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
        printf("§R°£½Òµ{¥¢±Ñ\: %s\n", cErrMsg);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        //return false;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("§R°£¡m%s¡n½Òµ{¦¨¥\\\n\n", sName.c_str());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    }

    //return true;
}

void ModifyClassName(const string& sName, const string& sNewName){
    string strSql = "";

    strSql += "update class set name ='";
    strSql += sNewName;
    strSql += "' where name='";
    strSql += sName;
    strSql += "';";

    char* cErrMsg;
    int nRes = sqlite3_exec(pDB , strSql.c_str() ,0 ,0, &cErrMsg);
    if (nRes != SQLITE_OK){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
        printf("­×§ï½Òµ{¦WºÙ¥¢±Ñ\: %s\n\n", cErrMsg);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        //return false;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("­×§ï¡m%s¡n½Òµ{¦WºÙ¦¨¥\\: %s\n\n", sName.c_str(), sNewName.c_str());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    }
    //return true;
}

void ModifyClassDescription(const string& sName, const string& sNewDescription){
    string strSql = "";

    strSql += "update class set description ='";
    strSql += sNewDescription;
    strSql += "' where name='";
    strSql += sName;
    strSql += "';";

    char* cErrMsg;
    int nRes = sqlite3_exec(pDB , strSql.c_str() ,0 ,0, &cErrMsg);
    if (nRes != SQLITE_OK){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
        printf("­×§ï½Òµ{»¡©ú¥¢±Ñ\: %s\n\n", cErrMsg);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        //return false;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("­×§ï¡m%s¡n½Òµ{»¡©ú¦¨¥\\: %s\n\n", sName.c_str(), sNewDescription.c_str());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    }
    //return true;
}

void ModifyClassTarget(const string& sName, const string& sNewTarget){
    string strSql = "";

    strSql += "update class set target ='";
    strSql += sNewTarget;
    strSql += "' where name='";
    strSql += sName;
    strSql += "';";

    char* cErrMsg;
    int nRes = sqlite3_exec(pDB , strSql.c_str() ,0 ,0, &cErrMsg);
    if (nRes != SQLITE_OK){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
        printf("­×§ï½Òµ{¾A¥Î¹ï¶H¥¢±Ñ\: %s\n\n", cErrMsg);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        //return false;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("­×§ï¡m%s¡n½Òµ{¾A¥Î¹ï¶H¦¨¥\\: %s\n\n", sName.c_str(), sNewTarget.c_str());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    }
    //return true;
}

void ModifyClassPrice(const string& sName, const string& sNewPrice){
    string strSql = "";

    strSql += "update class set price =";
    strSql += sNewPrice;
    strSql += " where name='";
    strSql += sName;
    strSql += "';";

    char* cErrMsg;
    int nRes = sqlite3_exec(pDB , strSql.c_str() ,0 ,0, &cErrMsg);
    if (nRes != SQLITE_OK){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
        printf("­×§ï½Òµ{©w»ù¥¢±Ñ\: %s\n\n", cErrMsg);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        //return false;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("­×§ï¡m%s¡n½Òµ{©w»ù¦¨¥\\: %s\n\n", sName.c_str(), sNewPrice.c_str());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    }
    //return true;
}

void ModifyClassAttention(const string& sName, const string& sNewAttention){
    string strSql = "";

    strSql += "update class set attention ='";
    strSql += sNewAttention;
    strSql += "' where name='";
    strSql += sName;
    strSql += "';";

    char* cErrMsg;
    int nRes = sqlite3_exec(pDB , strSql.c_str() ,0 ,0, &cErrMsg);
    if (nRes != SQLITE_OK){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
        printf("­×§ï½Òµ{ª`·N¨Æ¶µ¥¢±Ñ\: %s\n\n", cErrMsg);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        //return false;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("­×§ï¡m%s¡n½Òµ{ª`·N¨Æ¶µ¦¨¥\\: %s\n\n", sName.c_str(), sNewAttention.c_str());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    }
    //return true;
}

void ModifyClassNote(const string& sName, const string& sNewNote){
    string strSql = "";

    strSql += "update class set note ='";
    strSql += sNewNote;
    strSql += "' where name='";
    strSql += sName;
    strSql += "';";

    char* cErrMsg;
    int nRes = sqlite3_exec(pDB , strSql.c_str() ,0 ,0, &cErrMsg);
    if (nRes != SQLITE_OK){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
        printf("­×§ï½Òµ{³Æµù¥¢±Ñ\: %s\n\n", cErrMsg);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        //return false;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("­×§ï¡m%s¡n½Òµ{³Æµù¦¨¥\\: %s\n\n", sName.c_str(), sNewNote.c_str());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    }
    //return true;
}

static int UserResult(void *NotUsed, int argc, char **argv, char **azColName){
    for(int i = 1 ; i < argc ; i++){
        //cout<<azColName[i]<<" = "<<(argv[i] ? argv[i] : "NULL")<<", ";
        printf("%26s", (argv[i] ? argv[i] : "NULL"));
    }

    printf("\n");

    return 0;
}

void SelectClass(){
    char* cErrMsg;

    printf("\n[        ½Òµ{¦WºÙ        ][        ½Òµ{»¡©ú        ][        ½Òµ{¹ï¶H        ][        ½Òµ{©w»ù        ][        ª`·N¨Æ¶µ        ][        ½Òµ{³Æµù        ]\n");
    printf(" ------------------------  ------------------------  ------------------------  ------------------------  ------------------------  ------------------------ \n");


    int res = sqlite3_exec(pDB, "select * from class;", UserResult , 0 , &cErrMsg);

    if (res != SQLITE_OK){
        cout<<"select fail: "<<cErrMsg<<endl;
        //return false;
    }
    printf("\n");
    //return true;
}

void SelectClassOne(const string& sName){
    char* cErrMsg;
    string strSql = "";
    printf("\n[        ½Òµ{¦WºÙ        ][        ½Òµ{»¡©ú        ][        ½Òµ{¹ï¶H        ][        ½Òµ{©w»ù        ][        ª`·N¨Æ¶µ        ][        ½Òµ{³Æµù        ]\n");
    printf(" ------------------------  ------------------------  ------------------------  ------------------------  ------------------------  ------------------------ \n");
    strSql += "select * from class where name ='";
    strSql += sName;
    strSql += "';";

    int res = sqlite3_exec(pDB, strSql.c_str(), UserResult , 0 , &cErrMsg);

    if (res != SQLITE_OK){
        cout<<"select fail: "<<cErrMsg<<endl;
        //return false;
    }
    printf("\n");
    //return true;
}

static int UserResultName(void *NotUsed, int argc, char **argv, char **azColName){
    for(int i = 0 ; i < argc ; i++){
        //cout<<azColName[i]<<" = "<<(argv[i] ? argv[i] : "NULL")<<", ";
        printf("¡m%s¡n", (argv[i] ? argv[i] : "NULL"));
    }
    return 0;
}

void SelectClassName(){
    char* cErrMsg;
    printf("¥Ø«eªº½Òµ{¦³: ");
    int res = sqlite3_exec(pDB, "select name from class;", UserResultName , 0 , &cErrMsg);

    if (res != SQLITE_OK){
        cout<<"select fail: "<<cErrMsg<<endl;
        //return false;
    }
    printf("\n");
    //return true;
}

static int UserResultCheckName(void *data, int argc, char **argv, char **azColName){
    //printf("argc = %d\n", argc);
    //printf("data=%s\n", (const char*)data);
    check_class_exist = 1;
    //if (argc == 0){
    //    printf("§äµL¦¹½Òµ{\n");
    //}
    return 0;
}

void SelectCheckClassName(const string& sName){
    check_class_exist = 0;
    const char* data = "Callback function called";
    string strSql = "";

    strSql += "select name from class where name ='";
    strSql += sName;
    strSql += "';";

    char* cErrMsg;
    int res = sqlite3_exec(pDB, strSql.c_str(), UserResultCheckName , (void*)data, &cErrMsg);

    if (res != SQLITE_OK){
        cout<<"select fail: "<<cErrMsg<<endl;
        //return false;
    }
}
