void setup() {
  
  Serial.begin(9600);
  for (int current_servo_index = 0; current_servo_index < NUMBER_OF_SERVOS; current_servo_index++)
    if (!detached[current_servo_index])
        list_of_servos[current_servo_index].attach(pin_map[current_servo_index]); 
        
  int s[][NUMBER_OF_SERVOS] = {
    {72, 0, 180, CLOSE_CLAW_DEGREES},    
    {72, 160, 70, CLOSE_CLAW_DEGREES}, 
    {72 + 35, 180, 30, CLOSE_CLAW_DEGREES}, 
    {72 - 15, 180, 30, OPEN_CLAW_DEGREES}, //Turn Back
    {72 - 15, 100, 70, OPEN_CLAW_DEGREES}, //Get Into Position
    {72 - 15, 100, 70, CLOSE_CLAW_HOLDING_BALL_DEGREES}, //Pick Up The Ball
    {72 - 15, 140, 30, CLOSE_CLAW_HOLDING_BALL_DEGREES}, //Move Up A Bit
    {72, 140, 70, CLOSE_CLAW_HOLDING_BALL_DEGREES}, //Move Right A Bit
    {72, 140, 70, OPEN_CLAW_DEGREES} //Let Go
  };

  int list_of_delays[] = {
    2000,
    1000,
    3000,
    1000,
    1000,
    1000,
    1000
  };
  /*
  int s[][NUMBER_OF_SERVOS] = {
    {72, 180, 0, CLOSE_CLAW_DEGREES},
    {72, 110, 65, OPEN_CLAW_DEGREES},
    {72, 110, 65, CLOSE_CLAW_HOLDING_BALL_DEGREES},
    {72, 150, 90, CLOSE_CLAW_HOLDING_BALL_DEGREES},
    {72, 150, 90,  OPEN_CLAW_DEGREES},
    {72, 180, 0, CLOSE_CLAW_DEGREES}
  };
  
  int list_of_delays[] = {
    1000,
    1000,
    1000,
    1000,
    1000,
    1000
  };
  */
  int size_of_s = sizeof(s) / sizeof(int);
  sequence(s, size_of_s, list_of_delays, NUMBER_OF_SERVOS, list_of_servos, pin_map, detached);
}

void loop() {
    write_to_servos(NUMBER_OF_SERVOS, list_of_servos, pin_map, init_position, detached);
    delay(2000);
}
  
