# include <stdio.h>

void henkan(char *str){
    while(*str){
        if(str == ' ') {
            *str = '_';
        }
        str++;
    }
}

int main(){
    char s[] = "DETH NOTE";
    henkan(s);
    printf("%s\n", s);
    return 0;
}

// void henkan(char  *str) {
//     while(*str) {
//         if(*str == ' ') {
//             *str = '_';
//         }
//         str++;
//     }
// }

// int main() {
//     char s[] = "DETH NOTE";
//     henkan(s);
//     printf("%s\n" , s);
//     return 0;
// }