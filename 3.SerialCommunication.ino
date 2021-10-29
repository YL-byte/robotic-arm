void read_all_positions(int number_of_servos, Servo list_of_servos[], int pin_map[], bool detached[]){

  for (int servo_index = 0; servo_index < number_of_servos; servo_index++){
    
    if (detached[servo_index])
      list_of_servos[servo_index].attach(pin_map[servo_index]);

    Serial.print("Servo ");
    Serial.print(servo_index);
    Serial.print(": ");
    Serial.println(list_of_servos[servo_index].read());

    if (detached[servo_index])
      list_of_servos[servo_index].detach();

  }

  Serial.println("_______________");
  
}
