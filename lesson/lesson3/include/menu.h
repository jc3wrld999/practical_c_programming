#ifndef __MENU_H__
#define __MENU_H__
#include "address.h"


void menu_address_add(AddressList *address_list);
void menu_address_search(AddressList *address_list);
void menu_address_delete(AddressList *address_list);
void menu_address_edit(AddressList *address_list);
void menu_exit_program(AddressList *address_list);
void menu_address_print(AddressList *address_list);

#endif