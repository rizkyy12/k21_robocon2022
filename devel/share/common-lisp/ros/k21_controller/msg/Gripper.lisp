; Auto-generated. Do not edit!


(cl:in-package k21_controller-msg)


;//! \htmlinclude Gripper.msg.html

(cl:defclass <Gripper> (roslisp-msg-protocol:ros-message)
  ((gripper
    :reader gripper
    :initarg :gripper
    :type cl:float
    :initform 0.0))
)

(cl:defclass Gripper (<Gripper>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Gripper>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Gripper)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name k21_controller-msg:<Gripper> is deprecated: use k21_controller-msg:Gripper instead.")))

(cl:ensure-generic-function 'gripper-val :lambda-list '(m))
(cl:defmethod gripper-val ((m <Gripper>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader k21_controller-msg:gripper-val is deprecated.  Use k21_controller-msg:gripper instead.")
  (gripper m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Gripper>) ostream)
  "Serializes a message object of type '<Gripper>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'gripper))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Gripper>) istream)
  "Deserializes a message object of type '<Gripper>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'gripper) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Gripper>)))
  "Returns string type for a message object of type '<Gripper>"
  "k21_controller/Gripper")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Gripper)))
  "Returns string type for a message object of type 'Gripper"
  "k21_controller/Gripper")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Gripper>)))
  "Returns md5sum for a message object of type '<Gripper>"
  "7f719c6cfe1d2043c07be67576fd364e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Gripper)))
  "Returns md5sum for a message object of type 'Gripper"
  "7f719c6cfe1d2043c07be67576fd364e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Gripper>)))
  "Returns full string definition for message of type '<Gripper>"
  (cl:format cl:nil "float64 gripper~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Gripper)))
  "Returns full string definition for message of type 'Gripper"
  (cl:format cl:nil "float64 gripper~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Gripper>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Gripper>))
  "Converts a ROS message object to a list"
  (cl:list 'Gripper
    (cl:cons ':gripper (gripper msg))
))
