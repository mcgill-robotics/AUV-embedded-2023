
#include <mainpp.h>
#include <main.h>
#include <ros.h>
#include <auv_msgs/ThrusterMicroseconds.h>

extern TIM_HandleTypeDef htim2, htim3;

static void updateThrusters(const uint16_t microseconds[8])
{
	htim3.Instance->CCR2 = microseconds[SRG_P]; // Timer 3 Ch 2 (T1)
	htim3.Instance->CCR1 = microseconds[SRG_S]; // Timer 3 Ch 1 (T2)
	htim2.Instance->CCR2 = microseconds[SWY_BW]; // Timer 2 Ch 2 (T3)
	htim2.Instance->CCR1 = microseconds[SWY_ST]; // Timer 2 Ch 1 (T4)
	htim2.Instance->CCR3 = microseconds[HVE_BW_P]; // Timer 2 Ch 3 (T5)
	htim2.Instance->CCR4 = microseconds[HVE_BW_S]; // Timer 2 Ch 4 (T6)
	htim3.Instance->CCR4 = microseconds[HVE_ST_S]; // Timer 3 Ch 4 (T7)
	htim3.Instance->CCR3 = microseconds[HVE_ST_P]; // Timer 3 Ch 3 (T8)
}

static void thrustersOff(void)
{
	updateThrusters(offCommand);
}

static void initThrusters(void)
{
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
	thrustersOff();
}


static void commandCb(const auv_msgs::ThrusterMicroseconds& tc){
	// lastCommand = millis();
	const uint16_t* microseconds = tc.microseconds;
	updateThrusters(microseconds);
}

ros::NodeHandle nh;
ros::Subscriber<auv_msgs::ThrusterMicroseconds> sub("propulsion/thruster_microseconds", &commandCb);

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->reset_rbuf();
}


void setup(void)
{
	initThrusters();
	nh.subscribe(sub);
  nh.initNode();
}

void loop(void)
{
	nh.spinOnce();
	HAL_Delay(1);
}

