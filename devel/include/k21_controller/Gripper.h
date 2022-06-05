// Generated by gencpp from file k21_controller/Gripper.msg
// DO NOT EDIT!


#ifndef K21_CONTROLLER_MESSAGE_GRIPPER_H
#define K21_CONTROLLER_MESSAGE_GRIPPER_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace k21_controller
{
template <class ContainerAllocator>
struct Gripper_
{
  typedef Gripper_<ContainerAllocator> Type;

  Gripper_()
    : gripper(0.0)  {
    }
  Gripper_(const ContainerAllocator& _alloc)
    : gripper(0.0)  {
  (void)_alloc;
    }



   typedef double _gripper_type;
  _gripper_type gripper;





  typedef boost::shared_ptr< ::k21_controller::Gripper_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::k21_controller::Gripper_<ContainerAllocator> const> ConstPtr;

}; // struct Gripper_

typedef ::k21_controller::Gripper_<std::allocator<void> > Gripper;

typedef boost::shared_ptr< ::k21_controller::Gripper > GripperPtr;
typedef boost::shared_ptr< ::k21_controller::Gripper const> GripperConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::k21_controller::Gripper_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::k21_controller::Gripper_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::k21_controller::Gripper_<ContainerAllocator1> & lhs, const ::k21_controller::Gripper_<ContainerAllocator2> & rhs)
{
  return lhs.gripper == rhs.gripper;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::k21_controller::Gripper_<ContainerAllocator1> & lhs, const ::k21_controller::Gripper_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace k21_controller

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::k21_controller::Gripper_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::k21_controller::Gripper_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::k21_controller::Gripper_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::k21_controller::Gripper_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::k21_controller::Gripper_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::k21_controller::Gripper_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::k21_controller::Gripper_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7f719c6cfe1d2043c07be67576fd364e";
  }

  static const char* value(const ::k21_controller::Gripper_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7f719c6cfe1d2043ULL;
  static const uint64_t static_value2 = 0xc07be67576fd364eULL;
};

template<class ContainerAllocator>
struct DataType< ::k21_controller::Gripper_<ContainerAllocator> >
{
  static const char* value()
  {
    return "k21_controller/Gripper";
  }

  static const char* value(const ::k21_controller::Gripper_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::k21_controller::Gripper_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 gripper\n"
;
  }

  static const char* value(const ::k21_controller::Gripper_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::k21_controller::Gripper_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.gripper);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Gripper_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::k21_controller::Gripper_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::k21_controller::Gripper_<ContainerAllocator>& v)
  {
    s << indent << "gripper: ";
    Printer<double>::stream(s, indent + "  ", v.gripper);
  }
};

} // namespace message_operations
} // namespace ros

#endif // K21_CONTROLLER_MESSAGE_GRIPPER_H