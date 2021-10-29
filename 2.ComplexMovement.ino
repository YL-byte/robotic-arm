void sequence(int s[][NUMBER_OF_SERVOS], int number_of_sequences, int list_of_delays[], int number_of_servos, Servo list_of_servos[], int pin_map[], bool detached[]){
  for (int i = 0; i < number_of_sequences; i++){
    write_to_servos(NUMBER_OF_SERVOS, list_of_servos, pin_map, s[i], detached);
    delay(list_of_delays[i]);
  }
}
