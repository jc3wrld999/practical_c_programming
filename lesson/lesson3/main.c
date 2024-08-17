/*
 * 과제: MVC 모델로 수정
 * detail:
 *  * 검색에서 각각의 항목으로도 검색 가능하도록
 *  * 삭제를 할 때에 검색되어서 출력된 address 앞에 numbering 을 통해서 삭제하도록
 *  * address 출력을 어떻게 할 것인가..
 *  * 입력, 삭제 된 address 들을 파일에 저장
 *  * 예외처리
 *
 * Proceed:
 *  * MVC - data 처리 부분 따로..
 *   - View 를 어떻게 수정하느냐에 따라서 형태는 달라진다.
 *   - Web
 *    - data 처리는 database
 *    - api
 *   - GUI: Qt, GTK
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "address.h"
#include "menu.h"

int main(void)
{
    int choice;
    int status = 1;

    AddressList *address_list = malloc(sizeof(AddressList));

    while(status)
    {
        // 메인 메뉴 출력
        printf("\n******************* Main Menu *******************\n");
        printf("1. 주소 입력\n");
        printf("2. 주소 검색\n");
        printf("3. 주소 삭제\n");
        printf("4. 주소 수정\n");
        printf("5. 주소 출력\n");        
        printf("6. 닫기\n");
        printf("*************************************************\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: // 주소 입력
                menu_address_add(address_list);
                break;
            case 2: // 주소 검색
                menu_address_search(address_list);
                break;
            case 3: // 주소 삭제
                menu_address_delete(address_list);
                break;
            case 4: // 주소 수정
                menu_address_edit(address_list);
                break;
            case 5: // 주소 출력
                menu_address_print(address_list);
                break;                
            case 6: // 닫기
                menu_exit_program(address_list);
                status = 0;
                break;
            default:
                printf("Try Again...\n");
                break;
        }
    }

    return 0;
}


