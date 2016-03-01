local cropper = { }

-- requires imagemagick installed
function cropper.magic(img)
	-- AxB+C+D creates a A pixels x B pixels image starting at (C, D)
	op = { }
	op[1] = string.format("convert %s.jpg -crop 1397x1064+870+345 %s.0.png", img, img)
	op[2] = string.format("convert %s.jpg -crop 540x350+513+1470 %s.1.png", img, img)
	op[3] = string.format("convert %s.jpg -crop 540x350+1308+1470 %s.2.png", img, img)
	op[4] = string.format("convert %s.jpg -crop 540x350+2153+1470 %s.3.png", img, img)
	op[5] = string.format("convert %s.jpg -crop 540x350+513+1900 %s.4.png", img, img)
	op[6] = string.format("convert %s.jpg -crop 540x350+1308+1900 %s.5.png", img, img)
	op[7] = string.format("convert %s.jpg -crop 540x350+2153+1900 %s.6.png", img, img)

	for _, v in ipairs(op) do
		os.execute(v)
	end
end

return cropper
