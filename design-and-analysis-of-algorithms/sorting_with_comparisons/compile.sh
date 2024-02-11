CC=/usr/bin/gcc
INPUT=test-sort.c
OUTPUT=test-sort.out
if [ -x $OUTPUT ] ; then
    shred -zuv $OUTPUT
fi
$CC -o $OUTPUT $INPUT
./$OUTPUT | tee output.txt
