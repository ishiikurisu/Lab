local cropper = require "crop"

while true do
    line = io.read("*line")

    if #line >= 1 then
        cropper.magic(line:sub(1, #line-4))
    else
        break
    end
end
