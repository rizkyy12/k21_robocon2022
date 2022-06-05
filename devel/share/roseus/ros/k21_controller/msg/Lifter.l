;; Auto-generated. Do not edit!


(when (boundp 'k21_controller::Lifter)
  (if (not (find-package "K21_CONTROLLER"))
    (make-package "K21_CONTROLLER"))
  (shadow 'Lifter (find-package "K21_CONTROLLER")))
(unless (find-package "K21_CONTROLLER::LIFTER")
  (make-package "K21_CONTROLLER::LIFTER"))

(in-package "ROS")
;;//! \htmlinclude Lifter.msg.html


(defclass k21_controller::Lifter
  :super ros::object
  :slots (_lifter_point _gripper ))

(defmethod k21_controller::Lifter
  (:init
   (&key
    ((:lifter_point __lifter_point) 0.0)
    ((:gripper __gripper) 0.0)
    )
   (send-super :init)
   (setq _lifter_point (float __lifter_point))
   (setq _gripper (float __gripper))
   self)
  (:lifter_point
   (&optional __lifter_point)
   (if __lifter_point (setq _lifter_point __lifter_point)) _lifter_point)
  (:gripper
   (&optional __gripper)
   (if __gripper (setq _gripper __gripper)) _gripper)
  (:serialization-length
   ()
   (+
    ;; float64 _lifter_point
    8
    ;; float64 _gripper
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _lifter_point
       (sys::poke _lifter_point (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _gripper
       (sys::poke _gripper (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _lifter_point
     (setq _lifter_point (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _gripper
     (setq _gripper (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get k21_controller::Lifter :md5sum-) "4a3137a64e8cabd06e461b82358bf017")
(setf (get k21_controller::Lifter :datatype-) "k21_controller/Lifter")
(setf (get k21_controller::Lifter :definition-)
      "float64 lifter_point
float64 gripper
")



(provide :k21_controller/Lifter "4a3137a64e8cabd06e461b82358bf017")


