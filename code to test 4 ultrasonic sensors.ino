#define trigPin1 2
#define echoPin1 3
#define trigPin2 4
#define echoPin2 5
#define trigPin3 6
#define echoPin3 7
#define trigPin4 8
#define echoPin4 9

long duration, distance, RightSensor,BackSensor,FrontSensor,LeftSensor;

void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(trigPin4, OUTPUT);
pinMode(echoPin4, INPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
}

void loop()
{
FrontSensor =SonarSensor(trigPin1, echoPin1);delay(50);

BackSensor =SonarSensor(trigPin2, echoPin2);delay(50);

LeftSensor =SonarSensor(trigPin3, echoPin3);delay(50);

RightSensor =SonarSensor(trigPin4, echoPin4);delay(50);


Serial.print(FrontSensor);Serial.print("   ");Serial.print(BackSensor);Serial.print("   ");
Serial.print(LeftSensor);Serial.print("   ");Serial.println(RightSensor);


}

int SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
return distance;
delay(100);
}
