box: Box.cs
	csc /target:module Box.cs /nologo
app: App.cs box
	csc /addmodule:Box.netmodule App.cs /nologo
test: app
	more data.yml | App
more: app
