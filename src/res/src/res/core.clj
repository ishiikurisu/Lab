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
  (nth (re-find #"-(.*?)\(" line) 1))

(defn get-what-is-in-brackets
  [line]
  (map #(nth %1 1) (re-seq #"\((.*?)\)" line)))

(defn feed-table
  [lines]
  (let [names (map str/trim (map get-name lines))
        infos (map get-what-is-in-brackets lines)]
    (loop [n 0
           limit (count names)
           outlet "\nNome;E-mail;Identificação\n"]
      (if (= n limit)
        outlet
        (recur (inc n)
               limit
               (str outlet (nth names n) ";"
                           (nth (nth infos n) 0) ";"
                           (nth (nth infos n) 1) "\n"))))))

(defn task
  [arg]
  (let [lines (->> arg
                   slurp
                   get-lines
                   (filter #(not (invalid-line %1))))]
    (feed-table lines)))

(defn -main
  "I open a YAML file and turn it into a CSV file... I hope so."
  [& args]
  (println (map task args)))
