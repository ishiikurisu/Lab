-- # Logic of the problem
patterns = {
	"ECG",
	"Annotations",
	"A2-A1",
	"C3-A1",
	"C4-A1",
	"Cz-A1",
	"F3-A1",
	"F4-A1",
	"F7-A1",
	"F8-A1",
	"Fp1-A1",
	"Fp2-A1",
	"Fpz-A1",
	"Fz-A1",
	"O1-A1",
	"O2-A2",
	"Oz-A1",
	"P4-A1",
	"Pz-A1",
	"T3-A1",
	"T4-A1",
	"T5-A1",
	"T6-A1",
	"EMG-RGP",
	"EXT"
}

-- # Generating script name
shell = "cmd /C "
script_name = "." .. os.tmpname() .. "bat"

-- # Generating scripts
commands = { }
-- # Going to correct folder
table.insert(commands, "cd ..")
table.insert(commands, "cd github.com")
table.insert(commands, "cd lab-neuro-comp")
table.insert(commands, "cd SST-data")
-- ## Generating git actions
for _, pattern in pairs(patterns) do
	table.insert(commands, "git add *" .. pattern .. ".mat.fig")
	table.insert(commands, "git commit -m\"Adding " .. pattern .. " recs\"")
	table.insert(commands, "git push origin master")
end
-- ## Returning to source ##
for _ = 1, 3 do
	table.insert(commands, "cd ..")
end
table.insert(commands, "cd autoupload")

-- # Populating script file and executing it
fp = io.open(script_name, "w")
io.output(fp)
for _, cmd in ipairs(commands) do
  io.write(cmd .. "\n")
end
io.close(fp)
os.execute(shell .. script_name)
os.remove(script_name)
