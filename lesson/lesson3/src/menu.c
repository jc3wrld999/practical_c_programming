
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

// 주소 추가
void menu_address_add(AddressList *address_list)
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

    address_add(address_list, new_address);

    return;
}

// 주소 검색
void menu_address_search(AddressList *address_list)
{

    // 검색
    int choice;

    printf("Search by:\n");
    printf("1. Name\n");
    printf("2. Address\n");
    printf("3. Phone\n");
    printf("4. Age\n");
    printf("5. Gender\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    
    char search_value[100];
    int search_age;
    Result *result = malloc(sizeof(Result));

    switch (choice) {
        case 1:
            printf("Enter Name: ");
            scanf("%s", search_value);
            result = address_search_by_name(address_list, search_value);
            break;
        case 2:
            printf("Enter Address: ");
            scanf("%s", search_value);
            result = address_search_by_address(address_list, search_value);
            break;
        case 3:
            printf("Enter Phone: ");
            scanf("%s", search_value);
            result = address_search_by_phone(address_list, search_value);
            break;
        case 4:
            printf("Enter Age: ");
            scanf("%d", &search_age);
            result = address_search_by_age(address_list, search_age);
            break;
        case 5:
            printf("Enter Gender: ");
            scanf("%s", search_value);
            result = address_search_by_gender(address_list, search_value);
            break;
        default:
            printf("Try again...\n");
            return;
    }
    
    
    if(result->status == 0) {
        printf("Found Address: \n");
        printf("Name: %s\n", result->address->name);
        printf("Address: %s\n", result->address->address);
        printf("Age: %d\n", result->address->age);
        printf("Gender: %s\n", result->address->gender);
        printf("Phone: %s\n", result->address->phone);  
    } else {
        printf("Fail: %d\n", result->status);
    }

}

// 주소 삭제
void menu_address_delete(AddressList *address_list)
{

    int idx;
    printf("Select Delete Index: ");
    
    menu_address_print(address_list);
    scanf("%d", &idx);
    
    if(!idx)
    {
        printf("Fail!");
        return;
    }

    // 삭제 처리
    Result *result = address_delete(address_list, idx);

    if(result->status != 0) {
        printf("Not found!\n");
    }

}

// 주소 수정
void menu_address_edit(AddressList *address_list)
{
    int edit_idx;
    printf("Select Edit Index: ");
    
    menu_address_print(address_list);
    scanf("%d", &edit_idx);
    
    if(!edit_idx)
    {
        printf("Fail!");
        return;
    }

    Result *result = address_search_by_idx(address_list, edit_idx);

    if(result->status == 0) {
        printf("Found Address: \n");
        printf("Name: %s\n", result->address->name);
        printf("Address: %s\n", result->address->address);
        printf("Age: %d\n", result->address->age);
        printf("Gender: %s\n", result->address->gender);
        printf("Phone: %s\n", result->address->phone);  
    } else {
        printf("Fail: %d\n", result->status);
        return;
    }
    int choice;

    printf("Edit at :\n");
    printf("1. Name\n");
    printf("2. Address\n");
    printf("3. Phone\n");
    printf("4. Age\n");
    printf("5. Gender\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    Result *edit_result = malloc(sizeof(Result));
    
    char edit_value[100];
    int edit_age;


    switch (choice) {
        case 1:
            printf("Enter Name: ");
            scanf("%s", edit_value);

            edit_result = address_edit_name(result->address, edit_value);
            printf("Debug: %d\n", __LINE__);
            break;
        case 2:
            printf("Enter Address: ");
            scanf("%s", edit_value);
            edit_result = address_edit_address(result->address, edit_value);
            printf("Debug: %d\n", __LINE__);
            break;
        case 3:
            printf("Enter Phone: ");
            scanf("%s", edit_value);
            edit_result = address_edit_phone(result->address, edit_value);
            printf("Debug: %d\n", __LINE__);
            break;
        case 4:
            printf("Enter Age: ");
            scanf("%d", &edit_age);
            edit_result = address_edit_age(result->address, edit_age);
            printf("Debug: %d\n", __LINE__);
            break;
        case 5:
            printf("Enter Gender: ");
            scanf("%s", edit_value);
            edit_result = address_edit_gender(result->address, edit_value);
            printf("Debug: %d\n", __LINE__);
            break;
        default:
            printf("Try again...\n");
            return;
    }
    printf("??????? ");
    
    if(edit_result->status == 0) {
        printf("Edit Address: \n");
        printf("Name: %s\n", edit_result->address->name);
        printf("Address: %s\n", edit_result->address->address);
        printf("Age: %d\n", edit_result->address->age);
        printf("Gender: %s\n", edit_result->address->gender);
        printf("Phone: %s\n", edit_result->address->phone);  
    } else {
        printf("Fail:\n");
    }

}


void menu_address_print(AddressList *address_list)
{
    // head 검사
    if(address_list->head == NULL)
    {
        printf("Empty!\n");
        return;
    }

    Address *current_address = address_list->head;
    int i = 0;
    while(current_address != NULL)
    {
        i++;
        printf("[%d] Address: \n", i);
        printf("Name: %s\n", current_address->name);
        printf("Address: %s\n", current_address->address);
        printf("Age: %d\n", current_address->age);
        printf("Gender: %s\n", current_address->gender);
        printf("Phone: %s\n", current_address->phone);
        current_address = current_address->next;
    }
    return;
}

void menu_exit_program(AddressList *address_list)
{
    printf("Bye...\n");

    address_free(address_list);
}