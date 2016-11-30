function main(arg)
  os.execute("cd src")
  os.execute("cd")
end

if type(package.loaded[(...)]) ~= "userdata" then
  main(arg)
else
  module(..., package.seeall)
end
