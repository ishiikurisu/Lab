local creator = { }

--[[ Latex functions ]]
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

-- [[ IO functions ]]
creator.loadData = function(source)
  local lines = { }

  for line in io.lines(source) do
    lines[#lines + 1] = line
  end

  return table.concat(lines, '\n')
end

creator.buildTable = function(raw)
  local outlet = { }
  local data = { }
  local labels = { }
  local lines = strsplit(raw, '\n')
  local limit = -1

  -- Extracting fields from raw data
  for _, line in pairs(lines) do
    local columns = strsplit(line, '\t')
    table.insert(data, columns)
  end

  -- Building map
  labels = data[1]
  limit = #data - 1

  for j = 2, limit do
    for i, label in pairs(labels)  do
      if outlet[label] == nil then
        outlet[label] = { }
      end
      table.insert(outlet[label], data[j][i])
    end
  end

  return outlet
end

creator.table2string = function(matrix)
  local outlet = { }

  for tag, line in pairs(matrix) do
    table.insert(outlet, tag .. ": " .. table.concat(line, "; "))
  end

  return table.concat(outlet, '\n')
end

-- [[ Main functions ]]
function strsplit(inputstr, sep)
  -- http://stackoverflow.com/questions/1426954/split-string-in-lua
  local t = {}; i = 1
  if sep == nil then sep = "%s" end
  for str in string.gmatch(inputstr, "([^"..sep.."]+)") do
    t[i] = str
    i = i + 1
  end
  return t
end

creator.create = function(source)
  local outlet = creator.createHeader()
  local raw = creator.loadData(source)
  local data = creator.buildTable(raw)

  outlet = outlet .. creator.table2string(data) .. '\n'
  outlet = outlet .. creator.createTail()

  return outlet
end

return creator
