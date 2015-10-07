while true do
	local line
	local acertos = 0
	local erros = 0
	local nota = 0

	line = io.read()
	if string.len(line) == 0 then break end

	while string.len(line) > 0 do
		if tonumber(line) == 0 then
			erros = erros + 1
		else
			acertos = acertos + 1
		end
		line = io.read()
	end

	nota = acertos - erros/3
	print(nota)
end
