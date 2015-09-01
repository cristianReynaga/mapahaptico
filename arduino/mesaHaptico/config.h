
//LOGS CONF
boolean logEnable   = true;
boolean serialReady = false;

//THREADS CONF
ThreadController controll = ThreadController();
Thread* myThread  = new Thread();
Thread  nyThreads = Thread();

//EVENT CONFS
#define eventIt 50
#define defaultEventTime 4000//4 SECONDS!
#define noEvent   -1
#define lightOn    1
#define lightHold  0
#define lightOff  -1
#define lightIdle -2



//LEDS CONF
#define maxVias 7
#define lsFadeMod 5
int vias[maxVias]       = { 2, 3, 4, 5, 6, 7,8};
int viasAct[maxVias]    = { lightIdle, lightIdle, lightIdle, lightIdle, lightIdle, lightIdle, lightIdle};
int viasTime[maxVias]   = { 0, 0, 0, 0, 0, 0,0};
int viasValues[maxVias] = { 0, 0, 0, 0, 0, 0,0};

//BUTTONS CONFIGS
#define BANIOS                '0'
#define AUDITORIO             '1'
#define JUNTA_EVALUADORA      '2'
#define SALA_DE_ESPERA        '4'
#define CAPACITACION          '3'
#define COPIDISA_E            '5'
#define SALA_ADMINISTRATIVA   '6'  

char customKey = 0xff;
const byte ROWS = 3; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'}
};
byte rowPins[ROWS] = {48,46,50}; 
byte colPins[COLS] = {44, 42, 38, 40}; 
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
//ROMS
int h1 = 36;//BAÑO
int h2 = 34;//AUDITORIO
int h3 = 32;//JUNTA EVALUADORA
int h4 = 33;//SALA_DE_ESPERA
int h5 = 35;//CAPACITACION
int h6 = 37;//COPIDISE
int h7 = 53;//SALA_ADMINISTRATIVA

int in1 = 28;
int in2 = 30;
int in3 = 32;

//SOUND CONFIGS
int resetPin = 22;  // The pin number of the reset pin.
int clockPin = 24;  // The pin number of the clock pin.
int dataPin = 26;  // The pin number of the data pin.
int busyPin = 28;  // The pin number of the busy pin.
Wtv020sd16p wtv020sd16p(resetPin,clockPin,dataPin,busyPin);
#define audioDefaultTime 3000;
int soundRunTime = 0;
boolean playing = false;
