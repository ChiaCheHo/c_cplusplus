#include <stdio.h>

#define MAX_NAME_LENGTH 10

/********************************************************************
    STRUCTURES AND ENUMS FOR
    EVENT HANDLING FUNCTIONS
********************************************************************/
typedef enum Events{
    TEST1,
    TEST2,
    TEST3,
    MAX_EVENTS
}e_Events;

typedef void (*callback) (void *);

typedef struct EventHandlers{
    callback cb;
    struct EventHandlers *next;
    char name[MAX_NAME_LENGTH];
} s_EventHandlers;

s_EventHandlers *listeners[MAX_EVENTS];

/********************************************************************
    FORWARD DECLARES FOR
    EVENT HANDLING FUNCTIONS
********************************************************************/
void InitListeners(s_EventHandlers *handlers[], int size);
void DestroyListeners(s_EventHandlers *handlers[], int size);
void RegisterEvent(e_Events event, callback cb, char *name);

/********************************************************************
    TEST EVENT HANDLERS FUNCTIONS
********************************************************************/
void Test1Handler1(void *data){
    printf("In Test1 Handler 1 %s\n", data);
}
void Test1Handler2(void *data){
    printf("In Test1 Handler 2 %s\n", data);
}
void Test2Handler1(void *data){
    printf("In Test2 Handler 1 %s\n", data);
}
void Test3Handler1(void *data){
    printf("In Test3 Handler 1 %s\n", data);
}
void Test3Handler2(void *data){
    printf("In Test3 Handler 2 %s\n", data);
}

int main(int argc, char **argv) 
{
    s_EventHandlers *handlers = NULL;
    char data[] = "this is the data";
    
    InitListeners(listeners,MAX_EVENTS);
    
    RegisterEvent(TEST1, Test1Handler1, "T1H1");
    RegisterEvent(TEST1, Test1Handler2, "T1H2");
    RegisterEvent(TEST2, Test2Handler1, "T2H1");
    RegisterEvent(TEST3, Test3Handler1, "T3H1");
    RegisterEvent(TEST3, Test3Handler2, "T3H2");
    
    handlers = listeners[TEST1];
    for(; handlers != NULL; handlers = handlers->next){
        handlers->cb(data);
    }
    
    handlers = listeners[TEST2];
    for(; handlers != NULL; handlers = handlers->next){
        handlers->cb(data);
    }
    
    handlers = listeners[TEST3];
    for(; handlers != NULL; handlers = handlers->next){
        handlers->cb(data);
    }
    
    DestroyListeners(listeners,MAX_EVENTS);
    
    return 0;
}

void RegisterEvent(e_Events event, callback cb, char *name){
    s_EventHandlers **handlers = &listeners[event];
    
    if (*handlers == NULL){
        *handlers = (s_EventHandlers*) malloc(sizeof(s_EventHandlers));
        (*handlers)->cb = cb;
        
        strncpy((*handlers)->name,name,MAX_NAME_LENGTH);
        (*handlers)->name[MAX_NAME_LENGTH-1] = '\0';
        
        (*handlers)->next = NULL;
    } else { 
        while ((*handlers)->next != NULL){
            (*handlers)++;
        }
        (*handlers)->next = (s_EventHandlers*) malloc(sizeof(s_EventHandlers));
        (*handlers)->next->cb = cb;
        
        strncpy((*handlers)->next->name,name,MAX_NAME_LENGTH);
        (*handlers)->next->name[MAX_NAME_LENGTH-1] = '\0';
        
        (*handlers)->next->next = NULL;
    }	
}

void InitListeners(s_EventHandlers *handlers[], int size){
    int i;
    for (i = 0; i < MAX_EVENTS; i++){
        handlers[i] = NULL;
    }
}

void DestroyListeners(s_EventHandlers *handlers[], int size){
    int i;
    s_EventHandlers *deleteMe, *next;
    for (i = 0; i < MAX_EVENTS; i++){
        deleteMe = handlers[i];
        
        while (deleteMe){
            next = deleteMe->next;
            free(deleteMe);
            deleteMe = next;
        }
    }
}