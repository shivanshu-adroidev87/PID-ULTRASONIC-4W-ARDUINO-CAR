int dir1 = 36;
int dir2 = 42;
int pwm1 = 6;
int pwm2 = 7;
int dir3 = 44;
int dir4 = 46;
int pwm3 = 8;
int pwm4 = 9;
int trig1 = 45;
int trig2 = 32;
int echo1 = 47;
int echo2 = 30;
int t = 1;
int dis2;
int setpoint=40;
float k=.5;
float error;
float change;
float speed1=50;
int dur2, dis1, dur1, dis11, dis12, dis2lower, dis2upper;
void setup() {
  pinMode(trig1, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(pwm4, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(dir4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  distance();
  error=abs(setpoint-dis1);
  change=error*k;
  speed1-=change;

  if(dis1<42)
    {
      forward();
      
    }
    if (dis1>47)
    { 
        reverse();
    }
    if(dis1>42 && dis2<47)
    {
     stop();
    }}
void distance() {
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  dur1 = pulseIn(echo1, HIGH);
  dis1 = dur1 * 0.034 / 2;
  dis12 = dis1+2;
  dis11 = dis1-2;
  Serial.print("dis1 ");
  Serial.println(dis1);
}
void distance2(){ //left ultrasonic
 
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  dur2 = pulseIn(echo2, HIGH);
  dis2 = dur2 * 0.034 / 2;
  dis2upper = dis2+2;
  dis2lower = dis2-2;
  Serial.print("dis2 ");
  Serial.println(dis2);
 
}
void right(){
  analogWrite(pwm1, 0);
  analogWrite(pwm2, 50);
  analogWrite(pwm3, 50);
  analogWrite(pwm4, 50);
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, HIGH);
  digitalWrite(dir3, HIGH);
  digitalWrite(dir4, LOW);
  Serial.println("R");
 
 
}
void left(){
  analogWrite(pwm1, 50); // first wheel
  analogWrite(pwm2, 50); // secoend Wheel
  analogWrite(pwm3, 50); // fourth wheel
  analogWrite(pwm4, 50); // third wheel
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);
  digitalWrite(dir3, LOW);
  digitalWrite(dir4, HIGH);
  Serial.println("L");
 
}
void forward(){
   analogWrite(pwm1, speed1); // first wheel
  analogWrite(pwm2, 0); // second Wheel
  analogWrite(pwm3, 0); // fourth wheel
  analogWrite(pwm4, speed1); // third wheel
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, LOW);
  digitalWrite(dir3, LOW);
  digitalWrite(dir4, HIGH);
 Serial.println("F");
}
void reverse()
{
  analogWrite(pwm1, speed1); // first wheel
  analogWrite(pwm2, 0); // second Wheel
  analogWrite(pwm3, 0); // fourth wheel
  analogWrite(pwm4, speed1); // third wheel
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);
  digitalWrite(dir3, LOW);
  digitalWrite(dir4, LOW);
}
void stop(){
  analogWrite(pwm1, 0);
  analogWrite(pwm2, 0);
  analogWrite(pwm3, 0);
  analogWrite(pwm4, 0);
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, HIGH);
  digitalWrite(dir3, HIGH);
  digitalWrite(dir4, HIGH);
  Serial.println("S");
}
void aage()
{
 analogWrite(pwm1, 0); // first wheel
  analogWrite(pwm2, 50); // second Wheel
  analogWrite(pwm3, 50); // fourth wheel
  analogWrite(pwm4, 0); // third wheel
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, HIGH);
  digitalWrite(dir3, HIGH);
  digitalWrite(dir4, HIGH);
 Serial.println("F"); 
}
