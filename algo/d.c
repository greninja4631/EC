#include <stdio.h>

int main() {
int scores[] = {60, 70, 75, 80, 85, 90};
int i;
int min = scores[0];
int average = scores[0];

for(i = 0; i < 6; i++) {
if(scores[i] < min){
   min = scores[i];
      }

   }
     printf("%d\n" , min);
     return 0;


}
