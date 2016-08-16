while true
do

echo "1 Lower to Upper Case"
echo "2 Upper to Lower Case"
echo "3 Exit"
echo "Enter your choice : "
read choice

case $choice in

1) echo "Enter the name of the input file : "
   read filename

   if [ ! -f $filename ]
   then
	echo "The file '"$filename"' does not exist"
   else
	tr 'a-z' 'A-Z' <$filename
   fi
   ;;

2) echo "Enter the name of the input file : "
   read filename

   if [ ! -f $filename ]
   then
	echo "The file '"$filename"' does not exist"
   else
	tr 'A-Z' 'a-z' <$filename
   fi
   ;;

3) exit
   ;;

esac
done
