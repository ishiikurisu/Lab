(ns res.core
  (:gen-class)
  (:require [clojure.string :as str]))

(defn get-lines
  [raw]
  (str/split-lines raw))

(defn invalid-line
  [line]
  (or (= 0 (count line))
      (re-find #"([A-Za-z]:)" line)))

(defn feed-table
  [line]
  (let []
    ))

(defn get-name
  [line]
  line)

(defn get-what-is-in-brackets
  [line]
  (map #(nth %1 1) (re-seq #"\((.*?)\)" line)))

(defn task
  [arg]
  (->> arg
       slurp
       get-lines
       (filter #(not (invalid-line %1)))
       (map get-what-is-in-brackets)
  )
)

(defn -main
  "I open a YAML file and turn it into a CSV file... I hope so."
  [& args]
  (println (map task args)))
