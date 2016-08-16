while true
do

echo "1 List processes"
echo "2 List all processes"
echo "3 Change priority of a process"
echo "4 Kill a process"
echo "5 Exit"
echo "Enter your choice : "
read choice

case $choice in

1) ps -l
   ;;

2) top
   ;;

3) echo "Enter PID of the process : "
   read pid
   echo "Enter new priority of the process : "
   read prio

   renice $prio $pid
   ;;
4) echo "Enter PID of the process to be terminated : "
   read pid
   
   kill $pid
   ;;

5) exit
   ;;

*) echo "Please enter a proper value."
   ;;

esac
done
