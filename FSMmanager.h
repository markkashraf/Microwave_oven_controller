
void FSM_int();


enum StatesEnum { State_A, State_B };
    
typedef enum StatesEnum StatesEnum;


typedef void (*f_pointer_void_void)(void);
typedef void (*f_pointer_void_int)(int);



typedef struct StateNoParameters
{
    f_pointer_void_void Enter;
    f_pointer_void_void Loop;
    f_pointer_void_void Output;
} StateNoParameters;

typedef struct StateOneEnterParameter_int
{
    f_pointer_void_int Enter;
    f_pointer_void_void Loop;
    f_pointer_void_void Output;
    int t;
} StateOneEnterParameter_int;



typedef struct States
{
    StateNoParameters State_A;
    StateOneEnterParameter_int State_B;
}States;

extern States myStates ; //Extern tells the complier this variable exist and I am gonna use it but it is actually declared somewhere else

extern f_pointer_void_void* loop;

extern StatesEnum CurretState;



