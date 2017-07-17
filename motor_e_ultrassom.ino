//distance sensor
int trig = 11;
int echo = 10;
//motor one
int enA = 7;
int in1 = 6;
int in2 = 5;
// motor two
int enB = 2;
int in3 = 4;
int in4 = 3;
void setup(){
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop(){
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2)/29.1;
  
  if(distance<30){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
      analogWrite(enA, 150);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
      analogWrite(enB, 150);
  }
  else{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 150);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  }
   Serial.println(distance); 
}
