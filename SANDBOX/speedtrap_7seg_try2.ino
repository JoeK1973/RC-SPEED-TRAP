unsigned long count_start;
unsigned long count_stop;
unsigned long count_time;

int count_state = 0; // 0 for count not started, 1 for count started, 2 for finished
int first_beam_broken = 0;
int second_beam_broken = 0;
int rcvr_one = 2;
int rcvr_two = 3;
float distance = 75; //(Distance in mm between the laser beams)
float speedMPH = 0; // (Calculated speed of RC vehicle)
int speed_displayed = 0;

void setup(){
  pinMode(rcvr_one, INPUT_PULLUP);
  pinMode(rcvr_two, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(rcvr_one), counter_one, FALLING);
  attachInterrupt(digitalPinToInterrupt(rcvr_two), counter_two, FALLING);
}

void loop(){
  if (count_state == 2){
    count_time = count_stop - count_start;
    speedMPH = (distance / count_time) * 2.2374
    speed_displayed = (int) speedMPH; //chops the decimal off the end of the number and converts it to integer type
    Serial.println("Speed is:")
    Serial.println(speed_displayed);
    count_state = 0; // resets the count_state to start listening for the next RC vehicle
  }
}

void counter_one(){
  if (count_state == 0){ // if the count hasn't started yet
    count_start = millis();
    first_beam_broken = 1;
    count_state = 1;
  } else if (count_state == 1) && (second_beam_broken == 1){
    count_stop = millis();
    count_state = 2;
  }
}

void counter_two(){
  if (count_state == 0){ // if the count hasn't started yet
    count_start = millis();
    second_beam_broken = 1;
    count_state = 1;
  } else if (count_state == 1) && (first_beam_broken == 1){
    count_stop = millis();
    count_state = 2;
  }
}
