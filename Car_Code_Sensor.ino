// Author: Harmanpreet Singh Sagar
// Project: Robotic Car with Ultrasonic Sensor

int trigPin = 12;
int echoPin = 13;
long returnTime, cm, inches;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  //set trigPin #12 as output for Prox Sensor
  pinMode (trigPin, OUTPUT); 
  //set echoPin #13 as input for Prox Sensor
  pinMode (echoPin, INPUT); 
  Serial.begin(9600);
}

void loop()
{

  //Turn of trigPin for 5ms to ensure clean pulse
  digitalWrite(trigPin, LOW);
  //delay for 5 milli sec
  delay (5);
  //Pulse trigPin for exactly 10ms to send out a sound pulse
  digitalWrite(trigPin, HIGH); 
  //delay for 5 milli sec
  delay (10);
  //sets the trig pin to low
  digitalWrite(trigPin, LOW);
  //Read the time it takes for the signal to return and store to variable 'returntime'
  returnTime = pulseIn(echoPin, HIGH);
  //Convert the measured return time to cm and inches (Math from class)
  cm = (returnTime * 0.01715);
  // Output the result in cm using the Serial Monitor
  Serial.print ("Distance in cm: ");
  //prints the distance
  Serial.println (cm);
  //delays for 250 millis so you can read it
  delay (250);  

  /*
  //moving forwards code
  //I recommented on what they actually did
  // top motor forward pin
  digitalWrite(2, HIGH);
  //does nothing
  digitalWrite(3, LOW);
  
  // moves both forward?
  digitalWrite(4, HIGH);
  //moves top forward and bottom backwards
  digitalWrite(5, LOW);
  */
      if (cm < 15)
  {
  //moving forwards code
  //I recommented on what they actually did
  // top motor forward pin
  digitalWrite(2, HIGH);
  //does nothing
  digitalWrite(3, LOW);
  
  // moves both forward?
  digitalWrite(4, HIGH);
  //moves top forward and bottom backwards
  digitalWrite(5, LOW);
  }
 
 else
 {
       digitalWrite(3, HIGH);
     //does nothing
     digitalWrite(2, LOW);

     //does nothing
     digitalWrite(4, LOW);
     digitalWrite(5, HIGH);

 }

  /*
  digitalWrite(2, LOW);
  //does nothing
  digitalWrite(3, HIGH);
  
  // moves both forward?
  digitalWrite(4, LOW);
  //moves top forward and bottom backwards
  digitalWrite(5, HIGH);
  
  delay(2000);
  
  digitalWrite(2, LOW);
  //does nothing
  digitalWrite(3, LOW);
  
  // moves both forward?
  digitalWrite(4, LOW);
  //moves top forward and bottom backwards
  digitalWrite(5, LOW);
  // wait 3 seconds
  
  delay(2000); 
*/

}
