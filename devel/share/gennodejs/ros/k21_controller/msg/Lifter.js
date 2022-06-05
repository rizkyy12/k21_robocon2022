// Auto-generated. Do not edit!

// (in-package k21_controller.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Lifter {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.lifter_point = null;
      this.gripper = null;
    }
    else {
      if (initObj.hasOwnProperty('lifter_point')) {
        this.lifter_point = initObj.lifter_point
      }
      else {
        this.lifter_point = 0.0;
      }
      if (initObj.hasOwnProperty('gripper')) {
        this.gripper = initObj.gripper
      }
      else {
        this.gripper = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Lifter
    // Serialize message field [lifter_point]
    bufferOffset = _serializer.float64(obj.lifter_point, buffer, bufferOffset);
    // Serialize message field [gripper]
    bufferOffset = _serializer.float64(obj.gripper, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Lifter
    let len;
    let data = new Lifter(null);
    // Deserialize message field [lifter_point]
    data.lifter_point = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [gripper]
    data.gripper = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'k21_controller/Lifter';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4a3137a64e8cabd06e461b82358bf017';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 lifter_point
    float64 gripper
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Lifter(null);
    if (msg.lifter_point !== undefined) {
      resolved.lifter_point = msg.lifter_point;
    }
    else {
      resolved.lifter_point = 0.0
    }

    if (msg.gripper !== undefined) {
      resolved.gripper = msg.gripper;
    }
    else {
      resolved.gripper = 0.0
    }

    return resolved;
    }
};

module.exports = Lifter;
