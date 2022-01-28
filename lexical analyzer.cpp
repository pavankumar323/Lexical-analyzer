#include <stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<ctype.h>
#include<bits/stdc++.h>
using namespace std;
int isKeyword(string buffer){
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    int i, flag = 0;
    for (i = 0; i < 32; ++i){
        if (keywords[i] == buffer){
            flag = 1;
            break;
        }
    }
    return flag;
}
bool isOperator(char ch){
    char operators[] = "+-*/%=(){},";
    for (int i = 0; i < 11; ++i){
        if (ch == operators[i]){
            return true; 
        }
    }
    return false;
}
void Check(string &buffer){
    if(buffer.size() != 0){
        if (isKeyword(buffer) == 1){
            cout << buffer <<  " is keyword" << endl;
        }
        else{
            if(buffer == "include" || buffer =="stdioh" || buffer == "define" || buffer == ""){
                cout << buffer << " is not an identifier" << endl;
            }else{
                cout << buffer << " is identifer" << endl;
            }
        }
        buffer = "";
    }
}
int main()
{
    char ch;
    string buffer = "";
    FILE *fp;
    fp = fopen("input1.c", "r");
    if (fp == NULL){
        printf("error while opening the file\n");
        exit(0);
    }
    while ((ch = fgetc(fp)) != EOF){   
        if(isOperator(ch)){
            cout << ch << " is operator" << endl;
            Check(buffer);
        }
        if(isalnum(ch)){
            buffer += ch;
        }
        else if ((ch == ' ' || ch == '\n') && (buffer.size() != 0)){
            Check(buffer);
        }
    }
    fclose(fp);
    return 0;
}
