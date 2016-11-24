(defproject res "0.1.0"
  :description "Creates a table from a YAML file"
  :url "http://www.crisjr.eng.br"
  :license {:name "THE BEER-WARE LICENSE"
            :url "https://people.freebsd.org/~phk/"}
  :dependencies [[org.clojure/clojure "1.8.0"]]
  :main res.core
  :target-path "target/%s"
  :profiles {:uberjar {:aot :all}})
