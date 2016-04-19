unsigned long count_start;
unsigned long count_stop;
unsigned long count_time;

int rcvr_one = 2;
int rcvr_two = 3;
int direction;


void setup(){
  pinMode(rcvr_one, INPUT);
  pinMode(rcvr_two, INPUT);
}

void loop(){
  if (digitalRead(rcvr_one) == HIGH && digitalRead(rcvr_two) == LOW){
    direction = 1;
  } else if (digitalRead(rcvr_one) == LOW && digitalRead(rcvr_two) == HIGH){
    direction = 2;
  } else {
    direction = 0;
  }
  
  if (direction == 1) || (direction == 2){
    timing();
  }
}

void timing(){
  
}
