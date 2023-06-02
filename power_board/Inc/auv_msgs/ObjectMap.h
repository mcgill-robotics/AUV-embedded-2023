#ifndef _ROS_auv_msgs_ObjectMap_h
#define _ROS_auv_msgs_ObjectMap_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace auv_msgs
{

  class ObjectMap : public ros::Msg
  {
    public:
      uint32_t label_length;
      typedef int16_t _label_type;
      _label_type st_label;
      _label_type * label;
      uint32_t x_length;
      typedef double _x_type;
      _x_type st_x;
      _x_type * x;
      uint32_t y_length;
      typedef double _y_type;
      _y_type st_y;
      _y_type * y;
      uint32_t z_length;
      typedef double _z_type;
      _z_type st_z;
      _z_type * z;
      uint32_t theta_z_length;
      typedef double _theta_z_type;
      _theta_z_type st_theta_z;
      _theta_z_type * theta_z;
      uint32_t extra_field_length;
      typedef double _extra_field_type;
      _extra_field_type st_extra_field;
      _extra_field_type * extra_field;

    ObjectMap():
      label_length(0), st_label(), label(nullptr),
      x_length(0), st_x(), x(nullptr),
      y_length(0), st_y(), y(nullptr),
      z_length(0), st_z(), z(nullptr),
      theta_z_length(0), st_theta_z(), theta_z(nullptr),
      extra_field_length(0), st_extra_field(), extra_field(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->label_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->label_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->label_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->label_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->label_length);
      for( uint32_t i = 0; i < label_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_labeli;
      u_labeli.real = this->label[i];
      *(outbuffer + offset + 0) = (u_labeli.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_labeli.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->label[i]);
      }
      *(outbuffer + offset + 0) = (this->x_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->x_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->x_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->x_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_length);
      for( uint32_t i = 0; i < x_length; i++){
      union {
        double real;
        uint64_t base;
      } u_xi;
      u_xi.real = this->x[i];
      *(outbuffer + offset + 0) = (u_xi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_xi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_xi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_xi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_xi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x[i]);
      }
      *(outbuffer + offset + 0) = (this->y_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->y_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->y_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->y_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y_length);
      for( uint32_t i = 0; i < y_length; i++){
      union {
        double real;
        uint64_t base;
      } u_yi;
      u_yi.real = this->y[i];
      *(outbuffer + offset + 0) = (u_yi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_yi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_yi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_yi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_yi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y[i]);
      }
      *(outbuffer + offset + 0) = (this->z_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->z_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->z_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->z_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z_length);
      for( uint32_t i = 0; i < z_length; i++){
      union {
        double real;
        uint64_t base;
      } u_zi;
      u_zi.real = this->z[i];
      *(outbuffer + offset + 0) = (u_zi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_zi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_zi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_zi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_zi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->z[i]);
      }
      *(outbuffer + offset + 0) = (this->theta_z_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->theta_z_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->theta_z_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->theta_z_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->theta_z_length);
      for( uint32_t i = 0; i < theta_z_length; i++){
      union {
        double real;
        uint64_t base;
      } u_theta_zi;
      u_theta_zi.real = this->theta_z[i];
      *(outbuffer + offset + 0) = (u_theta_zi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_theta_zi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_theta_zi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_theta_zi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_theta_zi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_theta_zi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_theta_zi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_theta_zi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->theta_z[i]);
      }
      *(outbuffer + offset + 0) = (this->extra_field_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->extra_field_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->extra_field_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->extra_field_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->extra_field_length);
      for( uint32_t i = 0; i < extra_field_length; i++){
      union {
        double real;
        uint64_t base;
      } u_extra_fieldi;
      u_extra_fieldi.real = this->extra_field[i];
      *(outbuffer + offset + 0) = (u_extra_fieldi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_extra_fieldi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_extra_fieldi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_extra_fieldi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_extra_fieldi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_extra_fieldi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_extra_fieldi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_extra_fieldi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->extra_field[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t label_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      label_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      label_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      label_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->label_length);
      if(label_lengthT > label_length)
        this->label = (int16_t*)realloc(this->label, label_lengthT * sizeof(int16_t));
      label_length = label_lengthT;
      for( uint32_t i = 0; i < label_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_label;
      u_st_label.base = 0;
      u_st_label.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_label.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_label = u_st_label.real;
      offset += sizeof(this->st_label);
        memcpy( &(this->label[i]), &(this->st_label), sizeof(int16_t));
      }
      uint32_t x_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      x_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      x_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      x_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->x_length);
      if(x_lengthT > x_length)
        this->x = (double*)realloc(this->x, x_lengthT * sizeof(double));
      x_length = x_lengthT;
      for( uint32_t i = 0; i < x_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_x;
      u_st_x.base = 0;
      u_st_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_x = u_st_x.real;
      offset += sizeof(this->st_x);
        memcpy( &(this->x[i]), &(this->st_x), sizeof(double));
      }
      uint32_t y_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      y_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      y_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      y_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->y_length);
      if(y_lengthT > y_length)
        this->y = (double*)realloc(this->y, y_lengthT * sizeof(double));
      y_length = y_lengthT;
      for( uint32_t i = 0; i < y_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_y;
      u_st_y.base = 0;
      u_st_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_y = u_st_y.real;
      offset += sizeof(this->st_y);
        memcpy( &(this->y[i]), &(this->st_y), sizeof(double));
      }
      uint32_t z_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      z_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      z_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      z_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->z_length);
      if(z_lengthT > z_length)
        this->z = (double*)realloc(this->z, z_lengthT * sizeof(double));
      z_length = z_lengthT;
      for( uint32_t i = 0; i < z_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_z;
      u_st_z.base = 0;
      u_st_z.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_z.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_z.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_z.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_z.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_z.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_z.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_z.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_z = u_st_z.real;
      offset += sizeof(this->st_z);
        memcpy( &(this->z[i]), &(this->st_z), sizeof(double));
      }
      uint32_t theta_z_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      theta_z_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      theta_z_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      theta_z_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->theta_z_length);
      if(theta_z_lengthT > theta_z_length)
        this->theta_z = (double*)realloc(this->theta_z, theta_z_lengthT * sizeof(double));
      theta_z_length = theta_z_lengthT;
      for( uint32_t i = 0; i < theta_z_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_theta_z;
      u_st_theta_z.base = 0;
      u_st_theta_z.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_theta_z.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_theta_z.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_theta_z.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_theta_z.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_theta_z.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_theta_z.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_theta_z.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_theta_z = u_st_theta_z.real;
      offset += sizeof(this->st_theta_z);
        memcpy( &(this->theta_z[i]), &(this->st_theta_z), sizeof(double));
      }
      uint32_t extra_field_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      extra_field_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      extra_field_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      extra_field_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->extra_field_length);
      if(extra_field_lengthT > extra_field_length)
        this->extra_field = (double*)realloc(this->extra_field, extra_field_lengthT * sizeof(double));
      extra_field_length = extra_field_lengthT;
      for( uint32_t i = 0; i < extra_field_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_extra_field;
      u_st_extra_field.base = 0;
      u_st_extra_field.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_extra_field.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_extra_field.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_extra_field.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_extra_field.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_extra_field.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_extra_field.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_extra_field.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_extra_field = u_st_extra_field.real;
      offset += sizeof(this->st_extra_field);
        memcpy( &(this->extra_field[i]), &(this->st_extra_field), sizeof(double));
      }
     return offset;
    }

    virtual const char * getType() override { return "auv_msgs/ObjectMap"; };
    virtual const char * getMD5() override { return "9cfcd3759ce72620012a89bb3f99fc09"; };

  };

}
#endif
