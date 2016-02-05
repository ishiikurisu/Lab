(ns byebye-seesaw.core
  (:use seesaw.core)
  (:gen-class
    :name ))

(defn -main [& args]
  "let's create a swing window!"
  (invoke-later
    (-> (frame :title "Bye",
           :content "Bye bye, Seesaw",
           :on-close :exit)
     pack!
     show!)))
