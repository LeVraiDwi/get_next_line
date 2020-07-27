echo "test 1:\n"
sh compil.sh '1 main.c'
echo -n "asfqasfa" > text.txt
./a.out

echo "test 2:\n"
sh compil.sh '1 main.c'
cat -n get_next_line.h > text.txt
./a.out

echo "test 3:\n"
sh compil.sh '1 main.c'
echo -n "" > text.txt
./a.out

echo "test 4:\n"
sh compil.sh '1 main.c'
echo "" > text.txt
./a.out

echo "test 5:\n"
sh compil.sh '1 main.c'
rm text.txt
./a.out

echo "test 6:\n"
sh compil.sh '25 main.c'
echo -n "asfqasfa" > text.txt
./a.out

echo "test 7:\n"
sh compil.sh '25 main.c'
cat -n get_next_line.h > text.txt
./a.out

echo "test 8:\n"
sh compil.sh '33 main.c'
echo -n "" > text.txt
./a.out

echo "test 9:\n"
sh compil.sh '42 main.c'
echo "" > text.txt
./a.out

echo "test 10:\n"
sh compil.sh '18 main.c'
rm text.txt
./a.out

echo "test 11:\n"
sh compil.sh '2500 main.c'
echo -n "asfqasfa" > text.txt
./a.out

echo "test 12:\n"
sh compil.sh '25000 main.c'
cat -n get_next_line.h > text.txt
./a.out

echo "test 13:\n"
sh compil.sh '33000 main.c'
echo -n "" > text.txt
./a.out

echo "test 14:\n"
sh compil.sh '42000 main.c'
echo "" > text.txt
./a.out

echo "test 15:\n"
sh compil.sh '1800 main.c'
rm text.txt
./a.out

echo "test 16:\n"
sh compil.sh '0 main.c'
cat -n get_next_line.h > text.txt
./a.out

echo "test 17:\n"
sh compil.sh '-15 main.c'
cat -n get_next_line.h > text.txt
./a.out
