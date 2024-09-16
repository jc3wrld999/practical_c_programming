
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "address.h"
#include "menu.h"

// 주소 추가
Result *address_add(AddressList *address_list, Address *new_address)
{
    Result *result = malloc(sizeof(Result));

    // head 검사
    if(address_list->head == NULL)
    {
        address_list->head = new_address;
        address_list->length++;

        result->status = SUCCESS;
        result->address = new_address;
        return result;
    }
    
    Address *current_address = address_list->head;
    while(current_address->next != NULL)
    {
        current_address = current_address->next;
    }
    current_address->next = new_address;
    address_list->length++;

    result->status = SUCCESS;
    result->address = new_address;

    return result;
}



// 주소 검색
Result *address_search_by_idx(AddressList *address_list, int idx)
{
    Result *result = malloc(sizeof(Result));
    // 범위 넘어갔을 때
    if(idx > address_list->length)
    {
        result->status = OUT_OF_INDEX;
        return result;
    }
    int i = 0;
    Address *current_address = address_list->head;

    for (; current_address != NULL; current_address = current_address->next, i++) {
        if (i == idx - 1) {
            result->status = SUCCESS;
            result->address = current_address;
            return result;
        }
    }
    result->status = NOT_FOUND;
    return result;
}

Result *address_search_by_name(AddressList *address_list, char *name)
{
    Result *result = malloc(sizeof(Result));

    // head 검사
    if(address_list->head == NULL)
    {
        result->status = EMPTY;
        return result;
    }

    Address *current_address = address_list->head;

    while(current_address != NULL)
    {
        if(strcmp(current_address->name, name) == 0)
        {
            result->status = SUCCESS;
            result->address = current_address;
            return result;
        }
        current_address = current_address->next;
    }
    result->status = NOT_FOUND;

    return result;
}

Result *address_search_by_age(AddressList *address_list, int age)
{
    Result *result = malloc(sizeof(Result));

    // head 검사
    if(address_list->head == NULL)
    {
        result->status = EMPTY;
        return result;
    }

    Address *current_address = address_list->head;

    while(current_address != NULL)
    {
        if(current_address->age == age)
        {
            result->status = SUCCESS;
            result->address = current_address;
            return result;
        }
        current_address = current_address->next;
    }
    result->status = NOT_FOUND;

    return result;
}

Result *address_search_by_address(AddressList *address_list, char* address)
{
    Result *result = malloc(sizeof(Result));

    // head 검사
    if(address_list->head == NULL)
    {
        result->status = EMPTY;
        return result;
    }

    Address *current_address = address_list->head;

    while(current_address != NULL)
    {
        if(strcmp(current_address->address, address) == 0)
        {
            result->status = SUCCESS;
            result->address = current_address;
            return result;
        }
        current_address = current_address->next;
    }
    result->status = NOT_FOUND;

    return result;
}

Result *address_search_by_gender(AddressList *address_list, char* gender)
{
    Result *result = malloc(sizeof(Result));

    // head 검사
    if(address_list->head == NULL)
    {
        result->status = EMPTY;
        return result;
    }

    Address *current_address = address_list->head;

    while(current_address != NULL)
    {
        if(strcmp(current_address->gender, gender) == 0)
        {
            result->status = SUCCESS;
            result->address = current_address;
            return result;
        }
        current_address = current_address->next;
    }
    result->status = NOT_FOUND;

    return result;
}


Result *address_search_by_phone(AddressList *address_list, char* phone)
{
    Result *result = malloc(sizeof(Result));

    // head 검사
    if(address_list->head == NULL)
    {
        result->status = EMPTY;
        return result;
    }

    Address *current_address = address_list->head;

    while(current_address != NULL)
    {
        if(strcmp(current_address->phone, phone) == 0)
        {
            result->status = SUCCESS;
            result->address = current_address;
            return result;
        }
        current_address = current_address->next;
    }
    result->status = NOT_FOUND;

    return result;
}


// 주소 삭제
Result *address_delete(AddressList *address_list, int idx)
{
    Result *result = malloc(sizeof(Result));

    // 범위 넘어갔을 때
    if(idx > address_list->length)
    {
        result->status = OUT_OF_INDEX;
        return result;
    }
    int i = 0;
    Address *current_address = address_list->head;
    Address *prev_address = NULL;

    for (; current_address != NULL; current_address = current_address->next, i++) {
        if (i == idx - 1) {
            Address *next_address = current_address->next;

            if (next_address != NULL && prev_address == NULL) // HEAD 삭제
            {
                address_list->head = next_address;
            } else if (next_address != NULL) {
                prev_address->next = next_address;
            }
            free(current_address);
            address_list->length--;
            result->status = SUCCESS;

            return result;
        }
        prev_address = current_address;
        current_address = current_address->next;
    }
    result->status = NOT_FOUND;
    return result;
}

Result *address_edit_name(Address *address, char* name) {
    Result *result = malloc(sizeof(Result));
    if (result == NULL) return NULL;
    strncpy(address->name, name, sizeof(address->name) - 1);
    address->name[sizeof(address->name) - 1] = '\0';  

    result->address = address;
    result->status = SUCCESS;
    return result;
}

Result *address_edit_address(Address *address, char* new_address) {
    Result *result = malloc(sizeof(Result));
    if (result == NULL) return NULL;
    strncpy(address->address, new_address, sizeof(address->address) - 1);
    address->address[sizeof(address->address) - 1] = '\0';  

    result->address = address;
    result->status = SUCCESS;
    return result;
}

Result *address_edit_age(Address *address, int age) {
    Result *result = malloc(sizeof(Result));
    if (result == NULL) return NULL;
    address->age = age;
    result->address = address;
    result->status = SUCCESS;
    return result;
}

Result *address_edit_gender(Address *address, char* gender) {
    Result *result = malloc(sizeof(Result));
    if (result == NULL) return NULL;
    strncpy(address->gender, gender, sizeof(address->gender) - 1);
    address->gender[sizeof(address->gender) - 1] = '\0';  

    result->address = address;
    result->status = SUCCESS;
    return result;
}

Result *address_edit_phone(Address *address, char* phone) {
    Result *result = malloc(sizeof(Result));
    if (result == NULL) return NULL;
    strncpy(address->phone, phone, sizeof(address->phone) - 1);
    address->phone[sizeof(address->phone) - 1] = '\0';  

    result->address = address;
    result->status = SUCCESS;
    return result;
}

void address_free(AddressList *address_list)
{
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