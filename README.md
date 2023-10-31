# WBSU CMSACOR03P Solutions

cd into any set-* directory and run the following command to compile the .java files into .class inside class/ directory.

```sh
for f in src/*.java ; do \
	javac -d class/ $f ; done
```
