zip -q -r -e -o content.zip 'macos/' 'tips'
git add content.zip
git commit -m 'auto update'

#to avoid (would never happen but) potential info leak
git push -u origin master -f

#upload to gitlab
#git push -u gitlab master

# test git core.editor and gerrit
