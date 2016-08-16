while true
do

echo "1 Create a new Directory"
echo "2 Rename a Directory"
echo "3 Delete a Directory"
echo "4 Exit"
echo "Enter your choice : "
read choice

case $choice in

1) echo "Enter name of the Directory to be created : "
   read filename
   mkdir $filename
   echo "Directory of the name '"$filename"' created successfully."
   ;;

2) echo "Enter name of the Directory to be renamed : "
   read filename
   echo "Enter new name of the Directory : "
   read newname

   if [ -d $filename ] 
	then
	mv $filename $newname
	echo "Directory of the name '"$filename"' renamed successfully." 
   else
	echo "Directory of the name '"$filename"' does not exist."
   fi
   ;;
  
3) echo "Enter the name of the Directory to be deleted : "
   read filename
   
   if [ -d $filename ] 
	then
	rmdir $filename
	echo "Directory of the name '"$filename"' deleted successfully." 
   else
	echo "Directory of the name '"$filename"' does not exist."
   fi
   ;;

4) exit
   ;;  

*) echo "Enter a proper value."

esac
done
