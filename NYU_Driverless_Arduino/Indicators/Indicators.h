#define right_Indicator (0)
#define left_Indicator  (1)
#define brake_Light     (2)
#define head_Light      (3)
#define front_Light     (4)
#define autonomous_Mode (5)
#define circuit_Breaker (6)

struct Indicator_Status{
    bool Right_Indicator=false;
    bool Left_Indicator=false;
    bool Brake_Light=false;
    bool Head_Light=false;
    bool Front_Light=false;
    bool Autonomous_Mode=false;
    bool Circuit_Breaker=false;
};

void update_status(uint8_t data, Indicator_Status* stat){
    if(data & 1<<right_Indicator)
        stat->Right_Indicator=true;
    else stat->Right_Indicator=false;
    if(data & 1<<left_Indicator)
        stat->Left_Indicator=true;
    else stat->Left_Indicator=false;
    if(data & 1<<brake_Light)
        stat->Brake_Light=true;
    else stat->Brake_Light=false;
    if(data & 1<<head_Light)
        stat->Head_Light=true;
    else stat->Head_Light=false;
    if(data & 1<<front_Light)
        stat->Front_Light=true;
    else stat->Front_Light=false;
    if(data & 1<<autonomous_Mode)
        stat->Autonomous_Mode=true;
    else stat->Autonomous_Mode=false;
    if(data & 1<<circuit_Breaker)
        stat->Circuit_Breaker=true;
    else stat->Circuit_Breaker=false;
}
