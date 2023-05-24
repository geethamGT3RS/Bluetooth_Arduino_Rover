char t;
 
void setup() {
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);   
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);   
pinMode(10,OUTPUT);  
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);   
pinMode(13,OUTPUT);   
Serial.begin(9600);
}

void loop() {

if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
if(t == 'F'){     
  digitalWrite(10,HIGH);
  digitalWrite(13,HIGH);       //movE  forward(all motors rotate in forward direction)
  digitalWrite(6,HIGH);
  digitalWrite(9,HIGH);
} 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}
else if(t == 'L'){      //turn left (left side motors rotate in forward direction,right side motors doesn't rotate)
  digitalWrite(9,HIGH);
  digitalWrite(13,HIGH);
}
else if(t == 'R'){      //turn right (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(6,HIGH);
  digitalWrite(10,HIGH);
}

else if(t == 'G'){      //turn forward left (left side motors rotate in forward direction,right side motors doesn't rotate)
  digitalWrite(9,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(6,HIGH);
}
else if(t == 'I'){      //turn forward right (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(6,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
}
else if(t == 'H'){      //turn back left (left side motors rotate in forward direction,right side motors doesn't rotate)
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(8,HIGH);
}
else if(t == 'J'){      //turn back right (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(7,HIGH);
}

else if(t =='W'){    //turn led on or off)
  digitalWrite(5,HIGH);
}
else if(t == 'w'){
  digitalWrite(5,LOW);
}
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
delay(100);
}
}
const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
}
void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}
