#ifndef _ROS_auv_msgs_ImuData_h
#define _ROS_auv_msgs_ImuData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace auv_msgs
{

  class ImuData : public ros::Msg
  {
    public:
      typedef double _ROLL_type;
      _ROLL_type ROLL;
      typedef double _PITCH_type;
      _PITCH_type PITCH;
      typedef double _YAW_type;
      _YAW_type YAW;

    ImuData():
      ROLL(0),
      PITCH(0),
      YAW(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_ROLL;
      u_ROLL.real = this->ROLL;
      *(outbuffer + offset + 0) = (u_ROLL.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ROLL.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ROLL.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ROLL.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ROLL.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ROLL.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ROLL.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ROLL.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ROLL);
      union {
        double real;
        uint64_t base;
      } u_PITCH;
      u_PITCH.real = this->PITCH;
      *(outbuffer + offset + 0) = (u_PITCH.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_PITCH.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_PITCH.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_PITCH.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_PITCH.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_PITCH.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_PITCH.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_PITCH.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->PITCH);
      union {
        double real;
        uint64_t base;
      } u_YAW;
      u_YAW.real = this->YAW;
      *(outbuffer + offset + 0) = (u_YAW.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_YAW.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_YAW.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_YAW.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_YAW.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_YAW.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_YAW.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_YAW.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->YAW);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_ROLL;
      u_ROLL.base = 0;
      u_ROLL.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ROLL.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ROLL.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ROLL.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ROLL.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ROLL.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ROLL.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ROLL.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ROLL = u_ROLL.real;
      offset += sizeof(this->ROLL);
      union {
        double real;
        uint64_t base;
      } u_PITCH;
      u_PITCH.base = 0;
      u_PITCH.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_PITCH.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_PITCH.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_PITCH.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_PITCH.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_PITCH.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_PITCH.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_PITCH.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->PITCH = u_PITCH.real;
      offset += sizeof(this->PITCH);
      union {
        double real;
        uint64_t base;
      } u_YAW;
      u_YAW.base = 0;
      u_YAW.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_YAW.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_YAW.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_YAW.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_YAW.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_YAW.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_YAW.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_YAW.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->YAW = u_YAW.real;
      offset += sizeof(this->YAW);
     return offset;
    }

    virtual const char * getType() override { return "auv_msgs/ImuData"; };
    virtual const char * getMD5() override { return "5e410119c3186b5dbf9b94f595628907"; };

  };

}
#endif
