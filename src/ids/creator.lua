local creator = { }

creator.createHeader = function()
  return [[
\documentclass{article}

\begin{document}
]]
end

creator.createTail = function()
  return [[
\end{document}
]]
end

creator.loadData = function(source)
  local lines = { }

  for line in io.lines(source) do
    lines[#lines + 1] = line
  end

  return table.concat(lines, '\n')
end

creator.create = function(source)
  local outlet = creator.createHeader()
  outlet = outlet .. creator.loadData(source) .. '\n'
  outlet = outlet .. creator.createTail()
  return outlet
end

return creator
