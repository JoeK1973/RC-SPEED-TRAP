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
  if (count_started == 0){
    if (digitalRead(rcvr_one) == LOW && digitalRead(rcvr_two) == HIGH){
    count_started == 1;
    direction = 1;
  } else if (digitalRead(rcvr_one) == HIGH && digitalRead(rcvr_two) == LOW){
    count_started == 1;
    direction = 2;
  } else {
    direction = 0;
  }
  
  if (direction == 1) || (direction == 2){
    timing();
  }
}
}

void timing(){
  count_start = micros();
  if (direction == 1){
    
  }
}
