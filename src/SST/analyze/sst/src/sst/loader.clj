(ns sst.loader
    (:gen-class))

(def needed-stuff
    #{})

(defn update-dict
    [stuff dict i]
    (let [item (nth i stuff)]
        (if (contains? item)
            (assoc dict item i)
            dict)))

(defn get-needed-headers-loop
    [stuff dict index limit]
    (if (= index limit)
        dict
        (get-needed-headers
            stuff
            (update-dict stuff dict index)
            (inc index)
            limit)))

(defn get-needed-headers
    [stuff]
    (get-needed-headers-loop
        stuff (hash-map) 0 (count stuff)))
