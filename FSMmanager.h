void FSM_int();


enum StatesEnum { Idle, Popcorn,BeefChicken, FreeTimer, Pause, Timer};
    
typedef enum StatesEnum StatesEnum;


typedef void (*f_pointer_void_void)(void);
typedef void (*f_pointer_void_int)(int);
typedef void (*f_pointer_void_int_int)(int, int);
typedef int  (*f_pointer_int_void)(void);




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
    int parameter;
} StateOneEnterParameter_int;


typedef struct StateTwoEnterParameter_int
{
    f_pointer_void_int_int Enter;
    f_pointer_void_void Loop;
    f_pointer_void_void Output;
    int minutes;
    int seconds;
} StateTwoEnterParameter_int;

typedef struct StateNoParameterReturn
{
    f_pointer_int_void Enter;
    f_pointer_void_void Loop;
    f_pointer_void_void Output;
} StateNoParameterReturn;





typedef struct States
{
    StateNoParameters Idle;
    StateNoParameters Popcorn;
    StateOneEnterParameter_int BeefChicken;
    StateNoParameters FreeTimer;
    StateNoParameterReturn Pause;
    StateTwoEnterParameter_int Timer;

}States;

extern States myStates ; //Extern tells the complier this variable exist and I am gonna use it but it is actually declared somewhere else

extern f_pointer_void_void* loop;

extern StatesEnum CurrentState;



