
void FSM_int();


enum StatesEnum { Idle, Popcorn,BeefChicken, FreeTimer, Pause, Timer};
    
typedef enum StatesEnum StatesEnum;


typedef void (*f_pointer_void_void)(void);
typedef void (*f_pointer_void_int)(int);
typedef void (*f_pointer_void_int_int)(int, int);




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
    int x;
} StateOneEnterParameter_int;




typedef struct StateTwoEnterParameter_int
{
    f_pointer_void_int_int Enter;
    f_pointer_void_void Loop;
    f_pointer_void_void Output;
    int minutes;
    int seconds;
} StateTwoEnterParameter_int;




typedef struct States
{
    StateNoParameters Idle;
    StateNoParameters Popcorn;
    StateOneEnterParameter_int BeefChicken;
    StateNoParameters FreeTimer;
    StateOneEnterParameter_int Pause;
    StateTwoEnterParameter_int Timer;

}States;

extern States myStates ; //Extern tells the complier this variable exist and I am gonna use it but it is actually declared somewhere else

extern f_pointer_void_void* loop;

extern StatesEnum CurrentState;



