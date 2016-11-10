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

creator.create = function()
  local outlet = creator.createHeader()
  outlet = outlet .. "% Let's write this\n"
  outlet = outlet .. creator.createTail()
  return outlet
end

return creator
