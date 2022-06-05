
(cl:in-package :asdf)

(defsystem "k21_controller-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Gripper" :depends-on ("_package_Gripper"))
    (:file "_package_Gripper" :depends-on ("_package"))
    (:file "VelCmd" :depends-on ("_package_VelCmd"))
    (:file "_package_VelCmd" :depends-on ("_package"))
  ))