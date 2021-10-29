#include<Servo.h>
#define DELAY_TIME 50
#define NUMBER_OF_SERVOS 4
#define OPEN_CLAW_DEGREES 115
#define CLOSE_CLAW_DEGREES 155
#define CLOSE_CLAW_HOLDING_BALL_DEGREES 145

#define BASE_SERVO 0
#define LOWER_BODY_SERVO 1
#define UPPER_BODY_SERVO 2
#define CLAW_SERVO 3

//All Servos Involved - 0 = Base Servo, 1 = Lower Body Servo, 2 = Upper Body Servo, 3 = Claw Servo
Servo list_of_servos[NUMBER_OF_SERVOS];
int init_position[NUMBER_OF_SERVOS] = {72, 180, 0, CLOSE_CLAW_DEGREES};
int pin_map[NUMBER_OF_SERVOS] = {3, 5, 6, 9};
bool detached[NUMBER_OF_SERVOS] = {true, false, true, true};
char *servo_map[NUMBER_OF_SERVOS] = {"Base Servo", "Lower Body Servo", "Upper Body Servo", "Claw Servo"};

//Function Declaration
void cont_move_servos(int number_of_servos, Servo list_of_servos[], int pin_map[], int new_pos[], bool detached[]);
void reset_body(int number_of_servos, Servo list_of_servos[], int pin_map[], int pos[], bool detached[]);
void write_to_servos(int number_of_servos, Servo list_of_servos[], int pin_map[], int pos[], bool detached[]);
void read_all_positions(int number_of_servos, Servo list_of_servos[], int pin_map[], bool detached[]);
void sequence(int s[][NUMBER_OF_SERVOS], int number_of_sequences, int list_of_delays[], int number_of_servos, Servo list_of_servos[], int pin_map[], bool detached[]);
