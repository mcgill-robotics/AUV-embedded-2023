#ifndef _ROS_auv_msgs_DvlData_h
#define _ROS_auv_msgs_DvlData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace auv_msgs
{

  class DvlData : public ros::Msg
  {
    public:
      typedef double _depth_type;
      _depth_type depth;
      typedef double _temperature_type;
      _temperature_type temperature;
      typedef double _salinity_type;
      _salinity_type salinity;
      typedef double _roll_type;
      _roll_type roll;
      typedef double _pitch_type;
      _pitch_type pitch;
      typedef double _heading_type;
      _heading_type heading;
      typedef double _north_displacement_type;
      _north_displacement_type north_displacement;
      typedef double _east_displacement_type;
      _east_displacement_type east_displacement;
      typedef double _upward_displacement_type;
      _upward_displacement_type upward_displacement;
      typedef double _range_to_bottom_type;
      _range_to_bottom_type range_to_bottom;
      typedef double _time_since_good_type;
      _time_since_good_type time_since_good;
      typedef double _north_velocity_type;
      _north_velocity_type north_velocity;
      typedef double _east_velocity_type;
      _east_velocity_type east_velocity;
      typedef double _upward_velocity_type;
      _upward_velocity_type upward_velocity;
      typedef bool _velocity_valid_type;
      _velocity_valid_type velocity_valid;

    DvlData():
      depth(0),
      temperature(0),
      salinity(0),
      roll(0),
      pitch(0),
      heading(0),
      north_displacement(0),
      east_displacement(0),
      upward_displacement(0),
      range_to_bottom(0),
      time_since_good(0),
      north_velocity(0),
      east_velocity(0),
      upward_velocity(0),
      velocity_valid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_depth;
      u_depth.real = this->depth;
      *(outbuffer + offset + 0) = (u_depth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_depth.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_depth.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_depth.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_depth.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_depth.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_depth.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_depth.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->depth);
      union {
        double real;
        uint64_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_temperature.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_temperature.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_temperature.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_temperature.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->temperature);
      union {
        double real;
        uint64_t base;
      } u_salinity;
      u_salinity.real = this->salinity;
      *(outbuffer + offset + 0) = (u_salinity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_salinity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_salinity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_salinity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_salinity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_salinity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_salinity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_salinity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->salinity);
      union {
        double real;
        uint64_t base;
      } u_roll;
      u_roll.real = this->roll;
      *(outbuffer + offset + 0) = (u_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roll.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roll.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_roll.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_roll.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_roll.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_roll.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->roll);
      union {
        double real;
        uint64_t base;
      } u_pitch;
      u_pitch.real = this->pitch;
      *(outbuffer + offset + 0) = (u_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pitch.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pitch.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pitch.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pitch.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pitch);
      union {
        double real;
        uint64_t base;
      } u_heading;
      u_heading.real = this->heading;
      *(outbuffer + offset + 0) = (u_heading.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heading.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heading.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heading.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_heading.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_heading.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_heading.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_heading.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->heading);
      union {
        double real;
        uint64_t base;
      } u_north_displacement;
      u_north_displacement.real = this->north_displacement;
      *(outbuffer + offset + 0) = (u_north_displacement.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_north_displacement.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_north_displacement.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_north_displacement.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_north_displacement.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_north_displacement.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_north_displacement.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_north_displacement.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->north_displacement);
      union {
        double real;
        uint64_t base;
      } u_east_displacement;
      u_east_displacement.real = this->east_displacement;
      *(outbuffer + offset + 0) = (u_east_displacement.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_east_displacement.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_east_displacement.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_east_displacement.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_east_displacement.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_east_displacement.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_east_displacement.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_east_displacement.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->east_displacement);
      union {
        double real;
        uint64_t base;
      } u_upward_displacement;
      u_upward_displacement.real = this->upward_displacement;
      *(outbuffer + offset + 0) = (u_upward_displacement.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_upward_displacement.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_upward_displacement.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_upward_displacement.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_upward_displacement.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_upward_displacement.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_upward_displacement.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_upward_displacement.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->upward_displacement);
      union {
        double real;
        uint64_t base;
      } u_range_to_bottom;
      u_range_to_bottom.real = this->range_to_bottom;
      *(outbuffer + offset + 0) = (u_range_to_bottom.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range_to_bottom.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range_to_bottom.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range_to_bottom.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_range_to_bottom.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_range_to_bottom.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_range_to_bottom.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_range_to_bottom.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->range_to_bottom);
      union {
        double real;
        uint64_t base;
      } u_time_since_good;
      u_time_since_good.real = this->time_since_good;
      *(outbuffer + offset + 0) = (u_time_since_good.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time_since_good.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time_since_good.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time_since_good.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_time_since_good.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_time_since_good.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_time_since_good.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_time_since_good.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->time_since_good);
      union {
        double real;
        uint64_t base;
      } u_north_velocity;
      u_north_velocity.real = this->north_velocity;
      *(outbuffer + offset + 0) = (u_north_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_north_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_north_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_north_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_north_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_north_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_north_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_north_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->north_velocity);
      union {
        double real;
        uint64_t base;
      } u_east_velocity;
      u_east_velocity.real = this->east_velocity;
      *(outbuffer + offset + 0) = (u_east_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_east_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_east_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_east_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_east_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_east_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_east_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_east_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->east_velocity);
      union {
        double real;
        uint64_t base;
      } u_upward_velocity;
      u_upward_velocity.real = this->upward_velocity;
      *(outbuffer + offset + 0) = (u_upward_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_upward_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_upward_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_upward_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_upward_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_upward_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_upward_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_upward_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->upward_velocity);
      union {
        bool real;
        uint8_t base;
      } u_velocity_valid;
      u_velocity_valid.real = this->velocity_valid;
      *(outbuffer + offset + 0) = (u_velocity_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->velocity_valid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_depth;
      u_depth.base = 0;
      u_depth.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_depth.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_depth.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_depth.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_depth.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_depth.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_depth.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_depth.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->depth = u_depth.real;
      offset += sizeof(this->depth);
      union {
        double real;
        uint64_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
      union {
        double real;
        uint64_t base;
      } u_salinity;
      u_salinity.base = 0;
      u_salinity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_salinity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_salinity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_salinity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_salinity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_salinity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_salinity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_salinity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->salinity = u_salinity.real;
      offset += sizeof(this->salinity);
      union {
        double real;
        uint64_t base;
      } u_roll;
      u_roll.base = 0;
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->roll = u_roll.real;
      offset += sizeof(this->roll);
      union {
        double real;
        uint64_t base;
      } u_pitch;
      u_pitch.base = 0;
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pitch = u_pitch.real;
      offset += sizeof(this->pitch);
      union {
        double real;
        uint64_t base;
      } u_heading;
      u_heading.base = 0;
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->heading = u_heading.real;
      offset += sizeof(this->heading);
      union {
        double real;
        uint64_t base;
      } u_north_displacement;
      u_north_displacement.base = 0;
      u_north_displacement.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_north_displacement.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_north_displacement.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_north_displacement.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_north_displacement.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_north_displacement.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_north_displacement.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_north_displacement.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->north_displacement = u_north_displacement.real;
      offset += sizeof(this->north_displacement);
      union {
        double real;
        uint64_t base;
      } u_east_displacement;
      u_east_displacement.base = 0;
      u_east_displacement.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_east_displacement.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_east_displacement.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_east_displacement.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_east_displacement.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_east_displacement.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_east_displacement.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_east_displacement.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->east_displacement = u_east_displacement.real;
      offset += sizeof(this->east_displacement);
      union {
        double real;
        uint64_t base;
      } u_upward_displacement;
      u_upward_displacement.base = 0;
      u_upward_displacement.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_upward_displacement.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_upward_displacement.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_upward_displacement.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_upward_displacement.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_upward_displacement.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_upward_displacement.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_upward_displacement.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->upward_displacement = u_upward_displacement.real;
      offset += sizeof(this->upward_displacement);
      union {
        double real;
        uint64_t base;
      } u_range_to_bottom;
      u_range_to_bottom.base = 0;
      u_range_to_bottom.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range_to_bottom.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range_to_bottom.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range_to_bottom.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_range_to_bottom.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_range_to_bottom.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_range_to_bottom.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_range_to_bottom.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->range_to_bottom = u_range_to_bottom.real;
      offset += sizeof(this->range_to_bottom);
      union {
        double real;
        uint64_t base;
      } u_time_since_good;
      u_time_since_good.base = 0;
      u_time_since_good.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time_since_good.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time_since_good.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time_since_good.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_time_since_good.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_time_since_good.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_time_since_good.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_time_since_good.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->time_since_good = u_time_since_good.real;
      offset += sizeof(this->time_since_good);
      union {
        double real;
        uint64_t base;
      } u_north_velocity;
      u_north_velocity.base = 0;
      u_north_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_north_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_north_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_north_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_north_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_north_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_north_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_north_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->north_velocity = u_north_velocity.real;
      offset += sizeof(this->north_velocity);
      union {
        double real;
        uint64_t base;
      } u_east_velocity;
      u_east_velocity.base = 0;
      u_east_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_east_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_east_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_east_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_east_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_east_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_east_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_east_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->east_velocity = u_east_velocity.real;
      offset += sizeof(this->east_velocity);
      union {
        double real;
        uint64_t base;
      } u_upward_velocity;
      u_upward_velocity.base = 0;
      u_upward_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_upward_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_upward_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_upward_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_upward_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_upward_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_upward_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_upward_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->upward_velocity = u_upward_velocity.real;
      offset += sizeof(this->upward_velocity);
      union {
        bool real;
        uint8_t base;
      } u_velocity_valid;
      u_velocity_valid.base = 0;
      u_velocity_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->velocity_valid = u_velocity_valid.real;
      offset += sizeof(this->velocity_valid);
     return offset;
    }

    virtual const char * getType() override { return "auv_msgs/DvlData"; };
    virtual const char * getMD5() override { return "150f1870934f0e69ae70c72ee7accf78"; };

  };

}
#endif
