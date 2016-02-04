function java2ml()
	where = [cd '\cubic.jar']
	javaclasspath(where)
    joe = br.eng.crisjr.Cube
    fprintf('%f', joe.evaluate(3))
