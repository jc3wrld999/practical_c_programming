#ifndef __ADDRESS_H__
#define __ADDRESS_H__

// address node
typedef struct _address
{
    int header;
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

typedef struct _result
{
    int status;
    Address *address;
} Result;

#define SUCCESS         0
#define FAIL            1
#define NOT_FOUND       2
#define EMPTY           3
#define OUT_OF_INDEX    4

Result *address_add(AddressList *, Address *);

Result *address_search_by_idx(AddressList *, int);
Result *address_search_by_name(AddressList *, char *);
Result *address_search_by_age(AddressList *, int);
Result *address_search_by_address(AddressList *, char *);
Result *address_search_by_gender(AddressList *, char *);
Result *address_search_by_phone(AddressList *, char *);

Result *address_edit_name(Address *, char*);
Result *address_edit_address(Address *, char*);
Result *address_edit_age(Address *, int);
Result *address_edit_gender(Address *, char* );
Result *address_edit_phone(Address *, char* );


Result *address_delete(AddressList *, int);
void address_free(AddressList *);

#endif