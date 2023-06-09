find . -type -name "*.sh" -print | sed 's/...$//' | sed s'/^.*\///'
