(ns rocks.crisjr.inutils)

(defn write-array
  [n limit arr]
  (if (< n limit)
    (do
      (println n ": " (nth arr n) (class (nth arr n)))
      (write-array (inc n) limit arr))))

(defn for-arg-loop
  [n limit args f]
  (if (< n limit)
    (f (nth args n))))
(defn for-arg
  [args f]
  (for-arg-loop 0 (count args) args f))

(defn parse-int [s]
   (Integer. (re-find  #"\d+" s )))
