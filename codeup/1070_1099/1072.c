/*
1072.
n개의 정수가 순서대로 입력된다.
-2147483648 ~ +2147483647, 단 n의 최대 개수는 알 수 없다.

n개의 입력된 정수를 순서대로 출력해보자.

while( ), for( ), do~while( ) 등의 반복문을 사용할 수 없다.

n개의 정수를 한 개씩 줄을 바꿔 출력한다.

ex)
5
dfddk
1 2 3 4 5
 */

#include <stdio.h>

int main(void) {
  int num1, num2;
  scanf("%d", &num1);
replay:
  scanf("%d", &num2);
  if(num1-- != 0) {
    printf("%d\n", num2);
    goto replay;
  }
  return 0;
}