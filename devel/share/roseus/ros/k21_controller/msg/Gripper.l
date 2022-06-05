;; Auto-generated. Do not edit!


(when (boundp 'k21_controller::Gripper)
  (if (not (find-package "K21_CONTROLLER"))
    (make-package "K21_CONTROLLER"))
  (shadow 'Gripper (find-package "K21_CONTROLLER")))
(unless (find-package "K21_CONTROLLER::GRIPPER")
  (make-package "K21_CONTROLLER::GRIPPER"))

(in-package "ROS")
;;//! \htmlinclude Gripper.msg.html


(defclass k21_controller::Gripper
  :super ros::object
  :slots (_gripper ))

(defmethod k21_controller::Gripper
  (:init
   (&key
    ((:gripper __gripper) 0.0)
    )
   (send-super :init)
   (setq _gripper (float __gripper))
   self)
  (:gripper
   (&optional __gripper)
   (if __gripper (setq _gripper __gripper)) _gripper)
  (:serialization-length
   ()
   (+
    ;; float64 _gripper
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _gripper
       (sys::poke _gripper (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _gripper
     (setq _gripper (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get k21_controller::Gripper :md5sum-) "7f719c6cfe1d2043c07be67576fd364e")
(setf (get k21_controller::Gripper :datatype-) "k21_controller/Gripper")
(setf (get k21_controller::Gripper :definition-)
      "float64 gripper
")



(provide :k21_controller/Gripper "7f719c6cfe1d2043c07be67576fd364e")


