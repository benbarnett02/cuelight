/*
   Notes
   Cuelight
   Etc
   I know I could use arrays but I don't really understand them very well.
   The program isn't massive anyway.
   I also know I could use the IO register to remove a bunch of these vars. But I didn't.

   Still need to implement the debouncing, I don't really want another thousand unsigned longs.
   Could use ezbutton library or similar but Matt was having some issues with it
*/

const int estopButtonPin = 2;// the number of the pushbutton pin
const int liveButtonPin = 3;
const int standbyButtonPin = 4;
const int ButtonPin1 = 5;
const int ButtonPin2 = 6;
const int ButtonPin3 = 7;

// Using these to store the current states of all buttons
boolean estopButton = false;
boolean liveButton = false;
boolean standbyButton = false;
boolean Button1 = false;
boolean Button2 = false;
boolean Button3 = false;

// Using these to store the previous states of all these buttons
boolean estopButtonLast = false;
boolean liveButtonLast = false;
boolean standbyButtonLast = false;
boolean Button1Last = false;
boolean Button2Last = false;
boolean Button3Last = false;

const int LiveLightPin = 8;// the number of the LED pin
const int StandByLightPin = 9;
const int CueLightPin1 = 10;
const int CueLightPin2 = 11;
const int CueLightPin3 = 12;

boolean LiveLight = false;
boolean StandbyLight = false;

boolean cue1standby = false;
boolean cue2standby = false;
boolean cue3standby = false;

boolean cue1go = false;
boolean cue2go = false;
boolean cue3go = false;

//The following are unsigned longs because the time (ms) will quickly be
//bigger than an int can hold
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  
  // put your setup code here, to run once:
  //was intending to use internal INPUT_PULLUP but unsure of using it with multiple pins

  Serial.begin(9600);//making a serial thing

  // setting pinmodes of all buttons
  pinMode(estopButtonPin, INPUT);
  pinMode(liveButtonPin, INPUT);
  pinMode(ButtonPin1, INPUT);
  pinMode(ButtonPin2, INPUT);
  pinMode(ButtonPin3, INPUT);

  //pinmodes all lights
  pinMode(LiveLightPin, OUTPUT);
  pinMode(StandByLightPin, OUTPUT);
  pinMode(CueLightPin1, OUTPUT);
  pinMode(CueLightPin2, OUTPUT);
  pinMode(CueLightPin3, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  //Reading all the button states and writing them to integers (defined in top level)
  estopButton = digitalRead(estopButtonPin);
  liveButton = digitalRead(liveButtonPin);
  standbyButton = digitalRead(standbyButtonPin);
  Button1 = digitalRead(ButtonPin1);
  Button2 = digitalRead(ButtonPin2);
  Button3 = digitalRead(ButtonPin3);

  //Cue 1 ifs
  if (Button1 == HIGH && Button1Last == LOW) {//If button is pushed down

    if (cue1standby == 0) {//if button is pushed AND the LED is currently off
      // turn it on
      digitalWrite(CueLightPin1, HIGH);
      cue1standby = 1;

    } else {//if button is pushed and the LED is anything but off
      // turn it off
      digitalWrite(CueLightPin1, LOW);
      cue1standby = 0;
    }  
  }

  //Cue light 2 ifs
    if (Button2 == HIGH && Button2Last == LOW) {//If button is pushed down

    if (cue2standby == 0) {//if button is pushed AND the LED is currently off
      // turn it on
      digitalWrite(CueLightPin2, HIGH);
      cue2standby = 1;

    } else {//if button is pushed and the LED is anything but off
      // turn it off
      digitalWrite(CueLightPin2, LOW);
      cue2standby = 0;
    }
  }

  //Cue light 3 ifs
    if (Button3 == HIGH && Button3Last == LOW) {//If button is pushed down

    if (cue3standby == 0) {//if button is pushed AND the LED is currently off
      // turn it on
      digitalWrite(CueLightPin3, HIGH);
      cue3standby = 1;

    } else {//if button is pushed and the LED is anything but off
      // turn it off
      digitalWrite(CueLightPin3, LOW);
      cue3standby = 0;
    }
  }
  

}
