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

typedef struct StateOneEnterParameter
{
    f_pointer_void_int Enter;
    f_pointer_void_void Loop;
    f_pointer_void_void Output;
} StateOneEnterParameter;



typedef struct States
{
    StateNoParameters State_A;
    StateOneEnterParameter State_B;
}States;

extern States myStates ; //Extern tells the complier this variable exist and I am gonna use it but it is actually declared somewhere else

extern f_pointer_void_void* loop;

extern StatesEnum CurretState;

