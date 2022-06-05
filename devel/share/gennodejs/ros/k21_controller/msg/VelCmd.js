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

class VelCmd {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Vx = null;
      this.Vy = null;
      this.w = null;
    }
    else {
      if (initObj.hasOwnProperty('Vx')) {
        this.Vx = initObj.Vx
      }
      else {
        this.Vx = 0.0;
      }
      if (initObj.hasOwnProperty('Vy')) {
        this.Vy = initObj.Vy
      }
      else {
        this.Vy = 0.0;
      }
      if (initObj.hasOwnProperty('w')) {
        this.w = initObj.w
      }
      else {
        this.w = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type VelCmd
    // Serialize message field [Vx]
    bufferOffset = _serializer.float64(obj.Vx, buffer, bufferOffset);
    // Serialize message field [Vy]
    bufferOffset = _serializer.float64(obj.Vy, buffer, bufferOffset);
    // Serialize message field [w]
    bufferOffset = _serializer.float64(obj.w, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type VelCmd
    let len;
    let data = new VelCmd(null);
    // Deserialize message field [Vx]
    data.Vx = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Vy]
    data.Vy = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [w]
    data.w = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'k21_controller/VelCmd';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'dc80fc0c33bfc67846d488513b7c90a4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 Vx
    float64 Vy
    float64 w
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new VelCmd(null);
    if (msg.Vx !== undefined) {
      resolved.Vx = msg.Vx;
    }
    else {
      resolved.Vx = 0.0
    }

    if (msg.Vy !== undefined) {
      resolved.Vy = msg.Vy;
    }
    else {
      resolved.Vy = 0.0
    }

    if (msg.w !== undefined) {
      resolved.w = msg.w;
    }
    else {
      resolved.w = 0.0
    }

    return resolved;
    }
};

module.exports = VelCmd;
