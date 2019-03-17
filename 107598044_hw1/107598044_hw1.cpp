#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

int check_class_exist = 0;
sqlite3 * pDB = NULL;

//�W�[�ҵ{
void AddClass(const string& sName, const string& sDescription, const string& sTarget, const string& sPrice, const string& sAttention, const string& sNote);
//�R���ҵ{��
void DeleteClass(const string& sName);
//�s��ҵ{��
void ModifyClassName(const string& sName, const string& sNewName);
void ModifyClassDescription(const string& sName, const string& sNewDescription);
void ModifyClassTarget(const string& sName, const string& sNewTarget);
void ModifyClassPrice(const string& sName, const string& sNewPrice);
void ModifyClassAttention(const string& sName, const string& sNewAttention);
void ModifyClassNote(const string& sName, const string& sNewNote);
//�M��ҵ{
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
        printf("1. �C�X�Ҧ��ҵ{\n");
        printf("2. �s�W�ҵ{\n");
        printf("3. �R���ҵ{\n");
        printf("4. �s��ҵ{\n");
        printf("5. ���}\n");
        //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), );
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
        printf("�п�J�W���ҹ������Ʀr: ");
        scanf("%d", &input);
        gets(aa);
        system("cls");
        printf("�п�J�W���ҹ������Ʀr: %d\n\n", input);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        switch (input){
            case 1:
                printf("�Ҧ��ҵ{�p�U:\n\n");
                SelectClass();
                break;
            case 2:
                printf("-----�s�W�ҵ{-----\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                printf("��J�ҵ{�W��: ");
                gets(name);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                SelectCheckClassName(name);
                if (check_class_exist == 1){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
                    printf("�w�s�b�ۦP�W�٤��ҵ{�I\n\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                }
                else if (check_class_exist == 0 && strcmp (name, empty_class) == 0){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
                    printf("�ҵ{���o�d�šI\n\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                    printf("��J�ҵ{����: ");
                    gets(description);
                    printf("��J�ҵ{�A�X����H: ");
                    gets(target);
                    printf("��J�ҵ{�w��: ");
                    gets(price);
                    printf("��J�ҵ{�`�N�ƶ�: ");
                    gets(attention);
                    printf("��J�ҵ{�Ƶ�: ");
                    gets(note);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                    printf("\n[        �ҵ{�W��        ][        �ҵ{����        ][        �ҵ{��H        ][        �ҵ{�w��        ][        �`�N�ƶ�        ][        �ҵ{�Ƶ�        ]\n");
                    printf(" ------------------------  ------------------------  ------------------------  ------------------------  ------------------------  ------------------------ \n");
                    printf("%26s%26s%26s%26s%26s%26s\n", name, description, target, price, attention, note);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                    printf("\n�Y�T�w�n�s�W�A�ЦA��J�@���ҦW�A�_�h��J-1���X: ");
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
                            printf("��J���~�I\n");
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                            printf("�Y�T�w�n�s�W�A�ЦA��J�@���ҦW�A�_�h��J-1���X: ");
                        }
                    }
                }
                break;
            case 3:
                printf("-----�R���ҵ{-----\n\n");
                SelectClassName();
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                printf("�п�J�n�R�����ҵ{: ");
                gets(name);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                SelectCheckClassName(name);
                if (check_class_exist == 0){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
                    printf("�ҵ{���s�b�I\n\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                }
                else if (check_class_exist == 1){
                    SelectClassOne(name);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                    printf("�Y�T�w�n�R���A�ЦA��J�@���ҦW�A�_�h��J-1���X: ");
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
                            printf("��J���~�I\n");
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                            printf("�Y�T�w�n�R���A�ЦA��J�@���ҦW�A�_�h��J-1���X: ");
                        }
                    }
                }

                break;
            case 4:
                printf("-----�ҵ{�s��-----\n\n");
                SelectClassName();
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                printf("�п�J���ק蠟�ҵ{: ");
                gets(name);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                SelectCheckClassName(name);
                if (check_class_exist == 0){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
                    printf("�ҵ{���s�b�I\n\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                }
                else {
                    modify = 0;
                    while(modify!=7){
                        SelectClassOne(name);
                        printf("1. �ק�m%s�n�ҵ{�W��\n", name);
                        printf("2. �ק�m%s�n�ҵ{����\n", name);
                        printf("3. �ק�m%s�n�ҵ{�A�X����H\n", name);
                        printf("4. �ק�m%s�n�ҵ{�w��\n", name);
                        printf("5. �ק�m%s�n�ҵ{�`�N�ƶ�\n", name);
                        printf("6. �ק�m%s�n�ҵ{�Ƶ�\n", name);
                        printf("7. ���}�s��Ҧ�\n");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE);
                        printf("�п�J�W���ҹ������Ʀr: ");
                        scanf("%d", &modify);
                        gets(aa);
                        switch (modify){
                            case 1:
                                printf("�п�J���ק蠟�ҵ{�s�W��: ");
                                gets(newname);
                                if(strcmp (newname, empty_class) == 0){
                                    system("cls");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
                                    printf("���~�A�ҵ{���o�d�šI\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                                    break;
                                }
                                system("cls");
                                ModifyClassName(name, newname);
                                strcpy(name, newname);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                                break;
                            case 2:
                                printf("�п�J���ק蠟�ҵ{�s����: ");
                                gets(description);
                                system("cls");
                                ModifyClassDescription(name, description);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                                break;
                            case 3:
                                printf("�п�J���ק蠟�ҵ{�s�A�X����H: ");
                                gets(target);
                                system("cls");
                                ModifyClassTarget(name, target);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                                break;
                            case 4:
                                printf("�п�J���ק蠟�ҵ{�s�w��: ");
                                gets(price);
                                system("cls");
                                ModifyClassPrice(name, price);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                                break;
                            case 5:
                                printf("�п�J���ק蠟�ҵ{�s�`�N�ƶ�: ");
                                gets(attention);
                                system("cls");
                                ModifyClassAttention(name, attention);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                                break;
                            case 6:
                                printf("�п�J���ק蠟�ҵ{�s�Ƶ�: ");
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
                                printf("��J���~�A�Э��s��J�I\n");
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                        }
                    }
                    //printf("-----�w���}�ҵ{�s��Ҧ�-----\n\n");
                    system("cls");
                }
                break;
            case 5:
                return 0;
            default:
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED);
                printf("��J���~�A�Э��s��J\n\n");
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
        printf("�s�W�ҵ{����\: %s\n", cErrMsg);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        //return false;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("�s�W�m%s�n�ҵ{���\\\n\n", sName.c_str());
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
        printf("�R���ҵ{����\: %s\n", cErrMsg);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        //return false;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("�R���m%s�n�ҵ{���\\\n\n", sName.c_str());
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
        printf("�ק�ҵ{�W�٥���\: %s\n\n", cErrMsg);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        //return false;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("�ק�m%s�n�ҵ{�W�٦��\\: %s\n\n", sName.c_str(), sNewName.c_str());
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
        printf("�ק�ҵ{��������\: %s\n\n", cErrMsg);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        //return false;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("�ק�m%s�n�ҵ{�������\\: %s\n\n", sName.c_str(), sNewDescription.c_str());
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
        printf("�ק�ҵ{�A�ι�H����\: %s\n\n", cErrMsg);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        //return false;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("�ק�m%s�n�ҵ{�A�ι�H���\\: %s\n\n", sName.c_str(), sNewTarget.c_str());
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
        printf("�ק�ҵ{�w������\: %s\n\n", cErrMsg);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        //return false;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("�ק�m%s�n�ҵ{�w�����\\: %s\n\n", sName.c_str(), sNewPrice.c_str());
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
        printf("�ק�ҵ{�`�N�ƶ�����\: %s\n\n", cErrMsg);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        //return false;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("�ק�m%s�n�ҵ{�`�N�ƶ����\\: %s\n\n", sName.c_str(), sNewAttention.c_str());
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
        printf("�ק�ҵ{�Ƶ�����\: %s\n\n", cErrMsg);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        //return false;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf("�ק�m%s�n�ҵ{�Ƶ����\\: %s\n\n", sName.c_str(), sNewNote.c_str());
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

    printf("\n[        �ҵ{�W��        ][        �ҵ{����        ][        �ҵ{��H        ][        �ҵ{�w��        ][        �`�N�ƶ�        ][        �ҵ{�Ƶ�        ]\n");
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
    printf("\n[        �ҵ{�W��        ][        �ҵ{����        ][        �ҵ{��H        ][        �ҵ{�w��        ][        �`�N�ƶ�        ][        �ҵ{�Ƶ�        ]\n");
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
        printf("�m%s�n", (argv[i] ? argv[i] : "NULL"));
    }
    return 0;
}

void SelectClassName(){
    char* cErrMsg;
    printf("�ثe���ҵ{��: ");
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
    //    printf("��L���ҵ{\n");
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
