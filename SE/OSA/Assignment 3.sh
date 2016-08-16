while true
do

echo "1 Add a new user"
echo "2 Get access permissions of a file : "
echo "3 Set access permissions of a file : "
echo "4 Exit"
echo "Enter your choice : "
read choice

case $choice in

1) echo "Enter the name of the new user : "
   read username
   sudo adduser $username
   ;;

2) echo "Enter the name of the file or directory : "
   read filename
   
   if [ -e $filename ]
	then
	getfacl $filename
   else
	echo "The file or directory of the name '"$filename"' does not exist"
   fi
   ;;

3) echo "Enter the name of the file or directory : "
   read filename
   echo "Enter the name of the user : "
   read username
   echo "Enter the permission you want to set (rwx) : "
   read per

   if [ -e $filename ]
	then
	sudo setfacl -m u:$username:$per $filename 
   else
	echo "The file or directory of the name '"$filename"' does not exist"
   fi
   ;;

4) exit
   ;;

*) echo "Please enter a proper value"
      
esac
done

