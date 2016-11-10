local creator = { }

--[[ Latex functions ]]

-- Creates the standard header of a LaTeX file
creator.createHeader = function()
  return [[
\documentclass{article}

\begin{document}
]]
end

-- Creates the standard ending of a LaTeX file
creator.createTail = function()
  return [[
\end{document}
]]
end

-- [[ IO functions ]]

--- Loads a file to its raw string
creator.loadData = function(source)
  local lines = { }

  for line in io.lines(source) do
    lines[#lines + 1] = line
  end

  return table.concat(lines, '\n')
end

-- Builds a table from a TSV string
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

-- Turns a hashmap into a string
creator.table2string = function(matrix)
  local outlet = { }

  for tag, line in pairs(matrix) do
    table.insert(outlet, tag .. ": " .. table.concat(line, "; "))
  end

  return table.concat(outlet, '\n')
end

-- [[ Main functions ]]

-- Splits a string into its fields separated by a separator
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

-- The module's main function
creator.create = function(source)
  local outlet = creator.createHeader()
  local raw = creator.loadData(source)
  local data = creator.buildTable(raw)

  -- Formatting data
  outlet = outlet .. creator.table2string(data) .. '\n'

  -- Finishing file
  outlet = outlet .. creator.createTail()
  return outlet
end

return creator
