#include <stdio.h>
#include <stdlib.h>

// node 구조체
// 다음 노드를 가리키는 포인터 변수
// 노드의 값을 저장하는 정수형 변수
typedef struct _node
{
    struct _node *next;
    int value;
} Node;

// node 생성
// 값을 받아서 node 구조체 포인터를 반환
Node *node_create(int value)
{
    Node *n = malloc(sizeof(Node));
    n->value = value;
    return n;
}

// node 삭제
// node 구조체 포인터를 받아서 메모리 해제
void node_delete(Node *n)
{
    free(n);
}

// linked list 구조체
// 노드값의 헤더를 저장
// 링크드리스트의 길이를 저장
typedef struct _linkedList
{
    Node *head;
    int length;
} LinkedList;

LinkedList *linkedList_create(void)
{
    LinkedList *linked_list = malloc(sizeof(LinkedList));
    linked_list->head = NULL;
    linked_list->length = 0;
    return linked_list;
}

// 링크드리스트에 노드를 연결
// 링크드리스트를 받아서 노드를 생성후 연결
// 링크드리스트를 반환
LinkedList *linkedList_append(LinkedList *linked_list, int value)
{
    // 노드 생성후, 값을 할당
    Node *new_node = node_create(value);
    // head 값이 비어있는 경우
    if(linked_list->head == NULL)
    {
        linked_list->head = new_node;
        return linked_list;
    }
    // current_node의 next 값이 null 일때까지 탐색
    Node *current_node = linked_list->head;
    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    // 마지막 노드에 현재 노드 연결
    current_node->next = new_node;
    // 길이 증가
    linked_list->length++;
    return linked_list;
}

/*
    과제 1)
    test_xxx()

    test_insert(Test *t, int index, int value);
    test_delete_all(Test *t);
    test_print(Test *t);
        10 -> 20 -> 30 -> 40
*/

// linkedlist 출력
void linkedList_print(LinkedList *linked_list)
{   
    // linkedlist를 순회하면서 값을 출력
    Node *current_node = linked_list->head;

    while(current_node->next != NULL)
    {
        printf("%d -> ", current_node->value);
        current_node = current_node->next;
    }
    printf("%d\n", current_node->value);
}

// linked list 에 특정 인덱스에 값 추가
LinkedList *linkedList_insert(LinkedList *linked_list, int index, int value)
{

    // 잘못된 인덱스 처리
    if (index < 0 || index > linked_list->length)
    {
        printf("잘못된 인덱스: %d\n", index);
        return linked_list;
    }

    // 노드 생성
    Node *new_node = node_create(value);

    // 헤드에 삽입하는 경우
    if (index == 0)
    {
        new_node->next = linked_list->head;
        linked_list->head = new_node;
        
        // 길이 증가
        linked_list->length++;
        
        return linked_list;
    }

    int current_index = 0; // 현재 인덱스    
    Node *current_node = linked_list->head; // 현재 노드

    // 현재 인덱스가 특정인덱스-1이 될 때까지 노드 이동
    while(current_index < index - 1)
    {
        
        current_node = current_node->next;
        current_index++;
    }

    // Node *prev_node = current_node;
    Node *next_node = current_node->next;
    // 현재 노드의 다음 노드에 연결
    current_node->next = new_node;

    // 생성한 노드의 다음 노드를 다음 노드에 연결
    new_node->next = next_node;

    // 길이 증가
    linked_list->length++;
    
    return linked_list;
}

// linkedlist 삭제
int linkedList_delete_all(LinkedList *linked_list)
{
    // linkedlist 순회하면서 메모리 해제
    Node *current_node = linked_list->head;
    Node *next_node;
    while(current_node != NULL)
    {
        // 해제하기 전에 다음 포인터를 저장해야함
        next_node = current_node->next;
        // 메모리 해제
        free(current_node);
        current_node = next_node;
    }
    linked_list->head = NULL; 
    linked_list->length = 0; 
    return 0;
}


int main(void)
{
    LinkedList *linked_list = linkedList_create();

    linkedList_append(linked_list, 10);
    linkedList_append(linked_list, 20);
    linkedList_append(linked_list, 30);
    linkedList_append(linked_list, 40);
    linkedList_append(linked_list, 50);
    linkedList_insert(linked_list, 3, 88);
    linkedList_print(linked_list);

    linkedList_delete_all(linked_list);
    return 0;
}





