#ifndef _ROS_sbg_driver_SbgEkfNav_h
#define _ROS_sbg_driver_SbgEkfNav_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"
#include "sbg_driver/SbgEkfStatus.h"

namespace sbg_driver
{

  class SbgEkfNav : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _time_stamp_type;
      _time_stamp_type time_stamp;
      typedef geometry_msgs::Vector3 _velocity_type;
      _velocity_type velocity;
      typedef geometry_msgs::Vector3 _velocity_accuracy_type;
      _velocity_accuracy_type velocity_accuracy;
      typedef double _latitude_type;
      _latitude_type latitude;
      typedef double _longitude_type;
      _longitude_type longitude;
      typedef double _altitude_type;
      _altitude_type altitude;
      typedef float _undulation_type;
      _undulation_type undulation;
      typedef geometry_msgs::Vector3 _position_accuracy_type;
      _position_accuracy_type position_accuracy;
      typedef sbg_driver::SbgEkfStatus _status_type;
      _status_type status;

    SbgEkfNav():
      header(),
      time_stamp(0),
      velocity(),
      velocity_accuracy(),
      latitude(0),
      longitude(0),
      altitude(0),
      undulation(0),
      position_accuracy(),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->time_stamp >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_stamp >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_stamp >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_stamp >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_stamp);
      offset += this->velocity.serialize(outbuffer + offset);
      offset += this->velocity_accuracy.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_latitude;
      u_latitude.real = this->latitude;
      *(outbuffer + offset + 0) = (u_latitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_latitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_latitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_latitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_latitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->latitude);
      union {
        double real;
        uint64_t base;
      } u_longitude;
      u_longitude.real = this->longitude;
      *(outbuffer + offset + 0) = (u_longitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_longitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_longitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_longitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_longitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->longitude);
      union {
        double real;
        uint64_t base;
      } u_altitude;
      u_altitude.real = this->altitude;
      *(outbuffer + offset + 0) = (u_altitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_altitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_altitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_altitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_altitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_undulation;
      u_undulation.real = this->undulation;
      *(outbuffer + offset + 0) = (u_undulation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_undulation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_undulation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_undulation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->undulation);
      offset += this->position_accuracy.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->time_stamp =  ((uint32_t) (*(inbuffer + offset)));
      this->time_stamp |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_stamp |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_stamp |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_stamp);
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += this->velocity_accuracy.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_latitude;
      u_latitude.base = 0;
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->latitude = u_latitude.real;
      offset += sizeof(this->latitude);
      union {
        double real;
        uint64_t base;
      } u_longitude;
      u_longitude.base = 0;
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->longitude = u_longitude.real;
      offset += sizeof(this->longitude);
      union {
        double real;
        uint64_t base;
      } u_altitude;
      u_altitude.base = 0;
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->altitude = u_altitude.real;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_undulation;
      u_undulation.base = 0;
      u_undulation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_undulation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_undulation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_undulation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->undulation = u_undulation.real;
      offset += sizeof(this->undulation);
      offset += this->position_accuracy.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "sbg_driver/SbgEkfNav"; };
    virtual const char * getMD5() override { return "16e5ed53c5544dda563fc67fb816d9b9"; };

  };

}
#endif
