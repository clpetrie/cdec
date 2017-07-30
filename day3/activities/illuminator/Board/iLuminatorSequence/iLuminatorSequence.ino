int LED01 = 3;
int POT01 = A0;

int LED02  = 5;
int POT02 = A1;

int LED03 = 6;
int POT03 = A2;

int LED04 = 9;
int POT04 = A3;

int LED05 = 10;
int POT05 = A4;

int LED06 = 11;
int POT06 = A5;

int LED07 = 13;
int POT07 = A6;


void setup() {
  // put your setup code here, to run once:

  pinMode(LED01, OUTPUT);
  pinMode(LED02, OUTPUT);
  pinMode(LED03, OUTPUT);
  pinMode(LED04, OUTPUT);
  pinMode(LED05, OUTPUT);
  pinMode(LED06, OUTPUT);
  pinMode(LED07, OUTPUT);

  pinMode(POT01, INPUT);
  pinMode(POT02, INPUT);
  pinMode(POT03, INPUT);
  pinMode(POT04, INPUT);
  pinMode(POT05, INPUT);
  pinMode(POT06, INPUT);
  pinMode(POT07, INPUT);
}

void loop() {
  for (int i = 0; i < 255; i++) {
    writeLED(i, 0, 0, 0, 0, 0, 0);
    delay(10);
  }

  for (int i = 0; i < 255; i++) {
    writeLED(0, i, 0, 0, 0, 0, 0);
    delay(10);
  }

  for (int i = 0; i < 255; i++) {
    writeLED(0, 0, i, 0, 0, 0, 0);
    delay(10);
  }

  for (int i = 0; i < 255; i++) {
    writeLED(0, 0, 0, i, 0, 0, 0);
    delay(10);
  }

  for (int i = 0; i < 255; i++) {
    writeLED(0, 0, 0, 0, i, 0, 0);
    delay(10);
  }

  for (int i = 0; i < 255; i++) {
    writeLED(0, 0, 0, 0, 0, i, 0);
    delay(10);
  }

  for (int i = 0; i < 255; i++) {
    writeLED(0, 0, 0, 0, 0, 0, i);
    delay(10);
  }


  writeLED(0, 0, 0, 0, 0, 0, 0);
  delay(500);


  for (int i = 0; i < 255; i++) {
    writeLED(i, i, i, i, i, i, i);
    delay(20);
  }

}


void writeLED(int val01, int val02, int val03, int val04, int val05, int val06, int val07) {
  analogWrite(LED01, val01);
  analogWrite(LED02, val02);
  analogWrite(LED03, val03);
  analogWrite(LED04, val04);
  analogWrite(LED05, val05);
  analogWrite(LED06, val06);
  analogWrite(LED07, val07);
}

