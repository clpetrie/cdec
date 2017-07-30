// PWM Pins 3, 5, 6, 9, 10, 11, 12, 13

int LED1 = 3;
int LED2 = 5;
int LED3 = 6;
int LED4 = 9;
int LED5 = 10;
int LED6 = 11;
int LED7 = 12;
int LED8 = 13;


char inByte     = 0;
int  inValue    = 0;

String readStr;
String readStrIndex;

int indexLED = 0;
int counterIndex = 0;

//begins serial and tests one pin to make sure it works
void setup() {
  Serial.begin(9600);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);

  analogWrite(LED2, 255);
  delay(1000);
  analogWrite(LED2, 0);
  delay(1000);
  analogWrite(LED2, 255);
  delay(1000);
  analogWrite(LED2, 0);

}

void loop() {

  //read data when the serial is available to read.
  if (Serial.available()) {
    inByte = Serial.read();

    if (counterIndex == 0) {
      readStrIndex += inByte;
    } else {
      readStr += inByte;
    }


    counterIndex++;

    if (counterIndex == 4) {
      counterIndex = 0;
    }
  }



  if (readStr.length() == 3) {
    inValue = readStr.toInt();
    indexLED   = readStrIndex.toInt();
    readStr = "";
    readStrIndex = "";
  }

  if (indexLED == 1) {
    if (inValue <= 255 && inValue >= 0) {
      analogWrite(LED1, inValue);
    }
  }
  if (indexLED == 2) {
    if (inValue <= 255 && inValue >= 0) {
      analogWrite(LED2, inValue);
    }
  }
  if (indexLED == 3) {
    if (inValue <= 255 && inValue >= 0) {
      analogWrite(LED3, inValue);
    }
  }
  if (indexLED == 4) {
    if (inValue <= 255 && inValue >= 0) {
      analogWrite(LED4, inValue);
    }
  }
  if (indexLED == 5) {
    if (inValue <= 255 && inValue >= 0) {
      analogWrite(LED5, inValue);
    }
  }
  if (indexLED == 6) {
    if (inValue <= 255 && inValue >= 0) {
      analogWrite(LED6, inValue);
    }
  }
  if (indexLED == 7) {
    if (inValue <= 255 && inValue >= 0) {
      analogWrite(LED7, inValue);
    }
  }
  if (indexLED == 8) {
    if (inValue <= 255 && inValue >= 0) {
      analogWrite(LED8, inValue);
    }
  }
}
