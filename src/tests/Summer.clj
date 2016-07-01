(defn parse-int [s]
   (Integer. (re-find  #"\d+" s )))

(defn read-data []
	(loop [line (read-line)
		   stuff (list)]
		(if (= (count line) 0)
			stuff
			(recur (read-line)
				   (conj stuff line)))))

(println (reduce + (map parse-int (read-data))))