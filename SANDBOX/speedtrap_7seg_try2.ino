unsigned long count_start;
unsigned long count_stop;
unsigned long count_time;

int count_started = 0; // 0 for count not started, 1 for count started

int rcvr_one = 2;
int rcvr_two = 3;
int direction;


void setup(){
  pinMode(rcvr_one, INPUT);
  pinMode(rcvr_two, INPUT);
}

void loop(){

}

void timing(){
  count_start = micros();
  if (direction == 1){
    
  }
}
