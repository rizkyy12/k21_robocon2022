;; Auto-generated. Do not edit!


(when (boundp 'k21_controller::VelCmd)
  (if (not (find-package "K21_CONTROLLER"))
    (make-package "K21_CONTROLLER"))
  (shadow 'VelCmd (find-package "K21_CONTROLLER")))
(unless (find-package "K21_CONTROLLER::VELCMD")
  (make-package "K21_CONTROLLER::VELCMD"))

(in-package "ROS")
;;//! \htmlinclude VelCmd.msg.html


(defclass k21_controller::VelCmd
  :super ros::object
  :slots (_Vx _Vy _w ))

(defmethod k21_controller::VelCmd
  (:init
   (&key
    ((:Vx __Vx) 0.0)
    ((:Vy __Vy) 0.0)
    ((:w __w) 0.0)
    )
   (send-super :init)
   (setq _Vx (float __Vx))
   (setq _Vy (float __Vy))
   (setq _w (float __w))
   self)
  (:Vx
   (&optional __Vx)
   (if __Vx (setq _Vx __Vx)) _Vx)
  (:Vy
   (&optional __Vy)
   (if __Vy (setq _Vy __Vy)) _Vy)
  (:w
   (&optional __w)
   (if __w (setq _w __w)) _w)
  (:serialization-length
   ()
   (+
    ;; float64 _Vx
    8
    ;; float64 _Vy
    8
    ;; float64 _w
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _Vx
       (sys::poke _Vx (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Vy
       (sys::poke _Vy (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _w
       (sys::poke _w (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _Vx
     (setq _Vx (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Vy
     (setq _Vy (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _w
     (setq _w (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get k21_controller::VelCmd :md5sum-) "dc80fc0c33bfc67846d488513b7c90a4")
(setf (get k21_controller::VelCmd :datatype-) "k21_controller/VelCmd")
(setf (get k21_controller::VelCmd :definition-)
      "float64 Vx
float64 Vy
float64 w

")



(provide :k21_controller/VelCmd "dc80fc0c33bfc67846d488513b7c90a4")


