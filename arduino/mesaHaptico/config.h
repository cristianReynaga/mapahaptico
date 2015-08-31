
//LOGS CONF
boolean logActive   = false;
boolean serialReady = false;

//THREADS CONF
ThreadController controll = ThreadController();
Thread* myThread  = new Thread();
Thread  nyThreads = Thread();

//LEDS CONF
#define maxVias 7
int vias[maxVias]       = { 2, 3, 4, 5, 6, 7, 8};
int viasAct[maxVias]    = { 0, 0, 0, 0, 0, 0, 0};
int viasTime[maxVias]   = { 0, 0, 0, 0, 0, 0, 0};
int viasValues[maxVias] = { 0, 0, 0, 0, 0, 0, 0};

//EVENT CONFS
#define eventIt 100
#define defaultEventTime 3000//3 SECONDS!
#define noEvent   -1
#define ligthOn    1
#define lightHold  0
#define lightOff  -1
#define lightIdle -2

int eventTime   = 0;
int eventVia    = noEvent;
int eventAction = lightOff;
