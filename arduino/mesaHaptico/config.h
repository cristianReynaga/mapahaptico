
//LOGS CONF
boolean logActive   = false;
boolean serialReady = false;

//THREADS CONF
ThreadController controll = ThreadController();
Thread* myThread  = new Thread();
Thread  nyThreads = Thread();

//EVENT CONFS
#define eventIt 100
#define defaultEventTime 4000//3 SECONDS!
#define noEvent   -1
#define lightOn    1
#define lightHold  0
#define lightOff  -1
#define lightIdle -2

int eventTime   = 0;
int eventVia    = noEvent;
int eventAction = lightOff;

//LEDS CONF
#define maxVias 7
#define lsFadeMod 25
int vias[maxVias]       = { 2, 3, 4, 5, 6, 7, 8};
int viasAct[maxVias]    = { lightIdle, lightIdle, lightIdle, lightIdle, lightIdle, lightIdle, lightIdle};
int viasTime[maxVias]   = { 0, 0, 0, 0, 0, 0, 0};
int viasValues[maxVias] = { 0, 0, 0, 0, 0, 0, 0};

