int pinPWM = 3;

void setup() {
  //Simple serial comunication, to display the values in the monitor
  Serial.begin(9600);


  //enable pin 12 for digital OUTPUT
  pinMode(pinPWM, OUTPUT);

  //test turn on the LED strip for 5 sec and then turn it off
  digitalWrite(pinPWM, HIGH);
  delay(5000);
  digitalWrite(pinPWM, LOW);

  // instead of controlling the LED Strip with 0 and 1
  // we can control the LED h77Strip from 0 - 255
  analogWrite(pinPWM, 255);
  delay(1000);
  analogWrite(pinPWM, 155);
  delay(1000);
  analogWrite(pinPWM, 55);
  delay(1000);
  analogWrite(pinPWM, 0);
  delay(1000);
  
}

void loop() {

  for(int i = 0; i < 255; i++){
    analogWrite(pinPWM, i);

    //print the values in the serial monitor
    Serial.print("LED value: ");
    Serial.println(i);

    //wait 100ms 
    delay(100);
  }

}
