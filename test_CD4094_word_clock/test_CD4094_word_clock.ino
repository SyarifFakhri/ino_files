// CD4094 Constants
#define CD4094_CLOCK    10
#define CD4094_DATA     11
#define CD4094_STROBE   12
#define CD4094_OE     9

char shift_1 = 0, shift_2 = 0, shift_3 = 0, shift_4 = 0;

void setup() {
  pinMode(CD4094_CLOCK, OUTPUT);
  pinMode(CD4094_STROBE, OUTPUT);
  pinMode(CD4094_DATA, OUTPUT);
  pinMode(CD4094_OE, OUTPUT);

  digitalWrite(CD4094_STROBE, LOW);
  shiftOut(CD4094_DATA, CD4094_CLOCK, MSBFIRST, shift_1);
  shiftOut(CD4094_DATA, CD4094_CLOCK, MSBFIRST, shift_2);
  shiftOut(CD4094_DATA, CD4094_CLOCK, MSBFIRST, shift_3);
  shiftOut(CD4094_DATA, CD4094_CLOCK, MSBFIRST, shift_4);
  digitalWrite(CD4094_STROBE, HIGH);
}

void loop() {
  shift_1 = 251;
  shift_2 = 255;

  shift_3 = 4;
  shift_4 = 0;

  digitalWrite(CD4094_OE, LOW);
  digitalWrite(CD4094_STROBE, LOW);

  shiftOut(CD4094_DATA, CD4094_CLOCK, MSBFIRST, shift_1);
  shiftOut(CD4094_DATA, CD4094_CLOCK, MSBFIRST, shift_2);
  shiftOut(CD4094_DATA, CD4094_CLOCK, MSBFIRST, shift_3);
  shiftOut(CD4094_DATA, CD4094_CLOCK, MSBFIRST, shift_4);

  digitalWrite(CD4094_OE, HIGH);
  digitalWrite(CD4094_STROBE, HIGH);

  delay(1000);

  shift_1 = 247;
  shift_2 = 255;
  shift_3 = 2;
  shift_4 = 0;

  digitalWrite(CD4094_OE, LOW);
  digitalWrite(CD4094_STROBE, LOW);

  shiftOut(CD4094_DATA, CD4094_CLOCK, MSBFIRST, shift_1);
  shiftOut(CD4094_DATA, CD4094_CLOCK, MSBFIRST, shift_2);
  shiftOut(CD4094_DATA, CD4094_CLOCK, MSBFIRST, shift_3);
  shiftOut(CD4094_DATA, CD4094_CLOCK, MSBFIRST, shift_4);

  digitalWrite(CD4094_OE, HIGH);
  digitalWrite(CD4094_STROBE, LOW);

  delay(1000);
}
