(defproject rocks.crisjr.soma "0.1.0-SNAPSHOT"
    :description "A stupid app to sum numbers from a YAML list."
    :url "http://example.com/FIXME"
    :license {:name "Eclipse Public License"
              :url "http://www.eclipse.org/legal/epl-v10.html"}
    :dependencies [[org.clojure/clojure "1.7.0"]]
    :main ^:skip-aot rocks.crisjr.soma
    :target-path "target/%s"
    :profiles {:uberjar {:aot :all}})
