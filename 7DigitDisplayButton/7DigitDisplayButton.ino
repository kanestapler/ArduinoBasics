bool numbers[10][7] = {{true,true,true,true,true,true,false},
                      {false,true,true,false,false,false,false},
                      {true,true,false,true,true,false,true},
                      {true,true,true,true,false,false,true},
                      {false,true,true,false,false,true,true},
                      {true,false,true,true,false,true,true},
                      {true,false,true,true,true,true,true},
                      {true,true,true,false,false,false,false},
                      {true,true,true,true,true,true,true},
                      {true,true,true,false,false,true,true}};
int firstPin = 2;
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 8; i++) {
    pinMode(firstPin + i,OUTPUT);
  }
  pinMode(13, INPUT);
}
int numberToDisplay = 0;
int lastButtonState = 0;
void loop() {
  int currentButtonState = digitalRead(13);
  if (currentButtonState != lastButtonState && currentButtonState == HIGH) {
    if (numberToDisplay >= 9) {
      numberToDisplay = 0;
    } else {
      numberToDisplay++;
    }
    displayNumber(numberToDisplay);
  }
  lastButtonState = currentButtonState;
}

void displayNumber(int number) {
  for (int i = 0; i < sizeof(numbers[number]); i++) {
    if (numbers[number][i]) {
      digitalWrite(firstPin+i, HIGH);
    } else {
      digitalWrite(firstPin+i, LOW);
    }
  }
}

