TARGET_DIRECTORY="build"

rm $TARGET_DIRECTORY/*;

for f in $(ls *.c); do 
    gcc -o "$TARGET_DIRECTORY/${f%.c}.out" $f; 
done
