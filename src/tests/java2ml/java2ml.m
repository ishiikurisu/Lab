function java2ml()
    javaaddpath '\br\eng\crisjr'
    javaclasspath
    import br.eng.crisjr.*
    joe = br.eng.crisjr.Cube()
    fprintf('%f', joe.evaluate(3))
