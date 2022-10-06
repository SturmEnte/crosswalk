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
bool pressed = false;

void setup() {
  // Pin 4 is not used but this looks better and saves time while writing
  for(int i = PED_GREEN; i <= CAR_RED; i++) {
    pinMode(i, OUTPUT);
  }

  // Set the defualt state of the traffic lights
  digitalWrite(CAR_GREEN, HIGH);  
  digitalWrite(PED_RED, HIGH);
}

void loop() {
  // Check if the button is pressed and if so, save it in the pressed value
  if(digitalRead(BUTTON) == LOW) {
    pressed = true;
  }
  
  // Check if the button was pressed and if a green phase for the pedestrians can be started
  if(pressed && nextPress <= millis()) {
    
    // Set the traffic light of the cars to yellow
    digitalWrite(CAR_GREEN, LOW);
    digitalWrite(CAR_YELLOW, HIGH);
    delay(YELLOW_TIME);
    
    // Set the traffic light of the cars to red and of the pedestrians to green
    digitalWrite(CAR_YELLOW, LOW);
    digitalWrite(CAR_RED, HIGH);
    digitalWrite(PED_RED, LOW);
    digitalWrite(PED_GREEN, HIGH);
    delay(RED_TIME);
    
    // Set the traffic light of the cars to yellow-red and of the pedestrians to red
    digitalWrite(CAR_YELLOW, HIGH);
    digitalWrite(PED_GREEN, LOW);
    digitalWrite(PED_RED, HIGH);
    delay(YELLOW_TIME);
    
    // Set the traffic light of the cars to green
    digitalWrite(CAR_YELLOW, LOW);
    digitalWrite(CAR_RED, LOW);
    digitalWrite(CAR_GREEN, HIGH);
    
    // Reset the pressed value and calculate the earliest time of the next green phase for the pedestrians
    nextPress = millis() + TIME_BETWEEN_PRESSES;
    pressed = false;
  }
}
