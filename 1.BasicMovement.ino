void write_to_servos(int number_of_servos, Servo list_of_servos[], int pin_map[], int pos[], bool detached[]){
    for (int servo_index = 0; servo_index < NUMBER_OF_SERVOS; servo_index++){
      list_of_servos[servo_index].attach(pin_map[servo_index]);   
      list_of_servos[servo_index].write(pos[servo_index]);
      delay(DELAY_TIME);
      if (detached[servo_index])
        list_of_servos[servo_index].detach(); 
    }
}
