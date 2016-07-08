box: Box.cs
	csc /target:module Box.cs /nologo
app: App.cs box
	csc /addmodule:Box.netmodule App.cs /nologo
test: app data.yml
	more data.yml | App
more: app
