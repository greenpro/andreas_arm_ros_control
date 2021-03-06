// Generated by gencpp from file andreas_arm_drivers/motor_driver.msg
// DO NOT EDIT!


#ifndef ANDREAS_ARM_DRIVERS_MESSAGE_MOTOR_DRIVER_H
#define ANDREAS_ARM_DRIVERS_MESSAGE_MOTOR_DRIVER_H

#include <ros/service_traits.h>


#include <andreas_arm_drivers/motor_driverRequest.h>
#include <andreas_arm_drivers/motor_driverResponse.h>


namespace andreas_arm_drivers
{

struct motor_driver
{

typedef motor_driverRequest Request;
typedef motor_driverResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct motor_driver
} // namespace andreas_arm_drivers


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::andreas_arm_drivers::motor_driver > {
  static const char* value()
  {
    return "0883465462bd27ab262ea978b1ed9e7b";
  }

  static const char* value(const ::andreas_arm_drivers::motor_driver&) { return value(); }
};

template<>
struct DataType< ::andreas_arm_drivers::motor_driver > {
  static const char* value()
  {
    return "andreas_arm_drivers/motor_driver";
  }

  static const char* value(const ::andreas_arm_drivers::motor_driver&) { return value(); }
};


// service_traits::MD5Sum< ::andreas_arm_drivers::motor_driverRequest> should match 
// service_traits::MD5Sum< ::andreas_arm_drivers::motor_driver > 
template<>
struct MD5Sum< ::andreas_arm_drivers::motor_driverRequest>
{
  static const char* value()
  {
    return MD5Sum< ::andreas_arm_drivers::motor_driver >::value();
  }
  static const char* value(const ::andreas_arm_drivers::motor_driverRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::andreas_arm_drivers::motor_driverRequest> should match 
// service_traits::DataType< ::andreas_arm_drivers::motor_driver > 
template<>
struct DataType< ::andreas_arm_drivers::motor_driverRequest>
{
  static const char* value()
  {
    return DataType< ::andreas_arm_drivers::motor_driver >::value();
  }
  static const char* value(const ::andreas_arm_drivers::motor_driverRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::andreas_arm_drivers::motor_driverResponse> should match 
// service_traits::MD5Sum< ::andreas_arm_drivers::motor_driver > 
template<>
struct MD5Sum< ::andreas_arm_drivers::motor_driverResponse>
{
  static const char* value()
  {
    return MD5Sum< ::andreas_arm_drivers::motor_driver >::value();
  }
  static const char* value(const ::andreas_arm_drivers::motor_driverResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::andreas_arm_drivers::motor_driverResponse> should match 
// service_traits::DataType< ::andreas_arm_drivers::motor_driver > 
template<>
struct DataType< ::andreas_arm_drivers::motor_driverResponse>
{
  static const char* value()
  {
    return DataType< ::andreas_arm_drivers::motor_driver >::value();
  }
  static const char* value(const ::andreas_arm_drivers::motor_driverResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ANDREAS_ARM_DRIVERS_MESSAGE_MOTOR_DRIVER_H
