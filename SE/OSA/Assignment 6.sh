while true
do

echo "1 List Present working directory"
echo "2 List contents of directory"
echo "3 Change directory"
echo "4 Exit"
echo "Enter your choice : "
read choice

case $choice in

1) pwd
   ;;

2) ls
   ;;

3) echo "Enter path of the new directory : "
   read path
   
   cd $path
   ;;

4) exit
   ;;

*) echo "Please enter a proper value."

esac
done
