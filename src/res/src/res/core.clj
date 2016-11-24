(ns res.core
  (:gen-class)
  (:require [clojure.string :as str]))

(defn parse-args
  [args]
  (map slurp args))

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

(defn -main
  "I open a YAML file and turn it into a CSV file... I hope so."
  [& args]
  (println (->> (nth args 0)
                slurp
                get-lines
                (filter #(not (invalid-line %1)))
                (map feed-table)
           )))
