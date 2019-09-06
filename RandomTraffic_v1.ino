// 
int state0 = 0;
int state1 = 0;
int state2 = 0;

long del0 = 500;
long del1 = 500;
long del2 = 500;

unsigned long elap0 = 0;
unsigned long elap1 = 0;
unsigned long elap2 = 0;

void flip_state ( int state ) {
  // take any boolean state int and flip its value
  if (state == 0) {
      state = 1;
  } 
  else {
    state = 0;
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  // seed the ENG off of pin A0
  randomSeed(analogRead(0));
}

void loop() {
  // start raw timer for comparison
  unsigned long time0 = millis();

  //wrap in a for loop over the 3 LED leads
  // begin with pin 10 assigned to the zeroth index
  if ( (time0-elap0) >= del0) {
    // reset elapsed time
    elap0 = time0;
    // flip the LED state on/off
    flip_state(state0);

    // set the LED with the ledState of the variable:
    digitalWrite(10, state0);
    // pick a new random number to wait for state flip
    del0 = random(100,900);
  }
  if ( (time0-elap1) >= del1) {
    // reset elapsed time
    elap1 = time0;
    // flip the LED state on/off
    flip_state(state1);
    // set the pin state
    digitalWrite(9, state1);
    // pick a new random number to wait for state flip
    del1 = random(100,900);
  }
  if ( (time0-elap2) >= del2) {
    // reset elapsed time
    elap2 = time0;
    // flip the LED state on/off
    flip_state(state2);
    // pick a new random number to wait for state flip
    digitalWrite(8, state2);
    // pick a new random number to wait for flip
    del2 = random(100,900);
  }
}
