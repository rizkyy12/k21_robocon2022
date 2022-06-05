; Auto-generated. Do not edit!


(cl:in-package k21_controller-msg)


;//! \htmlinclude Lifter.msg.html

(cl:defclass <Lifter> (roslisp-msg-protocol:ros-message)
  ((lifter_point
    :reader lifter_point
    :initarg :lifter_point
    :type cl:float
    :initform 0.0)
   (gripper
    :reader gripper
    :initarg :gripper
    :type cl:float
    :initform 0.0))
)

(cl:defclass Lifter (<Lifter>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Lifter>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Lifter)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name k21_controller-msg:<Lifter> is deprecated: use k21_controller-msg:Lifter instead.")))

(cl:ensure-generic-function 'lifter_point-val :lambda-list '(m))
(cl:defmethod lifter_point-val ((m <Lifter>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader k21_controller-msg:lifter_point-val is deprecated.  Use k21_controller-msg:lifter_point instead.")
  (lifter_point m))

(cl:ensure-generic-function 'gripper-val :lambda-list '(m))
(cl:defmethod gripper-val ((m <Lifter>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader k21_controller-msg:gripper-val is deprecated.  Use k21_controller-msg:gripper instead.")
  (gripper m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Lifter>) ostream)
  "Serializes a message object of type '<Lifter>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'lifter_point))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Lifter>) istream)
  "Deserializes a message object of type '<Lifter>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lifter_point) (roslisp-utils:decode-double-float-bits bits)))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Lifter>)))
  "Returns string type for a message object of type '<Lifter>"
  "k21_controller/Lifter")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Lifter)))
  "Returns string type for a message object of type 'Lifter"
  "k21_controller/Lifter")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Lifter>)))
  "Returns md5sum for a message object of type '<Lifter>"
  "4a3137a64e8cabd06e461b82358bf017")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Lifter)))
  "Returns md5sum for a message object of type 'Lifter"
  "4a3137a64e8cabd06e461b82358bf017")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Lifter>)))
  "Returns full string definition for message of type '<Lifter>"
  (cl:format cl:nil "float64 lifter_point~%float64 gripper~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Lifter)))
  "Returns full string definition for message of type 'Lifter"
  (cl:format cl:nil "float64 lifter_point~%float64 gripper~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Lifter>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Lifter>))
  "Converts a ROS message object to a list"
  (cl:list 'Lifter
    (cl:cons ':lifter_point (lifter_point msg))
    (cl:cons ':gripper (gripper msg))
))
