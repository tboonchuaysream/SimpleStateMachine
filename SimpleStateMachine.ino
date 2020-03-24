/*
@author Tommy Boonchuaysream
- make button light up every 4 presses
*/

const int  pushButton = A0;
const int ledExternal = 12;
const int ledInternal = 13; 

int counter = 0;   
int buttonState = 0;         
int lastButtonState = 0;     

void setup() {
  
  pinMode(pushButton, INPUT);
  
  pinMode(ledExternal, OUTPUT);
  pinMode(ledInternal, OUTPUT);
  
  Serial.begin(9600);
}


void loop() {

  //read button state
  buttonState = digitalRead(pushButton);

  if (buttonState != lastButtonState) {
    
    if (buttonState == HIGH) {
      
      counter++;
      Serial.println("on");
        digitalWrite(ledInternal, HIGH);
      Serial.print("number of button pushes: ");
      Serial.println(counter);
    } else {
      
      Serial.println("off");
        digitalWrite(ledInternal, LOW);
    }
    
    delay(50);
  }

  //save button state for comparison
  lastButtonState = buttonState;

  //make button light up every 4 presses
  if (counter % 4 == 0) {
    digitalWrite(ledExternal, HIGH);
  } else {
    digitalWrite(ledExternal, LOW);
  }

}
