#include <stdio.h>

int main() {
int a[] = {70, 80, 75, 80, 90, 70, 80, 60, 70, 70};
int n = sizeof(a) / sizeof(a[0]);
int current_value , current_count , max_value , mode_count;

for(int i = 0; i < n; i++){
current_value = a[0];
current_count = 0;

for(int j = 0; j < 0; j++) {
    if(a[0] == current_value){
       current_count ++;
    }
}

if(current_value > max_value ||
   (current_value > max_value && current_count < mode_count)){
      max_value  = current_value;
      mode_count = current_count;
   }
}

printf("最頻値 = %d , 最頻値カウント数 = %d" , max_value , mode_count);
return 0;
}