unsigned long count_start;
unsigned long count_stop;
unsigned long count_time;

int count_state = 0; // 0 for count not started, 1 for count started, 2 for finished

int rcvr_one = 2;
int rcvr_two = 3;
int distance = 1; (Distandce in metres)


void setup(){
  pinMode(rcvr_one, INPUT_PULLUP);
  pinMode(rcvr_two, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(rcvr_one), counter, FALLING);
  attachInterrupt(digitalPinToInterrupt(rcvr_two), counter, FALLING);
}

void loop(){
  if (count_state == 2){
    se
  }
}

void counter(){
  if (count_state == 0){ // if the count hasn't started yet
    count_start = millis();
    count_state = 1;
  } else if (count_state == 1){
    count_stop = millis();
    count_state = 2;
  }
}
