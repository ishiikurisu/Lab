(ns sst.core
    (:gen-class)
    (:require [clojure.string :as str])
    (:use [sst.loader :as loader])

; draw functions

; main functions
(defn setup
    []
    (do
        (read-line)
        (loader/get-needed-headers (split (read-line) #"\s+"))))

(defn draw
    [header]
    header)

(defn -main
    "Let's process some data."
    [& args]
    (println (draw (setup))))
