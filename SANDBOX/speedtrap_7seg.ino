unsigned long count_start;
unsigned long count_stop;
unsigned long count_time;

int r_one_pin = 2;
int r_two_pin = 3;

int rcvr_one = 0;
int rcvr_two = 0;


void setup(){
  pinMode(r_one_pin, INPUT);
  pinMode(r_two_pin, INPUT);
}

void loop(){
  rcvr_one = digitalRead(r_one_pin);
  rcvr_two = digitalRead(r_two_pin);
}
