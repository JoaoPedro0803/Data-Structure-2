#include <stdio.h>
int h = 0;
void conta7(char *v, int i) {

 if (v[i] != '\0'){
    if (v[i] == '7'){
        h++;
        conta7(v, i+1);
    } else{
        conta7(v, i+1);
  }
 }
}

int main () {
    char v[1000];
    scanf("%s", v);
    conta7(v, 0);
    printf("%d", h);

    return 0;
}


