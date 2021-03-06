#include <stdio.h>
#include <time.h> 
#include "E101.h"

int Average();
int turnLeft();
int turnRight();
int driveStraight();
int reverse();
int wallDetector();
int defaultSpeed (20);
void lineRunner();
void wallRunner();

    // sets up everything to ensure it is working.
int main(){

}

int Average()
    {
    int track();
    int Average;

    // read analog input
    for(int c = 0; c<10; c++)
        {
        track += read_analog(0);
        sleep(0,5);
        return Average;
        }
    }

void lineRunner()
    {
    int currentEV();   //determines the current error of what is shown.
    int previousEV();  //tracks the previous error of what was shown.
    int difference();   // calculates the difference between previous and current.
    int errorTrack(); // tracks the total error (averages are cool) Sensor readings are key for errors.
    int pixelSum(); // pretty much the foundation, differentiates colours.

    double period = (0);
    clock_t start;
    clock_t now;

    float kDer = 0; // constant derivative.
    int derSig = 0; // used to scale motors.

    float kInt = 0; // constant integral.
    int intSig = 0; // used to scale motors.

    float kp = 0.1; // probably have to test this out, this changes based on a lot of factors.
    int pSig = 0; //scales using proportional constant and motors.

    int defaultSpeed = 20;

        // This part actually follows the line (hopefully) based on all the previously set things.

    while(true)
        { // will have to eventually break this to turn it off once the quadrant has been completed and the sensors detect walls.
            start = clock();
            take_picture();
            currentEV = 0; // keep this 0
            pSig = 0; // it's a constant, keep it 0.
            pixelSum = 0;

            for(int count = 0; count < 320; count++)
            {
            int noise = get_pixel(count, 120, 3); // Gives pixel brightness, handles the noise.

            if(noise < 120)
                {
                    noise = 0; // Always reset, it's a loop.
                }
                else
                {
                    noise = 1; // To follow the line.
                    pixelSum += 1;
                }

                currentEV += (count - 160) * noise; // Equates to 0, ensuring the edges of the line are followed. I hope.
            }
            // if there is no walls, only lines - aka quadrant whatever.

            if (currentEV < 500 && currentEV > -500 && pixelSum > 300)
            {
                return; // we out boiz.
            }

            now = clock();
            ePeriod = ((double)(now - start)) / CLOCKS_PER_SEC;

            difference = currentEV - previousEV;
            derSig = (difference/ePeriod) * kDer; // constant

            previousEV = currentEV;
            errorTrack += currentEV; //Sums error.

            pSig = currentEV*kp;
            intSig = (errorTrack * kInt);

            //change the speeds, based on the scaling of everything prior.

            set_motor(2, defaultSpeed - pSig - intSig + derSig);
            set_motor(1, defaultSpeed + pSig - intSig -derSig);
            }
    }
    // To properly turn right around a 90 degree bend without hitting any object
    // the motor must firstly slow to a point where the forward velocity does not
    // move the vehicle past the turn. Secondly, a partial right turn of max angle
    // must be executed, before stopping. Then the vehicle should reverse and straighten itself.
    // this may occur two times simultaneously for turns in which the vehicle must rotate
    // 180 degrees or more.
    // therefore, a right turn should detect whether a wall is in front of it or not after
    // the intiial two movements, and if there is then it should proceed to turn once more,
    // further detecting any walls and then continuing along the path.

    void turning left(){
        while (1){
            driveStraight
            if (analog_reading > wallDetector){
                set_motor(1,20); //right
                set_motor(2,20); //left
                sleep(1,5); //right
                set_motor(1,0);
                set_motor(2,0);
                sleep(0,5);
                set_motor(1,20);
                set_motor(2,40);


            }
        }

        }
    }
