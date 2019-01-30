
/* Shift Out Data
  Decimal to Binary using Android Emulator
*/

int ledPin = 13;
int data = 11;//Connect Pin 8 of Arduino to pin 2 of CD4094 or HEF4794
int strob = 12;//Connect Pin 12 to Pin 1 of CD4094
int clock = 10;//Connect pin 10 of Arduino to pin 3 of CD4094
int oe = 9;//Connect pin 9 of Arduino to pin 15 of CD4094
int count = 0;
int dato = 0;
int value;
String inString = " ";
void setup()
{
  Serial.begin(57600);
  pinMode(ledPin, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(strob, OUTPUT);
  pinMode(oe, OUTPUT);
  Serial.println("Enter digits");
}

void PulseClock(void) {
  digitalWrite(clock, LOW);
  delayMicroseconds(20);
  digitalWrite(clock, HIGH);
  delayMicroseconds(50);
  digitalWrite(clock, LOW);
}

void Dato(void) {
  for (count = 0; count < 8; count++) {
    digitalWrite(data, dato & 01);

    dato >>= 1;
    if (count == 7) {
      digitalWrite(oe, LOW);
      digitalWrite(strob, HIGH);

    }

    PulseClock();
    digitalWrite(oe, HIGH);
    inString = " ";
  }
  delayMicroseconds(20);
  digitalWrite(strob, LOW);
  delay(1000);
}
void loop()
{
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      inString += (char)inChar;
    }
    if (inChar == '?') {

      Serial.print("Value:");
      Serial.println(inString.toInt());
      Serial.println("******************");
      value = inString.toInt();
      dato = value;

      if (dato == 0)

      {

        dato = 0;
        Dato();
        digitalWrite(ledPin, HIGH);

        PulseClock();
        digitalWrite(oe, HIGH);

      }
      else if (dato > 255 ) // for all values above 255, dato= 255; all LEDs glow.
      {

        dato = 255;
        Dato();

        PulseClock();
        digitalWrite(ledPin, LOW);
        digitalWrite(oe, HIGH);


        Serial.println("******************");
        Serial.print("Enter value 0-255");
        Serial.println(" ");
        Serial.println("******************");
      }
      else
      {
        Dato();
        digitalWrite(ledPin, LOW);
      }

    }
  }
}
