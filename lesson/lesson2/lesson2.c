/*
주소록: 이름, 나이, 핸드폰번호, 주소, 성별
메뉴를 통해서 입력, 검색, 삭제, 수정
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// address node
typedef struct _address
{
    char name[100];
    char address[100];
    int age;
    char gender[8];
    char phone[100];
    struct _address *next;
} Address;

// address list
typedef struct _addressList
{
    Address *head;
    int length;
} AddressList;


// 주소 추가
void address_add(AddressList *address_list)
{
    // object initialize
    Address *new_address = malloc(sizeof(Address));

    // 주소 입력 받기
    printf("Name: ");
    scanf("%s", new_address->name);    
    printf("Address: ");
    scanf("%s", new_address->address);    
    printf("Age: ");
    scanf("%d", &(new_address->age));
    printf("Gender: ");
    scanf("%s", new_address->gender);
    printf("Phone: ");
    scanf("%s", new_address->phone);

    // head 검사
    if(address_list->head == NULL)
    {
        address_list->head = new_address;
        address_list->length++;
        return;
    }
    
    Address *current_address = address_list->head;
    while(current_address->next != NULL)
    {
        current_address = current_address->next;
    }
    current_address->next = new_address;
    address_list->length++;
    return;
}

// 주소 검색
void address_search(AddressList *address_list)
{

    // head 검사
    if(address_list->head == NULL)
    {
        printf("Empty!\n");
        return;
    }

    // 검색: 사람 이름으로 검색
    char name[100];
    printf("Search Name: ");
    scanf("%s", name);

    Address *current_address = address_list->head;

    while(current_address != NULL)
    {
        if(strcmp(current_address->name, name) == 0)
        {
            printf("Found Address: \n");
            printf("Name: %s\n", current_address->name);
            printf("Address: %s\n", current_address->address);
            printf("Age: %d\n", current_address->age);
            printf("Gender: %s\n", current_address->gender);
            printf("Phone: %s\n", current_address->phone);
            return;
        }
        current_address = current_address->next;
    }

    printf("Not Found!\n");
}

// 주소 삭제
void address_delete(AddressList *address_list)
{
    // head 검사
    if(address_list->head == NULL)
    {
        printf("Empty!\n");
        return;
    }
    // 삭제: 사람 이름으로 삭제
    char name[100], confirm[10];
    printf("Delete Name: ");
    scanf("%s", name);

    Address *current_address = address_list->head;
    Address *prev_address = NULL;

    while(current_address != NULL)
    {
        if(strcmp(current_address->name, name) == 0)
        {
            printf("Delete Address: \n");
            printf("Name: %s\n", current_address->name);
            printf("Address: %s\n", current_address->address);
            printf("Age: %d\n", current_address->age);
            printf("Gender: %s\n", current_address->gender);
            printf("Phone: %s\n", current_address->phone);
            
            // HEAD 삭제
            if (prev_address == NULL)
            {
                address_list->head = current_address->next;
                address_list->length--;
                free(current_address);
            } else {
                prev_address->next = current_address->next;
                free(current_address);
                address_list->length--;
            }
            return;
        }
        prev_address = current_address;
        current_address = current_address->next;
    }

    printf("Not found!\n");
}

void address_edit(AddressList *address_list)
{
    // head 검사
    if(address_list->head == NULL)
    {
        printf("Empty!\n");
        return;
    }
    // 수정: 사람 이름으로 수정
    char name[100], confirm[10];
    printf("Edit Name: ");
    scanf("%s", name);
    Address *current_address = address_list->head;

    while(current_address != NULL)
    {
        if(strcmp(current_address->name, name) == 0)
        {
            printf("Edit Address: \n");
            printf("Name: ");
            scanf("%s", current_address->name);    
            printf("Address: ");
            scanf("%s", current_address->address);    
            printf("Age: ");
            scanf("%d", &(current_address->age));
            printf("Gender: ");
            scanf("%s", current_address->gender);
            printf("Phone: ");
            scanf("%s", current_address->phone);
            return;
        }
        current_address = current_address->next;
    }

    printf("Not Found!\n");    
}

void address_print(AddressList *address_list)
{
    // head 검사
    if(address_list->head == NULL)
    {
        printf("Empty!\n");
        return;
    }

    Address *current_address = address_list->head;
    while(current_address != NULL)
    {
        printf("Address: \n");
        printf("Name: %s\n", current_address->name);
        printf("Address: %s\n", current_address->address);
        printf("Age: %d\n", current_address->age);
        printf("Gender: %s\n", current_address->gender);
        printf("Phone: %s\n", current_address->phone);
        current_address = current_address->next;
    }
    return;
}

void exit_program(AddressList *address_list)
{
    printf("Bye...\n");

    // linkedlist 순회하면서 메모리 해제
    Address *current_address = address_list->head;
    Address *next_address;
    while(current_address != NULL)
    {
        // 해제 되기전 다음 포인터 지정
        next_address = current_address->next;
        free(current_address);
        current_address = next_address;
    }
    address_list->head = NULL;
    address_list->length = 0;
}

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
                address_add(address_list);
                break;
            case 2: // 주소 검색
                address_search(address_list);
                break;
            case 3: // 주소 삭제
                address_delete(address_list);
                break;
            case 4: // 주소 수정
                address_edit(address_list);
                break;
            case 5: // 주소 출력
                address_print(address_list);
                break;                
            case 6: // 닫기
                exit_program(AddressList *address_list);
                status = 0;
                break;
            default:
                printf("잘못된 선택입니다. 다시 시도하세요.\n");
                break;
        }
    }

    return 0;
}
