(ns jake.core
  (:gen-class
   :name jake.core
   :methods [#^{:static true} [sayTime [String] String]]))

(defn say-time
  [what]
  (str "It's " what " time!"))

(defn -sayTime
  [what]
  (say-time what))

(defn -main
  "What time is it?"
  [& args]
  (println (say-time "adventure")))
