imagemagick = function(img)
	local resize = string.format("convert %s.png -resize 90%% %s.jpg", img, img)
	local crop0 = string.format("convert %s.jpg -crop 339x233+73+17 %s.0.png", img, img)
	local crop1 = string.format("convert %s.jpg -crop 134x100+15+278 %s.1.png", img, img)
	-- local crop2
	-- local crop3
	-- local crop4
	-- local crop5
	-- local crop6
	local clean = "del *.jpg"

	os.execute(resize)
	os.execute(crop0)
	os.execute(crop1)
	os.execute(clean)
end
