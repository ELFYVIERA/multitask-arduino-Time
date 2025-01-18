/*
 Multitasking Code for Arduino: This code demonstrates how to run a simple Blynk-controlled LED without using the delay() function. 
 Instead, it utilizes the millis() function to measure elapsed time in milliseconds. 

 The example is designed for the Arduino Uno, showcasing how to handle timing operations efficiently. 
 The duration of the LED's HIGH and LOW states can be adjusted by modifying the `trigg_time` and `rise_time` variables.

 Note:
   For example, setting `trigg_time = 2000` and `rise_time = 2000` means the condition will be triggered after 2 seconds, 
   and the LED will remain HIGH for approximately 1 second.

   The HIGH duration = `trigg_time - rise_time`
*/

// declaration for leds pin
const int ledPin_1 = 13;                              
const int ledPin_2 = 10;
const int ledPin_3 = 9;

//declaration for previousTime
unsigned long int led_prevTime1 = 0;
unsigned long int led_prevTime2 = 0;
unsigned long int led_prevTime3 = 0;


/*declaration for trigger time and rise time for each led*/
//led 1, Trigger at interval 2 seconds and HIGH about 2 second
unsigned long int trigg_time_1 = 2000;               
unsigned long int rise_time_1 = 4000;   
//led 2, Trigger at interval 3 seconds and HIGH about 1 second
unsigned long int trigg_time_2 = 3000;               
unsigned long int rise_time_2 = 4000;
//led 3, Trigger at interval 1 seconds and HIGH about 5 second
unsigned long int trigg_time_3 = 1000;               
unsigned long int rise_time_3 = 6000;  

             
void setup() {
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);         
  pinMode(ledPin_3, OUTPUT);                                   
  Serial.begin(9600);                               // Initialize the serial communication at baud rate 9600
}
void loop() {
  unsigned long int currentTime = 0;
  currentTime = millis();

  //analyze  for led 1
  if(currentTime - led_prevTime1 >= trigg_time_1){
    digitalWrite(ledPin_1, HIGH);
    if(currentTime - led_prevTime1 >= rise_time_1){
      led_prevTime1 = currentTime;                  // Reset the previous time to the current time
    }
  }
  else{
    digitalWrite(ledPin_1, LOW);                  // Turn off the LED
  }

  //analyze for led 2
  if(currentTime - led_prevTime2 >= trigg_time_2){
    digitalWrite(ledPin_2, HIGH);
    if(currentTime - led_prevTime2 >= rise_time_2){
      led_prevTime2 = currentTime;                  // Reset the previous time to the current time
    }
  }
  else{
    digitalWrite(ledPin_2, LOW);                  // Turn off the LED
  }

  //analyze for led 3

  if(currentTime - led_prevTime3 >= trigg_time_3){
    digitalWrite(ledPin_3, HIGH);
    if(currentTime - led_prevTime3 >= rise_time_3){
      led_prevTime3 = currentTime;                  // Reset the previous time to the current time
    }
  }
  else{
    digitalWrite(ledPin_3, LOW);                  // Turn off the LED
  }




  
  // Analyze the voltage changes HIGH(1) or LOW(0)
  //note, use the graph in serial communication for better view                    
}
