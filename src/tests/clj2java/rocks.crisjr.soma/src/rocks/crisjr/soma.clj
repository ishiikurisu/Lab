(ns rocks.crisjr.soma
  (:gen-class)
  (:use [rocks.crisjr.inutils :as inu])
  (:use [clojure.java.io :as io]))

; setup functions
(defn valid-line?
  [line]
    (not (or
           (= line "---")
           (= line "..."))))

(defn setup-loop
  [line box]
  (if (nil? line)
    box
    (setup-loop
      (read-line)
      (if (valid-line? line)
        (conj box line)
        box))))

; draw functions

; main functions
(defn setup
  []
  (setup-loop (read-line) [])
)

(defn draw
  [inlet]
  (reduce + (for [it inlet]
              (inu/parse-int it))))

(defn -main
  "I sum numbers from a YAML file lol"
  [& args]
  (println (draw (setup))))
