#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>

using namespace std;

int main() {
    char str[105];
    while(gets(str) != NULL) {
        for(int i = 0; i < strlen(str); i++) {
            if(str[i] == ' ' && isalpha(str[i+1]))
                str[i+1] = toupper(str[i+1]);
        }
        if(isalpha(str[0])) str[0] = toupper(str[0]);
        puts(str);
    }
    return 0;
}
