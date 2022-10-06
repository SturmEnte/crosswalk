const int BUTTON = A3;

const int PED_GREEN = 2;
const int PED_RED = 3;

const int CAR_GREEN = 5;
const int CAR_YELLOW = 6;
const int CAR_RED = 7;

const int YELLOW_TIME = 1000;
const int RED_TIME = 5000;
const int TIME_BETWEEN_PRESSES = 10000;

unsigned long nextPress = 0;
int buttonValue = HIGH;

void setup() {
  for(int i = PED_GREEN; i <= CAR_RED; i++) {
    pinMode(i, OUTPUT);
  }

  // Defualt state
  digitalWrite(CAR_GREEN, HIGH);  
  digitalWrite(PED_RED, HIGH);
}

void loop() {
  buttonValue = digitalRead(BUTTON);
  
  if(buttonValue == LOW && nextPress <= millis()) {
    
    digitalWrite(CAR_GREEN, LOW);
    digitalWrite(CAR_YELLOW, HIGH);
    delay(YELLOW_TIME);
    
    digitalWrite(CAR_YELLOW, LOW);
    digitalWrite(CAR_RED, HIGH);
    digitalWrite(PED_RED, LOW);
    digitalWrite(PED_GREEN, HIGH);
    delay(RED_TIME);
    
    digitalWrite(CAR_YELLOW, HIGH);
    digitalWrite(PED_GREEN, LOW);
    digitalWrite(PED_RED, HIGH);
    delay(YELLOW_TIME);
    
    digitalWrite(CAR_YELLOW, LOW);
    digitalWrite(CAR_RED, LOW);
    digitalWrite(CAR_GREEN, HIGH);
    
    nextPress = millis() + TIME_BETWEEN_PRESSES;
  }
}
