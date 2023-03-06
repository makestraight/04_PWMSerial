/*
  LED brightness controlled by Serial Communication

  prompt inquiry about brightness
  adjust brightness based on the user input

  Date: 6 Mar 2023
  Author: Yen-Chen Chang @ makestraight
*/


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  
  // initialize digital pin 11 as an output.
  // PWM pins on Arduino Uno include 3, 5, 6, 9, 10, 11
  pinMode(11, OUTPUT);
  
  //prompt inquiry
  Serial.println("Enter your desired brightness in percentage (0-100): ");
}

// the loop function runs over and over again forever
void loop() {
  // check input buffer
  if (Serial.available() > 0) {
    // read the incoming integer
    int incomingInt = Serial.parseInt();

    if(incomingInt>=0 && incomingInt<=100){
      // adjust the LED brightness
      analogWrite(11, incomingInt*255 / 100);

      // display current brightness on the serial window
      Serial.print("Current brightness: ");
      Serial.println(incomingInt);
    }else{
      // only accept value between 0 and 100
      Serial.println("Invalid Input Value!!!");
    }

    // prompt next inquiry
    Serial.println("Enter number from 0 to 100:");
  }

}
