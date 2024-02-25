TARGET_DIRECTORY="build"

if [ -x $TARGET_DIRECTORY ] ; then 
    echo "Found '$TARGET_DIRECTORY/' dir";
else
    echo "Created '$TARGET_DIRECTORY/' dir";
    mkdir "$TARGET_DIRECTORY";
fi

if [ $(find $TARGET_DIRECTORY -type f | wc -l) -gt 0 ]; then
    echo "Cleared '$TARGET_DIRECTORY/' dir"
    rm $TARGET_DIRECTORY/*;
fi

set out;
for f in $(ls *.c); do 
    out="$TARGET_DIRECTORY/$f.out";
    gcc -o $out $f; 
    echo "'$out' -> Compiled Successfully!"
done

for f in $(ls *.cc); do 
    out="$TARGET_DIRECTORY/$f.out";
    g++ -o $out $f; 
    echo "'$out' -> Compiled Successfully!"
done

unset out;
