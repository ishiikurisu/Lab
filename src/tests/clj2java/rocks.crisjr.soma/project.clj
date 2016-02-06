(defproject rocks.crisjr.soma "0.1.0-SNAPSHOT"
  :description "A stupid app that sums stuff"
  :url "https://github.com/ishiikurisu"
  :license {:name "Beerware"
            :url "https://fedoraproject.org/wiki/Licensing/Beerware"}
  :dependencies [[org.clojure/clojure "1.7.0"]]
  :main ^:skip-aot rocks.crisjr.soma
  :target-path "target/%s"
  :profiles {:uberjar {:aot :all}})
