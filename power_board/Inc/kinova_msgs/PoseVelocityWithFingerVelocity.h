#ifndef _ROS_kinova_msgs_PoseVelocityWithFingerVelocity_h
#define _ROS_kinova_msgs_PoseVelocityWithFingerVelocity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace kinova_msgs
{

  class PoseVelocityWithFingerVelocity : public ros::Msg
  {
    public:
      typedef float _twist_linear_x_type;
      _twist_linear_x_type twist_linear_x;
      typedef float _twist_linear_y_type;
      _twist_linear_y_type twist_linear_y;
      typedef float _twist_linear_z_type;
      _twist_linear_z_type twist_linear_z;
      typedef float _twist_angular_x_type;
      _twist_angular_x_type twist_angular_x;
      typedef float _twist_angular_y_type;
      _twist_angular_y_type twist_angular_y;
      typedef float _twist_angular_z_type;
      _twist_angular_z_type twist_angular_z;
      typedef float _finger1_type;
      _finger1_type finger1;
      typedef float _finger2_type;
      _finger2_type finger2;
      typedef float _finger3_type;
      _finger3_type finger3;

    PoseVelocityWithFingerVelocity():
      twist_linear_x(0),
      twist_linear_y(0),
      twist_linear_z(0),
      twist_angular_x(0),
      twist_angular_y(0),
      twist_angular_z(0),
      finger1(0),
      finger2(0),
      finger3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_twist_linear_x;
      u_twist_linear_x.real = this->twist_linear_x;
      *(outbuffer + offset + 0) = (u_twist_linear_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_twist_linear_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_twist_linear_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_twist_linear_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->twist_linear_x);
      union {
        float real;
        uint32_t base;
      } u_twist_linear_y;
      u_twist_linear_y.real = this->twist_linear_y;
      *(outbuffer + offset + 0) = (u_twist_linear_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_twist_linear_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_twist_linear_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_twist_linear_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->twist_linear_y);
      union {
        float real;
        uint32_t base;
      } u_twist_linear_z;
      u_twist_linear_z.real = this->twist_linear_z;
      *(outbuffer + offset + 0) = (u_twist_linear_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_twist_linear_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_twist_linear_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_twist_linear_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->twist_linear_z);
      union {
        float real;
        uint32_t base;
      } u_twist_angular_x;
      u_twist_angular_x.real = this->twist_angular_x;
      *(outbuffer + offset + 0) = (u_twist_angular_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_twist_angular_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_twist_angular_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_twist_angular_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->twist_angular_x);
      union {
        float real;
        uint32_t base;
      } u_twist_angular_y;
      u_twist_angular_y.real = this->twist_angular_y;
      *(outbuffer + offset + 0) = (u_twist_angular_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_twist_angular_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_twist_angular_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_twist_angular_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->twist_angular_y);
      union {
        float real;
        uint32_t base;
      } u_twist_angular_z;
      u_twist_angular_z.real = this->twist_angular_z;
      *(outbuffer + offset + 0) = (u_twist_angular_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_twist_angular_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_twist_angular_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_twist_angular_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->twist_angular_z);
      union {
        float real;
        uint32_t base;
      } u_finger1;
      u_finger1.real = this->finger1;
      *(outbuffer + offset + 0) = (u_finger1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_finger1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_finger1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_finger1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->finger1);
      union {
        float real;
        uint32_t base;
      } u_finger2;
      u_finger2.real = this->finger2;
      *(outbuffer + offset + 0) = (u_finger2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_finger2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_finger2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_finger2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->finger2);
      union {
        float real;
        uint32_t base;
      } u_finger3;
      u_finger3.real = this->finger3;
      *(outbuffer + offset + 0) = (u_finger3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_finger3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_finger3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_finger3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->finger3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_twist_linear_x;
      u_twist_linear_x.base = 0;
      u_twist_linear_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_twist_linear_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_twist_linear_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_twist_linear_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->twist_linear_x = u_twist_linear_x.real;
      offset += sizeof(this->twist_linear_x);
      union {
        float real;
        uint32_t base;
      } u_twist_linear_y;
      u_twist_linear_y.base = 0;
      u_twist_linear_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_twist_linear_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_twist_linear_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_twist_linear_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->twist_linear_y = u_twist_linear_y.real;
      offset += sizeof(this->twist_linear_y);
      union {
        float real;
        uint32_t base;
      } u_twist_linear_z;
      u_twist_linear_z.base = 0;
      u_twist_linear_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_twist_linear_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_twist_linear_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_twist_linear_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->twist_linear_z = u_twist_linear_z.real;
      offset += sizeof(this->twist_linear_z);
      union {
        float real;
        uint32_t base;
      } u_twist_angular_x;
      u_twist_angular_x.base = 0;
      u_twist_angular_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_twist_angular_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_twist_angular_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_twist_angular_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->twist_angular_x = u_twist_angular_x.real;
      offset += sizeof(this->twist_angular_x);
      union {
        float real;
        uint32_t base;
      } u_twist_angular_y;
      u_twist_angular_y.base = 0;
      u_twist_angular_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_twist_angular_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_twist_angular_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_twist_angular_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->twist_angular_y = u_twist_angular_y.real;
      offset += sizeof(this->twist_angular_y);
      union {
        float real;
        uint32_t base;
      } u_twist_angular_z;
      u_twist_angular_z.base = 0;
      u_twist_angular_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_twist_angular_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_twist_angular_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_twist_angular_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->twist_angular_z = u_twist_angular_z.real;
      offset += sizeof(this->twist_angular_z);
      union {
        float real;
        uint32_t base;
      } u_finger1;
      u_finger1.base = 0;
      u_finger1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_finger1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_finger1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_finger1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->finger1 = u_finger1.real;
      offset += sizeof(this->finger1);
      union {
        float real;
        uint32_t base;
      } u_finger2;
      u_finger2.base = 0;
      u_finger2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_finger2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_finger2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_finger2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->finger2 = u_finger2.real;
      offset += sizeof(this->finger2);
      union {
        float real;
        uint32_t base;
      } u_finger3;
      u_finger3.base = 0;
      u_finger3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_finger3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_finger3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_finger3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->finger3 = u_finger3.real;
      offset += sizeof(this->finger3);
     return offset;
    }

    virtual const char * getType() override { return "kinova_msgs/PoseVelocityWithFingerVelocity"; };
    virtual const char * getMD5() override { return "d8789bad3911d8a482fde371a6b8abac"; };

  };

}
#endif
