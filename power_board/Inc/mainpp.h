/*
 * mainpp.h
 *
 *  Created on: 2018/01/17
 *      Author: yoneken
 */

#ifndef MAINPP_H_
#define MAINPP_H_
#include <auv_msgs/ThrusterMicroseconds.h>
#ifdef __cplusplus
 extern "C" {
#endif

//#include <stdint.h>


const uint8_t SRG_P 	= auv_msgs::ThrusterMicroseconds::SURGE_PORT;
const uint8_t SRG_S 	= auv_msgs::ThrusterMicroseconds::SURGE_STAR;
const uint8_t SWY_BW 	= auv_msgs::ThrusterMicroseconds::SWAY_BOW;
const uint8_t SWY_ST 	= auv_msgs::ThrusterMicroseconds::SWAY_STERN;
const uint8_t HVE_BW_P 	= auv_msgs::ThrusterMicroseconds::HEAVE_BOW_PORT;
const uint8_t HVE_BW_S 	= auv_msgs::ThrusterMicroseconds::HEAVE_BOW_STAR;
const uint8_t HVE_ST_S 	= auv_msgs::ThrusterMicroseconds::HEAVE_STERN_STAR;
const uint8_t HVE_ST_P 	= auv_msgs::ThrusterMicroseconds::HEAVE_STERN_PORT;


const uint16_t offCommand[] = {1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500};

void setup(void);
void loop(void);

#ifdef __cplusplus
}
#endif


#endif /* MAINPP_H_ */
