const int pedalPin = 4; 
const int buttonPin = 7; 
const int sustainPin = 6;

int pedalLastState = 0;   
int buttonLastState = 0;   
int pedalState = 0;   
int buttonState = 0;   
int sustainState = 0; 

int sustainPEDAL = 0;
int sustainBUTTON = 0;

void clickSustain(){
  digitalWrite(sustainPin, HIGH);
  delay(50);  
  digitalWrite(sustainPin, LOW);
}

void setup() {
  pinMode(sustainPin, OUTPUT);
  pinMode(buttonPin, INPUT );
  pinMode(pedalPin, INPUT );
}

void loop() {
  pedalState = digitalRead(pedalPin);
  buttonState = digitalRead(buttonPin);

   if (pedalState != pedalLastState) { // SI EL PEDAL ESTA PULSADO = ENCENDER SUSTAIN
    clickSustain();
    sustainState = !sustainState;
    pedalLastState = pedalState;
  } else 
  if (buttonState == HIGH && buttonLastState == LOW) { // SI EL PEDAL ESTA PULSADO = ENCENDER SUSTAIN
    clickSustain();
    sustainState = !sustainState;
    buttonLastState = HIGH;
  } else
  if (buttonState == LOW) {
    buttonLastState = LOW;
  }

  delay(10.0);  

}
