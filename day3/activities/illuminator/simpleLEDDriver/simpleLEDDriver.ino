int pinLED = 10;

void setup() {
  // put your setup code here, to run once:

  pinMode(10, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < 256; i++) {
    analogWrite(pinLED, i);
    delay(50);
  }

}
