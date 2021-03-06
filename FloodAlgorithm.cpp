#include <stdio.h>
#include <time.h> 
#include "E101.h"

void turnLeft();
void turnRight();
void goStraight();
void turnAround();
void wallFront();
void wallLeft();
void wallRight();

int main(){
	init();
	int currentEV; //current error value
	int previousEV;
	int difference; // difference of current and previous error
	int errorTrack; // sum of errors
	int pixelSum = 0;

	double period = (0);
    clock_t start;
    clock_t now;

    float kDer = 0; // constant derivative.
    int derSig = 0; // used to scale motors.

    float kInt = 0; // constant integral.
    int intSig = 0; // used to scale motors.

    float kp = 0.1; // Test this at differing values.
    int pSig = 0; //scales using proportional constant and motors.

    int defaultSpeed = 20;

	while(LineQuad){
		start = clock();
		take_picture();
		currentEV = 0;
		pSig = 0;
		pixelSum = 0;

		// same as before, reset all values constantly.

		for(int count = 0; count < 320; count++){
			int noise = get_pixel(count, 120, 3);

			if (noise<100){
				noise = 0;
				else{
					noise = 1;
					pixelSum += 1;
				}

				}
			}
			if (currentEV < 500 && currentEV > -500 && pixelSum >= 150 && pixelSum <= 240){

				// from this point on code to follow the white line, may need to further calculate the threshoid
				// will also need to add a couple of if statements to ensure once left hand turns have been detected
				// that the robot will be able to differentiate from when it has completed quadrnt 2 and is within 3
				// will then need to reuse the algorithm to follow the walls instead of the line
				// after this the middle sensor should detect walls and red values (finish line is red tape)
				// flood algorithm means left turns only so (if right & left vailable , go left, if straight go straight)

			}
		}







}

void turnRight(){
	set_motor(1,20);
	set_motor(2,40);
	sleep(1,0); //or however long it takes to turn. Will have to test this value to figure out just how much time it takes
	set_motor(1,0);
	set_motor(2,0); //reset completely and begin reading the next set of readings from sensor
	sleep(1,0);

}
void turnLeft(){
	set_motor(1,40);
	set_motor(2,20);
	sleep(1,0);
	set_motor(1,0);
	set_motor(2,0)
}
void turnAround(){
	set_motor(1,20);
	set_motor(2,-20);
	sleep(2,0); // time to turn around, might need to change. Should complete a full 180 degree turn.
	set_motor(1,0);
	set_motor(2,0);
}
