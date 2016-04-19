
// speed trap

int sensor1 = 4;
int sensor2 = 5;
unsigned long startTime;
unsigned long stopTime;
unsigned long calculatedTime;
unsigned long bestTime = 1000000;
const int sensor1_tripped = 1;
const int sensor2_tripped = 2;
const int sensors_clear = 3;
unsigned int state = sensors_clear;
unsigned int Direction;
float currentSpeed;
float bestSpeed;


void setup()
{
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  digitalWrite(sensor1,HIGH);
  digitalWrite(sensor2,HIGH);

  Serial.begin(9600);
  Serial.println("READY");
}

void loop(){
   if(state == sensors_clear){ 
    Direction=0 == (digitalRead(sensor1) == HIGH && digitalRead(sensor2) == LOW);
    
   }
   if(state == sensors_clear){ 
     Direction=1 == (digitalRead(sensor2) == HIGH && digitalRead(sensor1) == LOW);
   }
     
  switch (Direction){
    
   case 0:
     
    if(state == sensors_clear){ 
      if(digitalRead(sensor1) == HIGH){
    startTime=micros();
    
    Serial.println("SENSOR 1 TRIPPED");
    
    state = sensor1_tripped;
      }
    }
   else if(state == sensor1_tripped){
   if(digitalRead(sensor2) == HIGH){

    stopTime = micros();
    
    calculatedTime = stopTime - startTime;
    
    if(calculatedTime < bestTime){
    bestTime = calculatedTime;
    }
    
    currentSpeed = (0.25/(calculatedTime*0.000001))*0.6818182;
    
    if(currentSpeed > bestSpeed){
    bestSpeed = currentSpeed;
    }
    
    Serial.println("SENSOR 2 TRIPPED");
    Serial.println("CALCULATED TIME :");
    Serial.print(calculatedTime);
    Serial.println(" MS");
    Serial.println("BEST TIME :");
    Serial.print(bestTime);
    Serial.println(" MS");
    Serial.println("CURRENT SPEED");
    Serial.print(currentSpeed);
    Serial.println(" MPH");
    Serial.println("BEST SPEED");
    Serial.print(bestSpeed);
    Serial.println(" MPH");
    
    state = sensor2_tripped;
      
   }
  }

  else if(state = sensor2_tripped){
   if(digitalRead(sensor1) == LOW && digitalRead(sensor2) == LOW){
     
     
     Serial.println("SENSORS CLEAR");
     Serial.println(" ");
     
     state = sensors_clear;
   }
  }
  


break;
  


case 1:
   
   if(state == sensors_clear){
     if(digitalRead(sensor2) == HIGH){
    startTime=micros();
    
    Serial.println("SENSOR 2 TRIPPED");
    
    state = sensor2_tripped;
   }
   }

   else if(state == sensor2_tripped){
   if(digitalRead(sensor1) == HIGH){

    stopTime = micros();
    
    calculatedTime = stopTime - startTime;
    
    if(calculatedTime < bestTime){
    bestTime = calculatedTime;
    }
    
    currentSpeed = (0.25/(calculatedTime*0.000001))*0.6818182;
    
    if(currentSpeed > bestSpeed){
    bestSpeed = currentSpeed;
    }
    
    Serial.println("SENSOR 1 TRIPPED");
    Serial.println("CALCULATED TIME :");
    Serial.print(calculatedTime);
    Serial.println(" MS");
    Serial.println("BEST TIME :");
    Serial.print(bestTime);
    Serial.println(" MS");
    Serial.println("CURRENT SPEED");
    Serial.print(currentSpeed);
    Serial.println(" MPH");
    Serial.println("BEST SPEED");
    Serial.print(bestSpeed);
    Serial.println(" MPH");
    
    state = sensor1_tripped;
      
   }
  }

  else if(state = sensor1_tripped){
   if(digitalRead(sensor2) == LOW && digitalRead(sensor1) == LOW){
     
     
     Serial.println("SENSORS CLEAR");
     Serial.println(" ");
     
     state = sensors_clear;
   }
}

break;

  }
  }



 
