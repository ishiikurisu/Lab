(ns hello-seesaw.core
  ; (:use seesaw.core)
  (:gen-class
    :name ))

(defn -main [& args]
  "let's create a swing window!"
  (invoke-later
    (-> (frame :title "Hello",
           :content "Hello, Seesaw",
           :on-close :exit)
     pack!
     show!)))
