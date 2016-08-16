while true
do

echo "1 Display Operating System"
echo "2 Display Username"
echo "3 Display Hostname"
echo "4 Exit"
echo "Enter your choice : "
read choice

case $choice in

1) uname -o
   ;;

2) logname
   ;;

3) hostname
   ;;

4) exit
   ;;

*) echo "Please enter a proper value"


esac
done

