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

  int potValue01 = analogRead(POT01);
  int potValue02 = analogRead(POT02);
  int potValue03 = analogRead(POT03);
  int potValue04 = analogRead(POT04);
  int potValue05 = analogRead(POT05);
  int potValue06 = analogRead(POT06);
  int potValue07 = analogRead(POT07);

  analogWrite(LED01, map(potValue01, 0, 1024, 0, 255));
  analogWrite(LED02, map(potValue02, 0, 1024, 0, 255));
  analogWrite(LED03, map(potValue03, 0, 1024, 0, 255));
  analogWrite(LED04, map(potValue04, 0, 1024, 0, 255));
  analogWrite(LED05, map(potValue05, 0, 1024, 0, 255));
  analogWrite(LED06, map(potValue06, 0, 1024, 0, 255));
  analogWrite(LED07, map(potValue07, 0, 1024, 0, 255));
}
