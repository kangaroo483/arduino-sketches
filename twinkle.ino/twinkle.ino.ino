void setup() {
  // set up a pin for each "note" of twinkle twinkle little star
pinMode(4, OUTPUT); //first note "twinkle"
pinMode(7, OUTPUT);//second note "twinkle"
pinMode(12, OUTPUT);//third note "little"
pinMode(13, OUTPUT);//fourth note "star"
}

void loop() {

  //let's set up an array for our pattern 
  //which pin (which LEDs) to turn on in sequence
  int pattern[]= {13, 12, 7, 4, 7, 12, 13};

  //loop through the ENTIRE pattern
  for(int count = 0; count < 8; count++){
    //pattern[count] gives me the note in the 
    //pattern that I've counted up to by now 
    digitalWrite(pattern[count], HIGH); // turn this light on 
    delay(50);
    digitalWrite(pattern[count], LOW);// turn this light off 
    delay(50);
   
  }
}
