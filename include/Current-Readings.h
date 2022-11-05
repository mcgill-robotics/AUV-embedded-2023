/**
 * Current Reading function calls for the AUV
 *  
*/

// The lines bellow are called an include guard. Please include those in any .h file
// See: https://en.wikipedia.org/wiki/Include_guard

#ifndef CURRENT_READINGS_H_
#define CURRENT_READINGS_H_

typedef struct ThrusterCurrent_t{
    int thruster_1_current;
    int thruster_2_current;
    int thruster_3_current;
    int thruster_4_current;
    int thruster_5_current;
    int thruster_6_current;
} ThrusterCurrent_t;

/**
 * Put the function prototype only for function which are relevant for other modules.
 * Internal function calls should not apprear in the header files.
*/
ThrusterCurrent_t getThrusterCurrent();
int getSystemCurrent();

#endif /* CURRENT_READINGS_H_ */
// The line above is important for the include guard as well