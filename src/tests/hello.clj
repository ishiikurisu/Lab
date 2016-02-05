(require '[clojure.string :as str])
(defn say-hi [name]
	(println (concat "hello " name)))
(say-hi "joe")